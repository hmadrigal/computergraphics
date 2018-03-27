#include "trans.h"

Point3D translate(Point3D p, double tx, double ty, double tz) {
	p.x += tx;
	p.y += ty;
	p.z += tz;
	return p;
}

Point3D scale(Point3D p, double sx, double sy, double sz) {
	p.x *= sx;
	p.y *= sy;
	p.z *= sz;
	return p;
}

Point3D rotate_x(Point3D p, Point3D ancla, double angle) {
	Point3D tmp, new;

	tmp = translate(p, -ancla.x, -ancla.y, -ancla.z);
	new.x = tmp.x;
	new.y = tmp.y * cos(angle) - tmp.z * sin(angle);
	new.z = tmp.y * sin(angle) + tmp.z * cos(angle);

	return translate(new, ancla.x, ancla.y, ancla.z);
}

Point3D rotate_y(Point3D p, Point3D ancla, double angle) {
	Point3D tmp, new;

	tmp = translate(p, -ancla.x, -ancla.y, -ancla.z);
	new.y = tmp.y;
	new.x = tmp.x * cos(angle) + tmp.z * sin(angle);
	new.z = tmp.z * cos(angle) - tmp.x * sin(angle);

	return translate(new, ancla.x, ancla.y, ancla.z);
}

Point3D rotate_z(Point3D p, Point3D ancla, double angle) {
	Point3D tmp, new;

	tmp = translate(p, -ancla.x, -ancla.y, -ancla.z);
	new.z = tmp.z;
	new.x = tmp.x * cos(angle) - tmp.y * sin(angle);
	new.y = tmp.x * sin(angle) + tmp.y * cos(angle);

	return translate(new, ancla.x, ancla.y, ancla.z);
}

Object * translate_object(Object *obj, double tx, double ty, double tz) {
	Sphere *sph;
	Cilinder *cil;
	Polygon *pol;
	PointNodeList *tmp;
	Cone *con;
	Disco *dis;
	Cuadratica *cuad;

	if(obj) {
		switch(obj->tipo) {
			case SPHERE: {
				Point3D  p1,p2;
				sph = (Sphere *) obj->object;
				sph->center = translate(sph->center, tx, ty, tz);
				p1 = translate(sph->north, tx, ty, tz);
				p2 = translate(sph->greenwich, tx, ty, tz);
				sph->plane = getPlane(sph->center, p1, p2);
				}break;
			case CONE: {
				Point3D newdir, newgreen;
				con = (Cone *) obj->object;
				con->center = translate(con->center, tx, ty, tz);
				newdir = translate(con->direction.direction, tx, ty, tz);
				newgreen = translate(con->greenwich, tx, ty, tz);
				con->plane = getPlane(con->center, newdir, newgreen);
				} break;
			case CILINDER: {
				Point3D newdir, newgreen;
				cil = (Cilinder *) obj->object;
				cil->center = translate(cil->center, tx, ty, tz);
				newdir = translate(cil->direction.direction, tx, ty, tz);
				newgreen = translate(cil->greenwich, tx, ty, tz);
				cil->plane = getPlane(cil->center, newdir, newgreen);
				}
				break;
			case POLYGON:
				printf("Traslado %.3f %.3f %.3f\n", tx, ty, tz);
				pol = (Polygon *) obj->object;
				pol->ancla = translate(pol->ancla, tx, ty, tz);
				tmp = pol->pl.first;
				while(tmp) {
					tmp->point = translate(tmp->point, tx, ty, tz);
					tmp = tmp->next;
				}
				pol->p0 = translate(pol->p0, tx, ty, tz);
				pol->plane = getPlane(pol->pl.first->point, pol->pl.first->next->point, pol->pl.first->next->next->point);
				printf("Sali de trasladar\n");
				break;
			case DISK:
				dis = (Disco *) obj->object;
				dis->center = translate(dis->center, tx, ty, tz);
				break;
			/*case QUADRIC: {
				Cuadratica tmp;
				cuad = (Cuadratica *) obj->object;
				tmp = *cuad;
				cuad->A = tmp.A - 2 * tmp.G * tx + tmp.K * tx * tx;
				cuad->B = tmp.B - 2 * tmp.H * ty + tmp.K * ty * ty;
				cuad->C = tmp.C - 2 * tmp.J * tz + tmp.K * tz * tz;
				cuad->D = tmp.D - tmp.H * tx - tmp.G * ty + tmp.K * tx * ty;
				cuad->E = tmp.E - tmp.J * ty - tmp.H * tz + tmp.K * ty * tz;
				cuad->F = tmp.F - tmp.J * tx - tmp.G * tz + tmp.K * tx * tz;
				cuad->G = tmp.G - tmp.K * tx;
				cuad->H = tmp.H - tmp.K * ty;
				cuad->J = tmp.J - tmp.K * tz;
				// La k queda igual
				ultimo_centro = translate(ultimo_centro, tx, ty, tz);
				}
				break;*/
			case QUADRIC: {
				Cuadratica tmp;
				cuad = (Cuadratica *) obj->object;
				tmp = *cuad;
				cuad->G = -(tx * tmp.A + ty * tmp.D + tz * tmp.F) + tmp.G;
				cuad->H = -(tx * tmp.D + ty * tmp.B + tz * tmp.E) + tmp.H;
				cuad->J = -(tx * tmp.F + ty * tmp.E + tz * tmp.C) + tmp.J;
				cuad->K = -tx * cuad->G + -ty * cuad->H + -tz * cuad->J + -(tx * tmp.G + ty * tmp.H + tz * tmp.F) + tmp.K;
				// La k queda igual
				ultimo_centro = translate(ultimo_centro, tx, ty, tz);
				}
				break;
			default:
				printf("Traslado de objeto no realizado\n");
				break;
		}
		trasladar_planos(tx, ty,  tz);
	}
	return obj;
}

Object * scale_object(Object *obj, double sx, double sy, double sz) {
	if(obj) {
		switch(obj->tipo) {
			case QUADRIC: {
				Cuadratica * cuad;
				cuad = (Cuadratica *) obj->object;
				cuad->A /= sx * sx;
				cuad->B /= sy * sy;
				cuad->C /= sz * sz;
				cuad->D /= sx * sy;
				cuad->E /= sy * sz;
				cuad->F /= sx * sz;
				cuad->G /= sx;
				cuad->H /= sy;
				cuad->J /= sz;
				// La k queda igual
				}
				break;
		}
	}
	return obj;
}

Object * rotate_x_object(Object *obj, double rx) {
	Sphere *sph;
	Cilinder *cil;
	Polygon *pol;
	PointNodeList *tmp;
	Cone *con;

	if(obj) {
		switch(obj->tipo) {
			case SPHERE:
				sph = (Sphere *) obj->object;
				sph->north = rotate_x(sph->north, sph->center, rx);
				sph->greenwich = rotate_x(sph->greenwich, sph->center, rx);
				sph->plane = getPlane(sph->center, sph->north, sph->greenwich);

				if(puntos_planos)
					rotar_planos_x(sph->center, rx);
				break;
			case CONE:
				con = (Cone *) obj->object;
				con->direction.direction = rotate_x(con->direction.direction, con->center, rx);
				con->greenwich = rotate_x(con->greenwich, con->center, rx);
				con->plane = getPlane(con->center, con->direction.direction, con->greenwich);
				if(puntos_planos)
					rotar_planos_x(con->center, rx);
				break;
			case CILINDER:
				cil = (Cilinder *) obj->object;
				cil->direction.direction = rotate_x(cil->direction.direction, cil->center, rx);
				cil->greenwich = rotate_x(cil->greenwich, cil->center, rx);
				cil->plane = getPlane(cil->center, cil->direction.direction, cil->greenwich);
				if(puntos_planos)
					rotar_planos_x(cil->center, rx);
				break;
			case POLYGON:
				pol = (Polygon *) obj->object;
				tmp = pol->pl.first;
				while(tmp) {
					//tmp->point = rotate_x(tmp->point, ultimo_centro, rx);
					tmp->point = rotate_x(tmp->point, pol->ancla, rx);
					tmp = tmp->next;
				}
				if(puntos_planos)
					rotar_planos_x(pol->ancla, rx);
				//pol->U = rotate_x(pol->U, ultimo_centro, rx);
				//pol->V = rotate_x(pol->V, ultimo_centro, rx);
				pol->U = rotate_x(pol->U, pol->ancla, rx);
				pol->V = rotate_x(pol->V, pol->ancla, rx);
				pol->p0 = rotate_x(pol->p0, pol->ancla, rx);
				pol->plane = getPlane(pol->pl.first->point, pol->pl.first->next->point, pol->pl.first->next->next->point);
				break;
			/*case QUADRIC:{
				Cuadratica tmp, *cuad;
				double seno, coseno;
				cuad = (Cuadratica *) obj->object;
				tmp = *cuad;
				seno = sin(rx);
				coseno = cos(rx);

				cuad->A = coseno * (coseno * tmp.A + seno * tmp.F) + seno * (coseno * tmp.F + seno * tmp.C);
				//B  queda igual
				cuad->C = -seno * (-seno * tmp.A + coseno * tmp.F) +  coseno * (-seno *  tmp.F + coseno * tmp.C);
				cuad->D = coseno *  tmp.D + seno *  tmp.E;
				cuad->E = -seno * tmp.D + coseno * tmp.E;
				cuad->F = coseno * (-seno * tmp.A +  coseno * tmp.F) + seno * (-seno * tmp.F + coseno * tmp.C);
				cuad->G = coseno * tmp.G + seno * tmp.J;
				//H  queda igual
				cuad->J = -seno * tmp.G +  coseno * tmp.J;
				//K  queda igal
				if(puntos_planos)
					rotar_planos_x(ultimo_centro, rx);
				}
				break;*/
			case QUADRIC:{
				Cuadratica tmp, *cuad;
				double seno, coseno;
				cuad = (Cuadratica *) obj->object;
				tmp = *cuad;
				seno = sin(rx);
				coseno = cos(rx);

				//cuad->A =
				cuad->B = coseno * (coseno * tmp.B + -seno * tmp.E) + -seno * (coseno * tmp.E + -seno*tmp.C);
				cuad->C = seno * (seno * tmp.B + coseno * tmp.E) + coseno * (seno * tmp.E + coseno * tmp.C);
				cuad->D = coseno * tmp.D + -seno * tmp.F;
				cuad->E = coseno * (seno * tmp.B + coseno * tmp.E) + -seno * (seno * tmp.E + coseno * tmp.C);
				cuad->F = seno * tmp.D + coseno * tmp.F;
				//cuad->G =
				cuad->H = coseno * tmp.H +  -seno * tmp.J;
				cuad->J = seno * tmp.H + coseno * tmp.J;
				//cuad->K =
				}
			default:
				printf("Rotacion de objeto no realizado\n");
				break;
		}
	}
	return obj;
}

Object * rotate_y_object(Object *obj, double ry) {
	Sphere *sph;
	Cilinder *cil;
	Polygon *pol;
	PointNodeList *tmp;
	Cone *con;

	if(obj) {
		switch(obj->tipo) {
			case SPHERE:
				sph = (Sphere *) obj->object;
				sph->north = rotate_y(sph->north, sph->center, ry);
				sph->greenwich = rotate_y(sph->greenwich, sph->center, ry);
				sph->plane = getPlane(sph->center, sph->north, sph->greenwich);
				if(puntos_planos)
					rotar_planos_y(sph->center, ry);
				break;
			case CONE:
				con = (Cone *) obj->object;
				con->direction.direction = rotate_y(con->direction.direction, con->center, ry);
				con->greenwich = rotate_y(con->greenwich, con->center, ry);
				con->plane = getPlane(con->center, con->direction.direction, con->greenwich);
				if(puntos_planos)
					rotar_planos_y(con->center, ry);
				break;
			case CILINDER:
				cil = (Cilinder *) obj->object;
				cil->direction.direction = rotate_y(cil->direction.direction, cil->center, ry);
				cil->greenwich = rotate_y(cil->greenwich, cil->center, ry);
				cil->plane = getPlane(cil->center, cil->direction.direction, cil->greenwich);
				printf("Rotamos el cilindro\n");
				if(puntos_planos)
					rotar_planos_y(cil->center, ry);
				break;
			case POLYGON:
				pol = (Polygon *) obj->object;
				tmp = pol->pl.first;
				while(tmp) {
					//tmp->point = rotate_y(tmp->point, ultimo_centro, ry);
					tmp->point = rotate_y(tmp->point, pol->ancla, ry);
					tmp = tmp->next;
				}
				if(puntos_planos)
					rotar_planos_y(pol->ancla, ry);
				//pol->U = rotate_y(pol->U, ultimo_centro, ry);
				//pol->V = rotate_y(pol->V, ultimo_centro, ry);
				pol->U = rotate_y(pol->U, pol->ancla, ry);
				pol->V = rotate_y(pol->V, pol->ancla, ry);
				pol->p0 = rotate_y(pol->p0, pol->ancla, ry);
				pol->plane = getPlane(pol->pl.first->point, pol->pl.first->next->point, pol->pl.first->next->next->point);
				break;
			case QUADRIC:{
				Cuadratica tmp, *cuad;
				double seno, coseno;
				cuad = (Cuadratica *) obj->object;
				tmp = *cuad;
				seno = sin(ry);
				coseno = cos(ry);
				cuad->A = coseno * (coseno*tmp.A + seno*tmp.F) + seno * (coseno * tmp.F + seno * tmp.C);
				//B  queda igual
				cuad->C = -seno * (-seno*tmp.A + coseno*tmp.F) + coseno * (-seno*tmp.F + coseno * tmp.C);
				cuad->D = coseno * tmp.D + seno * tmp.E;
				cuad->E = -seno *tmp.D + coseno *tmp.E;
				cuad->F = -seno * (coseno * tmp.A + seno * tmp.F) + coseno * (coseno * tmp.F + seno * tmp.C);
				cuad->G = coseno * tmp.G + seno * tmp.J;
				//H queda igual
				cuad->J = -seno * tmp.G + coseno *  tmp.J;
				//K queda igual
				if(puntos_planos)
					rotar_planos_y(ultimo_centro, ry);
				}
				break;
			default:
				printf("Rotacion de objeto no realizado\n");
				break;
		}
	}
	return obj;
}

Object * rotate_z_object(Object *obj, double rz) {
	Sphere *sph;
	Cilinder *cil;
	Polygon *pol;
	PointNodeList *tmp;
	Cone *con;
	Cuadratica *cuad;

	if(obj) {
		switch(obj->tipo) {
			case SPHERE:
				sph = (Sphere *) obj->object;
				sph->north = rotate_z(sph->north, sph->center, rz);
				sph->greenwich = rotate_z(sph->greenwich, sph->center, rz);
				sph->plane = getPlane(sph->center, sph->north, sph->greenwich);
				if(puntos_planos)
					rotar_planos_z(sph->center, rz);
				break;
			case CONE:
				con = (Cone *) obj->object;
				con->direction.direction = rotate_z(con->direction.direction, con->center, rz);
				con->greenwich = rotate_z(con->greenwich, con->center, rz);
				con->plane = getPlane(con->center, con->direction.direction, con->greenwich);
				if(puntos_planos)
					rotar_planos_z(con->center, rz);
				break;
			break;
			case CILINDER:
				cil = (Cilinder *) obj->object;
				cil->direction.direction = rotate_z(cil->direction.direction, cil->center, rz);
				//cil->north = rotate_z(cil->north, cil->center, rz);
				cil->greenwich = rotate_z(cil->greenwich, cil->center, rz);
				cil->plane = getPlane(cil->center, cil->direction.direction, cil->greenwich);
				if(puntos_planos)
					rotar_planos_z(cil->center, rz);
				break;
			case POLYGON:
				pol = (Polygon *) obj->object;
				tmp = pol->pl.first;
				while(tmp) {
					//tmp->point = rotate_z(tmp->point, ultimo_centro, rz);
					tmp->point = rotate_z(tmp->point, pol->ancla, rz);
					tmp = tmp->next;
				}
				if(puntos_planos)
					rotar_planos_z(pol->ancla, rz);
				//pol->U = rotate_z(pol->U, ultimo_centro, rz);
				//pol->V = rotate_z(pol->V, ultimo_centro, rz);
				pol->U = rotate_z(pol->U, pol->ancla, rz);
				pol->V = rotate_z(pol->V, pol->ancla, rz);
				pol->p0 = rotate_z(pol->p0, pol->ancla, rz);
				pol->plane = getPlane(pol->pl.first->point, pol->pl.first->next->point, pol->pl.first->next->next->point);
				break;
			case QUADRIC:{
				Cuadratica tmp;
				double seno, coseno;
				cuad = (Cuadratica *) obj->object;
				tmp = *cuad;
				seno = sin(rz);
				coseno = cos(rz);
				cuad->A = (tmp.A * coseno - tmp.D * seno) * coseno - (tmp.D * coseno - tmp.B * seno) * seno;
				cuad->B = (tmp.A * seno + tmp.D * coseno) * seno + (tmp.D * coseno + tmp.B * seno) * coseno;
				// C queda igual
				cuad->D = (tmp.A * coseno - tmp.D * seno) * seno + (tmp.D * coseno - tmp.B * seno) * coseno;
				cuad->E = tmp.F * seno + tmp.E * coseno;
				cuad->F = tmp.F * coseno - tmp.E * seno;
				cuad->G = tmp.G * coseno - tmp.H * seno;
				cuad->H = tmp.G * seno + tmp.H * coseno;
				// J y K quedan igual
				if(puntos_planos)
					rotar_planos_z(ultimo_centro, rz);
				printf("Rotamos Cuadratica en Z\n");
				printf("A --- A = %.4f B = %.4f C = %.4f D = %.4f E = %.7f F = %.4f G = %.4f H = %.4f J = %.4f K = %.4f\n",
					tmp.A, tmp.B, tmp.C, tmp.D, tmp.E, tmp.F, tmp.G, tmp.H, tmp.J, tmp.K );
				printf("D --- A = %.4f B = %.4f C = %.4f D = %.4f E = %.7f F = %.4f G = %.4f H = %.4f J = %.4f K = %.4f\n",
					cuad->A, cuad->B, cuad->C, cuad->D, cuad->E, cuad->F, cuad->G, cuad->H, cuad->J, cuad->K);
				}
				break;
			default:
				printf("Rotacion de objeto no realizado\n");
				break;
		}
	}
	return obj;
}

// Funciones que pertenecen al Parser
void rotar_disco_x(double angle) {
	double L;
	pdisk1 = rotate_x(pdisk1, ultimo_centro, angle);
	pdisk2 = rotate_x(pdisk2, ultimo_centro, angle);
	pdisk3 = rotate_x(pdisk3, ultimo_centro, angle);
	Udisk = rotate_x(Udisk, ultimo_centro, angle);
	Vdisk = rotate_x(Vdisk, ultimo_centro, angle);
	P0disk = rotate_x(P0disk, ultimo_centro, angle);
	L = sqrt(Udisk.x * Udisk.x + Udisk.y * Udisk.y + Udisk.z * Udisk.z);
	rotar_planos_x(ultimo_centro, angle);
}

void rotar_disco_y(double angle) {
	double L;
	pdisk1 = rotate_y(pdisk1, ultimo_centro, angle);
	pdisk2 = rotate_y(pdisk2, ultimo_centro, angle);
	pdisk3 = rotate_y(pdisk3, ultimo_centro, angle);
	Udisk = rotate_y(Udisk, ultimo_centro, angle);
	Vdisk = rotate_y(Vdisk, ultimo_centro, angle);
	P0disk = rotate_y(P0disk, ultimo_centro, angle);
	rotar_planos_y(ultimo_centro, angle);
}

void rotar_disco_z(double angle) {
	double L;
	pdisk1 = rotate_z(pdisk1, ultimo_centro, angle);
	pdisk2 = rotate_z(pdisk2, ultimo_centro, angle);
	pdisk3 = rotate_z(pdisk3, ultimo_centro, angle);
	Udisk = rotate_z(Udisk, ultimo_centro, angle);
	Vdisk = rotate_z(Vdisk, ultimo_centro, angle);
	P0disk = rotate_z(P0disk, ultimo_centro, angle);
	rotar_planos_z(ultimo_centro, angle);
}

void trasladar_disco(double tx, double ty, double tz) {
	pdisk1 = translate(pdisk1, tx, ty, tz);
	pdisk2 = translate(pdisk2, tx, ty, tz);
	pdisk3 = translate(pdisk3, tx, ty, tz);
	ultimo_centro = translate(ultimo_centro, tx, ty, tz);
	P0disk = translate(P0disk, tx, ty, tz);
	trasladar_planos(tx, ty, tz);
}

void rotar_planos_x(Point3D centro, double angle) {
	lista_puntos_planos *tmp;
	if(tmp = puntos_planos) {
		while(tmp) {
			tmp->p1 = rotate_x(tmp->p1, centro, angle);
			tmp->p2 = rotate_x(tmp->p2, centro, angle);
			tmp->p3 = rotate_x(tmp->p3, centro, angle);
			tmp = tmp->next;
		}
	}
}

void rotar_planos_y(Point3D centro, double angle) {
	lista_puntos_planos *tmp;
	if(tmp = puntos_planos) {
		while(tmp) {
			tmp->p1 = rotate_y(tmp->p1, centro, angle);
			tmp->p2 = rotate_y(tmp->p2, centro, angle);
			tmp->p3 = rotate_y(tmp->p3, centro, angle);
			tmp = tmp->next;
		}
	}
}

void rotar_planos_z(Point3D centro, double angle) {
	lista_puntos_planos *tmp;
	if(tmp = puntos_planos) {
		while(tmp) {
			tmp->p1 = rotate_z(tmp->p1, centro, angle);
			tmp->p2 = rotate_z(tmp->p2, centro, angle);
			tmp->p3 = rotate_z(tmp->p3, centro, angle);
			tmp = tmp->next;
		}
	}
}

void trasladar_planos(double tx, double ty, double tz) {
	lista_puntos_planos *tmp;
	if(tmp = puntos_planos) {
		while(tmp) {
			//printf("Trasladamos Plano %.3f %.3f %.3f\n", tx, ty, tz);
			tmp->p1 = translate(tmp->p1, tx, ty, tz);
			tmp->p2 = translate(tmp->p2, tx, ty, tz);
			tmp->p3 = translate(tmp->p3, tx, ty, tz);
			tmp = tmp->next;
		}
	}
	//printf("Sale de trasladar puntos\n");
}
// Funciones que pertenecen al Parser
