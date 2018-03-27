%{
#include <stdio.h>
#include <string.h>
#include "proceso_datos.h"
#include "trans.h"

// Variables externas
extern ObjectList lista_objetos;
extern Window ventana;
extern Color background;
extern double ia, c1, c2, c3;
extern Point3D peye;
extern LightList luces;
extern char *title;
extern int H_SIZE, V_SIZE;
extern Point3D peye;
extern lista_puntos_planos * puntos_planos;

extern double pol_ancho , pol_alto;
extern Point3D pol_p0;

extern char yytext[];
extern yylineno;
extern FILE *yyin;

//Funciones externas
Object *tmp_obj = NULL;
Point3D pdisk1, pdisk2, pdisk3, ptmp1, ptmp2, ptmp3, ultimo_centro, Udisk, Vdisk, P0disk;
PointList lista_puntos;
double d_tmp, acotado;
Disco *dis;
Sphere *sph;
Cilinder *cil;
Cone *con;
Polygon *pol;
Superficie2 *spf;

TexturaObjeto *textu;
%}

%token ESCENA, LUZ, TITULO,CADENA,VENTANA,NUMERO,COLOR_FONDO
%token POSICION_OJO,LUZ_AMBIENTE,FATT, COLOR,POSICION,INTENSIDAD
%token ESFERA,POLIGONO,CILINDRO,CONO,DISCO,FACTOR_K, ANCLA
%token ROTAR_X,ROTAR_Y,ROTAR_Z,TRASLADAR,ESCALAR,KD,KA,KS,KN, KT,CENTRO,RADIO,O1,O2,O3
%token RESOLUCION, SUPERFICIE_2, ROTAR, DIRECCION, TRANSFORMACIONES,PLANOS_DE_CORTE
%token PLANO_TRANSFORMADO_X, PLANO_TRANSFORMADO_Y, PLANO_TRANSFORMADO_Z
%token REFLEXION, TRANSPARECIA, ANTIALIASING, OBJETO, PUNTOS
%token MAPAS_DE_TEXTURAS, MAPAS_DE_GRISES, TEXTURA, GRIS, IMAGEN, TILED, STRETCH
%token ALTURA, BRILLO, TRANSPARENCIA, PHONG, RANGO, GREENWICH, NORTE
%token ACOTADO, SIN_ACOTAR, TIPO

%union {
	char *strval;
	long double ldval;
}

%start inicia_gramatica

%%
inicia_gramatica:
	escena
	mapas
	cuerpos {printf("Termino el Parseo\n");};

escena:
	lista_datos_escena
	| ;

lista_datos_escena:
	dato_escena
	| dato_escena lista_datos_escena;

dato_escena:
	TITULO CADENA {setTitle($<strval>2);}
	| VENTANA '(' NUMERO NUMERO ')' '(' NUMERO NUMERO ')' {setWindow((double) $<ldval>3, (double) $<ldval>4, (double) $<ldval>7, (double) $<ldval>8);}
	| COLOR_FONDO NUMERO NUMERO NUMERO {setBackground((double) $<ldval>2, (double) $<ldval>3, (double)$<ldval>4);}
	| POSICION_OJO '(' NUMERO NUMERO NUMERO ')' {setEye((double) $<ldval>3, (double) $<ldval>4, (double) $<ldval>5);}
	| LUZ_AMBIENTE NUMERO {setIntensidadAmbiente((double) $<ldval>2);}
	| FATT NUMERO NUMERO NUMERO {setFactoresAtenuacion((double) $<ldval>2, (double) $<ldval>3, (double) $<ldval>4);}
	| RESOLUCION NUMERO NUMERO {setResolucion((int) $<ldval>2, (int) $<ldval>3);}
	| REFLEXION NUMERO {setReflexion((int) $<ldval>2);}
	| TRANSPARECIA NUMERO {setTransparencia((int) $<ldval>2);}
	| ANTIALIASING NUMERO {setAnti((int) $<ldval>2);};

mapas:
	lista_mapas
	| ;

lista_mapas:
	textura_o_gris
	| lista_mapas textura_o_gris;

textura_o_gris:
	MAPAS_DE_TEXTURAS lista_texturas {loadTexturesList();}
	| MAPAS_DE_GRISES lista_grises {loadGrisesList();};

lista_texturas:
	textura
	| lista_texturas textura;

textura:
	TEXTURA CADENA {texturas_names = addString(texturas_names, (char *) $<strval>1);};

lista_grises:
	gris
	| lista_grises gris;

gris:
	GRIS CADENA {grises_names = addString(grises_names, (char *) $<strval>1);};

luz:
	LUZ
	COLOR NUMERO NUMERO NUMERO
	POSICION '(' NUMERO NUMERO NUMERO ')'
	INTENSIDAD NUMERO {
		luces = addLight(luces, (double) $<ldval>13,
							(double) $<ldval>3 / 255.0, (double) $<ldval>4 / 255.0, (double) $<ldval>5 / 255,
							(double) $<ldval>8, (double) $<ldval>9, (double) $<ldval>10);
	};

objeto:
	OBJETO {nuevoObjeto();}
	COLOR   NUMERO NUMERO NUMERO
	KD NUMERO
	KA NUMERO
	KS NUMERO
	KN NUMERO
	KT NUMERO
	O1 NUMERO
	O2 NUMERO
	O3 NUMERO {
		tmp_obj->color.r = (double) $<ldval>4 / 255;
		tmp_obj->color.g = (double) $<ldval>5 / 255;
		tmp_obj->color.b =(double)  $<ldval>6 / 255;
		tmp_obj->Kd = (double) $<ldval>8;
		tmp_obj->Ka = (double) $<ldval>10;
		tmp_obj->Ks = (double) $<ldval>12;
		tmp_obj->Kn = (int) $<ldval>14;
		tmp_obj->Kt = (double) $<ldval>16;
		tmp_obj->fO1 = (double) $<ldval>18;
		tmp_obj->fO2 = (double) $<ldval>20;
		tmp_obj->fO3 = (double) $<ldval>22;
	}
	objeto_real
	images
	planos
	transformaciones {
		if(tmp_obj->tipo == DISK) {
			dis->center = ultimo_centro;
			dis->plane = getPlane(pdisk1, pdisk2, pdisk3);
			dis->U = Udisk;
			dis->V = Vdisk;
			dis->P0 = P0disk;
		}
		if(puntos_planos) {
			agrega_planos();
			puntos_planos = freeListaPlanosPuntos(puntos_planos);
		}
		lista_objetos = addObjectDone(lista_objetos, tmp_obj);
		tmp_obj = NULL;
	};

cuerpos:
	lista_elementos
	| ;

lista_elementos:
	elemento
	| lista_elementos elemento;

elemento:
	luz
	| objeto;

disco:
	DISCO
	RADIO NUMERO NUMERO {
		printf("Disco\n");
		dis = (Disco *) calloc(1, sizeof(Disco));
		dis->radius1 = (double) $<ldval>3;
		dis->radius2 = (double) $<ldval>4;
		tmp_obj->object = dis;
		tmp_obj->tipo = DISK;
		ultimo_centro.x = ultimo_centro.y = ultimo_centro.z = 0.0;
		pdisk1.x = pdisk1.y = pdisk1.z = 0.0;
		pdisk2.x = pdisk2.y = 1.0; pdisk2.z = 0.0;
		pdisk3.x = 1.0; pdisk3.y = pdisk3.z = 0.0;
		P0disk.x = ultimo_centro.x - dis->radius2;
		P0disk.y = ultimo_centro.y - dis->radius2;
		P0disk.z = 0.0;
		Udisk.x = 1.0; Udisk.y = Udisk.z = 0.0;
		Vdisk.y = 1.0; Vdisk.x = Vdisk.z = 0.0;
		printf("Disco Rec\n");
	};

esfera:
	ESFERA
	POSICION '(' NUMERO NUMERO NUMERO ')'
	RADIO NUMERO
	GREENWICH '[' NUMERO NUMERO NUMERO ']'
	NORTE '[' NUMERO NUMERO NUMERO ']' {
		printf("Esfera\n");
		sph = (Sphere *) calloc(1, sizeof(Sphere));
		sph->center.x = (double) $<ldval>4;
		sph->center.y =(double) $<ldval>5;
		sph->center.z = (double) $<ldval>6;
		sph->radius =(double) $<ldval>9;
		sph->north.x =(double) $<ldval>12;
		sph->north.y =(double) $<ldval>13;
		sph->north.z =(double) $<ldval>14;
		sph->greenwich.x =(double) $<ldval>9;
		sph->greenwich.y =(double) $<ldval>9;
		sph->greenwich.z =(double) $<ldval>9;
		sph->plane = getPlane(sph->center, sph->north, sph->greenwich);
		tmp_obj->object = sph;
		tmp_obj->tipo = SPHERE;
		ultimo_centro = sph->center;
		sph = NULL;
		printf("Esfera rec\n");
	};

poligono:
	POLIGONO
	ANCLA '('NUMERO NUMERO NUMERO')' {
		printf("Poligono\n");
		ultimo_centro.x = (double) $<ldval>4;
		ultimo_centro.y = (double) $<ldval>5;
		ultimo_centro.z = (double) $<ldval>6;
		lista_puntos.first = lista_puntos.last = NULL;
	}
	PUNTOS vertice vertice lista_vertices {
		if(! (tmp_obj->object = makePolygon(ultimo_centro, lista_puntos))) {
			printf("Poligono Malo. No fue incluido\n");
			free(tmp_obj);
			freePointList(lista_puntos);
			tmp_obj = NULL;
		} else {
			Point3D N = {1.0, 0.0, 0.0};
			((Polygon *) tmp_obj->object)->ancla = ultimo_centro;
			tmp_obj->tipo = POLYGON;
			//Valores de U=[1.0,0.0,0.0] V =[0.0,1.0,.0.0]
			((Polygon *) tmp_obj->object)->U = N;
			N.x = 0.0; N.y = 1.0;
			((Polygon *) tmp_obj->object)->V = N;
			((Polygon *) tmp_obj->object)->ancho = pol_ancho;
			((Polygon *) tmp_obj->object)->alto  = pol_alto;
			((Polygon *) tmp_obj->object)->p0 = pol_p0;
			printf("X0%f Y0%f Z0%f" ,pol_p0.x ,pol_p0.y , pol_p0.z);
			}
		printf("Poligono rec\n");
	};

lista_vertices:
	vertice
	| vertice lista_vertices;

vertice:
	'(' NUMERO NUMERO NUMERO')' {lista_puntos = addPoint(lista_puntos, (double) $<ldval>2, (double) $<ldval>3, (double) $<ldval>4);};

cono:
	CONO
	POSICION NUMERO NUMERO NUMERO
	DIRECCION NUMERO NUMERO NUMERO
	FACTOR_K NUMERO
	GREENWICH '[' NUMERO NUMERO NUMERO ']'
	NORTE '[' NUMERO NUMERO NUMERO ']'
	tipo_acotado {
		printf("Cono\n");
		con = (Cone *) calloc(1, sizeof(Cone));
		con->center.x = (double) $<ldval>3;
		con->center.y = (double) $<ldval>4;
		con->center.z = (double) $<ldval>5;
		d_tmp = sqrt($<ldval>7 * $<ldval>7 + $<ldval>8 * $<ldval>8 + $<ldval>9 * $<ldval>9);
		con->direction.direction.x = (double) $<ldval>7 / d_tmp;
		con->direction.direction.y = (double) $<ldval>8 / d_tmp;
		con->direction.direction.z = (double) $<ldval>9 / d_tmp;
		con->fk = (double) $<ldval>11;
		con->angle = (double) cos(atan(con->fk));
		con->greenwich.x = (double) $<ldval>14;
		con->greenwich.y = (double) $<ldval>15;
		con->greenwich.z = (double) $<ldval>16;
		con->north.x = (double) $<ldval>20;
		con->north.y = (double) $<ldval>21;
		con->north.z = (double) $<ldval>22;
		con->plane = getPlane(con->center, con->north, con->greenwich);
		con->distancia = acotado;
		tmp_obj->tipo = CONE;
		tmp_obj->object = con;
		ultimo_centro = con->center;
		con = NULL;
		printf("Cono Rec\n");
	};

cilindro:
	CILINDRO
	POSICION NUMERO NUMERO NUMERO
	DIRECCION NUMERO NUMERO NUMERO
	RADIO NUMERO
	GREENWICH '[' NUMERO NUMERO NUMERO ']'
	NORTE '[' NUMERO NUMERO NUMERO ']'
	tipo_acotado {
		printf("Cilindro\n");
		cil = (Cilinder *) calloc(1, sizeof(Cilinder));
		cil->center.x = (double) $<ldval>3;
		cil->center.y = (double) $<ldval>4;
		cil->center.z = (double) $<ldval>5;
		d_tmp = sqrt($<ldval>7 * $<ldval>7 + $<ldval>8 * $<ldval>8 + $<ldval>9 * $<ldval>9);
		cil->direction.direction.x = (double) $<ldval>7 / d_tmp;
		cil->direction.direction.y = (double) $<ldval>8 / d_tmp;
		cil->direction.direction.z = (double) $<ldval>9 / d_tmp;
		cil->radius = (double) $<ldval>11;
		cil->greenwich.x = (double) $<ldval>14;
		cil->greenwich.y = (double) $<ldval>15;
		cil->greenwich.z = (double) $<ldval>16;
		cil->north.x = (double) $<ldval>20;
		cil->north.y = (double) $<ldval>21;
		cil->north.z = (double) $<ldval>22;
		cil->plane = getPlane(cil->center, cil->north, cil->greenwich);
		cil->distancia = acotado;
		tmp_obj->tipo = CILINDER;
		tmp_obj->object = cil;
		ultimo_centro = cil->center;
		cil = NULL;
		printf("Cilindro rec\n");
	};

tipo_acotado:
	TIPO ACOTADO NUMERO {acotado = (double) $<ldval>3;}
	| TIPO SIN_ACOTAR {acotado = -1.0;};

superficie:
	SUPERFICIE_2 '[' NUMERO ',' NUMERO ',' NUMERO ',' NUMERO ','
					NUMERO ',' NUMERO ',' NUMERO ',' NUMERO ',' NUMERO ',' NUMERO ']'{
		spf = (Superficie2 *) calloc(1, sizeof(Superficie2));
		spf->A = $<ldval>3;  spf->B = $<ldval>5;  spf->C = $<ldval>7;
		spf->D = $<ldval>9;  spf->E = $<ldval>11; spf->F = $<ldval>13;
		spf->G = $<ldval>15; spf->H = $<ldval>17; spf->J = $<ldval>19;
		spf->K = $<ldval>21;
		tmp_obj->tipo = SUPERFICIE2;
		tmp_obj->object = spf;
		spf = NULL;		// No se cual es el centro en este
	};

objeto_real:
	disco
	| esfera
	| poligono
	| cono
	| cilindro
	| superficie;

transformaciones:
	TRANSFORMACIONES lista_transformaciones
	| ;

lista_transformaciones:
	transformacion
	| lista_transformaciones transformacion;

transformacion:
	  ROTAR_X NUMERO {
	  	if(tmp_obj->tipo == DISK)
			rotar_disco_x((double) $<ldval>2 / RADIAN);
		else tmp_obj = (Object *) rotate_x_object(tmp_obj, (double) $<ldval>2 / RADIAN);}
	| ROTAR_Y NUMERO {
	  	if(tmp_obj->tipo == DISK)
			rotar_disco_y((double) $<ldval>2 / RADIAN);
		else tmp_obj = (Object *) rotate_y_object(tmp_obj, (double) $<ldval>2 / RADIAN);}
	| ROTAR_Z NUMERO {
	  	if(tmp_obj->tipo == DISK)
			rotar_disco_z((double) $<ldval>2 / RADIAN);
		else tmp_obj = (Object *) rotate_z_object(tmp_obj, (double) $<ldval>2 / RADIAN);}
	| TRASLADAR '[' NUMERO NUMERO NUMERO ']' {
	  	if(tmp_obj->tipo == DISK)
			trasladar_disco((double) $<ldval>3, (double) $<ldval>4, (double) $<ldval>5);
		else tmp_obj = translate_object(tmp_obj, (double) $<ldval>3, (double) $<ldval>4, (double) $<ldval>5);}
	| ESCALAR '[' NUMERO NUMERO NUMERO ']'
	| ROTAR_X '[' NUMERO  NUMERO  NUMERO ']'
	  ROTAR_Y '[' NUMERO  NUMERO  NUMERO ']'
	  ROTAR_Z '[' NUMERO  NUMERO  NUMERO ']'
	;

planos:
	PLANOS_DE_CORTE lista_planos
	| ;

lista_planos:
	plano_de_corte
	| lista_planos plano_de_corte;

plano_de_corte:
	PLANO_TRANSFORMADO_X '+' {ubica_plano_x();} '{' tranformaciones_para_plano '}' {
		puntos_planos = agregaPlano(puntos_planos, ptmp1, ptmp2, ptmp3, TRUE);
	}
	| PLANO_TRANSFORMADO_X '-' {ubica_plano_x();} '{' tranformaciones_para_plano '}' {
		puntos_planos = agregaPlano(puntos_planos, ptmp1, ptmp2, ptmp3, FALSE);
	}
	| PLANO_TRANSFORMADO_Y '+' {ubica_plano_y();} '{' tranformaciones_para_plano '}' {
		puntos_planos = agregaPlano(puntos_planos, ptmp1, ptmp2, ptmp3, TRUE);
	}
	| PLANO_TRANSFORMADO_Y '-' {ubica_plano_y();} '{' tranformaciones_para_plano '}' {
		puntos_planos = agregaPlano(puntos_planos, ptmp1, ptmp2, ptmp3, FALSE);
	}
	| PLANO_TRANSFORMADO_Z '+' {ubica_plano_z();} '{' tranformaciones_para_plano '}' {
		puntos_planos = agregaPlano(puntos_planos, ptmp1, ptmp2, ptmp3, TRUE);
	}
	| PLANO_TRANSFORMADO_Z '-' {ubica_plano_z();} '{' tranformaciones_para_plano '}' {
		puntos_planos = agregaPlano(puntos_planos, ptmp1, ptmp2, ptmp3, FALSE);
	};

tranformaciones_para_plano:
	trans_plano
	| ;

trans_plano :
	transforma_plano
	| trans_plano transforma_plano;

transforma_plano :
	ROTAR_X NUMERO {
						ptmp1 = rotate_x(ptmp1, ultimo_centro, (double) $<ldval>2 / RADIAN);
						ptmp2 = rotate_x(ptmp2, ultimo_centro, (double) $<ldval>2 / RADIAN);
						ptmp3 = rotate_x(ptmp3, ultimo_centro, (double) $<ldval>2 / RADIAN);}
	| ROTAR_Y NUMERO {
						ptmp1 = rotate_y(ptmp1, ultimo_centro, (double) $<ldval>2 / RADIAN);
						ptmp2 = rotate_y(ptmp2, ultimo_centro, (double) $<ldval>2 / RADIAN);
						ptmp3 = rotate_y(ptmp3, ultimo_centro, (double) $<ldval>2 / RADIAN);}
	| ROTAR_Z NUMERO {
						ptmp1 = rotate_z(ptmp1, ultimo_centro, (double) $<ldval>2 / RADIAN);
						ptmp2 = rotate_z(ptmp2, ultimo_centro, (double) $<ldval>2 / RADIAN);
						ptmp3 = rotate_z(ptmp3, ultimo_centro, (double) $<ldval>2 / RADIAN);}
	| TRASLADAR '[' NUMERO NUMERO NUMERO ']' {
						ptmp1 = translate(ptmp1, (double) $<ldval>3, (double) $<ldval>4, (double) $<ldval>5);
						ptmp2 = translate(ptmp2, (double) $<ldval>3, (double) $<ldval>4, (double) $<ldval>5);
						ptmp3 = translate(ptmp3, (double) $<ldval>3, (double) $<ldval>4, (double) $<ldval>5);
		};

images:
	image_list
	| ;

image_list:
	image
	| image_list image;
/*
tipo:
	STRETCH
	| TILED NUMERO NUMERO

image:
	TEXTURA IMAGEN NUMERO tipo
	| ALTURA IMAGEN NUMERO RANGO NUMERO NUMERO
	| BRILLO IMAGEN NUMERO
	| TRANSPARENCIA IMAGEN NUMERO
	| PHONG IMAGEN NUMERO;*/

tipo:
	STRETCH	 {textu->tipo=FILL_STRETCH;}
	| TILED NUMERO NUMERO {textu->tipo=FILL_TILED; textu->ancho = $<ldval>2; textu->alto = $<ldval>3;}

image:
	TEXTURA IMAGEN {textu = (TexturaObjeto *) calloc (1,sizeof(TexturaObjeto));} NUMERO tipo
		{
			textu->index = (int) $<ldval>4;
			tmp_obj->textura =  textu;
			textu = NULL;

		}
	| ALTURA IMAGEN NUMERO RANGO NUMERO NUMERO
	| BRILLO IMAGEN NUMERO
	| TRANSPARENCIA IMAGEN NUMERO
	| PHONG IMAGEN NUMERO;
%%

//Manejo de errores
yyerror(char *s)
{
	printf("YACC Says: Invalid \"%s\" in line %i.\n.", yytext, yylineno);
        fflush(stdout);
	yyerrok;
	exit(0);
}

//Inicia el Parseo de un archivo
int LoadUniversoFromFile (char *filename) {
	//arregla_trans();
	yyin = fopen(filename, "r+");
	if (! yyin) {
		printf("El archivo '%s'\n",filename);
		exit(0);
	}
	return yyparse();
}

void agrega_planos() {
	lista_puntos_planos *tmp;
	if(tmp = puntos_planos) {
		while(tmp) {
			if(tmp->chr)
				tmp_obj->plane_list = addPlaneObject(tmp_obj->plane_list, getPlane(tmp->p1, tmp->p2, tmp->p3), TRUE);
			else
				tmp_obj->plane_list = addPlaneObject(tmp_obj->plane_list, getPlane(tmp->p1, tmp->p2, tmp->p3), FALSE);
			tmp = tmp->next;
		}
	}
}
