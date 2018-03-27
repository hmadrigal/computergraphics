D			[0-9]

%{

#include <stdio.h>
#include "y.tab.h"

%}	
	
%%

"/*"				{comment();}
"//".*\n			{ /*Comentario de Linea*/ }

"RESOLUCION"			{return RESOLUCION;}
"VENTANA"			{return VENTANA;}
"INCREMENTO"			{return INCREMENTO;}
"INICIAN_PUNTOS"		{return INICIAN_PUNTOS;}
"FIN_PUNTOS"			{return FIN_PUNTOS;}
"FOREGROUND"			{return FOREGROUND;}
"BACKGROUND"			{return BACKGROUND;}


"-"{D}+|{D}+			{yylval.dblval = atof(yytext); return NUMERO;}
"-"{D}*"."{D}+|{D}*"."{D}+	{yylval.dblval = atof(yytext); return NUMERO;}
"-"{D}+"."{D}*|{D}+"."{D}*	{yylval.dblval = atof(yytext); return NUMERO;}

"("				{return '(';}
")"				{return ')';}
","				{return ',';}

[ \t\v\f\n]			{/* Espacios en blanco*/}
.				{ printf("LEX Says: Unknow token \"%s\" in line:%i.\n", yytext, yylineno); exit(1); }

%%

yywrap()
{ return(1); }
	
//Omite los comentarios
comment() {
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
//PROBANDO LEX
int main(int argc, char *argv[]) {
	int lexy;
	while( lexy = yylex()) {
		printf("%s", yytext,lexy);
	}
	return 0;
}
*/