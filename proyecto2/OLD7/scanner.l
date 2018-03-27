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
typedef enum { as,ESCENA, LUZ, TITULO,CADENA,VENTANA,NUMERO,COLOR_FONDO,POSICION_OJO,LUZ_AMBIENTE,FATT,
COLOR,POSICION,INTENSIDAD,ESFERA,POLIGONO,CILINDRO,CONO,
INICIO_PLANOS_DE_CORTE,FIN_PLANOS_CORTE,INICIO_TRANSFORMACIONES,FIN_TRANSFORMACIONES
, ROTAR_X,ROTAR_Y,ROTAR_Z,TRASLADAR,ESCALAR
, KD,KA,KS,KN, CENTRO,RADIO
} rango;
*/
%}

%%

"/*"							{ comment(); }
"//".*[\n]*						{ /* Comentario de una linea */ }

"RESOLUCION"				{ return  RESOLUCION; }
"SUPERFICIE_2"				{ return SUPERFICIE_2 ; }
"TRASLADAR"				{ return TRASLADAR ; }
"ROTAR"						{ return ROTAR ; }
"DIRECCION"					{ return DIRECCION ; }
"TRANSFORMACIONES"		{ return TRANSFORMACIONES ; }
"ESCENA"					{ return ESCENA ; }
"LUZ"						{ return LUZ ;}
"TITULO" 					{ return TITULO ; }
"CADENA"					{ return CADENA ; }
"VENTANA"					{ return VENTANA ; }
"NUMERO"					{ return NUMERO ; }
"COLOR_FONDO"				{ return COLOR_FONDO ; }
"POSICION_OJO"				{ return POSICION_OJO ; }
"LUZ_AMBIENTE"				{ return LUZ_AMBIENTE ; }
"FATT"						{ return FATT ; }
"COLOR"						{ return COLOR ; }
"POSICION"					{ return POSICION ; }
"INTENSIDAD"				{ return INTENSIDAD ; }
"ESFERA"					{ return ESFERA ; }
"POLIGONO"					{ return POLIGONO ; }
"CILINDRO"					{ return CILINDRO ; }
"CONO"						{ return CONO ; }
"PLANOS_DE_CORTE"			{ return PLANOS_DE_CORTE ; }
"TRANSFORMACIONES"		{ return TRANSFORMACIONES ; }
"ROTAR_X"					{ return ROTAR_X ; }
"ROTAR_Y"					{ return ROTAR_Y ; }
"ROTAR_Z"					{ return ROTAR_Z ; }
"TRASLADAR"				{ return TRASLADAR ; }
"ESCALAR"					{ return ESCALAR ; }
"KD"							{ return KD ; }
"KA"							{ return KA ; }
"KS"							{ return KS ; }
"KN"							{ return KN ; }
"POSICION"					{ return POSICION; }
"RADIO"						{ return RADIO; }
"ANCLA"						{ return ANCLA; }
"PLANO_ECUACION"			{ return PLANO_ECUACION; }
"PLANO_PUNTOS"				{ return PLANO_PUNTOS; }
"DISCO"						{ return DISCO; }
"FACTOR_K"						{ return FACTOR_K; }

"+"							{ return '+' ; }
"-"							{ return '-' ; }
"="							{ return '=' ; }
"("							{ return '(' ; }
")"							{ return ')' ; }
"["							{ return '[' ; }
"]"							{ return ']' ; }
","							{ return ',' ; }


"-"{D}+|{D}+					{yylval.ldval = (long double) atof(yytext); return NUMERO;}
"-"{D}*"."{D}+|{D}*"."{D}+			{yylval.ldval = (long double) atof(yytext); return NUMERO;}
"-"{D}+"."{D}*|{D}+"."{D}*			{yylval.ldval = (long double) atof(yytext); return NUMERO;}
L?\"("\\\""|[^\"\n])*\" 			 	{yytext[yyleng-1] = 0; yylval.strval = yytext+1; return(CADENA); }

[ \t\v\f\n]						{/* Espacios en blanco*/}
.							{ printf("LEX Says: Unknow token \"%s\" in line:%i.\n", yytext, yylineno); exit(1); }

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
PROBAR LEX
main(int argc, char *argv[]) {
	int lexy;
	while( lexy = yylex()) {
		printf("%s->[%i]\n", yytext,lexy);
	}
}
*/
