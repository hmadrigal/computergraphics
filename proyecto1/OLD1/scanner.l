
D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*

%{
#include <stdio.h>
#include "y.tab.h"
/*
#define CONSTANT 200
#define STRING_LITERAL 201
#define BEGINN 202
#define WINDOW 203
#define COLOR_RGB 204
#define COLOR 205
#define TERRITORY 206
#define TEXTURE 207
#define LIMITS 208
#define END 209

#define WHITE 210
#define YELLOW 211
#define MAGENT 212
#define RED 213
#define CYAN 214
#define GREEN 215
#define BLUE 216
#define BLACK 217*/

%}

%%
"/*"				{ comment(); }
"//".*\n			{ /* Comentario de una linea */ }

"window"				{ return(WINDOW); }
"begin"				{ return(BEGINN); }
"rgb-color"			{ return(COLOR_RGB); }
"color"				{ return(COLOR); }
"territory"				{ return(TERRITORY); }
"texture"				{ return(TEXTURE); }
"limits"				{ return(LIMITS); }
"end"				{ return(END); }

"WHITE"				{ return(WHITE); }
"YELLOW"			{ return(YELLOW); }
"MAGENT"			{ return(MAGENT); }
"RED"				{ return(RED); }
"CYAN"				{ return(CYAN); }
"GREEN"				{ return(GREEN); }
"BLUE"				{ return(BLUE); }
"BLACK"				{ return(BLACK); }

{D}+{L}+				{ printf("ERROR: %s en linea %i\n", yytext, yylineno); exit(1); }

{D}+					{ yylval.val = atoi(yytext); return(CONSTANT); return(CONSTANT); }
{D}*"."{D}+			{ yylval.dval = atof(yytext); return(CONSTANT); return(CONSTANT); }
{D}+"."{D}*			{ yylval.dval = atof(yytext); return(CONSTANT); return(CONSTANT); }

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
