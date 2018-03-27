/*
Archivo: univeresal_data.c
*/

#include "universal_data.h"

Window win;
Mapa *first_map = NULL, *last_map = NULL;
Mapa *first_transformed_map = NULL, *last_transformed_map = NULL;
Mapa *first_clipped_map = NULL, *last_clipped_map = NULL;
char error = FALSE;

/* Funciones */
UniversalPoint2D newUniversalPoint2D(double x, double y) {
	UniversalPoint2D tmp;

	tmp.x = x;
	tmp.y = y;
	return tmp;
}

/* Fija el tamano del Window */
void setWindow(double x0, double y0, double x1, double y1) {
	if (x0 <= x1 && y0 <= y1) {
		win.pmin.x = x0;
		win.pmin.y = y0;
		win.pmax.x = x1;
		win.pmax.y = y1;
	}
	else if (x0 > x1 && y0 <= y1) {
		win.pmin.x = x1;
		win.pmin.y = y0;
		win.pmax.x = x0;
		win.pmax.y = y1;
	}
	else if (x0 <= x1 && y0 > y1) {
		win.pmin.x = x0;
		win.pmin.y = y1;
		win.pmax.x = x1;
		win.pmax.y = y0;
	}
	else {
		win.pmin.x = x1;
		win.pmin.y = y1;
		win.pmax.x = x0;
		win.pmax.y = y0;
	}
}

/* Le asigna memoria a lst_map */
void start_territory() {
	if (! first_map)
		first_map = last_map = (Mapa *) calloc(1, sizeof(Mapa));
	else
		last_map = last_map->next = (Mapa *) calloc(1, sizeof(Mapa));
	last_map->first = last_map->last = NULL;
	last_map->next = NULL;
}

/* Fija el color del mapa (last_map) */
void set_color_map(double r, double g, double b) {
	last_map->color.r = r;
	last_map->color.g = g;
	last_map->color.b = b;
}

/* Fija el nombre de la textura*/
void set_texture(char *str) {
	//strcpy(last_map->file, str);
	if (! loadImage(str, &(last_map->image)))
		printf("Problemas cargando imagen %s\n", str);
}

/* Agrega un Limite al mapa (last_map) */
void addLimit(double x, double y) {
	if (! last_map->first)
		last_map->first = last_map->last = (Limite *) calloc(1, sizeof(Limite));
	else
		last_map->last = last_map->last->next = (Limite *) calloc(1, sizeof(Limite));
	last_map->last->point.x = x;
	last_map->last->point.y = y;
	last_map->last->next = NULL;
}

/* Cuenta los mapas que han sido definidos */
int map_count() {
	Mapa *tmp = first_map;
	int size = 0;

	while(tmp) {size++; tmp = tmp->next;}
	return size;
}

/* Carga toda la imagen en una estructura del tipo Image */
/* Suponemos que el archivo es del formato avs */
/* image->buffer[i][j]  ** i es columna**   ****   ** j es fila** */
int loadImage(char *file, Image *image) {
	FILE *handle;
	int i, j;
	AVSPixel pixel;
	AVSHeader header;
	char ret = TRUE;

	if ((handle = fopen(file, "r+"))) {
		fread(&header, sizeof(AVSHeader), 1, handle);
		FIX(header.ancho);
		FIX(header.alto);

		image->width = header.ancho;
		image->height = header.alto;
		image->buffer = (Color **) calloc(image->width, sizeof(Color *));
		for (i = 0; i < image->width; i++)
			image->buffer[i] = (Color *) calloc(image->height, sizeof(Color));
		for (j = 0; j < image->height; j++)
			for (i = 0; i < image->width; i++) {
				fread(&pixel, sizeof(AVSPixel), 1, handle);
				image->buffer[i][j].r = (double) pixel.r / 255;
				image->buffer[i][j].g = (double) pixel.g / 255;
				image->buffer[i][j].b = (double) pixel.b / 255;
				//printf("R G B - %.2f %.2f %.2f\n", image->buffer[i][j].r, image->buffer[i][j].g,image->buffer[i][j].b);
			}
		fclose(handle);
	}
	else ret = FALSE;
	return ret;
}

/* Funciones para hacer el clipping */
/* Se espera dejar un nuevo puntero a un dato Mapa que contiene la lista de los nuevos poligonos ya clippeados */

int test_xmax(UniversalPoint2D p1, UniversalPoint2D p2) {
	int ret;

	if (p1.x <= win.pmax.x && p2.x <= win.pmax.x)
		ret = ADD_NEXT;
	else if (p1.x <= win.pmax.x && p2.x > win.pmax.x)
		ret = ADD_INTERSECTION;
	else if (p1.x > win.pmax.x && p2.x <= win.pmax.x)
		ret = ADD_TWO;
	else
		ret = DO_NOT_ADD;
	return ret;
}

int test_xmin(UniversalPoint2D p1, UniversalPoint2D p2) {
	int ret;

	if (p1.x >= win.pmin.x && p2.x >= win.pmin.x)
		ret = ADD_NEXT;
	else if (p1.x >= win.pmin.x && p2.x < win.pmin.x)
		ret = ADD_INTERSECTION;
	else if (p1.x < win.pmin.x && p2.x >= win.pmin.x)
		ret = ADD_TWO;
	else
		ret = DO_NOT_ADD;
	return ret;
}

int test_ymax(UniversalPoint2D p1, UniversalPoint2D p2) {
	int ret;

	if (p1.y <= win.pmax.y && p2.y <= win.pmax.y)
		ret = ADD_NEXT;
	else if (p1.y <= win.pmax.y && p2.y > win.pmax.y)
		ret = ADD_INTERSECTION;
	else if (p1.y > win.pmax.y && p2.y <= win.pmax.y)
		ret = ADD_TWO;
	else
		ret = DO_NOT_ADD;
	return ret;
}

int test_ymin(UniversalPoint2D p1, UniversalPoint2D p2) {
	int ret;

	if (p1.y >= win.pmin.y && p2.y >= win.pmin.y)
		ret = ADD_NEXT;
	else if (p1.y >= win.pmin.y && p2.y < win.pmin.y)
		ret = ADD_INTERSECTION;
	else if (p1.y < win.pmin.y && p2.y >= win.pmin.y)
		ret = ADD_TWO;
	else
		ret = DO_NOT_ADD;
	return ret;
}

UniversalPoint2D xmax_intersect(UniversalPoint2D p1, UniversalPoint2D p2) {
	double m, b;
	UniversalPoint2D new;

	if (p1.y != p2.y) {
		m = (double) (p1.y - p2.y) / (p1.x - p2.x);
		b = (double) p1.y - m * p1.x;
		new.x = win.pmax.x;
		new.y = m * new.x + b;
	} else {
		new.x = win.pmax.x;
		new.y = p1.y;
	}

	return new;
}

UniversalPoint2D xmin_intersect(UniversalPoint2D p1, UniversalPoint2D p2) {
	double m, b;
	UniversalPoint2D new;

	if (p1.y != p2.y) {
		m = (double) (p1.y - p2.y) / (p1.x - p2.x);
		b = (double) p1.y - m * p1.x;
		new.x = win.pmin.x;
		new.y = m * new.x + b;
	} else {
		new.x = win.pmin.x;
		new.y = p1.y;
	}

	return new;
}

UniversalPoint2D ymax_intersect(UniversalPoint2D p1, UniversalPoint2D p2) {
	double m, b;
	UniversalPoint2D new;

	if (p1.x != p2.x) {
		m = (double) (p1.y - p2.y) / (p1.x - p2.x);
		b = (double) p1.y - m * p1.x;
		new.y = win.pmax.y;
		new.x = (double) (new.y - b) / m;
	} else {
		new.x = p1.x;
		new.y = win.pmax.y;
	}

	return new;
}

UniversalPoint2D ymin_intersect(UniversalPoint2D p1, UniversalPoint2D p2) {
	double m, b;
	UniversalPoint2D new;

	if (p1.x != p2.x) {
		m = (double) (p1.y - p2.y) / (p1.x - p2.x);
		b = (double) p1.y - m * p1.x;
		new.y = win.pmin.y;
		new.x = (double) (new.y - b) / m;
	} else {
		new.x = p1.x;
		new.y = win.pmin.y;
	}

	return new;
}

Mapa * clip_map_xmax(Mapa *mapa) {
	Mapa * tmp = NULL;
	Limite * tmp_lim = NULL;
	char action;

	if (mapa->first && mapa->last && mapa->first != mapa->last) {
		tmp = (Mapa *) calloc(1, sizeof(Mapa));
		tmp->color = mapa->color;
		tmp->image = mapa->image;	// Pueden haber problemas...
		tmp->next = NULL;
		for(tmp_lim = mapa->first; tmp_lim != mapa->last; tmp_lim = tmp_lim->next) {
			switch(test_xmax(tmp_lim->point, tmp_lim->next->point)) {
				case ADD_NEXT:
					if (! tmp->first)
						tmp->first = tmp->last = (Limite *) calloc(1, sizeof(Limite));
					else
						tmp->last = tmp->last->next  = (Limite *) calloc(1, sizeof(Limite));
					tmp->last->point = tmp_lim->next->point;
					break;
				case ADD_INTERSECTION:
					if (! tmp->first)
						tmp->first = tmp->last = (Limite *) calloc(1, sizeof(Limite));
					else
						tmp->last = tmp->last->next  = (Limite *) calloc(1, sizeof(Limite));
					tmp->last->point = xmax_intersect(tmp_lim->point, tmp_lim->next->point);
					break;
				case ADD_TWO:
					if (! tmp->first)
						tmp->first = tmp->last = (Limite *) calloc(1, sizeof(Limite));
					else
						tmp->last = tmp->last->next  = (Limite *) calloc(1, sizeof(Limite));
					tmp->last->point = xmax_intersect(tmp_lim->point, tmp_lim->next->point);
					tmp->last = tmp->last->next  = (Limite *) calloc(1, sizeof(Limite));
					tmp->last->point = tmp_lim->next->point;
					break;
				default:
					break;
			}
		}
		switch(test_xmax(mapa->last->point, mapa->first->point)) { // El final con el inicio
			case ADD_NEXT:
				if (! tmp->first)
					tmp->first = tmp->last = (Limite *) calloc(1, sizeof(Limite));
				else
					tmp->last = tmp->last->next  = (Limite *) calloc(1, sizeof(Limite));
				tmp->last->point = mapa->first->point;
				break;
			case ADD_INTERSECTION:
				if (! tmp->first)
					tmp->first = tmp->last = (Limite *) calloc(1, sizeof(Limite));
				else
					tmp->last = tmp->last->next  = (Limite *) calloc(1, sizeof(Limite));
				tmp->last->point = xmax_intersect(mapa->last->point, mapa->first->point);
				break;
			case ADD_TWO:
				if (! tmp->first)
					tmp->first = tmp->last = (Limite *) calloc(1, sizeof(Limite));
				else
					tmp->last = tmp->last->next  = (Limite *) calloc(1, sizeof(Limite));
				tmp->last->point = xmax_intersect(mapa->last->point, mapa->first->point);
				tmp->last = tmp->last->next  = (Limite *) calloc(1, sizeof(Limite));
				tmp->last->point = mapa->first->point;
				break;
			default:
				break;
		}
		if (! tmp->first) {
			free(tmp);
			tmp = NULL;
		}
	}
	return tmp;
}

Mapa * clip_map_ymax(Mapa *mapa) {
	Mapa * tmp = NULL;
	Limite * tmp_lim = NULL;
	char action;

	if (mapa->first && mapa->last && mapa->first != mapa->last) {
		tmp = (Mapa *) calloc(1, sizeof(Mapa));
		tmp->color = mapa->color;
		tmp->image = mapa->image;	// Pueden haber problemas...
		tmp->next = NULL;
		for(tmp_lim = mapa->first; tmp_lim != mapa->last; tmp_lim = tmp_lim->next) {
			switch(test_ymax(tmp_lim->point, tmp_lim->next->point)) {
				case ADD_NEXT:
					if (! tmp->first)
						tmp->first = tmp->last = (Limite *) calloc(1, sizeof(Limite));
					else
						tmp->last = tmp->last->next  = (Limite *) calloc(1, sizeof(Limite));
					tmp->last->point = tmp_lim->next->point;
					break;
				case ADD_INTERSECTION:
					if (! tmp->first)
						tmp->first = tmp->last = (Limite *) calloc(1, sizeof(Limite));
					else
						tmp->last = tmp->last->next  = (Limite *) calloc(1, sizeof(Limite));
					tmp->last->point = ymax_intersect(tmp_lim->point, tmp_lim->next->point);
					break;
				case ADD_TWO:
					if (! tmp->first)
						tmp->first = tmp->last = (Limite *) calloc(1, sizeof(Limite));
					else
						tmp->last = tmp->last->next  = (Limite *) calloc(1, sizeof(Limite));
					tmp->last->point = ymax_intersect(tmp_lim->point, tmp_lim->next->point);
					tmp->last = tmp->last->next  = (Limite *) calloc(1, sizeof(Limite));
					tmp->last->point = tmp_lim->next->point;
					break;
				default:
					break;
			}
		}
		switch(test_ymax(mapa->last->point, mapa->first->point)) { // El final con el inicio
			case ADD_NEXT:
				if (! tmp->first)
					tmp->first = tmp->last = (Limite *) calloc(1, sizeof(Limite));
				else
					tmp->last = tmp->last->next  = (Limite *) calloc(1, sizeof(Limite));
				tmp->last->point = mapa->first->point;
				break;
			case ADD_INTERSECTION:
				if (! tmp->first)
					tmp->first = tmp->last = (Limite *) calloc(1, sizeof(Limite));
				else
					tmp->last = tmp->last->next  = (Limite *) calloc(1, sizeof(Limite));
				tmp->last->point = ymax_intersect(mapa->last->point, mapa->first->point);
				break;
			case ADD_TWO:
				if (! tmp->first)
					tmp->first = tmp->last = (Limite *) calloc(1, sizeof(Limite));
				else
					tmp->last = tmp->last->next  = (Limite *) calloc(1, sizeof(Limite));
				tmp->last->point = ymax_intersect(mapa->last->point, mapa->first->point);
				tmp->last = tmp->last->next  = (Limite *) calloc(1, sizeof(Limite));
				tmp->last->point = mapa->first->point;
				break;
			default:
				break;
		}
		if (! tmp->first) {
			free(tmp);
			tmp = NULL;
		}
	}
	return tmp;
}

Mapa * clip_map_xmin(Mapa *mapa) {
	Mapa * tmp = NULL;
	Limite * tmp_lim = NULL;
	char action;

	if (mapa->first && mapa->last && mapa->first != mapa->last) {
		tmp = (Mapa *) calloc(1, sizeof(Mapa));
		tmp->color = mapa->color;
		tmp->image = mapa->image;	// Pueden haber problemas...
		tmp->next = NULL;
		for(tmp_lim = mapa->first; tmp_lim != mapa->last; tmp_lim = tmp_lim->next) {
			switch(test_xmin(tmp_lim->point, tmp_lim->next->point)) {
				case ADD_NEXT:
					if (! tmp->first)
						tmp->first = tmp->last = (Limite *) calloc(1, sizeof(Limite));
					else
						tmp->last = tmp->last->next  = (Limite *) calloc(1, sizeof(Limite));
					tmp->last->point = tmp_lim->next->point;
					break;
				case ADD_INTERSECTION:
					if (! tmp->first)
						tmp->first = tmp->last = (Limite *) calloc(1, sizeof(Limite));
					else
						tmp->last = tmp->last->next  = (Limite *) calloc(1, sizeof(Limite));
					tmp->last->point = xmin_intersect(tmp_lim->point, tmp_lim->next->point);
					break;
				case ADD_TWO:
					if (! tmp->first)
						tmp->first = tmp->last = (Limite *) calloc(1, sizeof(Limite));
					else
						tmp->last = tmp->last->next  = (Limite *) calloc(1, sizeof(Limite));
					tmp->last->point = xmin_intersect(tmp_lim->point, tmp_lim->next->point);
					tmp->last = tmp->last->next  = (Limite *) calloc(1, sizeof(Limite));
					tmp->last->point = tmp_lim->next->point;
					break;
				default:
					break;
			}
		}
		switch(test_xmin(mapa->last->point, mapa->first->point)) {	// El final con el inicio
			case ADD_NEXT:
				if (! tmp->first)
					tmp->first = tmp->last = (Limite *) calloc(1, sizeof(Limite));
				else
					tmp->last = tmp->last->next  = (Limite *) calloc(1, sizeof(Limite));
				tmp->last->point = mapa->first->point;
				break;
			case ADD_INTERSECTION:
				if (! tmp->first)
					tmp->first = tmp->last = (Limite *) calloc(1, sizeof(Limite));
				else
					tmp->last = tmp->last->next  = (Limite *) calloc(1, sizeof(Limite));
				tmp->last->point = xmin_intersect(mapa->last->point, mapa->first->point);
				break;
			case ADD_TWO:
				if (! tmp->first)
					tmp->first = tmp->last = (Limite *) calloc(1, sizeof(Limite));
				else
					tmp->last = tmp->last->next  = (Limite *) calloc(1, sizeof(Limite));
				tmp->last->point = xmin_intersect(mapa->last->point, mapa->first->point);
				tmp->last = tmp->last->next  = (Limite *) calloc(1, sizeof(Limite));
				tmp->last->point = mapa->first->point;
				break;
			default:
				break;
		}
		if (! tmp->first) {
			free(tmp);
			tmp = NULL;
		}
	}
	return tmp;
}

Mapa * clip_map_ymin(Mapa *mapa) {
	Mapa * tmp = NULL;
	Limite * tmp_lim = NULL;
	char action;

	if (mapa->first && mapa->last && mapa->first != mapa->last) {
		tmp = (Mapa *) calloc(1, sizeof(Mapa));
		tmp->color = mapa->color;
		tmp->image = mapa->image;	// Pueden haber problemas...
		tmp->next = NULL;
		for(tmp_lim = mapa->first; tmp_lim != mapa->last; tmp_lim = tmp_lim->next) {
			switch(test_ymin(tmp_lim->point, tmp_lim->next->point)) {
				case ADD_NEXT:
					if (! tmp->first)
						tmp->first = tmp->last = (Limite *) calloc(1, sizeof(Limite));
					else
						tmp->last = tmp->last->next  = (Limite *) calloc(1, sizeof(Limite));
					tmp->last->point = tmp_lim->next->point;
					break;
				case ADD_INTERSECTION:
					if (! tmp->first)
						tmp->first = tmp->last = (Limite *) calloc(1, sizeof(Limite));
					else
						tmp->last = tmp->last->next  = (Limite *) calloc(1, sizeof(Limite));
					tmp->last->point = ymin_intersect(tmp_lim->point, tmp_lim->next->point);
					break;
				case ADD_TWO:
					if (! tmp->first)
						tmp->first = tmp->last = (Limite *) calloc(1, sizeof(Limite));
					else
						tmp->last = tmp->last->next  = (Limite *) calloc(1, sizeof(Limite));
					tmp->last->point = ymin_intersect(tmp_lim->point, tmp_lim->next->point);
					tmp->last = tmp->last->next  = (Limite *) calloc(1, sizeof(Limite));
					tmp->last->point = tmp_lim->next->point;
					break;
				default:
					break;
			}
		}
		switch(test_ymin(mapa->last->point, mapa->first->point)) {	// El final con el inicio
			case ADD_NEXT:
				if (! tmp->first)
					tmp->first = tmp->last = (Limite *) calloc(1, sizeof(Limite));
				else
					tmp->last = tmp->last->next  = (Limite *) calloc(1, sizeof(Limite));
				tmp->last->point = mapa->first->point;
				break;
			case ADD_INTERSECTION:
				if (! tmp->first)
					tmp->first = tmp->last = (Limite *) calloc(1, sizeof(Limite));
				else
					tmp->last = tmp->last->next  = (Limite *) calloc(1, sizeof(Limite));
				tmp->last->point = ymin_intersect(mapa->last->point, mapa->first->point);
				break;
			case ADD_TWO:
				if (! tmp->first)
					tmp->first = tmp->last = (Limite *) calloc(1, sizeof(Limite));
				else
					tmp->last = tmp->last->next  = (Limite *) calloc(1, sizeof(Limite));
				tmp->last->point = ymin_intersect(mapa->last->point, mapa->first->point);
				tmp->last = tmp->last->next  = (Limite *) calloc(1, sizeof(Limite));
				tmp->last->point = mapa->first->point;
				break;
			default:
				break;
		}
		if (! tmp->first) {
			free(tmp);
			tmp = NULL;
		}
	}
	return tmp;
}

/* Retorna un puntero a un Mapa nuevo, ya clippeado */
Mapa * clip_map(Mapa *mapa) {
	Mapa *tmp0, *tmp1, *tmp2, *tmp3;

	tmp0 = clip_map_xmax(mapa);
	tmp1 = clip_map_ymax(tmp0);
	tmp2 = clip_map_xmin(tmp1);
	tmp3 = clip_map_ymin(tmp2);
	free_tmp_map(tmp0);
	free_tmp_map(tmp1);
	free_tmp_map(tmp2);
	return tmp3;
}

// Le hace el clip a cada uno de los mapas
void clip_all_maps() {
	Mapa *first_clipped = NULL, *last_clipped  = NULL;
	Mapa *tmp = first_map, *tmp_clipped;

	while (tmp) {
		if (tmp_clipped = clip_map(tmp)) {
			if (! first_clipped)
				first_clipped = last_clipped = tmp_clipped;
			else
				last_clipped = last_clipped->next = tmp_clipped;
		}
		tmp = tmp->next;
	} // Ya tenemos la lista de los nuevos mapas ya clippeados

	// Vamos a liberar la memoria los mapas clippeados anteriormente
	tmp = first_clipped_map;
	while(tmp) {
		tmp_clipped = tmp->next;
		free_tmp_map(tmp);
		tmp = tmp_clipped;
	}

	// Ponemos a apuntar a los nuevos clippeados
	first_clipped_map = first_clipped;
	last_clipped_map = last_clipped;
}

void free_tmp_map(Mapa *mapa) {
	Limite *tmp1, *tmp2;

	tmp1 = mapa->first;
	while(tmp1) {
		tmp2 = tmp1->next;
		free(tmp1);
		tmp1 = tmp2;
	}
	free(mapa);
}

void puntos(Mapa *mapa) {
	Limite *tmp;
	if(mapa) {
		tmp = mapa->first;
		while(tmp) {
			printf("%.2f %.2f\n", tmp->point.x, tmp->point.y);
			tmp = tmp->next;
		}
	} else printf("NullPointerException\n");
}

