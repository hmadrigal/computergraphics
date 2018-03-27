
#include <stdlib.h>
#include <stdio.h>
#include "proceso_datos.h"

lista_puntos_planos *puntos_planos = NULL;

void defaults() {
	title = "Raytracing: Computer Graphics";
	background.r = background.g = background.b = 0.0;
	H_SIZE = 640;
	V_SIZE = 480;
	ia = 0.5;
	c1 = 1.0; c2 = 0.005; c3 = 0.00005;
	peye.x = peye.y = 0.0;
	peye.z = -1000.0;
	nivel_reflexion = 0; nivel_transparencia = 0; nivel_anti = 0;
	ventana.pmin.x =-50.0; ventana.pmin.y =-50.0; ventana.pmin.z =0.0;
	ventana.pmax.x =50.0; ventana.pmax.y =50.0; ventana.pmax.z =0.0;
	texturas_names.first = texturas_names.last = grises_names.first = grises_names.last = NULL;
	lista_objetos.first = lista_objetos.last = NULL;
}

void setTitle(char *t) {
	title = (char *) strdup(t);
}

void setWindow(double minx, double miny, double maxx, double maxy) {
	ventana.pmin.x = minx; ventana.pmin.y = miny;
	ventana.pmax.x = maxx; ventana.pmax.y = maxy;
}

void setBackground(double r, double g, double b) {
	background.r = (double) r / 255;
	background.g = (double) g / 255;
	background.b = (double) b / 255;
}

void setEye(double x, double y, double z) {
	peye.x = x; peye.y = y; peye.z = z;
}

void setIntensidadAmbiente(double i) {
	ia = i;
}

void setFactoresAtenuacion(double f1, double f2, double f3) {
	c1 = f1;
	c2 = f2;
	c3 = f3;
}

void setResolucion(int w, int h) {
	H_SIZE = w;
	V_SIZE = h;
}

void setReflexion(int r) {
	nivel_reflexion = r;
}

void setTransparencia(int t) {
	nivel_transparencia = t;
}

void setAnti(int a) {
	nivel_anti = a;
}

void loadTexturesList() {
	str_list *tmp;
	int i;

	if(texturas_names.size) {
		arreglo_texturas = (Textura **) calloc(texturas_names.size, sizeof(Textura*));
		tmp = texturas_names.first;
		i = 0;
		while(tmp) {
			arreglo_texturas[i++] = loadTextura(tmp->str);
			tmp = tmp->next;
		}
	}
	texturas_names = freeStringList(texturas_names);
}

void loadGrisesList() {
	str_list *tmp;
	int i;

	if(grises_names.size) {
		arreglo_grises = (Mapa_Grises **) calloc(grises_names.size, sizeof(Mapa_Grises*));
		tmp = grises_names.first;
		i = 0;
		while(tmp) {
			arreglo_grises[i++] = loadGris(tmp->str);
			tmp = tmp->next;
		}
	}
	grises_names = freeStringList(grises_names);
}

lista_puntos_planos * agregaPlano(lista_puntos_planos * pl, Point3D p1, Point3D p2, Point3D p3, int chr) {
	lista_puntos_planos * tmp = pl;
	while(tmp) {
		tmp = tmp->next;
	}
	if(tmp)
		tmp = tmp->next = (lista_puntos_planos *) calloc(1, sizeof(lista_puntos_planos));
	else
		pl = tmp = (lista_puntos_planos *) calloc(1, sizeof(lista_puntos_planos));
	tmp->p1 = p1;
	tmp->p2 = p2;
	tmp->p3 = p3;
	tmp->chr = chr;
	return pl;
}

lista_puntos_planos * freeListaPlanosPuntos(lista_puntos_planos * pl) {
	lista_puntos_planos * tmp = pl, *tmp2;
	while(tmp) {
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	return NULL;
}

void nuevoObjeto() {
	tmp_obj = (Object *) calloc(1, sizeof(Object));
	tmp_obj->mapa_brillo = tmp_obj->mapa_transparencia = tmp_obj->mapa_calado = tmp_obj->mapa_especular = -1;
	//puntos_planos = NULL;
}

void ubica_plano_x() {
	ptmp1.x = ptmp2.x = ptmp3.x = 0.0;
	ptmp1.y = ptmp2.y = 1.0; ptmp3.y = 0.0;
	ptmp1.z = 1.0; ptmp2.z = ptmp3.z = 0.0;
}
void ubica_plano_y() {
	ptmp1.y = ptmp2.y = ptmp3.y = 0.0;
	ptmp1.x = ptmp2.x = 1.0; ptmp3.x = 0.0;
	ptmp1.z = 1.0; ptmp2.z = ptmp3.z = 0.0;
}
void ubica_plano_z() {
	ptmp1.z = ptmp2.z = ptmp3.z = 0.0;
	ptmp1.y = ptmp2.y = 1.0; ptmp3.y = 0.0;
	ptmp1.x = 1.0; ptmp2.x = ptmp3.x = 0.0;
}