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
typedef enum {
			ESCENA, LUZ, TITULO,CADENA,VENTANA,NUMERO,COLOR_FONDO,
			POSICION_OJO,LUZ_AMBIENTE,FATT, COLOR,POSICION,INTENSIDAD,
			ESFERA,POLIGONO,CILINDRO,CONO,DISCO,FACTOR_K, ANCLA,
			ROTAR_X,ROTAR_Y,ROTAR_Z,TRASLADAR,ESCALAR,KD,KA,KS,KN, CENTRO,RADIO,O1,O2,O3,
			RESOLUCION, SUPERFICIE_2, ROTAR, DIRECCION, TRANSFORMACIONES,PLANOS_DE_CORTE,
			PLANO_TRANSFORMADO_X, PLANO_TRANSFORMADO_Y, PLANO_TRANSFORMADO_Z,
			REFLEXION, TRANSPARECIA, ANTIALIASING, OBJETO, PUNTOS,
			MAPAS_DE_TEXTURAS, MAPAS_DE_GRISES, TEXTURA, GRIS, IMAGEN, TILED, STRETCH,
			ALTURA, BRILLO, TRANSPARENCIA, PHONG, RANGO
} rango;
*/
%}

%%

"/*"							{ comment(); }
"//".*[\n]*						{ /* Comentario de una linea */ }

"TOROIDE"						{ return  TOROIDE; }
"RANGO"						{ return  RANGO; }
"IMAGEN"					{ return  IMAGEN; }
"TILED"						{ return  TILED; }
"STRETCH"					{ return  STRETCH; }
"ALTURA"					{ return  ALTURA; }
"BRILLO"						{ return  BRILLO; }
"TRANSPARENCIA"			{ return  TRANSPARENCIA; }
"PHONG"						{ return  PHONG; }
"MAPAS_DE_TEXTURAS"		{ return  MAPAS_DE_TEXTURAS; }
"MAPAS_DE_GRISES"			{ return  MAPAS_DE_GRISES; }
"TEXTURA"					{ return  TEXTURA; }
"GRIS"						{ return  GRIS; }
"PUNTOS"					{ return  PUNTOS; }
"OBJETO"					{ return  OBJETO; }
"REFLEXION"					{ return  REFLEXION; }
"TRANSPARECIA"				{ return  TRANSPARECIA; }
"ANTIALIASING"				{ return  ANTIALIASING; }
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
"KT"							{ return KT ; }
"POSICION"					{ return POSICION; }
"RADIO"						{ return RADIO; }
"ANCLA"						{ return ANCLA; }
"PLANO_TRANSFORMADO_X"	{ return PLANO_TRANSFORMADO_X; }
"PLANO_TRANSFORMADO_Y"	{ return PLANO_TRANSFORMADO_Y; }
"PLANO_TRANSFORMADO_Z"	{ return PLANO_TRANSFORMADO_Z; }
"DISCO"						{ return DISCO; }
"FACTOR_K"					{ return FACTOR_K; }
"O1"							{ return O1; }
"O2"							{ return O2; }
"O3"							{ return O3; }

"+"							{ return '+' ; }
"-"							{ return '-' ; }
"="							{ return '=' ; }
"("							{ return '(' ; }
")"							{ return ')' ; }
"["							{ return '[' ; }
"]"							{ return ']' ; }
","							{ return ',' ; }
"{"							{ return '{' ; }
"}"							{ return '}' ; }


"-"{D}+|{D}+					{yylval.ldval = (double) atof(yytext); return NUMERO;}
"-"{D}*"."{D}+|{D}*"."{D}+			{yylval.ldval = (double) atof(yytext); return NUMERO;}
"-"{D}+"."{D}*|{D}+"."{D}*			{yylval.ldval = (long double) atof(yytext); return NUMERO;}
L?\"("\\\""|[^\"\n])*\" 			 	{yytext[yyleng-1] = 0; yylval.strval = yytext+1;return(CADENA); }

[ \t\v\f\n]						{/* Espacios en blanco*/}
.							{ printf("LEX Says: Unknown token \"%s\" in line:%i.\n", yytext, yylineno); exit(1); }

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

//PROBAR LEX
main(int argc, char *argv[]) {
	int lexy;
	while( lexy = yylex()) {
		printf("%s->[%i]\n", yytext,lexy);
	}
}*/

