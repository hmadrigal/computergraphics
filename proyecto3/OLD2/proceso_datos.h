#ifndef DATA_PROCESS
#define DATA_PROCESS

#include "data_structures.h"
#include "proyecto.h"

typedef struct pnl {
	Point3D p1, p2, p3;
	char chr;
	struct pnl *next;
} lista_puntos_planos;

void defaults();
void setTitle(char *t);

void setWindow(double minx, double miny, double maxx, double maxy);
void setBackground(double r, double g, double b);
void setEye(double x, double y, double z);
void setIntensidadAmbiente(double i);
void setFactoresAtenuacion(double f1, double f2, double f3);
void setResolucion(int w, int h);
void setReflexion(int r);
void setTransparencia(int t);
void setAnti(int a);
void agregaTextura(char *f);
lista_puntos_planos * agregaPlano(lista_puntos_planos * pl, Point3D p1, Point3D p2, Point3D p3, int chr);

extern Window ventana;
extern Color background;
extern double ia, c1, c2, c3;
extern char * title;
extern int H_SIZE, V_SIZE;
extern int nivel_reflexion, nivel_transparencia, nivel_anti;
extern Point3D peye;
extern Object *tmp_obj;
extern Point3D pdisk1, pdisk2, pdisk3, ptmp1, ptmp2, ptmp3, ultimo_centro;
extern ObjectList lista_objetos;

extern StringList texturas_names, grises_names;

extern Textura **arreglo_texturas;
extern Mapa_Grises **arreglo_grises;

#endif