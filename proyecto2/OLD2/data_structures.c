#include <stdlib.h>
#include <math.h>
#include "data_structures.h"

char phong = TRUE, lights = TRUE;

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

	tmp = ol.first;
	while(tmp) {
		switch(tmp->tipo) {
			case SPHERE:
				sph = (Sphere *) tmp->object;
				printf("Sphere\n");
				printf("R = %.4f G = %.4f B = %.4f\n", tmp->color.r, tmp->color.g, tmp->color.b);
				printf("Kd = %.4f Ka = %.4f Ks = %.4f Kn = %i\n", tmp->Kd, tmp->Ka, tmp->Ks, tmp->Kn);
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
				printf("Radius: %.3f\n", con->radius);
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
				printPoints(pol->pl);
				printf("A = %.4f B = %.4f C = %.4f D = %.4f\n", pol->plane.A, pol->plane.B, pol->plane.C, pol->plane.D);
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
			while(t > tmp->next->t)
				tmp = tmp->next;
			inter->next = tmp->next;
			tmp->next = inter;
		}
	}
	return il;
}

void printIntersectionList(IntersectionList il) {
	Intersection * tmp = il.first;
	while(tmp) {
		printf("---- %.4f %i\n", (double) tmp->t, tmp->obj->Kn);
		tmp = tmp->next;
	}
}

// Calcula las intersecciones de los objetos con el rayo definido.
IntersectionList getIntersections(Point3D origin, Point3D direction) {
	double t_temp, a, b, c, disc;
	Object *tmp;
	Sphere *sph;
	Cilinder *cil;
	IntersectionList inter_list = {NULL, NULL};

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
				if(abs(disc) < EPSILON /*! disc*/) {	// Hay una solucion
					t_temp = (double) -b / 2;	// Puede haber problemas en esto *****
					inter_list = addIntersection(inter_list, t_temp, tmp);
				}
				else if (disc > 0) {			// Hay dos soluciones
					t_temp = (double) (-b + sqrt(disc)) / 2;
					inter_list = addIntersection(inter_list, t_temp, tmp);
					t_temp = (double) (-b - sqrt(disc)) / 2;
					inter_list = addIntersection(inter_list, t_temp, tmp);
				}
				break;
			case CONE:	// Codigo del calculo de interseccion para el Cono
			
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
				if(/*abs(disc) < EPSILON*/ ! disc) {	// Hay una solucion
					t_temp = (double) -b / 2;	// Puede haber problemas en esto *****
					inter_list = addIntersection(inter_list, t_temp, tmp);
				}
				else if (disc > 0) {			// Hay dos soluciones
					t_temp = (double) (-b + sqrt(disc)) / 2;
					inter_list = addIntersection(inter_list, t_temp, tmp);
					t_temp = (double) (-b - sqrt(disc)) / 2;
					inter_list = addIntersection(inter_list, t_temp, tmp);
				}
				break;
			case POLYGON:	// Codigo del calculo de interseccion para el poligono
				break;
			default:
				printf("Objeto sin ecuacion de intersecciones\n");
				break;
		}
		tmp = tmp->next;
	}
	return inter_list;
}

// Obtiene el color que le toca al punto definido en este rayo.
Color getColor(Point3D origin, Point3D direction) {
	IntersectionList inter_list;
	Color color = background;
	Intersection * tmp;
	Point3D pi, normal;
	double dotProduct, I, P;

	inter_list = getIntersections(origin, direction);
	if(tmp = inter_list.first) {
		while(tmp) {
			if(tmp->t > EPSILON) {
				pi.x = origin.x + tmp->t * direction.x;
				pi.y = origin.y + tmp->t * direction.y;
				pi.z = origin.z + tmp->t * direction.z;
				color = tmp->obj->color;
				normal = getNormal(pi,  tmp->obj);
				dotProduct = normal.x * direction.x + normal.z * direction.z + normal.y * direction.y;
				if(acos(dotProduct) * RADIAN < 90.0 - EPSILON) {	// Hay que arreglar la normal
					//printf("Alfa %.6f\n", acos(dotProduct) * RADIAN);
					normal.x *= -1;
					normal.y *= -1;
					normal.z *= -1;
				}
				I = getIntensity(pi, normal, tmp->obj);
				P = getPhong(pi, direction, normal, tmp->obj);
				if (! phong)
					P = 0.0;
				if (! lights)
					I = 1.0;
				color.r = MIN(color.r * I + P, 1.0);
				color.g = MIN(color.g * I + P, 1.0);
				color.b = MIN(color.b * I + P, 1.0);
				break;
			}
			tmp = tmp->next;
		}
	}
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
	Point3D normal = {0.0, 0.0, 0.0}, Pm;
	double L, tmp;
	Sphere *sph;
	Cilinder *cil;

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
				break;
			case CILINDER:
				cil = (Cilinder *) obj->object;
				tmp = 	(p.x - cil->center.x) * cil->direction.direction.x
						+ (p.y - cil->center.y) * cil->direction.direction.y
						+ (p.z - cil->center.z) * cil->direction.direction.z;
				Pm.x = cil->center.x + tmp * cil->direction.direction.x;
				Pm.y = cil->center.y + tmp * cil->direction.direction.y;
				Pm.z = cil->center.z + tmp * cil->direction.direction.z;
				normal.x = p.x - Pm.x;
				normal.y = p.y - Pm.y;
				normal.z = p.z - Pm.z;
				L = sqrt(normal.x * normal.x + normal.y * normal.y + normal.z * normal.z);
				normal.x /= L;
				normal.y /= L;
				normal.z /= L;
				break;
			case POLYGON:	// Donde se agrega el calculo de la normal para el plano.
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

// Calcula la intensidad de luz que debe recibir un punto
// Recibe el punto, la normal en ese punto, y el objeto
// Por el momento no se toma en cuenta las sombras
double getIntensity(Point3D point, Point3D normal, Object *obj) {
	double I = 0.0, lon, Fatt, cos_alfa;
	Point3D L;
	Light *light;
	IntersectionList inter_list;

	light = luces.first;
	while(light) {
		L.x = light->location.x - point.x;
		L.y = light->location.y - point.y;
		L.z = light->location.z - point.z;
		lon = (double) sqrt(L.x*L.x + L.y*L.y + L.z*L.z);
		L.x /= lon;
		L.y /= lon;
		L.z /= lon;
		Fatt = 1 / (c1 + c2 * lon + c3 * lon * lon);
		// Por aqui se verifica si hay sombra, no se como.
		cos_alfa =(double) (L.x * normal.x + L.y * normal.y + L.z * normal.z);
		I += cos_alfa * light->intensity * obj->Kd * Fatt;
		light = light->next;
	}

	I = MIN(I, 1.0);
	return I;
}

// Calcula el Phong para un punto
// Recibe el punto, la direccion desde el ojo, la normal en ese punto y el objeto al que pertenece
double getPhong(Point3D point, Point3D direction, Point3D normal, Object *obj) {
	Point3D L, V, Temp, R;
	double P = 0.0, lon, Fatt, cos_alfa, cos_beta;
	Light *light;

	light = luces.first;
	while(light) {
		L.x = light->location.x - point.x;
		L.y = light->location.y - point.y;
		L.z = light->location.z - point.z;
		lon = (double) sqrt(L.x*L.x + L.y*L.y + L.z*L.z);
		L.x /= lon;
		L.y /= lon;
		L.z /= lon;
		// Tenemos el L calculado
		Fatt = 1 / (c1 + c2 * lon + c3 * lon * lon);	// Calculamos el Fatt
		cos_alfa =(double) (L.x * normal.x + L.y * normal.y + L.z * normal.z);	// N punto L = cos_alfa
		Temp.x = normal.x * cos_alfa;
		Temp.y = normal.y * cos_alfa;
		Temp.z = normal.z * cos_alfa;		// N * cos_alfa = Temp
		R.x = 2 * Temp.x - L.x;
		R.y = 2 * Temp.y - L.y;
		R.z = 2 * Temp.z - L.z;			// 2 * Temp - L = R
		V.x = -1 * direction.x;
		V.y = -1 * direction.y;
		V.z = -1 * direction.z;			// -D = V
		P += pow((double)V.x * R.x + V.y * R.y + V.z * R.z, obj->Kn % 2 == 0? obj->Kn + 1 : obj->Kn) * light->intensity * obj->Ks * Fatt;;
		light = light->next;
	}

	P = MIN(P, 1.0);
	return P;
}
