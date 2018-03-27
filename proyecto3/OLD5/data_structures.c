#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "data_structures.h"

char phong = TRUE, lights = TRUE;
StringList texturas_names, grises_names;

Textura **arreglo_texturas = NULL;
Mapa_Grises **arreglo_grises = NULL;

double pol_ancho , pol_alto;
Point3D pol_p0;

double stretch_height_default, stretch_width_default;

// Funciones para el manejo de las estructuras

// Para la lista de puntos
PointList addPoint(PointList pl, double x, double y, double z) {
	PointNodeList *tmp;

	tmp = (PointNodeList *) calloc(1, sizeof(PointNodeList));
	tmp->point.x = (double) x;
	tmp->point.y = (double) y;
	tmp->point.z = (double) z;
	if(! pl.first)
		pl.first = pl.last = tmp;
	else
		pl.last = pl.last->next = tmp;
	return pl;
}

void printPoints(PointList pl) {
	PointNodeList *tmp;

	tmp = pl.first;
	while(tmp) {
		printf("[%.3f, %.3f, %.3f]\n", tmp->point.x, tmp->point.y, tmp->point.z);
		tmp = tmp->next;
	}
}

void freePointList(PointList pl) {
	PointNodeList *tmp, *tmp1;

	tmp = pl.first;
	while(tmp) {
		tmp1 = tmp->next;
		free(tmp);
		tmp = tmp1;
	}
}

// Para la lista de planos

// Se recibe el A, B, C, y D de la ecuacion del plano
// sign es el lado de que se acepta...
PlaneList addPlane(PlaneList plane_list, double A, double B, double C, double D, char sign) {
	PlaneNodeList *tmp;

	tmp = (PlaneNodeList *) calloc(1, sizeof(PlaneNodeList));
	tmp->plane.A = A;
	tmp->plane.B = B;
	tmp->plane.C = C;
	tmp->plane.D = D;
	tmp->adm = sign;
	if(! plane_list.first)
		plane_list.first = plane_list.last = tmp;
	else
		plane_list.last = plane_list.last->next = tmp;
	return plane_list;
}

PlaneList addPlaneObject(PlaneList plane_list, Plane plane, char sign) {
	PlaneNodeList *tmp;

	tmp = (PlaneNodeList *) calloc(1, sizeof(PlaneNodeList));
	tmp->plane = plane;
	tmp->adm = sign;
	if(! plane_list.first)
		plane_list.first = plane_list.last = tmp;
	else
		plane_list.last = plane_list.last->next = tmp;
	return plane_list;
}

void printPlanes(PlaneList pl) {
	PlaneNodeList *tmp;

	tmp = pl.first;
	while(tmp) {
		printf("[%.3f, %.3f, %.3f, %.3f, %i]\n", tmp->plane.A, tmp->plane.B, tmp->plane.C, tmp->plane.D, tmp->adm);
		tmp = tmp->next;
	}
}

void freePlaneList(PlaneList pl) {
	PlaneNodeList *tmp, *tmp1;

	tmp = pl.first;
	while(tmp) {
		tmp1 = tmp->next;
		free(tmp);
		tmp = tmp1;
	}
}

// Agrega un objeto a la lista de objetos
// Se debe tener cuidado con que el tipo coincida con el objeto asignado
ObjectList addObject(ObjectList ol, Color c, double Kd, double Ka, double Ks, int Kn, char type, void * ptr) {
	Object *tmp;

	tmp = (Object *) calloc(1, sizeof(Object));

	tmp->color = c;
	tmp->Kd = Kd;
	tmp->Ka = Ka;
	tmp->Ks = Ks;
	tmp->Kn = Kn;
	tmp->tipo = type;
	tmp->object = ptr;

	if(! ol.first)
		ol.first = ol.last = tmp;
	else
		ol.last = ol.last->next = tmp;
	return ol;
}

int countObjects(ObjectList ol) {
	Object *tmp;
	int contador = 0;

	tmp = ol.first;
	while(tmp) {
		contador++;
		tmp = tmp->next;
	}
	return contador;
}

ObjectList addObjectDone(ObjectList ol, Object *tmp) {
	if(tmp) {
		if(! ol.first)
			ol.first = ol.last = tmp;
		else
			ol.last = ol.last->next = tmp;
	}
	return ol;
}

void printObjectList(ObjectList ol) {
	Object *tmp;
	Sphere *sph;
	Cilinder *cil;
	Cone *con;
	Polygon *pol;
	Disco *dis;

	tmp = ol.first;
	while(tmp) {
		switch(tmp->tipo) {
			case SPHERE:
				sph = (Sphere *) tmp->object;
				printf("Sphere\n");
				printf("R = %.4f G = %.4f B = %.4f\n", tmp->color.r, tmp->color.g, tmp->color.b);
				printf("Kd = %.4f Ka = %.4f Ks = %.4f Kn = %i\n", tmp->Kd, tmp->Ka, tmp->Ks, tmp->Kn);
				printf("Kt = %.4f O1 = %.4f O2 = %.4f O3 = %.4f\n", tmp->Kt, tmp->fO1, tmp->fO2, tmp->fO3);
				printf("Center: %.3f %.3f %.3f\n", sph->center.x, sph->center.y, sph->center.z);
				printf("Radius: %.3f\n", sph->radius);
				break;
			case CONE:
				con = (Cone *) tmp->object;
				printf("Cone\n");
				printf("Kd = %.4f Ka = %.4f Ks = %.4f Kn = %i\n", tmp->Kd, tmp->Ka, tmp->Ks, tmp->Kn);
				printf("R = %.4f G = %.4f B = %.4f\n", tmp->color.r, tmp->color.g, tmp->color.b);
				printf("Center: %.3f %.3f %.3f\n", con->center.x, con->center.y, con->center.z);
				printf("Direction: %.3f %.3f %.3f\n", con->direction.direction.x, con->direction.direction.y, con->direction.direction.z);
				printf("K Fact: %.3f\n", con->fk);
				break;
			case CILINDER:
				cil = (Cilinder *) tmp->object;
				printf("Cilinder\n");
				printf("Kd = %.4f Ka = %.4f Ks = %.4f Kn = %i\n", tmp->Kd, tmp->Ka, tmp->Ks, tmp->Kn);
				printf("R = %.4f G = %.4f B = %.4f\n", tmp->color.r, tmp->color.g, tmp->color.b);
				printf("Center: %.3f %.3f %.3f\n", cil->center.x, cil->center.y, cil->center.z);
				printf("Direction: %.3f %.3f %.3f\n", cil->direction.direction.x, cil->direction.direction.y, cil->direction.direction.z);
				printf("Radius: %.3f\n", cil->radius);
				break;
			case POLYGON:
				pol = (Polygon *) tmp->object;
				printf("Polygon\n");
				printf("Kd = %.4f Ka = %.4f Ks = %.4f Kn = %i\n", tmp->Kd, tmp->Ka, tmp->Ks, tmp->Kn);
				printf("R = %.4f G = %.4f B = %.4f\n", tmp->color.r, tmp->color.g, tmp->color.b);
				printf("A = %.4f B = %.4f C = %.4f D = %.4f\n", pol->plane.A, pol->plane.B, pol->plane.C, pol->plane.D);
				printPoints(pol->pl);
				printf("Ancla = %.4f %.4f %.4f\n", pol->ancla.x, pol->ancla.y, pol->ancla.z);
				printf("P0= %.4f %.4f %.4f\n", pol->p0.x, pol->p0.y, pol->p0.z);
				printf ("Ancho= %.4f Alto= %.4f\n", (double) pol->ancho, (double) pol->alto);
				break;
			case DISK:
				dis = (Disco *) tmp->object;
				printf("Disco");
				printf("Kd = %.4f Ka = %.4f Ks = %.4f Kn = %i\n", tmp->Kd, tmp->Ka, tmp->Ks, tmp->Kn);
				printf("R = %.4f G = %.4f B = %.4f\n", tmp->color.r, tmp->color.g, tmp->color.b);
				printf("Radios %.3f %.3f\n", dis->radius1, dis->radius2);
				printf("U = %.3f %.3f %.3f\n", dis->U.x, dis->U.y, dis->U.z);
				printf("V = %.3f %.3f %.3f\n", dis->V.x, dis->V.y, dis->V.z);
				printf("P0 = %.3f %.3f %.3f\n", dis->P0.x, dis->P0.y, dis->P0.z);
				break;
			default:
				printf("Esta raro!!\n");
				break;
		}
		tmp = tmp->next;
		printf("***********\n");
	}
}

LightList addLight(LightList ll, double intensity, double color_r, double color_g, double color_b,
						double pos_x, double pos_y, double pos_z) {
	Light *tmp = (Light *) calloc(1, sizeof(Light));

	tmp->intensity = intensity;
	tmp->location.x = pos_x;
	tmp->location.y = pos_y;
	tmp->location.z = pos_z;
	tmp->color.r = color_r;
	tmp->color.g = color_g;
	tmp->color.b = color_b;
	if(! ll.first)
		ll.first = ll.last = tmp;
	else
		ll.last = ll.last->next = tmp;
	return ll;
}

void printLightList(LightList ll) {
	Light *tmp;

	tmp = ll.first;
	printf("********** Begin lights list\n");
	while(tmp) {
		printf("---\n");
		printf("Intensity %.2f\n", tmp->intensity);
		printf("Location %.2f %.2f %.2f\n", tmp->location.x, tmp->location.y, tmp->location.z);
		printf("Color %.2f %.2f %.2f\n", tmp->color.r, tmp->color.g, tmp->color.b);
		tmp = tmp->next;
	}
	printf("********** End lights list\n");
}

IntersectionList addIntersection(IntersectionList il, double t, Object *obj) {
	if(obj) {
		Intersection * tmp, * inter = (Intersection *) calloc(1, sizeof(Intersection));
		inter->t = t;
		inter->obj = obj;

		if(! il.first || (il.first && il.first->t > t)) {
			if(! il.first)
				il.first = il.last = inter;
			else {
				inter->next = il.first;
				il.first = inter;
			}
		}
		else if(il.last->t < t)
			il.last = il.last->next = inter;
		else {
			tmp = il.first;
			while(tmp->next && t > tmp->next->t)
				tmp = tmp->next;
			inter->next = tmp->next;
			tmp->next = inter;
		}
	}
	return il;
}

IntersectionList freeIntersectionList(IntersectionList il) {
	Intersection *tmp1, *tmp2;
	tmp1 = il.first;
	while(tmp1) {
		tmp2 = tmp1->next;
		free(tmp1);
		tmp1 = tmp2;
	}
	il.first = il.last = NULL;
	return il;
}

void printIntersectionList(IntersectionList il) {
	Intersection * tmp = il.first;
	while(tmp) {
		printf("---- %.15f %i\n", (double) tmp->t, tmp->obj->Kn);
		tmp = tmp->next;
	}
}

// Calcula las intersecciones de los objetos con el rayo definido.
IntersectionList getIntersections(Point3D origin, Point3D direction) {
	double t_temp, a, b, c, disc;
	Object *tmp;
	Sphere *sph;
	Cilinder *cil;
	Polygon *pol;
	Cone *con;
	Disco *dis;
	IntersectionList inter_list = {NULL, NULL};
	Point3D tmp_point;
	Superficie2 *spf;

	tmp = lista_objetos.first;
	while(tmp) {
		switch(tmp->tipo) {
			case SPHERE:
				sph = (Sphere *) tmp->object;
				//a = (double) 1.0;
				b = (double) 2 * (direction.x * (origin.x - sph->center.x) +
					     direction.y * (origin.y - sph->center.y) +
					     direction.z * (origin.z - sph->center.z));
				c = (double) (origin.x - sph->center.x) * (origin.x - sph->center.x) +
				       (origin.y - sph->center.y) * (origin.y - sph->center.y) +
				       (origin.z - sph->center.z) * (origin.z - sph->center.z) - sph->radius * sph->radius;
				disc = b*b - 4*c;
				//t_temp = (disc < 0.0) ? -disc : disc;
				if(fabs(disc) < EPSILON) {	// Hay una solucion
					t_temp = (double) -b / 2;	// Puede haber problemas en esto *****
					if (t_temp > EPSILON && isAccepted(t_temp, origin, direction, tmp->plane_list))
						inter_list = addIntersection(inter_list, t_temp, tmp);
				}
				else if (disc > 0) {			// Hay dos soluciones
					t_temp = (double) (-b + sqrt(disc)) / 2;
					if (t_temp > EPSILON && isAccepted(t_temp, origin, direction, tmp->plane_list))
						inter_list = addIntersection(inter_list, t_temp, tmp);
					t_temp = (double) (-b - sqrt(disc)) / 2;
					if (t_temp > EPSILON && isAccepted(t_temp, origin, direction, tmp->plane_list))
						inter_list = addIntersection(inter_list, t_temp, tmp);
				}
				break;
			case CONE:	// Codigo del calculo de interseccion para el Cono
// ############################################## INICIO CONO
				con = (Cone *) tmp->object;
				a = pow((double) (direction.x
								- direction.x * con->direction.direction.x * con->direction.direction.x
								- direction.y * con->direction.direction.y * con->direction.direction.x
								- direction.z * con->direction.direction.z * con->direction.direction.x), (double) 2.0)
				+ pow((double) (direction.y
								- direction.y * con->direction.direction.y * con->direction.direction.y
								- direction.x * con->direction.direction.x * con->direction.direction.y
								- direction.z * con->direction.direction.z * con->direction.direction.y), (double) 2.0)
				+ pow((double) (direction.z
								- direction.z * con->direction.direction.z * con->direction.direction.z
								- direction.y * con->direction.direction.y * con->direction.direction.z
								- direction.x * con->direction.direction.x * con->direction.direction.z), (double) 2.0)
				- con->fk * con->fk * pow((direction.x * con->direction.direction.x
										+ direction.y * con->direction.direction.y
										+ direction.z * con->direction.direction.z), 2.0);
				b = 2 * ((direction.x
								- direction.x * con->direction.direction.x * con->direction.direction.x
								- direction.y * con->direction.direction.y * con->direction.direction.x
								- direction.z * con->direction.direction.z * con->direction.direction.x)
						* (origin.x - con->center.x - origin.x * con->direction.direction.x * con->direction.direction.x
						    + con->center.x * con->direction.direction.x * con->direction.direction.x
						    - origin.y * con->direction.direction.y * con->direction.direction.x
						    + con->center.y * con->direction.direction.y * con->direction.direction.x
						    - origin.z * con->direction.direction.z * con->direction.direction.x
						    + con->center.z * con->direction.direction.z * con->direction.direction.x)
						+ (direction.y
								- direction.y * con->direction.direction.y * con->direction.direction.y
								- direction.x * con->direction.direction.x * con->direction.direction.y
								- direction.z * con->direction.direction.z * con->direction.direction.y)
						* (origin.y - con->center.y - origin.y * con->direction.direction.y * con->direction.direction.y
						    + con->center.y * con->direction.direction.y * con->direction.direction.y
						    - origin.x * con->direction.direction.x * con->direction.direction.y
						    + con->center.x * con->direction.direction.x * con->direction.direction.y
						    - origin.z * con->direction.direction.z * con->direction.direction.y
						    + con->center.z * con->direction.direction.z * con->direction.direction.y)
						+ (direction.z
								- direction.z * con->direction.direction.z * con->direction.direction.z
								- direction.y * con->direction.direction.y * con->direction.direction.z
								- direction.x * con->direction.direction.x * con->direction.direction.z)
						* (origin.z - con->center.z - origin.z * con->direction.direction.z * con->direction.direction.z
						    + con->center.z * con->direction.direction.z * con->direction.direction.z
						    - origin.y * con->direction.direction.y * con->direction.direction.z
						    + con->center.y * con->direction.direction.y * con->direction.direction.z
						    - origin.x * con->direction.direction.x * con->direction.direction.z
						    + con->center.x * con->direction.direction.x * con->direction.direction.z))
						- 2 * con->fk * con->fk * (direction.x * con->direction.direction.x
										+ direction.y * con->direction.direction.y
										+ direction.z * con->direction.direction.z)
							* (con->direction.direction.x * (origin.x - con->center.x)
								+ con->direction.direction.y * (origin.y - con->center.y)
								+ con->direction.direction.z * (origin.z - con->center.z));
					c = pow((double) (origin.x - con->center.x - origin.x * con->direction.direction.x * con->direction.direction.x
						    + con->center.x * con->direction.direction.x * con->direction.direction.x
						    - origin.y * con->direction.direction.y * con->direction.direction.x
						    + con->center.y * con->direction.direction.y * con->direction.direction.x
						    - origin.z * con->direction.direction.z * con->direction.direction.x
						    + con->center.z * con->direction.direction.z * con->direction.direction.x), 2.0)
					      + pow((double) (origin.y - con->center.y - origin.y * con->direction.direction.y * con->direction.direction.y
						    + con->center.y * con->direction.direction.y * con->direction.direction.y
						    - origin.x * con->direction.direction.x * con->direction.direction.y
						    + con->center.x * con->direction.direction.x * con->direction.direction.y
						    - origin.z * con->direction.direction.z * con->direction.direction.y
						    + con->center.z * con->direction.direction.z * con->direction.direction.y), 2.0)
					      + pow((double) (origin.z - con->center.z - origin.z * con->direction.direction.z * con->direction.direction.z
						    + con->center.z * con->direction.direction.z * con->direction.direction.z
						    - origin.y * con->direction.direction.y * con->direction.direction.z
						    + con->center.y * con->direction.direction.y * con->direction.direction.z
						    - origin.x * con->direction.direction.x * con->direction.direction.z
						    + con->center.x * con->direction.direction.x * con->direction.direction.z), 2.0)
						- con->fk * con->fk * pow((con->direction.direction.x * (origin.x - con->center.x)
													+ con->direction.direction.y * (origin.y - con->center.y)
													+ con->direction.direction.z * (origin.z - con->center.z)), 2.0);
				disc = b*b - 4*a*c;
				if(fabs(disc) < EPSILON) {	// Hay una solucion
					t_temp = (double) -b / (2 * a);	// Puede haber problemas en esto *****
					if (t_temp > EPSILON && isAccepted(t_temp, origin, direction, tmp->plane_list))
						inter_list = addIntersection(inter_list, t_temp, tmp);
				}
				else if (disc > 0) {			// Hay dos soluciones
					t_temp = (double) (-b + sqrt(disc)) / (2 * a);
					if (t_temp > EPSILON && isAccepted(t_temp, origin, direction, tmp->plane_list))
						inter_list = addIntersection(inter_list, t_temp, tmp);
					t_temp = (double) (-b - sqrt(disc)) / (2 * a);
					if (t_temp > EPSILON && isAccepted(t_temp, origin, direction, tmp->plane_list))
						inter_list = addIntersection(inter_list, t_temp, tmp);
				}
				break;
// ############################################## FIN DEL CONO
				break;
			case CILINDER:
				cil = (Cilinder *) tmp->object;
				a = pow((double) (direction.x
								- direction.x * cil->direction.direction.x * cil->direction.direction.x
								- direction.y * cil->direction.direction.y * cil->direction.direction.x
								- direction.z * cil->direction.direction.z * cil->direction.direction.x), (double) 2.0)
				+ pow((double) (direction.y
								- direction.y * cil->direction.direction.y * cil->direction.direction.y
								- direction.x * cil->direction.direction.x * cil->direction.direction.y
								- direction.z * cil->direction.direction.z * cil->direction.direction.y), (double) 2.0)
				+ pow((double) (direction.z
								- direction.z * cil->direction.direction.z * cil->direction.direction.z
								- direction.y * cil->direction.direction.y * cil->direction.direction.z
								- direction.x * cil->direction.direction.x * cil->direction.direction.z), (double) 2.0);
				b = 2 * ((direction.x
								- direction.x * cil->direction.direction.x * cil->direction.direction.x
								- direction.y * cil->direction.direction.y * cil->direction.direction.x
								- direction.z * cil->direction.direction.z * cil->direction.direction.x)
						* (origin.x - cil->center.x - origin.x * cil->direction.direction.x * cil->direction.direction.x
						    + cil->center.x * cil->direction.direction.x * cil->direction.direction.x
						    - origin.y * cil->direction.direction.y * cil->direction.direction.x
						    + cil->center.y * cil->direction.direction.y * cil->direction.direction.x
						    - origin.z * cil->direction.direction.z * cil->direction.direction.x
						    + cil->center.z * cil->direction.direction.z * cil->direction.direction.x)
						+ (direction.y
								- direction.y * cil->direction.direction.y * cil->direction.direction.y
								- direction.x * cil->direction.direction.x * cil->direction.direction.y
								- direction.z * cil->direction.direction.z * cil->direction.direction.y)
						* (origin.y - cil->center.y - origin.y * cil->direction.direction.y * cil->direction.direction.y
						    + cil->center.y * cil->direction.direction.y * cil->direction.direction.y
						    - origin.x * cil->direction.direction.x * cil->direction.direction.y
						    + cil->center.x * cil->direction.direction.x * cil->direction.direction.y
						    - origin.z * cil->direction.direction.z * cil->direction.direction.y
						    + cil->center.z * cil->direction.direction.z * cil->direction.direction.y)
						+ (direction.z
								- direction.z * cil->direction.direction.z * cil->direction.direction.z
								- direction.y * cil->direction.direction.y * cil->direction.direction.z
								- direction.x * cil->direction.direction.x * cil->direction.direction.z)
						* (origin.z - cil->center.z - origin.z * cil->direction.direction.z * cil->direction.direction.z
						    + cil->center.z * cil->direction.direction.z * cil->direction.direction.z
						    - origin.y * cil->direction.direction.y * cil->direction.direction.z
						    + cil->center.y * cil->direction.direction.y * cil->direction.direction.z
						    - origin.x * cil->direction.direction.x * cil->direction.direction.z
						    + cil->center.x * cil->direction.direction.x * cil->direction.direction.z));
					c = pow((double) (origin.x - cil->center.x - origin.x * cil->direction.direction.x * cil->direction.direction.x
						    + cil->center.x * cil->direction.direction.x * cil->direction.direction.x
						    - origin.y * cil->direction.direction.y * cil->direction.direction.x
						    + cil->center.y * cil->direction.direction.y * cil->direction.direction.x
						    - origin.z * cil->direction.direction.z * cil->direction.direction.x
						    + cil->center.z * cil->direction.direction.z * cil->direction.direction.x), 2.0)
					      + pow((double) (origin.y - cil->center.y - origin.y * cil->direction.direction.y * cil->direction.direction.y
						    + cil->center.y * cil->direction.direction.y * cil->direction.direction.y
						    - origin.x * cil->direction.direction.x * cil->direction.direction.y
						    + cil->center.x * cil->direction.direction.x * cil->direction.direction.y
						    - origin.z * cil->direction.direction.z * cil->direction.direction.y
						    + cil->center.z * cil->direction.direction.z * cil->direction.direction.y), 2.0)
					      + pow((double) (origin.z - cil->center.z - origin.z * cil->direction.direction.z * cil->direction.direction.z
						    + cil->center.z * cil->direction.direction.z * cil->direction.direction.z
						    - origin.y * cil->direction.direction.y * cil->direction.direction.z
						    + cil->center.y * cil->direction.direction.y * cil->direction.direction.z
						    - origin.x * cil->direction.direction.x * cil->direction.direction.z
						    + cil->center.x * cil->direction.direction.x * cil->direction.direction.z), 2.0)
						-  cil->radius * cil->radius;
				disc = b*b - 4*a*c;
				//t_temp = (disc < 0.0) ? -disc : disc;
				if(fabs(disc) < EPSILON) {	// Hay una solucion
					t_temp = (double) -b / (2 * a);	// Puede haber problemas en esto *****
					if (t_temp > EPSILON && ! estaFuera(t_temp, origin, direction, tmp)
						&& isAccepted(t_temp, origin, direction, tmp->plane_list))
						inter_list = addIntersection(inter_list, t_temp, tmp);
				}
				else if (disc > 0) {			// Hay dos soluciones
					t_temp = (double) (-b + sqrt(disc)) / (2 * a);
					if (t_temp > EPSILON && ! estaFuera(t_temp, origin, direction, tmp)
						&& isAccepted(t_temp, origin, direction, tmp->plane_list))
						inter_list = addIntersection(inter_list, t_temp, tmp);
					t_temp = (double) (-b - sqrt(disc)) / (2 * a);
					if (t_temp > EPSILON && ! estaFuera(t_temp, origin, direction, tmp)
						&& isAccepted(t_temp, origin, direction, tmp->plane_list))
						inter_list = addIntersection(inter_list, t_temp, tmp);
				}
				break;
			case POLYGON:	// Codigo del calculo de interseccion para el poligono
				pol = (Polygon *) tmp->object;
				t_temp = pol->plane.A * direction.x + pol->plane.B * direction.y + pol->plane.C * direction.z;
				//disc = t_temp < 0.0 ? - t_temp : t_temp;
				if(fabs(t_temp) > EPSILON) {
					t_temp = -(pol->plane.A * origin.x
								+ pol->plane.B * origin.y
								+ pol->plane.C * origin.z
								+ pol->plane.D) / t_temp;
					tmp_point.x = origin.x + direction.x * t_temp;
					tmp_point.y = origin.y + direction.y * t_temp;
					tmp_point.z = origin.z + direction.z * t_temp;
					if(t_temp > EPSILON && intersectPolygon(tmp_point, pol) && isAccepted(t_temp, origin, direction, tmp->plane_list))
						inter_list = addIntersection(inter_list, t_temp, tmp);
				}
				break;
			case DISK:	// Codigo del calculo de interseccion para el poligono
				dis = (Disco *) tmp->object;
				//printf("Disco\n");
				t_temp = dis->plane.A * direction.x + dis->plane.B * direction.y + dis->plane.C * direction.z;
				disc = t_temp < 0.0 ? - t_temp : t_temp;
				if(disc > EPSILON) {
					t_temp = -(dis->plane.A * origin.x
								+ dis->plane.B * origin.y
								+ dis->plane.C * origin.z
								+ dis->plane.D) / t_temp;
					tmp_point.x = origin.x + direction.x * t_temp;
					tmp_point.y = origin.y + direction.y * t_temp;
					tmp_point.z = origin.z + direction.z * t_temp;
					disc = sqrt((tmp_point.x - dis->center.x) * (tmp_point.x - dis->center.x)
								+ (tmp_point.y - dis->center.y) * (tmp_point.y - dis->center.y)
								+ (tmp_point.z - dis->center.z) * (tmp_point.z - dis->center.z));
					if(t_temp > EPSILON && disc > dis->radius1 && disc < dis->radius2 && isAccepted(t_temp, origin, direction, tmp->plane_list))
						inter_list = addIntersection(inter_list, t_temp, tmp);
				}
				break;
			case SUPERFICIE2:
				spf = (Superficie2 *) tmp->object;
				a=
					pow(spf->A * direction.x,2.0) +
					pow(spf->B * direction.y,2.0) +
					pow(spf->C * direction.z,2.0) +
					(double) 2.0  * (
						spf->D * direction.x * direction.y +
						spf->E * direction.y * direction.z +
						spf->F * direction.x * direction.z
					);
				b=(double) 2.0  * (
					spf->A * origin.x * direction.x +
					spf->B * origin.y * direction.y +
					spf->C * origin.z * direction.z +
					spf->D * origin.x * direction.y +
					spf->D * origin.y * direction.x +
					spf->E * origin.y * direction.z +
					spf->E * origin.z * direction.y +
					spf->F * origin.z * direction.x +
					spf->F * origin.x * direction.z +
					spf->G * direction.x +
					spf->H * direction.y +
					spf->J * direction.z
				);
				c=
					spf->A * origin.x * origin.x +
					spf->B * origin.y * origin.y +
					spf->C * origin.z * origin.z +
					(double) 2.0 * (
						spf->D * origin.x * origin.y +
						spf->E * origin.x * origin.z +
						spf->F * origin.z * origin.x +
						spf->G * origin.x +
						spf->H * origin.y +
						spf->J * origin.z
					) +
					spf->K;

				disc = b*b - 4*a*c;

				if(fabs(disc) < EPSILON) {	// Hay una solucion
					t_temp = (double) -b / (2 * a);	// Puede haber problemas en esto *****
					if (t_temp > EPSILON && isAccepted(t_temp, origin, direction, tmp->plane_list))
						inter_list = addIntersection(inter_list, t_temp, tmp);
				}
				else if (disc > 0) {			// Hay dos soluciones
					t_temp = (double) (-b + sqrt(disc)) / (2 * a);
					if (t_temp > EPSILON && isAccepted(t_temp, origin, direction, tmp->plane_list) )
						inter_list = addIntersection(inter_list, t_temp, tmp);
					t_temp = (double) (-b - sqrt(disc)) / (2 * a);
					if (t_temp > EPSILON && isAccepted(t_temp, origin, direction, tmp->plane_list))
						inter_list = addIntersection(inter_list, t_temp, tmp);
				}
			break;
			default:
				printf("Objeto sin ecuacion de intersecciones\n");
				break;
		}
		tmp = tmp->next;
	}
	return inter_list;
}

int estaFuera(double t, Point3D origin, Point3D direction, Object *obj) {
	char fuera = FALSE;
	Cilinder *cil;
	if(obj) {
		switch(obj->tipo) {
			case CILINDER:
				cil = (Cilinder *) obj->object;
				if (cil->distancia > 0.0) {
					double D;
					Point3D pi = {origin.x + direction.x * t,
								origin.y + direction.y * t,
								origin.z + direction.z * t};
					D = (pi.x - cil->center.x) * cil->direction.direction.x
						+ (pi.y - cil->center.y) * cil->direction.direction.y
						+ (pi.z - cil->center.z) * cil->direction.direction.z;
					if(D < 0.0 || D > cil->distancia)
						fuera = TRUE;
				}
				break;
		}
	}
	return fuera;
}

int isAccepted(double t, Point3D origin, Point3D direction, PlaneList plane_list) {
	PlaneNodeList *plane_tmp;

	plane_tmp = plane_list.first;
	while(plane_tmp) {
		if (plane_tmp->adm) {
			if(((origin.x + t * direction.x) * plane_tmp->plane.A
				+ (origin.y + t * direction.y) * plane_tmp->plane.B
				+ (origin.z + t * direction.z) * plane_tmp->plane.C
				+ plane_tmp->plane.D) < -EPSILON)
				return FALSE;
		} else {
			if(((origin.x + t * direction.x) * plane_tmp->plane.A
				+ (origin.y + t * direction.y) * plane_tmp->plane.B
				+ (origin.z + t * direction.z) * plane_tmp->plane.C
				+ plane_tmp->plane.D) > EPSILON)
				return FALSE;
		}
		plane_tmp = plane_tmp->next;
	}
	return TRUE;
}

// Devuelve una estructura del tipo UV_st que contiene el u y v correspondiente a tal punto en el objeto
// Se sabe que el punto pertenece al objeto
UV_st getUV(Object *obj , Point3D pi , Point3D normal) {
	UV_st struc = {-1.0, -1.0};
	double v ,u , d1 , d2, ancho, alto;

	if (obj->textura) {
		//Calcula el U y V
		switch (obj->tipo) {
			case POLYGON: {
				Polygon * pol = (Polygon * ) obj->object;
				Point3D L = {pi.x - pol->p0.x , pi.y - pol->p0.y , pi.z - pol->p0.z};
				//Ancho y Alto hasta Total de La superficie
				ancho=pol->ancho;
				alto=pol->alto;
				// Ancho y Alto hasta la interseccion
				d1 = MIN(fabs(L.x*pol->U.x + L.y*pol->U.y + L.z*pol->U.z), ancho);
				d2 = MIN(fabs(L.x*pol->V.x + L.y*pol->V.y + L.z*pol->V.z), alto);
			}break;
			case DISK: {
				Disco *dis = (Disco *) obj->object;
				Point3D L = {pi.x - dis->P0.x , pi.y - dis->P0.y , pi.z - dis->P0.z};
				ancho = alto = 2 * dis->radius2;
				d1 = fabs(L.x*dis->U.x + L.y*dis->U.y + L.z*dis->U.z);
				d2 = fabs(L.x*dis->V.x + L.y*dis->V.y + L.z*dis->V.z);
			} break;
			case CILINDER: {		// stretch_height_default, stretch_width_default;
				Cilinder *cil = (Cilinder *) obj->object;
				ancho = 2 * PI;
				d1 = cil->north.x * cil->greenwich.x
					+ cil->north.y * cil->greenwich.y
					+ cil->north.z * cil->greenwich.z;
				if(pi.x * cil->plane.A + pi.y * cil->plane.B + pi.z * cil->plane.C + cil->plane.D < 0.0)
					d1 = ancho - d1;
				d2 = (pi.x - cil->center.x) * cil->direction.direction.x
					+ (pi.y - cil->center.y) * cil->direction.direction.y
					+ (pi.z - cil->center.z) * cil->direction.direction.z;
				if(cil->distancia > 0.0) 	// Esta acotado
					alto = cil->distancia;
				else {
					printf("El cilindro no esta acotado\n");
					alto = stretch_height_default;
				}
			}break;
			case SPHERE:{
				Sphere *sp = (Sphere *) obj->object;
				Point3D P;
				// d = North Dot_Product  Normal
				double d = (sp->north.x * normal.x + sp->north.y * normal.y + sp->north.z * normal.z);

				//Calcula V
				v = acos (d) / PI; // d = North Dot_Product  Normal

				//Sombra = ( Pi - (North Dot_Product  Normal) * Radio * Norte ) - Center
				P.x = (pi.x - d * sp->radius * sp->north.x) - sp->center.x;
				P.y = (pi.y - d * sp->radius * sp->north.y) - sp->center.y;
				P.z = (pi.z - d * sp->radius * sp->north.z) - sp->center.z;

				//P = Nomalizar (Sombra)
				d = sqrt ( P.x*P.x + P.y*P.y +P.z*P.z );
				P.x /= d; P.y /= d; P.z /= d;

				//Calcula U
				d = P.x * sp->greenwich.x + P.y * sp->greenwich.y + P.z * sp->greenwich.z;
				u = acos (d/RADIAN) / (2.0 *  PI);


				d = sp->plane.A*pi.x + sp->plane.B*pi.y + sp->plane.C*pi.z + sp->plane.D;
				if (d>=0.0) u = 1.0 - u ;

				struc.u=u;
				struc.v=v;
				return struc;

			}break;

		}

		//No Realiza Mas Calculos si un valor es negativo
		if ((u<0) || (v<0)) return struc;

		//Pregunta cual modo de textura
		if (obj->textura->tipo == FILL_TILED) {
			struc.u = (double) ((int) d1 % (int) obj->textura->ancho)  / obj->textura->ancho;
			struc.v = (double) ((int) d2 % (int) obj->textura->alto ) / obj->textura->alto;
			//printf ("U[%f] =  d1[%f] / ancho[%f]\n",struc.u,d1,ancho);
		} else { //if (obj->textura->tipo == FILL_STRETCH) {
			struc.u = d1 / ancho;
			struc.v = d2 / alto;
			//printf ("U[%f] =  d1[%f] / ancho[%f]\n",struc.u,d1,ancho);
		}
	}
	return struc;
}
//Regresa el color de un Objecto, Busca en texturas
Color getObjectColor (Object *obj , Point3D pi , Point3D normal) {
	UV_st punto;
	int x,y;
	Color color = obj->color;

	//Hay Textura ?
	if (obj->textura) {
		punto = getUV(obj, pi , normal);
		if ((punto.u>-1) && (punto.v>-1)) {//No Hace calculos si es negativo
			x = (int)(punto.u * (arreglo_texturas[obj->textura->index]->width - 1));
			y = (int)(punto.v * (arreglo_texturas[obj->textura->index]->height - 1 ));
			color = arreglo_texturas[obj->textura->index]->image[x][arreglo_texturas[obj->textura->index]->height -1 - y];
		}
	}

	return color;
}

// Obtiene el color que le toca al punto definido en este rayo.
Color getColor(Point3D origin, Point3D direction, int nivel) {
	IntersectionList inter_list;
	Color color = background, reflejo = {0.0, 0.0, 0.0}, transparencia = {0.0, 0.0, 0.0};
	Intersection * tmp;
	Point3D pi, normal, V, R;
	double dotProduct, I, P, prod_tmp;
	IP_st intensity_and_phong;

	inter_list = getIntersections(origin, direction);
	if(tmp = inter_list.first) {
		pi.x = origin.x + tmp->t * direction.x;
		pi.y = origin.y + tmp->t * direction.y;
		pi.z = origin.z + tmp->t * direction.z;
		normal = getNormal(pi,  tmp->obj);
		color = getObjectColor(tmp->obj,pi,normal);

		if(nivel && tmp->obj->fO2 != 0.0) {
			//printf("Refleja\n");
			V.x = -direction.x;
			V.y = -direction.y;
			V.z = -direction.z;
			prod_tmp = V.x * normal.x + V.y * normal.y + V.z * normal.z;		// N punto V
			R.x = 2 * prod_tmp * normal.x - V.x;
			R.y = 2 * prod_tmp * normal.y - V.y;
			R.z = 2 * prod_tmp * normal.z - V.z;
			reflejo = getColor(pi, R, nivel - 1);
		}
		if(acos(normal.x * direction.x + normal.z * direction.z + normal.y * direction.y) * RADIAN < 90.0 - EPSILON) {	// Hay que arreglar la normal
			//printf("Alfa %.6f\n", acos(dotProduct) * RADIAN);
			normal.x *= -1;
			normal.y *= -1;
			normal.z *= -1;
		}
		intensity_and_phong = getIntensityAndPhong(pi, direction, normal, tmp->obj);
		I = intensity_and_phong.intensity;
		P = intensity_and_phong.phong;
		//printf("Transparencia = %i\n", nivel_transparencia);
		if(tmp->obj->Kt > EPSILON && nivel_transparencia) {
			//printf("Porque?\n");
			transparencia = getTransparenciaMejorada(nivel_transparencia, pi, origin, direction, tmp->next, intensity_and_phong.Fatt);
			transparencia.r *= intensity_and_phong.Fatt;
			transparencia.g *= intensity_and_phong.Fatt;
			transparencia.b *= intensity_and_phong.Fatt;
		}
		/*if (! phong)
			P = 0.0;
		if (! lights)
			I = 1.0;*/
		color.r = MIN(color.r * I, 1.0);
		color.g = MIN(color.g * I, 1.0);
		color.b = MIN(color.b * I, 1.0);
		/*if(transparencia.r + transparencia.g + transparencia.b > 0.0 || reflejo.r + reflejo.g + reflejo.b > 0.0) {
			printf("Color %.4f %.4f %.4f\n", color.r, color.g, color.b);
			printf("Reflejo %.4f %.4f %.4f\n", reflejo.r, reflejo.g, reflejo.b);
			printf("Transparencia %.4f %.4f %.4f\n", transparencia.r, transparencia.g, transparencia.b);
		}*/
		color.r =	tmp->obj->fO1 * color.r + tmp->obj->fO2 * reflejo.r + tmp->obj->fO3 * transparencia.r;
		color.g =	tmp->obj->fO1 * color.g + tmp->obj->fO2 * reflejo.g + tmp->obj->fO3 * transparencia.g;
		color.b =	tmp->obj->fO1 * color.b + tmp->obj->fO2 * reflejo.b + tmp->obj->fO3 * transparencia.b;

		color.r = MIN(color.r + P, 1.0);
		color.g = MIN(color.g + P, 1.0);
		color.b = MIN(color.b + P, 1.0);
	}
	freeIntersectionList(inter_list);
	//printf("Sale de Get Color\n");
	return color;
}

Color getTransparenciaMejorada(int nivel, Point3D point, Point3D origin, Point3D direction, Intersection *next_int, double Fatt) {
	Color color = {0.0, 0.0, 0.0}, agregar = {0.0, 0.0, 0.0};
	Point3D proximo;

	//printf("Entra a Transparencia Puntero %i Nivel %i\n", next_int, nivel);
	color = getColor(point, direction, nivel_reflexion);
	//printf("Tomamos el color\n");
	if(next_int && next_int->obj->Kt > EPSILON && nivel ) {
		//printf("Entra a Transparencia -- Puntero %i Nivel %i Kt %.4f\n", next_int, nivel, next_int->obj->Kt);
		proximo.x = origin.x + next_int->t * direction.x;
		proximo.y = origin.y + next_int->t * direction.y;
		proximo.z = origin.z + next_int->t * direction.z;
		agregar = getTransparenciaMejorada(nivel - 1, proximo, origin, direction, next_int->next, Fatt);
		agregar.r *= Fatt;
		agregar.g *= Fatt;
		agregar.b *= Fatt;
	}
	color.r += agregar.r;
	color.g += agregar.g;
	color.b += agregar.b;
	//printf("Sale de Transparencia\n");
	return color;
}

Vector makeVector(Point3D origin, Point3D direction) {
	Vector new;
	double L;

	new.direction.x = direction.x - origin.x;
	new.direction.y = direction.y - origin.y;
	new.direction.z = direction.z - origin.z;
	L = (double) sqrt(new.direction.x * new.direction.x + new.direction.y * new.direction.y + new.direction.z * new.direction.z);
	new.direction.x /= L;
	new.direction.y /= L;
	new.direction.z /= L;
	return new;
}

// Obteniene la normal en el punto.
// Ya se sabe que el punto pertenece al objeto recibido.
// Si no se tiene el calculo de la normal para el objeto, se devuelve N = [0.0,0.0,0.0]
Point3D getNormal(Point3D p, Object *obj) {
	Point3D normal = {0.0, 0.0, 0.0}, Pm, R, New;
	double L, tmp;
	Sphere *sph;
	Cilinder *cil;
	Polygon *pol;
	Disco *dis;
	Cone *con;
	double alfa, beta, gamma, cita;
	Superficie2 *spf;

	if(obj) {
		switch(obj->tipo) {
			case SPHERE:
				sph = (Sphere *) obj->object;
				normal.x = p.x - sph->center.x;
				normal.y = p.y - sph->center.y;
				normal.z = p.z - sph->center.z;
				normal.x /= sph->radius;
				normal.y /= sph->radius;
				normal.z /= sph->radius;
				break;
			case CONE:	// Donde se agrega el calculo de la normal para el cono.
				con = (Cone *) obj->object;
				tmp = 	(L = sqrt((p.x - con->center.x) * (p.x - con->center.x)
						+ (p.y - con->center.y) * (p.y - con->center.y)
						+ (p.z - con->center.z) * (p.z - con->center.z))) * con->angle; // Obtengo el d
				tmp += (L = tmp * con->fk) * con->fk;	// d + k^2 * d
				Pm.x = con->center.x + tmp * con->direction.direction.x;
				Pm.y = con->center.y + tmp * con->direction.direction.y;
				Pm.z = con->center.z + tmp * con->direction.direction.z;
				normal.x = p.x - Pm.x;
				normal.y = p.y - Pm.y;
				normal.z = p.z - Pm.z;
				L *= con->fk;
				normal.x /= L;
				normal.y /= L;
				normal.z /= L;
			case CILINDER:
				cil = (Cilinder *) obj->object;
				tmp = 	(p.x - cil->center.x) * cil->direction.direction.x
						+ (p.y - cil->center.y) * cil->direction.direction.y
						+ (p.z - cil->center.z) * cil->direction.direction.z;
				Pm.x = cil->center.x + tmp * cil->direction.direction.x;
				Pm.y = cil->center.y + tmp * cil->direction.direction.y;
				Pm.z = cil->center.z + tmp * cil->direction.direction.z;
				/*normal.x = p.x - Pm.x;
				normal.y = p.y - Pm.y;
				normal.z = p.z - Pm.z;*/
				normal.x = 2 * (p.x - Pm.x);
				normal.y = 2 * (p.y - Pm.y);
				normal.z = 2 * (p.z - Pm.z);
				L = sqrt(normal.x * normal.x + normal.y * normal.y + normal.z * normal.z);
				normal.x /= L;
				normal.y /= L;
				normal.z /= L;
				break;
			case POLYGON:	// Donde se agrega el calculo de la normal para el plano.
				//printf("Normal en el poligono\n");
				pol = (Polygon *) obj->object;
				normal.x = pol->plane.A;
				normal.y = pol->plane.B;
				normal.z = pol->plane.C;
				break;
			case DISK:	// Donde se agrega el calculo de la normal para el plano.
				//printf("Normal en el poligono\n");
				dis = (Disco *) obj->object;
				normal.x = dis->plane.A;
				normal.y = dis->plane.B;
				normal.z = dis->plane.C;
				//printf("Normal = %.3f %.3f %.3f\n", normal.x, normal.y, normal.z);
				break;
			case SUPERFICIE2:
				spf = (Superficie2 *) obj->object;
				normal.x = (double) 2.0 * (
					spf->A * p.x +
					spf->D * p.y +
					spf->F * p.z +
					spf->G
				);
				normal.y = (double) 2.0 * (
					spf->D * p.x +
					spf->B * p.y +
					spf->E * p.z +
					spf->H
				);
				normal.z = (double) 2.0 * (
					spf->F * p.x +
					spf->E * p.y +
					spf->C * p.z +
					spf->J
				);

				L = sqrt(normal.x * normal.x + normal.y * normal.y + normal.z * normal.z);
				normal.x /= L;
				normal.y /= L;
				normal.z /= L;
			break;
			default:
				printf("Object not implemented\n");
				break;
		}
	}
	else
		printf("El objeto es nulo\n");
	return normal;
}

// Devuelve una estructura que contiene la Intensidad y el Phong un punto
IP_st getIntensityAndPhong(Point3D point, Point3D direction, Point3D normal, Object *obj) {
	double I = 0.0, lon, Fatt, cos_alfa;
	double P = 0.0, multi_Kt;
	Light *light;
	Intersection *tmp_int, *tmp_int2;
	Point3D L, V, Temp, R;
	IP_st ret;
	IntersectionList int_list;

	light = luces.first;
	if(light)
		while(light) {
			L.x = light->location.x - point.x;
			L.y = light->location.y - point.y;
			L.z = light->location.z - point.z;
			lon = (double) sqrt(L.x*L.x + L.y*L.y + L.z*L.z);
			L.x /= lon;
			L.y /= lon;
			L.z /= lon;
			Fatt = 1 / (c1 + c2 * lon + c3 * lon * lon);
			cos_alfa =(double) (L.x * normal.x + L.y * normal.y + L.z * normal.z);
			// Para ver si hay sombra
			tmp_int = (int_list = getIntersections(point, L)).first;
			if(tmp_int) {
				if(nivel_transparencia) {
					multi_Kt = 1.0;
					while(tmp_int){
						multi_Kt *= tmp_int->obj->Kt;
						tmp_int = tmp_int->next;
					}
				}
				//printf("Multi Kt %.4f\n", multi_Kt);
				I += (obj->Ka * ia + multi_Kt * light->intensity * cos_alfa * obj->Kd) * Fatt;
			}
			else {
				I += (cos_alfa * light->intensity * obj->Kd + obj->Ka * ia) * Fatt;
				Temp.x = normal.x * cos_alfa;
				Temp.y = normal.y * cos_alfa;
				Temp.z = normal.z * cos_alfa;		// N * cos_alfa = Temp
				R.x = 2 * Temp.x - L.x;
				R.y = 2 * Temp.y - L.y;
				R.z = 2 * Temp.z - L.z;			// 2 * Temp - L = R
				V.x = -direction.x;
				V.y = -direction.y;
				V.z = -direction.z;				// -D = V
				P += pow((double)V.x * R.x + V.y * R.y + V.z * R.z, obj->Kn % 2 == 0? obj->Kn + 1 : obj->Kn) * light->intensity * obj->Ks * Fatt;
			}
			light = light->next;
		}
	else
		I += obj->Ka * ia;
	ret.intensity = MIN(I, 1.0);
	ret.phong = MIN(P, 1.0);
	ret.Fatt = Fatt;
	freeIntersectionList(int_list);
	return ret;
}

// ****************************** POLIGONOS ******************************
// Sabemos que al menos vienen tres puntos

// Verifica si los puntos de la lista pertenecen al plano
Polygon * makePolygon(Point3D center, PointList pl) {
	Polygon * poly = NULL;
	Plane plane;
	plane = getPlane(pl.first->point, pl.first->next->point, pl.first->next->next->point);	// Obtenemos el plano

	if(puntosEnPlano(plane, pl)) {	// Hacemos el pligono
		poly = (Polygon *) calloc(1, sizeof(Polygon));
		poly->plane = plane;
		poly->pl = pl;
		poly->ancla = center;
	}
	return poly;
}

/*Polygon * makePolygon(Point3D center, PointList pl) {
	Polygon * poly = NULL;
	Plane plane;
	plane = getPlane(pl.first->point, pl.first->next->point, pl.first->next->next->point);	// Obtenemos el plano
	//printf("Plano A = %.2f B = %.2f  C = %.2f D = %.2f\n", plane.A, plane.B, plane.C, plane.D);
	if(puntosEnPlano(plane, pl)) {	// Hacemos el pligono
		poly = (Polygon *) calloc(1, sizeof(Polygon));
		poly->plane = plane;
		poly->pl = pl;
		poly->ancla = center;
	}
	return poly;
}*/

// Verifica si los puntos de la lista pertenecen al plano
int puntosEnPlano(Plane plane, PointList pl) {
	PointNodeList *tmp;
	double d;
	Point3D max , min;

	tmp = pl.first;
	max = min = tmp->point;	//Asume que el primero es [X0,Y0,Z0]

	while(tmp) {
		if(fabs(plane.A * tmp->point.x + plane.B * tmp->point.y + plane.C * tmp->point.z  + plane.D) > EPSILON) {
			printf("Plano %.3f %.3f %.3f %.3f\n", plane.A, plane.B, plane.C, plane.D);
			printf("Punto %.3f %.3f %.3f\n", tmp->point.x, tmp->point.y, tmp->point.z );
			return FALSE;
		}

		//Averigua el [X0,Y0,Z0] para texturizar el poligono
		if (tmp->point.x < min.x)
			min.x = tmp->point.x;
		if (tmp->point.y < min.y)
			min.y = tmp->point.y;

		if (tmp->point.x > max.x)
			max.x  = tmp->point.x;
		if (tmp->point.y > max.y)
			max.y  = tmp->point.y;
		tmp = tmp->next;
	}

	//Calcula la altura del rectangulo que encierra al poligono
	pol_ancho = max.x - min.x;
	pol_alto  = max.y - min.y;

	//Guarda la posicion de la esquina
	pol_p0.x = min.x; pol_p0.y = min.y; pol_p0.z=0.0;
	return TRUE;
}

// Se reciben tre puntos, a partir de esos puntos, se obtiene el plano
// La ecuacion se encuentra normalizada
Plane getPlane(Point3D p1, Point3D p2, Point3D p3) {
	Point3D L1, L2;
	double L;
	Plane plane;

	L1.x = (double) (p2.x - p1.x);
	L1.y = (double) (p2.y - p1.y);
	L1.z = (double) (p2.z - p1.z);
	L2.x = (double) (p3.x - p1.x);
	L2.y = (double) (p3.y - p1.y);
	L2.z = (double) (p3.z - p1.z);
	plane.A = (double) L1.y * L2.z - L1.z * L2.y;
	plane.B = (double) L1.z * L2.x - L1.x * L2.z;
	plane.C = (double) L1.x * L2.y - L1.y * L2.x;
	plane.D = (double) -p1.x * plane.A - p1.y * plane.B - p1.z * plane.C;
	L = (double) sqrt(plane.A * plane.A + plane.B * plane.B + plane.C * plane.C);
	plane.A /= L;
	plane.B /= L;
	plane.C /= L;
	plane.D /= L;
	return plane;
}
/*
// Verifica si los puntos de la lista pertenecen al plano
int puntosEnPlano(Plane plane, PointList pl) {
	PointNodeList *tmp;
	double d;

	tmp = pl.first;
	while(tmp) {
		if(fabs(plane.A * tmp->point.x + plane.B * tmp->point.y + plane.C * tmp->point.z  + plane.D) > EPSILON) {
			//printf("Plano %.3f %.3f %.3f %.3f\n", plane.A, plane.B, plane.C, plane.D);
			//printf("Punto %.3f %.3f %.3f\n", tmp->point.x, tmp->point.y, tmp->point.z );
			return FALSE;
		}
		tmp = tmp->next;
	}
	return TRUE;
}*/

// Para convertir el poligono a 2D
P2DList addPoint2D(P2DList pl, double u, double v) {
	Point2D *tmp;

	tmp = (Point2D *) calloc(1, sizeof(Point2D));
	tmp->u = u;
	tmp->v = v;
	if(! pl.first)
		pl.first = pl.last = tmp;
	else
		pl.last = pl.last->next = tmp;
	return pl;
}

void free2DList(P2DList pl) {
	Point2D *tmp1, *tmp2;
	for(tmp1 = pl.first; tmp1; tmp1 = tmp2) {
		tmp2 = tmp1->next;
		free(tmp1);
	}
}

int intersectPolygon(Point3D point, Polygon *pol) {
	P2DList lista = {NULL, NULL};
	char resultado;
	int inter = 0;
	double x;
	PointNodeList *tmp;
	Point2D *tmp2D;

	if ((double) fabs(pol->plane.A) > (double) fabs(pol->plane.B) && (double) abs(pol->plane.A) > (double) fabs(pol->plane.C))
		resultado = MAX_X;
	else if((double) fabs(pol->plane.B) > (double) fabs(pol->plane.A) && (double) fabs(pol->plane.B) > (double) fabs(pol->plane.C))
		resultado = MAX_Y;
	else
		resultado = MAX_Z;
	tmp = pol->pl.first;
	while(tmp) {
		switch(resultado) {
			case MAX_X:
				//printf("X\n");
				lista = addPoint2D(lista, tmp->point.y - point.y, tmp->point.z - point.z);
				break;
			case MAX_Y:
				lista = addPoint2D(lista, tmp->point.x - point.x, tmp->point.z - point.z);
				break;
			case MAX_Z:
				lista = addPoint2D(lista, tmp->point.x - point.x, tmp->point.y - point.y);
				break;
		}
		tmp = tmp->next;
	}

	if (tmp2D = lista.first) {
		while(tmp2D->next) {
			if(((tmp2D->v > 0.0 && tmp2D->next->v < 0.0)
				|| (tmp2D->v < 0.0 && tmp2D->next->v > 0.0)) && (tmp2D->u > 0.0 && tmp2D->next->u > 0.0)) {
				inter++;
			}
			else if(((tmp2D->v > 0.0 && tmp2D->next->v < 0.0)
					|| (tmp2D->v < 0.0 && tmp2D->next->v > 0.0)) && (tmp2D->u > 0.0 || tmp2D->next->u > 0.0)) {
					x = tmp2D->u - (tmp2D->v * (tmp2D->next->u - tmp2D->u)) / (tmp2D->next->v - tmp2D->v);
					if(x >= 0.0)
						inter++;
				}
			tmp2D = tmp2D->next;
		}
		if(((lista.last->v > 0.0 && lista.first->v < 0.0)
			|| (lista.last->v < 0.0 && lista.first->v > 0.0)) && (lista.last->u > 0.0 && lista.first->u > 0.0)) {
			inter++;
		}
		else if(((lista.last->v > 0.0 && lista.first->v < 0.0)
				|| (lista.last->v < 0.0 && lista.first->v > 0.0)) && (lista.last->u > 0.0 || lista.first->u > 0.0)) {
				x = lista.last->u - (lista.last->v * (lista.first->u - lista.last->u)) / (lista.first->v - lista.last->v);
				if(x >= 0.0)
					inter++;
			}
	}
	free2DList(lista);
	if(inter % 2) return TRUE;
	else return FALSE;
}

// Agrega un string a la lista
StringList addString(StringList strl, char *str) {
	if(str) {
		if(! strl.first)
			strl.first = strl.last = (str_list *) calloc(1, sizeof(str_list));
		else
			strl.last = strl.last->next = (str_list *) calloc(1, sizeof(str_list));
		strl.last->str = (char *) strdup(str);
		strl.size++;
	}
	return strl;
}

StringList freeStringList(StringList strl) {
	str_list *tmp1, *tmp2;
	tmp1 = strl.first;
	while(tmp1) {
		tmp2 = tmp1->next;
		free(tmp1);
		tmp1 = tmp2;
	}
	strl.first = strl.last = NULL;
	strl.size = 0;
	return strl;
}

void printStringList(StringList strl) {
	str_list *tmp;
	
	tmp = strl.first;
	while(tmp) {
		printf("%s\n", tmp->str);
		tmp = tmp->next;
	}
}

/* Carga toda la imagen en una estructura del tipo Image */
/* Suponemos que el archivo es del formato avs */
/* image->buffer[i][j]  ** i es columna**   ****   ** j es fila** */
Textura * loadTextura(char *file) {
	FILE *handle;
	Textura *image = NULL;
	int i, j;
	AVSPixel pixel;
	AVSHeader header;
	char ret = TRUE;

	if ((handle = fopen(file, "r+")) && (fread(&header, sizeof(AVSHeader), 1, handle)) && esAVS(handle, header)) {
		FIX(header.ancho);
		FIX(header.alto);

		image = (Textura *) calloc(1, sizeof(Textura));
		image->width = header.ancho;
		image->height = header.alto;
		image->image = (Color **) calloc(image->width, sizeof(Color *));
		for (i = 0; i < image->width; i++)
			image->image[i] = (Color *) calloc(image->height, sizeof(Color));
		for (j = 0; j < image->height; j++)
			for (i = 0; i < image->width; i++) {
				fread(&pixel, sizeof(AVSPixel), 1, handle);
				image->image[i][j].r = (double) pixel.r / 255;
				image->image[i][j].g = (double) pixel.g / 255;
				image->image[i][j].b = (double) pixel.b / 255;
				//printf("R G B - %.2f %.2f %.2f\n", image->buffer[i][j].r, image->buffer[i][j].g,image->buffer[i][j].b);
			}
		fclose(handle);
	} else {
		if(handle) fclose(handle);
		printf("El archivo %s no se logro abrir.\n",file);
		//exit(1);
	}
	return image;
}

Mapa_Grises * loadGris(char *file) {
	FILE *handle;
	Mapa_Grises *image = NULL;
	int i, j;
	AVSPixel pixel;
	AVSHeader header;
	char ret = TRUE;

	if ((handle = fopen(file, "r+")) && fread(&header, sizeof(AVSHeader), 1, handle) && esAVS(handle, header)) {
		//fread(&header, sizeof(AVSHeader), 1, handle);
		//FIX(header.ancho);
		//FIX(header.alto);
		//printf("Posicion %i\n", ftell(handle));
		image = (Mapa_Grises *) calloc(1, sizeof(Mapa_Grises));
		image->width = header.ancho;
		image->height = header.alto;
		image->grises = (double **) calloc(image->width, sizeof(double *));
		for (i = 0; i < image->width; i++)
			image->grises[i] = (double *) calloc(image->height, sizeof(double));
		for (j = 0; j < image->height; j++)
			for (i = 0; i < image->width; i++) {
				fread(&pixel, sizeof(AVSPixel), 1, handle);
				image->grises[i][j] = (double) pixel.r / 255;
			}
		fclose(handle);
	} else {
		if(handle) fclose(handle);
		printf("El archivo %s no se logro abrir.\n",file);
		//exit(1);
	}
	return image;
}

// El alto y ancho viene sin arreglar.
int esAVS(FILE *f, AVSHeader h) {
	long old_offset;
	char res = FALSE;
	old_offset = ftell(f);
	FIX(h.ancho); FIX(h.alto);
	fseek(f, 0.0, SEEK_END);
	if (ftell(f) == ((int)(h.ancho * h.alto * 4 + 8)))
		res = TRUE;
	fseek(f, old_offset, SEEK_SET);
	return res;
}
