%{
	#include <stdio.h>
	#include <string.h>
	#include <math.h>
	#include "firma.h"
	
	extern tlinea nodo;
	int cntpunto=0;
%}

%token BACKGROUND FOREGROUND RESOLUCION VENTANA INCREMENTO 
%token INICIAN_PUNTOS FIN_PUNTOS NUMERO

%union {
	char *strval;
	double dblval;
}

%start regla_inicial_cfg

%%
regla_inicial_cfg :
	FOREGROUND NUMERO NUMERO NUMERO {set_forecolor ($<dblval>2,$<dblval>3,$<dblval>4);}
	BACKGROUND NUMERO NUMERO NUMERO {set_backcolor ($<dblval>7,$<dblval>8,$<dblval>9);}
	RESOLUCION NUMERO NUMERO {set_resolution($<dblval>12,$<dblval>13);}
	VENTANA NUMERO NUMERO NUMERO NUMERO {set_universal_window($<dblval>16,$<dblval>17,$<dblval>18,$<dblval>19);}
	INCREMENTO NUMERO {set_incremento($<dblval>22);}
	seccion_puntos
	;

seccion_puntos :
	INICIAN_PUNTOS 
		lista_puntos
	FIN_PUNTOS

punto:
	'(' NUMERO ',' NUMERO ')' {guardar_punto($<dblval>2, $<dblval>4);}
	;

lista_puntos:
	punto punto punto punto {Insertar();} lista_puntos 
	| punto punto punto punto  {Insertar();}
	;
%%

extern char yytext[];
extern yylineno;
extern FILE *yyin;

extern int H_SIZE;
extern int V_SIZE;
extern tpunto wmin;
extern tpunto wmax;
extern tcolor fg;
extern tcolor bg;

extern double incval;
extern double inccnt;

extern tlista lineas;

// ACCIONES SEMANTICAS
Insertar () {
	lineas.first = (tlinea *) inserta_nodo (lineas , nodo);
}

guardar_punto(double x, double y) {
	
	nodo.p[cntpunto].x = x;
	nodo.p[cntpunto].y = y;	
	#ifdef DEBUG
	printf("[%i] (%f,%f)\n",cntpunto,x,y);
	#endif
	cntpunto++;
	(cntpunto==4) ? cntpunto=0 : 0;
	
}
set_resolution(double H, double V) {
	H_SIZE = (int)H;
	V_SIZE = (int)V;
	#ifdef DEBUG
	printf("Resolucion H=%i V=%i\n",H_SIZE,V_SIZE);
	#endif
}

set_universal_window(double xmin, double ymin,double xmax, double ymax) {
	wmin.x = xmin;
	wmin.y = ymin;
	wmax.x = xmax;
	wmax.y = ymax;
	#ifdef DEBUG
	printf("Ventana Universal [%f,%f][%f,%f]\n",xmin,ymin,xmax,ymax);
	#endif
}

set_forecolor (double r, double g, double b) {
	fg.r=r;
	fg.g=g;
	fg.b=b;
	#ifdef DEBUG
	printf("Forecolor (%f,%f,%f)\n",r,g,b);
	#endif
}

set_backcolor (double r, double g, double b) {
	bg.r=r;
	bg.g=g;
	bg.b=b;
	#ifdef DEBUG
	printf("Backcolor (%f,%f,%f)\n",r,g,b);
	#endif
}

set_incremento(double pinc) {
	incval = (double) 1 / pinc;
	inccnt = pinc;
	#ifdef DEBUG
	printf("Incremento %f, Cantidad %f\n",incval,inccnt);
	#endif
}

int loadfile(char *s) {
	if (!(yyin = fopen(s, "r+"))) {
		printf("I Say:I can\'t open the file \"%s\".\n",s);
		exit(1);
	}
	
	return yyparse();
}


//Manejo de errores
yyerror(char *s)
{
	printf("YACC Says: Invalid \"%s\" in line %i.\n.", s, yylineno);
        fflush(stdout);
	yyerrok;
	exit(0);
}

/*
//PROBANDO YACC
int main (int argc, char *argv[]) {
	
	if (argc==2) {
		return loadfile((char *)argv[1]);
	} else {
		printf("Usage:\n\tfile <filename>\n");
		return 1;
	}
	
}
*/