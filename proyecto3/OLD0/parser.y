%{
#include <stdio.h>
#include <string.h>
#include "proyecto.h"
#include "data_structures.h"
#include "trans.h"
%}

%token ESCENA LUZ
%token TITULO CADENA VENTANA NUMERO COLOR_FONDO  POSICION_OJO LUZ_AMBIENTE FATT ANCLA
%token COLOR POSICION INTENSIDAD ESFERA POLIGONO CILINDRO CONO DISCO SUPERFICIE_2
%token PLANOS_DE_CORTE TRANSFORMACIONES PLANO_ECUACION PLANO_PUNTOS PLANO_PUNTO_NORMAL PLANO_TRANSFORMADO
%token ROTAR_X ROTAR_Y ROTAR_Z TRASLADAR ESCALAR FACTOR_K RESOLUCION
%token KD KA KS KN
%token POSICION RADIO DIRECCION TRANSFORMACIONES
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
	FATT NUMERO NUMERO NUMERO
	RESOLUCION NUMERO NUMERO {
		ventana.pmin.x =$<ldval>6;
		ventana.pmin.y =$<ldval>7;
		ventana.pmin.z =0.0;
		ventana.pmax.x =$<ldval>10;
		ventana.pmax.y =$<ldval>11;
		ventana.pmax.z =0.0;
		background.r = $<ldval>14 / 255;
		background.g = $<ldval>15 / 255;
		background.b = $<ldval>16 / 255;
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
		luces = addLight(luces, $<ldval>12, $<ldval>2 / 255.0, $<ldval>3 / 255.0, $<ldval>4 / 255, $<ldval>7, $<ldval>8, $<ldval>9);
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
		tmp->color.r = $<ldval>2 / 255;
		tmp->color.g = $<ldval>3 / 255;
		tmp->color.b = $<ldval>4 / 255;
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
	| POLIGONO poligono {	if(! (tmp->object = makePolygon(pol, pol->pl)))
							printf("Poligono Malo. No fue incluido\n");
						else {
								lista_objetos = addObjectDone(lista_objetos, tmp); // Agregamos el poligono
							}
						}
	| LUZ luz 
	| DISCO disco
	| SUPERFICIE_2 superficie_2
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
	PLANO_ECUACION '+' '[' NUMERO NUMERO NUMERO NUMERO ']' {
		tmp->plane_list = addPlane(tmp->plane_list, $<ldval>4, $<ldval>5, $<ldval>6, $<ldval>7, TRUE); }
	| PLANO_ECUACION '-' '[' NUMERO NUMERO NUMERO NUMERO ']' 
		{ tmp->plane_list = addPlane(tmp->plane_list, $<ldval>4, $<ldval>5, $<ldval>6, $<ldval>7, FALSE);}
	| PLANO_PUNTOS '+' '(' NUMERO NUMERO NUMERO ')' '(' NUMERO NUMERO NUMERO ')' '(' NUMERO NUMERO NUMERO ')' {
		ptmp1.x = $<ldval>4;
		ptmp1.y = $<ldval>5;
		ptmp1.z = $<ldval>6;
		ptmp2.x = $<ldval>9;
		ptmp2.y = $<ldval>10;
		ptmp2.z = $<ldval>11;
		ptmp3.x = $<ldval>14;
		ptmp3.y = $<ldval>15;
		ptmp3.z = $<ldval>16;
		tmp->plane_list = addPlaneObject(tmp->plane_list, getPlane(ptmp1, ptmp2, ptmp3), TRUE);
		}
	| PLANO_PUNTOS '-' '('NUMERO NUMERO NUMERO')' '('NUMERO NUMERO NUMERO')' '('NUMERO NUMERO NUMERO')'{
		ptmp1.x = $<ldval>4;
		ptmp1.y = $<ldval>5;
		ptmp1.z = $<ldval>6;
		ptmp2.x = $<ldval>9;
		ptmp2.y = $<ldval>10;
		ptmp2.z = $<ldval>11;
		ptmp3.x = $<ldval>14;
		ptmp3.y = $<ldval>15;
		ptmp3.z = $<ldval>16;
		tmp->plane_list = addPlaneObject(tmp->plane_list, getPlane(ptmp1, ptmp2, ptmp3), FALSE);
		}
	| PLANO_PUNTO_NORMAL '+' '(' NUMERO NUMERO NUMERO ')' '[' NUMERO NUMERO NUMERO ']'{
		double L, D;
		D = -($<ldval>4 * $<ldval>9 + $<ldval>5 * $<ldval>10 + $<ldval>6 * $<ldval>11);
		L = sqrt($<ldval>9 * $<ldval>9 + $<ldval>10 * $<ldval>10 + $<ldval>11 * $<ldval>11);
		tmp->plane_list = addPlane(tmp->plane_list, $<ldval>9/L, $<ldval>10/L, $<ldval>11/L, D/L, TRUE);
		}
	| PLANO_PUNTO_NORMAL '-' '(' NUMERO NUMERO NUMERO ')' '[' NUMERO NUMERO NUMERO ']'{
		double L, D;
		D = -($<ldval>4 * $<ldval>9 + $<ldval>5 * $<ldval>10 + $<ldval>6 * $<ldval>11);
		L = sqrt($<ldval>9 * $<ldval>9 + $<ldval>10 * $<ldval>10 + $<ldval>11 * $<ldval>11);
		tmp->plane_list = addPlane(tmp->plane_list, $<ldval>9/L, $<ldval>10/L, $<ldval>11/L, D/L, FALSE);
		}
	| PLANO_TRANSFORMADO {arregla_trans();} '+' '{' trans_plano '}' {
		tmp->plane_list = addPlaneObject(tmp->plane_list, getPlane(p_trans1, p_trans2, p_trans3), TRUE);
	}
	| PLANO_TRANSFORMADO {arregla_trans();} '-' '{' trans_plano '}' {
		tmp->plane_list = addPlaneObject(tmp->plane_list, getPlane(p_trans1, p_trans2, p_trans3), FALSE);
	}
	;

trans_plano :
	transforma_plano
	| trans_plano transforma_plano
	;

transforma_plano :
	ROTAR_X NUMERO {
						p_trans1 = rotate_x(p_trans1, ultimo_centro, $<ldval>2 / RADIAN);
						p_trans2 = rotate_x(p_trans2, ultimo_centro, $<ldval>2 / RADIAN);
						p_trans3 = rotate_x(p_trans3, ultimo_centro, $<ldval>2 / RADIAN);}
	| ROTAR_Y NUMERO {
						p_trans1 = rotate_y(p_trans1, ultimo_centro, $<ldval>2 / RADIAN);
						p_trans2 = rotate_y(p_trans2, ultimo_centro, $<ldval>2 / RADIAN);
						p_trans3 = rotate_y(p_trans3, ultimo_centro, $<ldval>2 / RADIAN);}
	| ROTAR_Z NUMERO {
						p_trans1 = rotate_z(p_trans1, ultimo_centro, $<ldval>2 / RADIAN);
						p_trans2 = rotate_z(p_trans2, ultimo_centro, $<ldval>2 / RADIAN);
						p_trans3 = rotate_z(p_trans3, ultimo_centro, $<ldval>2 / RADIAN);}
	| TRASLADAR '[' NUMERO NUMERO NUMERO ']' {
						p_trans1 = translate(p_trans1, $<ldval>3, $<ldval>4, $<ldval>5);
						p_trans2 = translate(p_trans2, $<ldval>3, $<ldval>4, $<ldval>5);
						p_trans3 = translate(p_trans3, $<ldval>3, $<ldval>4, $<ldval>5);
						}
	| ;

info_esfera:
	POSICION NUMERO NUMERO NUMERO
	RADIO    NUMERO
	{
		sph = (Sphere *) calloc(1, sizeof(Sphere));
		sph->center.x = $<ldval>2;
		sph->center.y = $<ldval>3;
		sph->center.z = $<ldval>4;
		ultimo_centro = sph->center;
		sph->radius = $<ldval>6;
		tmp->tipo = SPHERE;
		tmp->object = sph;
		sph = NULL;
	}
	;

esfera:
	info_objeto
	info_esfera
	seccion_planos_de_corte
	seccion_transformaciones	{lista_objetos = addObjectDone(lista_objetos, tmp);} 
	;

info_cilindro:
	POSICION NUMERO NUMERO NUMERO
	DIRECCION NUMERO NUMERO NUMERO
	RADIO NUMERO {
		cil = (Cilinder *) calloc(1, sizeof(Cilinder));
		cil->center.x = $<ldval>2;
		cil->center.y = $<ldval>3;
		cil->center.z = $<ldval>4;
		ultimo_centro = cil->center;
		d_tmp = sqrt($<ldval>6 * $<ldval>6 + $<ldval>7 * $<ldval>7 + $<ldval>8 * $<ldval>8);
		cil->direction.direction.x = $<ldval>6 / d_tmp;
		cil->direction.direction.y = $<ldval>7 / d_tmp;
		cil->direction.direction.z = $<ldval>8 / d_tmp;
		cil->radius = $<ldval>10;
		tmp->tipo = CILINDER;
		tmp->object = cil;
		cil = NULL; };

cilindro:
	info_objeto
	info_cilindro
	seccion_planos_de_corte
	seccion_transformaciones	{lista_objetos = addObjectDone(lista_objetos, tmp);}
	;

info_cono:
	POSICION NUMERO NUMERO NUMERO
	DIRECCION NUMERO NUMERO NUMERO
	FACTOR_K NUMERO {
		con = (Cone *) calloc(1, sizeof(Cone));
		con->center.x = $<ldval>2;
		con->center.y = $<ldval>3;
		con->center.z = $<ldval>4;
		ultimo_centro = con->center;
		
		d_tmp = sqrt($<ldval>6 * $<ldval>6 + $<ldval>7 * $<ldval>7 + $<ldval>8 * $<ldval>8);
		con->direction.direction.x = $<ldval>6 / d_tmp;
		con->direction.direction.y = $<ldval>7 / d_tmp;
		con->direction.direction.z = $<ldval>8 / d_tmp;
		
		con->fk = $<ldval>10;
		con->angle = atan(con->fk);
		tmp->tipo = CONE;
		tmp->object = con;
		con = NULL; }
	;

cono:
	info_objeto
	info_cono
	seccion_planos_de_corte
	seccion_transformaciones {lista_objetos = addObjectDone(lista_objetos, tmp);}	
	;
	
info_disco:
	RADIO NUMERO NUMERO {
		dis = (Disco *) calloc(1, sizeof(Disco));
		dis->radius1 = $<ldval>2;
		dis->radius2 = $<ldval>3;
		tmp->tipo = DISK;
		tmp->object = dis;
		ultimo_centro.x = ultimo_centro.y = ultimo_centro.z = 0.0;
		arregla_trans();
		}
	tranformaciones_disco {
		dis->center = ultimo_centro;
		dis->plane = getPlane(p_trans1, p_trans2, p_trans3);
	}
	;


	
tranformaciones_disco:
	trans_disco
	| tranformaciones_disco trans_disco
	;
	
trans_disco :
	ROTAR_X NUMERO {
						p_trans1 = rotate_x(p_trans1, ultimo_centro, $<ldval>2 / RADIAN);
						p_trans2 = rotate_x(p_trans2, ultimo_centro, $<ldval>2 / RADIAN);
						p_trans3 = rotate_x(p_trans3, ultimo_centro, $<ldval>2 / RADIAN);}
	| ROTAR_Y NUMERO {
						p_trans1 = rotate_y(p_trans1, ultimo_centro, $<ldval>2 / RADIAN);
						p_trans2 = rotate_y(p_trans2, ultimo_centro, $<ldval>2 / RADIAN);
						p_trans3 = rotate_y(p_trans3, ultimo_centro, $<ldval>2 / RADIAN);}
	| ROTAR_Z NUMERO {
						p_trans1 = rotate_z(p_trans1, ultimo_centro, $<ldval>2 / RADIAN);
						p_trans2 = rotate_z(p_trans2, ultimo_centro, $<ldval>2 / RADIAN);
						p_trans3 = rotate_z(p_trans3, ultimo_centro, $<ldval>2 / RADIAN);}
	| TRASLADAR '[' NUMERO NUMERO NUMERO ']' {
						ultimo_centro = translate(ultimo_centro, $<ldval>3, $<ldval>4, $<ldval>5);
						p_trans1 = translate(p_trans1, $<ldval>3, $<ldval>4, $<ldval>5);
						p_trans2 = translate(p_trans2, $<ldval>3, $<ldval>4, $<ldval>5);
						p_trans3 = translate(p_trans3, $<ldval>3, $<ldval>4, $<ldval>5);
		}
	| 
	;

disco:
	info_objeto
	info_disco
	seccion_planos_de_corte;
	seccion_transformaciones {lista_objetos = addObjectDone(lista_objetos, tmp);}
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

lista_vertices:
	vertice
	| vertice lista_vertices
	;

vertice:
	'(' NUMERO NUMERO NUMERO')' {pol->pl = addPoint(pol->pl, (double) $<ldval>2, (double) $<ldval>3, (double) $<ldval>4);}
	;

seccion_transformaciones:
	TRANSFORMACIONES lista_de_transformaciones
	|
	;

lista_de_transformaciones:
	  transformacion lista_de_transformaciones
	| transformacion
	;

transformacion:
	  ROTAR_X NUMERO {tmp = (Object *) rotate_x_object(tmp, (double) $<ldval>2 / RADIAN);}
	| ROTAR_Y NUMERO {tmp = (Object *) rotate_y_object(tmp, (double) $<ldval>2 / RADIAN);}
	| ROTAR_Z NUMERO {tmp = (Object *) rotate_z_object(tmp, (double) $<ldval>2 / RADIAN);}
	| TRASLADAR '[' NUMERO NUMERO NUMERO ']' {tmp = translate_object(tmp, (double) $<ldval>3, (double) $<ldval>4, (double) $<ldval>5);}
	| ESCALAR '[' NUMERO NUMERO NUMERO ']'   {escalar ($<ldval>3,$<ldval>4,$<ldval>5); };
	;

info_poligono:
	ANCLA '('NUMERO NUMERO NUMERO')' {	pol = (Polygon *) calloc(1, sizeof(Polygon));
		pol->ancla.x = (double) $<ldval>3;
		pol->ancla.y = (double) $<ldval>4;
		pol->ancla.z = (double) $<ldval>5;
		tmp->object = pol;}
	vertice vertice lista_vertices
	;

poligono:
	info_objeto {tmp->tipo = POLYGON;}
	info_poligono
	seccion_planos_de_corte
	seccion_transformaciones
	;
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
extern int H_SIZE, V_SIZE;
extern Point3D peye;

//Funciones externas

// Para la insersion de los datos
Object *tmp;
Sphere *sph;
Cilinder *cil;
Cone *con;
Polygon *pol;
Disco *dis;
Point3D ptmp1, ptmp2, ptmp3;
double d_tmp;
Superficie2 *spf;
Point3D p_trans1 = {0.0, 0.0, 0.0}, p_trans2 = {0.0, 1.0, 0.0}, p_trans3 = {1.0, 1.0, 0.0}, ultimo_centro;

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
	arregla_trans();
	if (! yyin) {
		printf("El archivo '%s'\n",filename);
		exit(0);
	}
	return yyparse();
}

int arregla_trans() {
		p_trans1.x = p_trans1.y = p_trans1.z = 0.0;
		p_trans2.x = p_trans2.z = 0.0; p_trans2.y = 1.0;
		p_trans3.x = p_trans3.y = 1.0; p_trans3.z = 0.0;
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
