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
			case SPHERE:
				sph = (Sphere *) obj->object;
				sph->center = translate(sph->center, tx, ty, tz);
				break;
			case CONE:
				con = (Cilinder *) obj->object;
				con->center = translate(con->center, tx, ty, tz);
				break;
			case CILINDER:
				cil = (Cilinder *) obj->object;
				cil->center = translate(cil->center, tx, ty, tz);
				//cil->direction.direction = translate(cil->direction.direction, tx, ty, tz);
				break;
			case POLYGON:
				pol = (Polygon *) obj->object;
				pol->ancla = translate(pol->ancla, tx, ty, tz);
				tmp = pol->pl.first;
				while(tmp) {
					tmp->point = translate(tmp->point, tx, ty, tz);
					tmp = tmp->next;
				}
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
				break;
			case CONE:
				con = (Cone *) obj->object;
				con->direction.direction = rotate_x(con->direction.direction, con->center, rx);
				break;
			case CILINDER:
				cil = (Cilinder *) obj->object;
				cil->direction.direction = rotate_x(cil->direction.direction, cil->center, rx);
				break;
			case POLYGON:
				pol = (Polygon *) obj->object;
				tmp = pol->pl.first;
				while(tmp) {
					tmp->point = rotate_x(tmp->point, pol->ancla, rx);
					tmp = tmp->next;
				}
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
				break;
			case CONE:
				con = (Cone *) obj->object;
				con->direction.direction = rotate_y(con->direction.direction, con->center, ry);
				break;
			case CILINDER:
				cil = (Cilinder *) obj->object;
				cil->direction.direction = rotate_y(cil->direction.direction, cil->center, ry);
				break;
			case POLYGON:
				pol = (Polygon *) obj->object;
				tmp = pol->pl.first;
				while(tmp) {
					tmp->point = rotate_y(tmp->point, pol->ancla, ry);
					tmp = tmp->next;
				}
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
			break;
			case CONE:
				con = (Cone *) obj->object;
				con->direction.direction = rotate_z(con->direction.direction, con->center, rz);
				break;
			break;
			case CILINDER:
				cil = (Cilinder *) obj->object;
				cil->direction.direction = rotate_z(cil->direction.direction, cil->center, rz);
				break;
			case POLYGON:
				pol = (Polygon *) obj->object;
				tmp = pol->pl.first;
				while(tmp) {
					tmp->point = rotate_z(tmp->point, pol->ancla, rz);
					tmp = tmp->next;
				}
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
