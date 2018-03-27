/*
Archivo:
	firma.c
Creador: 
	Herberth Madrigal Bendless
Objetivo:
	Implementación para la técnica Bezier para el trazado de lineas curvas.
*/

#include "firma.h"

//Variables Globales
	//Resolucón
int H_SIZE=320;
int V_SIZE=200;
	//Dimensiones del Window
tpunto wmin;
tpunto wmax;
	//Color de lineas y fondo
tcolor fg;
tcolor bg;
	//Cunto incrementar para calcular T.
double incval;
double inccnt;

tlista lineas;
tlinea nodo;

//Algoritmo de Bresenham (Punto Medio)
void linea (int x0, int y0, int x1, int y1) {
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

//Algoritmo de Bezier: 
//	Regresa un punto determinado por "t" que pertenece a [0,1], 
//	que se encuentra entre los puntos p0 y p3. 
//	El punto cuando t=0 es p0
//	El punto cuando t<0.5 se aproxima a p1
//	El punto cuando t>0.5 se aproxima a p2
//	El punto cuando t=1 es p3
bezier(double t, tpunto p0, tpunto p1, tpunto p2, tpunto p3, tpunto *np) {
	double ct=1-t;
	np->x = pow (ct,3)*p0.x + 
		3*t*pow (ct,2)*p1.x +
		3*pow (t,2)*ct*p2.x +
		pow (t,3)*p3.x;
	
	np->y = pow (ct,3)*p0.y + 
		3*t*pow (ct,2)*p1.y +
		3*pow (t,2)*ct*p2.y +
		pow (t,3)*p3.y;
}

//Inserta un nodo y genera los calculos Tx
tlinea *inserta_nodo (tlista lista, tlinea nodo) {
	struct stlinea *aux;
	tlinea *nuevo;
	int i;
	double j;
	tpunto p,np;
	
	aux = lista.first;
	nuevo =  (tlinea *) malloc (sizeof (struct stlinea));
	
	//Copia datos
	for (i=0;i<4;i++) 
		nuevo->p[i] = nodo.p[i];
	
	//CALCULOS T
	nuevo->t = (tpunto *) calloc(inccnt+1,sizeof(tpunto));
	for (j=0,i=0;i<=inccnt;j+=incval,i++) {
		//Calcula el punto en el Universo
		bezier(j, nodo.p[0], nodo.p[1], nodo.p[2], nodo.p[3], &p);
		
		//Cambia de Coordenadas Universales a Coordenadas de Pixels
		Universal2Pixel(p.x, p.y, &np);

		//Alamacena el punto segun Coordenadas Universales
		nuevo->t[i].x = np.x;
		nuevo->t[i].y = np.y;
		#ifdef DEBUG
		printf("(%i)x:%f y:%f\n",i,nuevo->t[i].x,nuevo->t[i].y);
		#endif
	}
	nuevo->next = NULL;
	//Cambia los P[x] a Coordenadas de Pixel
	for (i=0;i<4;i++) {
		Universal2Pixel(nodo.p[i].x, nodo.p[i].y, &np);
		nodo.p[i].x = np.x;
		nodo.p[i].y = np.y;
	}
	
	//Inserta al final
	if (aux) {
		while (aux->next)
			aux = aux->next;
		aux->next = nuevo;
		#ifdef DEBUG
		printf("Insertando Al final.\n");
		#endif
	} else {
		lista.first = nuevo;
		#ifdef DEBUG
		printf("Insertando al Inicio.\n");
		#endif
	}
	
	return lista.first;
}

// Pasa de Coordenadas universales a Coordenadas de Pixel
Universal2Pixel(double px, double py, tpunto *np) {
	np->x = ((H_SIZE * (px - wmin.x)) / (wmax.x - wmin.x));
	np->y = ((V_SIZE * (py - wmin.y)) / (wmax.y - wmin.y));
}

//Rutina para dibujar en pantalla
void drawScene() {
	int i,j;	
	struct stlinea *aux;
		
	double x,y;
	tpunto np1,np2;
	
	//Limpia la pantalla en Negro
	glBegin(GL_POINTS);
	glColor3f(bg.r,bg.g,bg.b);
	for (i=0;i<=H_SIZE;i++)
		for(j=0;j<=V_SIZE;j++)	
			glVertex2i(i,j);
	
	
	//Dibuja una cuadrícula
	#ifdef DEBUG
	glColor3f(fg.r,fg.g,fg.b);
	for (y=floor(wmin.y)	;y<=wmax.y;y++) {
		Universal2Pixel(wmin.x,y,&np1);
		Universal2Pixel(wmax.x,y,&np2);
		linea(np1.x,np1.y,np2.x,np2.y);
	}
	for (x=floor(wmin.x);x<=wmax.x;x++) {
		Universal2Pixel(x,wmin.y,&np1);
		Universal2Pixel(x,wmax.y,&np2);
		linea(np1.x,np1.y,np2.x,np2.y);
	}
	#endif
	
	//Cambia el color a Blanco
	glColor3f(fg.r,fg.g,fg.b);
	for (aux = lineas.first; aux; aux = aux->next) {
		#ifdef DEBUG
		printf("DIBUJO: LINEA\n");
		#endif
		for (i=1;i<=inccnt;i++)  {
			linea(aux->t[i-1].x,aux->t[i-1].y,aux->t[i].x,aux->t[i].y);
			#ifdef DEBUG
			printf("[%i]x0:%f y0:%f x1:%f y1:%f\n",i,aux->t[i-1].x,aux->t[i-1].y,aux->t[i].x,aux->t[i].y);
			#endif
		}
	}
	glEnd();
	//Dibuja cualquier cosa que haga falta de sacar del buffer
	glFlush();
}

//PROGRAMA PRINCIPAL
int main (int argc, char **argv) {
	// Inicialización del GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
		
	lineas.first = NULL;
	
	//Carga el archivo con puntos
	if (argc==2) {
		loadfile((char *)argv[1]);
	} else {
		printf("Usage:\n\tfile <filename>\n");
		return 1;
	}

	// Tamaño de la ventana.
	glutInitWindowSize(H_SIZE,V_SIZE);
	
	// Título de la ventana.
	glutCreateWindow("Herberth Madrigal [Yogurt]");
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(-0.5, H_SIZE +0.5, -0.5, V_SIZE + 0.5);
	
	// Se le dice al GLUT cual es la función que debe llamar
	glutDisplayFunc(drawScene);

	// Este metodo inicia al proceso de dibujado.
	glutMainLoop();
	
	return 0;
}