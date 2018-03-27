%{
#include <stdio.h>
#include <string.h>
#include "proyecto.h"
#include "data_structures.h"

%}

%token ESCENA LUZ RESOLUCION
%token TITULO CADENA VENTANA NUMERO COLOR_FONDO  POSICION_OJO LUZ_AMBIENTE FATT
%token COLOR POSICION INTENSIDAD ESFERA POLIGONO CILINDRO CONO
%token PLANOS_DE_CORTE TRANSFORMACIONES
%token ROTAR_X ROTAR_Y ROTAR_Z TRASLADAR ESCALAR
%token KD KA KS KN SUPERFICIE_2
%token POSICION RADIO DIRECCION TRANSFORMACIONES ALTURA
%token ROTAR TRASLADAR

%union {
	char *strval;
	double ldval;
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
	FATT NUMERO NUMERO NUMERO
	RESOLUCION NUMERO NUMERO {
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
		H_SIZE= (int) $<ldval>30;
		V_SIZE= (int) $<ldval>31;
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
	| LUZ luz
	| SUPERFICIE_2 superficie_2
	;

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

info_superficie_2:
	'['
		NUMERO ','NUMERO ','NUMERO ','NUMERO ','
		NUMERO ','NUMERO ','NUMERO ','NUMERO ','
		NUMERO ','NUMERO
	']'
	{
		spf = (Superficie2 *) calloc(1, sizeof(Superficie2));
		//Guarda Valores
		spf->A = $<ldval>2;  spf->B = $<ldval>4;  spf->C = $<ldval>6;
		spf->D = $<ldval>8;  spf->E = $<ldval>10; spf->F = $<ldval>12;
		spf->G = $<ldval>14; spf->H = $<ldval>16; spf->J = $<ldval>18;
		spf->K = $<ldval>20;
		//Inserta el Objeto
		tmp->tipo = SUPERFICIE2;
		tmp->object = spf;
		spf = NULL;
	}
	;

superficie_2:
	info_objeto
	info_superficie_2
	seccion_planos_de_corte
	seccion_transformaciones
	{lista_objetos = addObjectDone(lista_objetos, tmp);}
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
		con->fk = $<ldval>10;

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
	TRASLADAR '[' NUMERO ',' NUMERO ',' NUMERO ']' {trasladar($<ldval>3,$<ldval>5,$<ldval>7);}
	| ESCALAR '[' NUMERO ',' NUMERO ',' NUMERO ']' {escalar ($<ldval>3,$<ldval>5,$<ldval>7); }
	| ROTAR_X '[' NUMERO ',' NUMERO ',' NUMERO ']'
	  ROTAR_Y '[' NUMERO ',' NUMERO ',' NUMERO ']'
	  ROTAR_Z '[' NUMERO ',' NUMERO ',' NUMERO ']'
	  {rotar($<ldval>3,$<ldval>5,$<ldval>7,
	  	 $<ldval>11,$<ldval>13,$<ldval>15,
	  	 $<ldval>19,$<ldval>21,$<ldval>23);}
	| ROTAR_X NUMERO
	| ROTAR_Y NUMERO
	| ROTAR_Z NUMERO
	;

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
extern int H_SIZE;
extern int V_SIZE;

//Funciones externas

// Para la insersion de los datos
Object *tmp;
Sphere *sph;
Cilinder *cil;
Cone *con;
Polygon *pol;
PointList pl;
Superficie2 *spf;

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

/*---------------------------------------*/
trasladar (double tx, double ty, double tz) {
	switch (tmp->tipo) {
		case SUPERFICIE2:
		{
			Superficie2 t; //Almacena Temporalmente los valores {A..K]
			spf = (Superficie2 *) tmp->object;
			t.A = spf->A; t.B = spf->B; t.C = spf->C; t.D = spf->D; t.E = spf->E;
			t.F = spf->F; t.G = spf->G; t.H = spf->H; t.J = spf->J; t.K = spf->K;

			spf->G = t.G - t.A * tx - t.D * ty - t.F * tz;
			spf->H = t.H - t.D * tx - t.B * ty - t.E * tz;
			spf->J = t.J - t.F * tx - t.E * ty - t.C * tz;
			spf->K = t.K -
				((double) 2.0 * ( t.G * tx + t.H * ty + t.J * tz))+
				tx   * ( t.A * tx + t.D * ty + t.F * tz) +
				ty   * ( t.D * tx + t.B * ty + t.E * tz) +
				tz   * ( t.F * tx + t.E * ty + t.C * tz) ;
		}
		break;
	}
}

escalar (double sx, double sy, double sz) {
	switch (tmp->tipo) {
		case SUPERFICIE2:
			spf = (Superficie2 *) tmp->object;
			spf->A =  spf->A / (sx * sx);
			spf->B =  spf->B / (sy * sy);
			spf->C =  spf->C / (sz * sz);
			spf->D =  spf->D / (sx * sy);
			spf->E =  spf->E / (sy * sz);
			spf->F =  spf->F / (sx * sz);
			spf->G =  spf->G / sx;
			spf->H =  spf->H / sy;
			spf->J =  spf->J / sz;
		break;
	}
}

rotar (double xu,double yu,double zu, double xv,double yv,double zv, double xn,double yn,double zn) {
	switch (tmp->tipo) {
		case SUPERFICIE2:
		{
			Superficie2 t; //Almacena Temporalmente los valores {A..K]
			spf = (Superficie2 *) tmp->object;
			t.A = spf->A; t.B = spf->B; t.C = spf->C; t.D = spf->D; t.E = spf->E;
			t.F = spf->F; t.G = spf->G; t.H = spf->H; t.J = spf->J; t.K = spf->K;

			spf->A= xu * (t.A * xu + t.D * xv + t.F * xn) +
				xv * (t.D * xu + t.B * xv + t.E * xn) +
				xn * (t.F * xu + t.E * xv + t.C * xn);
			spf->B= yu * (t.A * yu + t.D * yv + t.F * yn) +
				yv * (t.D * yu + t.B * yv + t.E * yn) +
				yn * (t.F * yu + t.E * yv + t.C * yn);
			spf->C= zu * (t.A * zu + t.D * zv + t.F * zn) +
				zv * (t.D * zu + t.B * zv + t.E * zn) +
				zn * (t.F * zu + t.E * zv + t.C * zn);
			spf->D= xu * (t.A * yu + t.D * yv + t.F * yn) +
				xv * (t.D * yu + t.B * yv + t.E * yn) +
				xn * (t.F * yu + t.E * yv + t.C * yn);
			spf->E= yu * (t.A * zu + t.D * zv + t.F * zn) + 
				yv * (t.D * zu + t.B * zv + t.E * zn) + 
				yn * (t.F * zu + t.E * zv + t.C * zn);
			spf->F= zu * (t.A * xu + t.D * xv + t.F * xn) +
				zv * (t.D * xu + t.B * xv + t.E * xn) +
				zn * (t.F * xu + t.E * xv + t.C * xn);
			spf->G= t.G * xu + t.H * xv + t.J * xn;
			spf->H= t.G * yu + t.H * yv + t.J * yn;
			spf->J= t.G * zu + t.H * zv + t.J * zn;
		}
		break;
	}
}
