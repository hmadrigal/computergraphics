%{
#include <stdio.h>
#include <string.h>
%}

%token ESCENA LUZ 
%token TITULO CADENA VENTANA NUMERO COLOR_FONDO  POSICION_OJO LUZ_AMBIENTE FATT 
%token COLOR POSICION INTENSIDAD ESFERA POLIGONO CILINDRO CONO 
%token PLANOS_DE_CORTE TRANSFORMACIONES 
%token ROTAR_X ROTAR_Y ROTAR_Z TRASLADAR ESCALAR
%token KD KA KS KN 
%token POSICION RADIO DIRECCION TRANSFORMACIONES
%token ROTAR TRASLADAR

%union {
	char *strval;
	int intval;
	long double ldval;
}

%start inicia_gramatica

%%
inicia_gramatica: 
	ESCENA seccion_escena 	
	seccion_objetos
	;

seccion_escena:
	TITULO CADENA {printf("Escena=%s\n",$<strval>2);}
	VENTANA '('NUMERO NUMERO')' '('NUMERO NUMERO ')' 
	COLOR_FONDO NUMERO NUMERO NUMERO 
	POSICION_OJO '('NUMERO NUMERO NUMERO')'
	LUZ_AMBIENTE NUMERO
	FATT NUMERO NUMERO NUMERO 	
	{
		printf("Xmin=%Lf Ymin=%Lf Xmax=%Lf YMnax=%Lf\n",$<ldval>6, $<ldval>7, $<ldval>10, $<ldval>11);
		printf("BG R=%Lf G=%Lf B:%Lf \n",$<ldval>14, $<ldval>15, $<ldval>16);
		printf("OJO X=%Lf Y=%Lf Z=%Lf \n",$<ldval>19, $<ldval>20, $<ldval>21);
		printf("Ia=%Lf FATT: C1=%Lf C2=%Lf C3=%Lf \n",$<ldval>24, $<ldval>26, $<ldval>27, $<ldval>28);
	}
	;

	
seccion_objetos:
	lista_objetos
	|
	;

lista_objetos:
	  objeto lista_objetos
	| objeto
	;

info_objeto:
	COLOR   NUMERO NUMERO NUMERO
	KD   NUMERO
	KA   NUMERO
	KS   NUMERO
	KN   NUMERO
	;

objeto:
	  ESFERA esfera
	| CILINDRO cilindro
	| CONO cono
	| POLIGONO poligono
	| LUZ luz
	;

luz:
	COLOR NUMERO NUMERO NUMERO
	POSICION '(' NUMERO NUMERO NUMERO ')'	
	INTENSIDAD NUMERO
	{
		printf("NUEVA LUZ\n\t Color R=%Lf G=%Lf B=%Lf\n\t POS: X=%Lf Y=%Lf Z=%Lf\n\t Ip=%Lf\n",$<ldval>2,$<ldval>3,$<ldval>4,$<ldval>7,$<ldval>8,$<ldval>9,$<ldval>12);
	}
	;

seccion_planos_de_corte:
	 PLANOS_DE_CORTE lista_planos_de_corte
	|
	;

lista_planos_de_corte:
	 plano_de_corte lista_planos_de_corte
	| plano_de_corte
	;

plano_de_corte:
	 NUMERO NUMERO NUMERO NUMERO
	| '[' NUMERO NUMERO NUMERO ']' '('NUMERO NUMERO NUMERO')'
	| '('NUMERO NUMERO NUMERO')' '('NUMERO NUMERO NUMERO')' '('NUMERO NUMERO NUMERO')'
	;


info_esfera:
	POSICION NUMERO NUMERO NUMERO 
	RADIO    NUMERO
	;

esfera:
	info_objeto
	info_esfera
	seccion_planos_de_corte
	seccion_transformaciones
	;

info_cilindro:
	POSICION NUMERO NUMERO NUMERO 
	DIRECCION NUMERO NUMERO NUMERO
	RADIO NUMERO
	;

cilindro:
	info_objeto
	info_cilindro
	seccion_planos_de_corte
	seccion_transformaciones
	;

info_cono:
	POSICION NUMERO NUMERO NUMERO 	
	DIRECCION NUMERO NUMERO NUMERO
	RADIO NUMERO	
	;
	
cono:
	info_objeto
	info_cono
	seccion_planos_de_corte
	seccion_transformaciones
	;

seccion_vertices:
	'(' NUMERO NUMERO ')' '(' NUMERO NUMERO ')' '(' NUMERO NUMERO ')' lista_vertices
	|
	;

lista_vertices:
	vertice lista_vertices
	| vertice
	;

vertice:
	'(' NUMERO NUMERO ')'

seccion_transformaciones:
	TRANSFORMACIONES lista_de_transformaciones
	| 
	;

lista_de_transformaciones:
	  transformacion lista_de_transformaciones
	| transformacion
	;

transformacion:
	  ROTAR NUMERO
	| TRASLADAR NUMERO NUMERO NUMERO
	;

info_poligono:
	seccion_vertices
	;
	
poligono:
	info_objeto
	info_poligono
	seccion_planos_de_corte
	seccion_transformaciones
	;
%%

extern char yytext[];
extern yylineno;
extern FILE *yyin;

//Manejo de errores
yyerror(char *s)
{
	printf("YACC Says: Invalid \"%s\" in line %i.\n.", s, yylineno);
        fflush(stdout);
	yyerrok;
	exit(0);
}

//Carga los datos de un archivo 
int LoadFile (char *filename) {
	yyin = fopen(filename, "r+");
	if (! yyin) {
		printf("El archivo '%s'\n",filename);
		exit(0);
	}
	return yyparse();
}

//Prueba Para Yacc
main(int argc, char *argv[]) {
	LoadFile ((char *)argv[1]);
}
