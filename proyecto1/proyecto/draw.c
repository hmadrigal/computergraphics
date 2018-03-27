#include "draw.h"

int mode=MODE_1;

//Dibuja una lina utilizando el algoritmo de Bresenham
void linea(int x0, int y0, int x1, int y1, Color color) {
	int tmp;
	int d0, dL, dDL;
	int xP, yP;
	if(x1 == H_SIZE)
		x1 -= 1;
	if(x0 == H_SIZE)
		x0 -= 1;
	if ((y1 - y0) >= 0 && (x1 - x0) >= 0) { // Son los Octantes 1 y 2
		if (abs(x1 - x0) >= abs(y1 - y0)) { // El Octante 1
			d0 = 2 * (y1 - y0) - (x1 - x0);
			dL = 2 * (y1 - y0);
			dDL = 2 * ((y1 - y0) - (x1 - x0));

			for (; x0 <= x1 && y0 <= y1;) {
				buffer[x0][y0] = color;
				if(d0 < 0)
					d0 += dL;
				else {
					y0++;
					d0 += dDL;
				}
				x0++;
			}
		}
		else { // El Octante 2
			d0 = (y1 - y0) - 2 * (x1 - x0);
			dL = -2 * (x1 - x0);
			dDL = 2 * (y1 - y0) - 2 * (x1 - x0);

			//glBegin(GL_POINTS);
			for (; x0 <= x1 && y0 <= y1;) {
				buffer[x0][y0] = color;
				if(d0 > 0)
					d0 += dL;
				else {
					x0++;
					d0 += dDL;
				}
				y0++;
			}
		}
	}
	else if ((y1 - y0) <=0 && (x1 - x0) >= 0) { // Los Octantes 7 y 8
		if (abs(x1 - x0) > abs(y1 - y0)) { // El Octante 8
			d0 = 2 * (y1 - y0) + (x1 - x0);
			dL = 2 * (y1 - y0);
			dDL = 2 * (y1 - y0) + 2 * (x1 - x0);

			for (; x0 <= x1 && y0 >= y1;) {
				buffer[x0][y0] = color;
				if(d0 > 0)
					d0 += dL;
				else {
					y0--;
					d0 += dDL;
				}
				x0++;
			}
		}
		else { // El Octante 7
			d0 = (y1 - y0) + 2 * (x1 - x0);
			dL = 2 * (x1 - x0);
			dDL = 2 * (y1 - y0) + 2 * (x1 - x0);

			for (;x0 <= x1 && y0 >= y1;) {
				buffer[x0][y0] = color;
				if(d0 < 0)
					d0 += dL;
				else {
					x0++;
					d0 += dDL;
				}
				y0--;
			}
		}
	}
	else if ((y1 - y0) >= 0 && (x1 - x0) <= 0) { // Son los Octantes 3 y 4
		if (abs(x1 - x0) < abs(y1 - y0)) { // El Octante 3
			d0 = -(y1 - y0) - 2 * (x1 - x0);
			dL = -2 * (x1 - x0);
			dDL = -2 * (y1 - y0) - 2 * (x1 - x0);

			for (; x0 >= x1 && y0 <= y1;) {
				buffer[x0][y0] = color;
				if(d0 < 0)
					d0 += dL;
				else {
					x0--;
					d0 += dDL;
				}
				y0++;
			}
		}
		else { // El Octante 4
			d0 = -2 * (y1 - y0) - (x1 - x0);
			dL = -2 * (y1 - y0);
			dDL = -2 * (y1 - y0) - 2 * (x1 - x0);
			
			for (; x0 >= x1 && y0 <= y1;) {
				buffer[x0][y0] = color;
				if(d0 > 0)
					d0 += dL;
				else {
					y0++;
					d0 += dDL;
				}
				x0--;
			}
		}
	}
	else if ((y1 - y0) <= 0 && (x1 - x0) <= 0) { // Son los Octantes 5 y 6
		if (abs(x1 - x0) > abs(y1 - y0)) { // El Octante 5
			d0 = -2 * (y1 - y0) + (x1 - x0);
			dL = -2 * (y1 - y0);
			dDL = -2 * (y1 - y0) + 2 * (x1 - x0);

			for (; x0 >= x1 && y0 >= y1;) {
				buffer[x0][y0] = color;
				if(d0 < 0)
					d0 += dL;
				else {
					y0--;
					d0 += dDL;
				}
				x0--;
			}
		}
		else { // El Octante 6
			d0 = -(y1 - y0) + 2 * (x1 - x0);
			dL = 2 * (x1 - x0);
			dDL = -2 * (y1 - y0) + 2 * (x1 - x0);

			for (; x0 >= x1 && y0 >= y1;) {
				buffer[x0][y0] = color;
				if(d0 > 0)
					d0 += dL;
				else {
					x0--;
					d0 += dDL;
				}
				y0--;
			}
		}
	}
}

// Dibuja lineas. Recibe una lista de vertices
void draw_mode_1 () {
	PixelMapa *tmp_map = first_clipped_map;
	PixelLimite *aux;
	while(tmp_map) {
		//Fija el Color
		glColor3f(tmp_map->color.r,tmp_map->color.g,tmp_map->color.b);
		//Une los puntos con lineas
		if (aux = tmp_map->first) {
			for (; aux != tmp_map->last; aux = aux->next)
				linea(aux->point.x,aux->point.y,aux->next->point.x,aux->next->point.y, tmp_map->color);
			linea(aux->point.x, aux->point.y, tmp_map->first->point.x, tmp_map->first->point.y, tmp_map->color);
		}
		tmp_map = tmp_map->next;
	}
}

// Funciones para el algoritmos de Relleno de poligonos

// Retorna -1 si ymaxl1 < ymaxl2
// Retorna 0 si ymaxl1 == ymaxl2
// Retorna 1 si ymaxl1 > ymaxl2
int cmplin(Line l1, Line l2) {
	int ymaxl1, ymaxl2;

	ymaxl1 = (l1.p1->y < l1.p2->y) ? l1.p2->y : l1.p1->y;
	ymaxl2 = (l2.p1->y < l2.p2->y) ? l2.p2->y : l2.p1->y;
	return (ymaxl1 == ymaxl2) ? 0 : (ymaxl1 < ymaxl2) ? -1 : 1;
}

LineList addLine(LineList llist, Line line) {
	int ymaxl1, ymaxl2;
	LineNode * ln = (LineNode *) calloc(1, sizeof(LineNode)), *tmp;
	line.xold = (double) (line.p1->y > line.p2->y) ? line.p1->x : line.p2->x;
	line.m = (double) (line.p2->x - line.p1->x) / (line.p2->y - line.p1->y);
	ln->line = line;

	if (!llist.first) {
		llist.first = llist.last = ln;
	}
	else {
		if (cmplin(llist.first->line, ln->line) == -1) {
			ln->next = llist.first;
			llist.first = ln;
		} else {
			tmp = llist.first;
			while (tmp->next) {
				if(cmplin(tmp->next->line, ln->line) == -1) {
					ln->next = tmp->next;
					tmp->next = ln;
					break;
				}
				tmp = tmp->next;
			}
			if(! tmp->next)
				llist.last = llist.last->next = ln;
		}
	}
	return llist;
}

LineList getLines(PixelMapa *pm) {
	LineList llist;
	Line line;
	PixelLimite *lim;

	llist.first = llist.last = NULL;
	if (pm) {
		lim = pm->first;
		while(lim) {
			if(lim->next) {
				line.p1 = &(lim->point);
				line.p2 = &(lim->next->point);
				llist = addLine(llist, line);
			}
			lim = lim->next;
		}
		if(pm->first && pm->last) {
				line.p1 = &(pm->last->point);
				line.p2 = &(pm->first->point);
				llist = addLine(llist, line);
		} else printf("Something wrong has ocurred!!!!!***\n");
	}
	return llist;
}

void printLines(LineList llist) {
	LineNode *ln;
	for(ln = llist.first; ln; ln = ln->next)
		printf("Linea [%i,%i] - [%i,%i] ** %.2f * %.2f\n", ln->line.p1->x, ln->line.p1->y, ln->line.p2->x, ln->line.p2->y, ln->line.xold, ln->line.m);
}

void freeLineList(LineList *llist) {
	LineNode *tmp1, *tmp2;

	if(llist) {
		for(tmp1 = llist->first; tmp1; tmp1 = tmp2) {
			tmp2 = tmp1->next;
			free(tmp1);
		}
	}
	llist->first = llist->last = NULL;
}

/* Ordena con respecto a x */
PointList addPoint(PointList pl, PixelPoint2D point) {
	PointNode *pn = (PointNode *) calloc(1, sizeof(PointNode)), *tmp;
	pn->point = point;

	if (! pl.first)
		pl.first = pl.last = pn;
	else {
		if(pl.first->point.x > pn->point.x) {
			pn->next = pl.first;
			pl.first = pn;
		}
		else {
			tmp = pl.first;
			while(tmp->next) {
				if(tmp->next->point.x > pn->point.x) {
					pn->next = tmp->next;
					tmp->next = pn;
					break;
				}
				tmp = tmp->next;
			}
			if(! tmp->next)
				pl.last = tmp->next = pn;
		}
	}
	return pl;
}

void printPoints(PointList pl) {
	PointNode *p;
	p = pl.first;
	while(p) {
		printf("Puntos %i *-* %i\n", p->point.x, p->point.y);
		p = p->next;
	}
}

/* Despues de ejecutar esta funcion */
/* Se debe poner en nulos los apuntadores de la lista liberada */
void freePointList(PointList pl) {
	PointNode *pn, *pn2;
	pn = pl.first;
	while(pn) {
		pn2 = pn->next;
		free(pn);
		pn = pn2;
	}
}

/* Se espera que la lista se encuentre ordenada descendentemente*/
Yminmax getYminmax(LineList llist) {
	Yminmax tmp;
	int yemin;
	LineNode *tmpln;

	if(llist.first) {
		tmp.ymax = (llist.first->line.p1->y > llist.first->line.p2->y) ? llist.first->line.p1->y : llist.first->line.p2->y;
		tmp.ymin = V_SIZE;
		for(tmpln = llist.first; tmpln; tmpln = tmpln->next) {
			yemin = (tmpln->line.p1->y > tmpln->line.p2->y) ? tmpln->line.p2->y : tmpln->line.p1->y;
			if(yemin < tmp.ymin)
				tmp.ymin = yemin;
		}
	} else {
		tmp.ymin = 0;
		tmp.ymax = 0;
	}
	return tmp;
}

int getymax(Line l) {
	return (l.p1->y > l.p2->y) ? l.p1->y : l.p2->y;
}

int getymin(Line l) {
	return (l.p1->y < l.p2->y) ? l.p1->y : l.p2->y;
}

PointList getIntersections(LineList list, int scanline) {
	LineNode *ln;
	PixelPoint2D point;
	PointList plist;

	point.y = scanline;
	plist.first = plist.last = NULL;
	ln = list.first;
	while(ln) {
		if(ln->line.p1->y != ln->line.p2->y) {	// No consederamos las horizontales
			if(ln->line.p1->x == ln->line.p2->x) {
				point.x = ln->line.p1->x;
			} else {
				point.x = (int) ln->line.xold;
				ln->line.xold -= ln->line.m;
			}
			plist = addPoint(plist, point);
		}
		ln = ln->next;
	}
	return plist;
}

void drawFilledMaps() {
	LineList activos, inactivos;
	LineNode *ln;
	PointList pl;
	Yminmax yes;
	int scanline;
	PixelMapa *tmp_map = first_clipped_map;

	activos.first = NULL;
	activos.last = NULL;
	while(tmp_map) {
		glColor3f(tmp_map->color.r,tmp_map->color.g,tmp_map->color.b);
		inactivos = getLines(tmp_map);
		if(inactivos.first) {
			yes = getYminmax(inactivos);
			for(scanline = yes.ymax; scanline >= yes.ymin; scanline--) {
				for(;;) {	// Escogemos los que se activan...
					if((ln = inactivos.first) && (scanline == getymax(inactivos.first->line))) {
						activos = addLine(activos, ln->line);
						inactivos.first = inactivos.first->next;
						free(ln);
					} else break;
				}
				for(;;) {	// Eliminamos los que salen
					if(hayMinimoIgual(activos, scanline))
						activos = removeYmins(activos, scanline);
					else break;
				}

				// Ya podemos trabajar sobre la lista de activos
				pl = getIntersections(activos, scanline);
				if (mode==MODE_2)  //Color
					drawLines(pl, tmp_map->color);
				else if (mode==MODE_3) //Textura
					draw_textura(pl,tmp_map->image);
				freePointList(pl);
			}
		}
		activos.first = NULL;
		activos.last = NULL;
		tmp_map = tmp_map->next;
	}
}

/* Retorna 1 si hay algun ymin igual */
int hayMinimoIgual(LineList llist, int yminPar) {
	LineNode *tmp;

	tmp = llist.first;
	while(tmp) {
		if(getymin(tmp->line) == yminPar)
			return 1;
		tmp = tmp->next;
	}
	return 0;
}

/* Elimina las lineas cuyos ymin conciden con el parametro*/
LineList removeYmins(LineList llist, int yminPar) {
	LineNode *tmp, *tmp1;

	while((tmp = llist.first) && (getymin(llist.first->line) == yminPar)) {
		llist.first = llist.first->next;
		if(tmp == llist.last)
			llist.last = llist.first;
		free(tmp);
	}
	tmp = llist.first;
	while(tmp && tmp->next) {
		if(yminPar == getymin(tmp->next->line)) {
			tmp1 = tmp->next;
			tmp->next = tmp1->next;
			if(tmp1 == llist.last)
				llist.last = tmp;
			free(tmp1);
		}
		tmp = tmp->next;
	}
	return llist;
}

int lengthPL(PointList pl) {
	int len = 0;
	PointNode *tmp;

	tmp = pl.first;
	while(tmp) {
		len++;
		tmp = tmp->next;
	}
	return len;
}

void drawLines(PointList pl, Color color) {
	int len;

	PointNode *tmp1, *tmp2;
	if(! ((len = lengthPL(pl)) % 2) && len) {
		tmp1 = pl.first;
		do {
			linea(tmp1->point.x, tmp1->point.y, tmp1->next->point.x, tmp1->next->point.y, color);
			tmp1 = tmp1->next->next;
		} while(tmp1);
	} //else  {printf("Hay puntos impares!!!!\n"); printPoints(pl);}
}


void draw_textura (PointList pl, Image *img) {
	int len, x;

	PointNode *tmp1, *tmp2;
	if(! ((len = lengthPL(pl)) % 2) && len) {
		tmp1 = pl.first;
		do {
			for (x=tmp1->point.x ; x < tmp1->next->point.x; x++) {
				buffer[x][tmp1->next->point.y] = img->buffer[x%img->width][(V_SIZE - tmp1->next->point.y -1)%img->height];
			}
			tmp1 = tmp1->next->next;
		} while(tmp1);
	}
}

// Funciones para el uso del buffer

void drawBuffer() {
	int i,j;
	
	if (image_loaded)
		for(i = 0; i < H_SIZE; i++)
			for(j = 0; j < V_SIZE; j++)
				buffer[i][j] = background_image->buffer[i%background_image->width][(V_SIZE - j -1)%background_image->height];
	else
		for(i = 0; i < H_SIZE; i++)
			for(j = 0; j < V_SIZE; j++)
				buffer[i][j] = background;
	
	
	// Dibujamos el background
	clip_all_maps();
	if (mode == MODE_1)
		draw_mode_1(first_clipped_map);
	else
		drawFilledMaps();
}
