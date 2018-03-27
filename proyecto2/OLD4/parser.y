%{
#include <stdio.h>
#include <string.h>
#include "proyecto.h"
#include "data_structures.h"
%}

%token ESCENA LUZ
%token TITULO CADENA VENTANA NUMERO COLOR_FONDO  POSICION_OJO LUZ_AMBIENTE FATT
%token COLOR POSICION INTENSIDAD ESFERA POLIGONO CILINDRO CONO
%token PLANOS_DE_CORTE TRANSFORMACIONES
%token ROTAR_X ROTAR_Y ROTAR_Z TRASLADAR ESCALAR
%token KD KA KS KN
%token POSICION RADIO DIRECCION TRANSFORMACIONES ALTURA 
%token ROTAR TRASLADAR

%union {
	char *strval;
	long double ldval;
}

%start inicia_gramatica

%%
inicia_gramatica:
	ESCENA seccion_escena
	seccion_objetos
	;

seccion_escena:
	TITULO CADENA {title = strdup($<strval>2);}
	VENTANA '('NUMERO NUMERO')' '('NUMERO NUMERO')'
	COLOR_FONDO NUMERO NUMERO NUMERO
	POSICION_OJO '('NUMERO NUMERO NUMERO')'
	LUZ_AMBIENTE NUMERO
	FATT NUMERO NUMERO NUMERO {
		ventana.pmin.x =$<ldval>6;
		ventana.pmin.y =$<ldval>7;
		ventana.pmin.z =0.0;
		ventana.pmax.x =$<ldval>10;
		ventana.pmax.y =$<ldval>11;
		ventana.pmax.z =0.0;
		background.r = $<ldval>14;
		background.g = $<ldval>15;
		background.b = $<ldval>16;
		peye.x = $<ldval>19;
		peye.y = $<ldval>20;
		peye.z = $<ldval>21;
		ia = $<ldval>24;
		c1 = $<ldval>26;
		c2 = $<ldval>27;
		c3 = $<ldval>28;
	}
	;

luz:
	COLOR NUMERO NUMERO NUMERO
	POSICION '(' NUMERO NUMERO NUMERO ')'
	INTENSIDAD NUMERO
	{
		luces = addLight(luces, $<ldval>12, $<ldval>2, $<ldval>3, $<ldval>4, $<ldval>7, $<ldval>8, $<ldval>9);
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
	{
		tmp = (Object *) calloc(1, sizeof(Object));
		tmp->color.r = $<ldval>2;
		tmp->color.g = $<ldval>3;
		tmp->color.b = $<ldval>4;
		tmp->Kd = $<ldval>6;
		tmp->Ka = $<ldval>8;
		tmp->Ks = $<ldval>10;
		tmp->Kn = $<ldval>12;
	}
	;

objeto:
	  ESFERA esfera
	| CILINDRO cilindro
	| CONO cono
	| POLIGONO poligono {	if(! (tmp->object = makePolygon(pl)))
							printf("Poligono Malo\n");
						else
							lista_objetos = addObjectDone(lista_objetos, tmp); // Agregamos el poligono
						}
	| LUZ luz;

seccion_planos_de_corte:
	 PLANOS_DE_CORTE lista_planos_de_corte
	|
	;

lista_planos_de_corte:
	 plano_de_corte lista_planos_de_corte
	| plano_de_corte;

plano_de_corte:
	 NUMERO NUMERO NUMERO NUMERO {printf ("\tPLANO_CORTE: A=%Lf B=%Lf C=%Lf D=%Lf\n",$<ldval>1,$<ldval>2,$<ldval>3,$<ldval>4);}
	| '[' NUMERO NUMERO NUMERO ']' '('NUMERO NUMERO NUMERO')'
	| '('NUMERO NUMERO NUMERO')' '('NUMERO NUMERO NUMERO')' '('NUMERO NUMERO NUMERO')';

info_esfera:
	POSICION NUMERO NUMERO NUMERO
	RADIO    NUMERO
	{
		sph = (Sphere *) calloc(1, sizeof(Sphere));
		sph->center.x = $<ldval>2;
		sph->center.y = $<ldval>3;
		sph->center.z = $<ldval>4;
		sph->radius = $<ldval>6;
		tmp->tipo = SPHERE;
		tmp->object = sph;
		sph = NULL;
	};

esfera:
	info_objeto
	info_esfera
	seccion_planos_de_corte
	seccion_transformaciones	{lista_objetos = addObjectDone(lista_objetos, tmp);} // Agregamos la esfera a la lista
	;

info_cilindro:
	POSICION NUMERO NUMERO NUMERO
	DIRECCION NUMERO NUMERO NUMERO
	RADIO NUMERO {
		cil = (Cilinder *) calloc(1, sizeof(Cilinder));
		cil->center.x = $<ldval>2;
		cil->center.y = $<ldval>3;
		cil->center.z = $<ldval>4;
		// Primer direction... El vector.
		// Segundo direction... Punto dentro la estructura del vector.
		cil->direction.direction.x = $<ldval>6;
		cil->direction.direction.y = $<ldval>7;
		cil->direction.direction.z = $<ldval>8;
		cil->direction = makeVector(cil->center, cil->direction.direction);
		cil->radius = $<ldval>10;
		tmp->tipo = CILINDER;
		tmp->object = cil;
		cil = NULL; };

cilindro:
	info_objeto
	info_cilindro
	seccion_planos_de_corte
	seccion_transformaciones	{lista_objetos = addObjectDone(lista_objetos, tmp);}	// Agregamos el cilindro a la lista;

info_cono:
	POSICION NUMERO NUMERO NUMERO
	DIRECCION NUMERO NUMERO NUMERO
	RADIO NUMERO{
		con = (Cone *) calloc(1, sizeof(Cone));
		con->center.x = $<ldval>2;
		con->center.y = $<ldval>3;
		con->center.z = $<ldval>4;
		// Primer direction... El vector.
		// Segundo direction... Punto dentro la estructura del vector.
		con->direction.direction.x = $<ldval>6;
		con->direction.direction.y = $<ldval>7;
		con->direction.direction.z = $<ldval>8;
		con->direction = makeVector(con->center, con->direction.direction);
		con->radius = $<ldval>10;
	
		tmp->tipo = CONE;
		tmp->object = con;
		con = NULL; };

cono:
	info_objeto
	info_cono
	seccion_planos_de_corte
	seccion_transformaciones {lista_objetos = addObjectDone(lista_objetos, tmp);}	// Agregamos el cono a la lista;

lista_vertices:
	vertice
	| vertice lista_vertices;

vertice:
	'(' NUMERO NUMERO NUMERO')' {pl = addPoint(pl, (double) $<ldval>2, (double) $<ldval>3, (double) $<ldval>4);}

seccion_transformaciones:
	TRANSFORMACIONES lista_de_transformaciones
	|
	;

lista_de_transformaciones:
	  transformacion lista_de_transformaciones
	| transformacion;

transformacion:
	  ROTAR NUMERO
	| TRASLADAR NUMERO NUMERO NUMERO;

info_poligono:
	vertice vertice lista_vertices;

poligono:
	info_objeto {pl.first = pl.last = NULL; tmp->tipo = POLYGON;}
	info_poligono
	seccion_planos_de_corte
	seccion_transformaciones;
%%

// Variables externas
extern char yytext[];
extern yylineno;
extern FILE *yyin;
extern ObjectList lista_objetos;
extern Window ventana;
extern Color background;
extern double ia, c1, c2, c3;
extern Point3D peye;
extern LightList luces;
extern char *title;

//Funciones externas

// Para la insersion de los datos
Object *tmp;
Sphere *sph;
Cilinder *cil;
Cone *con;
Polygon *pol;
PointList pl;

//Manejo de errores
yyerror(char *s)
{
	printf("YACC Says: Invalid \"%s\" in line %i.\n.", s, yylineno);
        fflush(stdout);
	yyerrok;
	exit(0);
}

//Inicia el Parseo de un archivo
int LoadUniversoFromFile (char *filename) {
	yyin = fopen(filename, "r+");
	if (! yyin) {
		printf("El archivo '%s'\n",filename);
		exit(0);
	}
	return yyparse();
}
