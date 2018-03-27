#include "draw.h"

//Dibuja una lina utilizando el algoritmo de Bresenham
void linea(int x0, int y0, int x1, int y1) {
	int tmp;
	int d0, dL, dDL;
	int xP, yP;

	if ((y1 - y0) >= 0 && (x1 - x0) >= 0) { // Son los Octantes 1 y 2
		if (abs(x1 - x0) >= abs(y1 - y0)) { // El Octante 1
			d0 = 2 * (y1 - y0) - (x1 - x0);
			dL = 2 * (y1 - y0);
			dDL = 2 * ((y1 - y0) - (x1 - x0));

			glBegin(GL_POINTS);
			for (; x0 <= x1 && y0 <= y1;) {
				glVertex2i(x0, y0);
				if(d0 < 0)
					d0 += dL;
				else {
					y0++;
					d0 += dDL;
				}
				x0++;
			}
			glEnd();
		}
		else { // El Octante 2
			d0 = (y1 - y0) - 2 * (x1 - x0);
			dL = -2 * (x1 - x0);
			dDL = 2 * (y1 - y0) - 2 * (x1 - x0);

			glBegin(GL_POINTS);
			for (; x0 <= x1 && y0 <= y1;) {
				glVertex2i(x0, y0);
				if(d0 > 0)
					d0 += dL;
				else {
					x0++;
					d0 += dDL;
				}
				y0++;
			}
			glEnd();
		}
	}
	else if ((y1 - y0) <=0 && (x1 - x0) >= 0) { // Los Octantes 7 y 8
		if (abs(x1 - x0) > abs(y1 - y0)) { // El Octante 8
			d0 = 2 * (y1 - y0) + (x1 - x0);
			dL = 2 * (y1 - y0);
			dDL = 2 * (y1 - y0) + 2 * (x1 - x0);

			glBegin(GL_POINTS);
			for (; x0 <= x1 && y0 >= y1;) {
				glVertex2i(x0, y0);
				if(d0 > 0)
					d0 += dL;
				else {
					y0--;
					d0 += dDL;
				}
				x0++;
			}
			glEnd();
		}
		else { // El Octante 7
			d0 = (y1 - y0) + 2 * (x1 - x0);
			dL = 2 * (x1 - x0);
			dDL = 2 * (y1 - y0) + 2 * (x1 - x0);

			glBegin(GL_POINTS);
			for (;x0 <= x1 && y0 >= y1;) {
				glVertex2i(x0, y0);
				if(d0 < 0)
					d0 += dL;
				else {
					x0++;
					d0 += dDL;
				}
				y0--;
			}
			glEnd();
		}
	}
	else if ((y1 - y0) >= 0 && (x1 - x0) <= 0) { // Son los Octantes 3 y 4
		if (abs(x1 - x0) < abs(y1 - y0)) { // El Octante 3
			d0 = -(y1 - y0) - 2 * (x1 - x0);
			dL = -2 * (x1 - x0);
			dDL = -2 * (y1 - y0) - 2 * (x1 - x0);

			glBegin(GL_POINTS);
			for (; x0 >= x1 && y0 <= y1;) {
				glVertex2i(x0, y0);
				if(d0 < 0)
					d0 += dL;
				else {
					x0--;
					d0 += dDL;
				}
				y0++;
			}
			glEnd();

		}
		else { // El Octante 4
			d0 = -2 * (y1 - y0) - (x1 - x0);
			dL = -2 * (y1 - y0);
			dDL = -2 * (y1 - y0) - 2 * (x1 - x0);

			glBegin(GL_POINTS);
			for (; x0 >= x1 && y0 <= y1;) {
				glVertex2i(x0, y0);
				if(d0 > 0)
					d0 += dL;
				else {
					y0++;
					d0 += dDL;
				}
				x0--;
			}
			glEnd();
		}
	}
	else if ((y1 - y0) <= 0 && (x1 - x0) <= 0) { // Son los Octantes 5 y 6
		if (abs(x1 - x0) > abs(y1 - y0)) { // El Octante 5
			d0 = -2 * (y1 - y0) + (x1 - x0);
			dL = -2 * (y1 - y0);
			dDL = -2 * (y1 - y0) + 2 * (x1 - x0);

			glBegin(GL_POINTS);
			for (; x0 >= x1 && y0 >= y1;) {
				glVertex2i(x0, y0);
				if(d0 < 0)
					d0 += dL;
				else {
					y0--;
					d0 += dDL;
				}
				x0--;
			}
			glEnd();
		}
		else { // El Octante 6
			d0 = -(y1 - y0) + 2 * (x1 - x0);
			dL = 2 * (x1 - x0);
			dDL = -2 * (y1 - y0) + 2 * (x1 - x0);

			glBegin(GL_POINTS);
			for (; x0 >= x1 && y0 >= y1;) {
				glVertex2i(x0, y0);
				if(d0 > 0)
					d0 += dL;
				else {
					x0--;
					d0 += dDL;
				}
				y0--;
			}
			glEnd();
		}
	}
}

// Dibuja lineas. Recibe una lista de vertices
draw_mode_1 (Mapa *poli) {	
	Limite *aux=poli->first;
	
	//Fija el Color 
	glColor3f(poli->color.r,poli->color.g,poli->color.b);
	
	//Une los puntos con lineas
	if (aux) {
	   for (; aux != poli->last; aux = aux->next) 
		linea(aux->point.x,aux->point.y,aux->next->point.x,aux->next->point.y);
	   linea(aux->point.x,aux->point.y,poli->first->point.x,poli->first->point.y);
	}
}
