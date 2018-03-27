
D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*

%{
#include <stdio.h>
#include "y.tab.h"

%}

%%
"/*"				{ comment(); }
"//".*\n			{ /* Comentario de una linea */ }

"window"				{ return(WINDOW); }
"begin"				{ return(BEGINN); }
"color"				{ return(COLOR); }
"background"			{ return(BACK); }
"territory"				{ return(TERRITORY); }
"texture"				{ return(TEXTURE); }
"limits"				{ return(LIMITS); }
"end"				{ return(END); }
"screen-size"			{ return(SCREEN_SIZE); }

"WHITE"				{ return(WHITE); }
"YELLOW"			{ return(YELLOW); }
"MAGENTA"			{ return(MAGENTA); }
"RED"				{ return(RED); }
"CYAN"				{ return(CYAN); }
"GREEN"				{ return(GREEN); }
"BLUE"				{ return(BLUE); }
"BLACK"				{ return(BLACK); }

{D}+{L}+				{ printf("ERROR: %s en linea %i\n", yytext, yylineno); exit(1); }

[- \t]{D}+					{ yylval.val = atoi(yytext); return(CONSTANT); return(CONSTANT); }
[- \t]{D}*"."{D}+			{ yylval.dval = atof(yytext); return(CONSTANT); printf("%.3f\n", yylval.dval); return(CONSTANT); }
[- \t]{D}+"."{D}*			{ yylval.dval = atof(yytext); return(CONSTANT); printf("%.3f\n", yylval.dval); return(CONSTANT); }

L?\"("\\\""|[^\"\n])*\"  		{ yytext[yyleng-1] = 0; yylval.str = yytext+1; return(STRING_LITERAL); }
\"			 		{ fprintf(stderr, "ERROR: %s en linea %i\n", yytext, yylineno); exit(1); }

"="					{ return('='); }
[ \t\v\f\n]				{ }
.					{ printf("Error %s en linea %i\n", yytext, yylineno); exit(1); }
%%

yywrap()
{
	return(1);
}

comment()
{
	char c, c1;

loop:
	while ((c = input()) != '*' && c != 0);

	if ((c1 = input()) != '/' && c != 0)
	{
		unput(c1);
		goto loop;
	}
}
/*
main(int argc, char *argv[]) {
	int lexy;
	while( lexy = yylex()) {
		printf("number %i - %s\n", lexy, yytext);
	}
}*/
