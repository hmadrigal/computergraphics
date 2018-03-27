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
	Superficie2 *spf;
	Cone *con;
	Disco *dis;

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
			case SUPERFICIE2:
				{
					Superficie2 t; //Almacena Temporalmente los valores {A..K]
					spf = (Superficie2 *) obj->object;
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
			case DISK:
				dis = (Disco *) obj->object;
				dis->center = translate(dis->center, tx, ty, tz);
				break;
			default:
				printf("Traslado de objeto no realizado\n");
				break;
		}
		trasladar_planos(tx, ty,  tz);
	}
	return obj;
}

//Rota una Superfice
Superficie2 * rotar_spf (Superficie2 *spf, double xu,double yu,double zu, double xv,double yv,double zv, double xn,double yn,double zn) {

	Superficie2 t; //Almacena Temporalmente los valores {A..K]
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

	return spf;
}

Object * rotate_x_object(Object *obj, double rx) {
	Sphere *sph;
	Cilinder *cil;
	Polygon *pol;
	PointNodeList *tmp;
	Superficie2 *spf;
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
			case SUPERFICIE2:
			{
				Point3D pu = {1.0 , 0.0 , 0.0}, pv = {0.0 , 1.0 , 0.0}, pn = {0.0 , 0.0 , 1.0}, ancla={0.0 , 0.0 , 0.0},np;
				spf = (Superficie2 *) obj->object;
				np = rotate_x(pu, ancla, rx);
				printf("Rx=%f\n",rx);
				printf("PU=[%f,%f,%f]\n",pu.x,pu.y,pu.z);
				printf("NP=[%f,%f,%f]\n",np.x,np.y,np.z);
				spf = rotar_spf (spf, np.x,np.y,np.z, pv.x,pv.y,pv.z,pn.x,pn.y,pn.z);
			}
			break;
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
	Superficie2 *spf;
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
			case SUPERFICIE2:
			{
				Point3D pu = {1.0 , 0.0 , 0.0}, pv = {0.0 , 1.0 , 0.0}, pn = {0.0 , 0.0 , 1.0}, ancla={0.0 , 0.0 , 0.0},np;
				spf = (Superficie2 *) obj->object;
				np = rotate_y(pv, ancla, ry);
				spf = rotar_spf (spf, pu.x,pu.y,pu.z, np.x,np.y,np.z,pn.x,pn.y,pn.z);
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
	Superficie2 *spf;
	Cone *con;
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
			case SUPERFICIE2:
			{
				Point3D pu = {1.0 , 0.0 , 0.0}, pv = {0.0 , 1.0 , 0.0}, pn = {0.0 , 0.0 , 1.0}, ancla={0.0 , 0.0 , 0.0},np;
				spf = (Superficie2 *) obj->object;
				np = rotate_z(pn, ancla, rz);
				spf = rotar_spf (spf, pu.x,pu.y,pu.z, pv.x,pv.y,pv.z,np.x,np.y,np.z);
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
