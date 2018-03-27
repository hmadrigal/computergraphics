#include "transf.h"

//Define cuanto debe ser el PAN-HIGH
double step_high_pan_x;
double step_high_pan_y;

//Escala el Window desde el centro => Hace un Zoom.
void zoom_window(double porq) {
	double xz, yz;

	//Calcula la escala
	xz =  (win.pmax.x - win.pmin.x) * porq;
	yz =  (win.pmax.y - win.pmin.y) * porq;

	//Hace un zoom
	win.pmin.x -= (double) xz/2.0;
	win.pmin.y -= (double) yz/2.0;
	win.pmax.x += (double) xz/2.0;
	win.pmax.y += (double) yz/2.0;
	
	//Indica que se debe redibujar
	drawBuffer();
	glutPostRedisplay();
}

//Translador del window=> Hace Pan
void pan_window(double tx, double ty) {
	win.pmin.x += tx; win.pmin.y += ty;
	win.pmax.x += tx; win.pmax.y += ty;

	//Indica que se debe redibujar
	drawBuffer();
	glutPostRedisplay();
}

//translate_at_point : T=>Trasladar
// [nx,ny] = [x,y]*T(tx,ty)
void translate_at_point (double tx,double ty,double x, double y, UniversalPoint2D *np) {
	np->x = x + tx;
	np->y = y + ty;
}

//Actualiza el STEP_PAN
void act_step_pan(void) {
	step_high_pan_x = (double)(PIXEL_HIGH_PAN) * (win.pmax.x - win.pmin.x);
	step_high_pan_y = (double)(PIXEL_HIGH_PAN) * (win.pmax.y - win.pmin.y);

	step_low_pan_x = (double)(PIXEL_LOW_PAN) * (win.pmax.x - win.pmin.x);
	step_low_pan_y = (double)(PIXEL_LOW_PAN) * (win.pmax.y - win.pmin.y);
}


/* El angulo debe estar en radianes */
UniversalPoint2D rotate(UniversalPoint2D p, double angle) {
	double cos_an, sin_an;
	UniversalPoint2D new;

	cos_an = cos(angle);
	sin_an = sin(angle);
	new.x = p.x * cos_an - p.y * sin_an - win.center.x * cos_an + win.center.y * sin_an + win.center.x;
	new.y = p.x * sin_an + p.y * cos_an -win.center.x * sin_an - win.center.y * cos_an + win.center.y;
	return new;
}

/* El angulo se recibe en grados */
void rotate_maps(int angle) {
	Mapa *first_roted, *last_roted;
	Mapa *tmp_map, *tmp_map1;
	Limite *tmp_lim;
	double angulo = (double) angle / RADIAN_VALUE;

	if (first_map || first_transformed_map) {
		if (first_transformed_map)
			tmp_map = first_transformed_map;
		else
			tmp_map = first_map;
		first_roted = last_roted = (Mapa *) calloc(1, sizeof(Mapa));
		while(tmp_map) {
			last_roted->color = tmp_map->color;
			last_roted->image = tmp_map->image;
			tmp_lim = tmp_map->first;	// Estamos seguros de que al menos tiene un Limite
			last_roted->first = last_roted->last = (Limite *) calloc(1, sizeof(Limite));
			while(tmp_lim) {
				last_roted->last->point = rotate(tmp_lim->point, angulo);
				if(tmp_lim = tmp_lim->next)
					last_roted->last = last_roted->last->next = (Limite *) calloc(1, sizeof(Limite));
			}
			if(tmp_map = tmp_map->next)
				last_roted = last_roted->next = (Mapa *) calloc(1, sizeof(Mapa));
		}
		if (tmp_map = first_transformed_map) {
			while(tmp_map) {
				tmp_map1 = tmp_map->next;
				free_tmp_map(tmp_map);
				tmp_map = tmp_map1;
			}
		}
		first_transformed_map = first_roted;
		last_transformed_map = last_roted;
	}
	
	drawBuffer();
	//Indica que se debe redibujar
	glutPostRedisplay();
}
