//----------------------------------------------------
//ADMINISTRATIVO
// 	Instituto Tecnologico de Costa Rica
//	Departamento de Ingenieria en Computacion
//	Introduccion a los graficos por computadora
//Autores:
//	Herberth Madrigal
//	Roberto Pineda
//Explicacion:
//	Implementacion de 4 algoritmos de lineas
//
//----------------------------------------------------
//COMPILACION
//Compilador:
//	gcc version 2.95.3 20010315 (release)
//Plataforma:
//	Slackware 8.1
//Bliblotecas:
//	Mesa 3.3.5
//----------------------------------------------------
// {}


#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <time.h>
#include <stdio.h>

typedef struct {
	int x0, y0, x1, y1;
} Linea;

Linea *lineas;

int resolucion;
int cantidad;
int loop;

void crea_lineas() {
	int i;

	lineas = (Linea *) calloc(cantidad, sizeof(Linea));
	for( i = 0; i < cantidad; i++) {
		lineas[i].x0 = rand() % resolucion;
		lineas[i].y0 = rand() % resolucion;
		lineas[i].x1 = rand() % resolucion;
		lineas[i].y1 = rand() % resolucion;
	}
}

void pinta_blanco() {
	int i, j;

	glColor3f(1,1,1);
	glBegin(GL_POINTS);
	for (i = 0; i < resolucion; i++)
		for (j = 0; j < resolucion; j++)
			glVertex2i(i,j);
	glEnd();
}

//ALGORITMO 1: Fuerza Bruta
int linea_1 (int x0,int y0, int x1, int y1){
	long double m;
	long double b;
	long double y;
	int x;

	//Pendiente Infinita
	if (x1 == x0){
		if (y0 < y1) {
			glBegin(GL_POINTS);
			for (y=y0;y<=y1;y++)
				glVertex2i(x0,y);
			glEnd();
		} else{
			glBegin(GL_POINTS);
			for (y=y0;y>=y1;y--)
				glVertex2i(x0,y);
			glEnd();
		}
	//Pendiente Real
	} else {
		m = (long double)(y1-y0) / (long double) (x1 - x0);
		b = y0 - m * x0;

		//Dibuja en la izquierda
		if (x0>x1) {
			glBegin(GL_POINTS);
			for (x=x0;x>=x1;x--){
				y = (m * x) + b;
				glVertex2i(x,y);
			}
			glEnd();
		//Dibuja en la derecha
		}else {
			//Dibuja la linea
			glBegin(GL_POINTS);
			for (x=x0;x<=x1;x++){
				y = (m * x) + b;
				glVertex2i(x,y);
			}
			glEnd();
		}
	}
}

//ALGORITMO 2: Incremental
int linea_2 (int x0,int y0, int x1, int y1){
	int x;
	long double dy;
	long double dx;
	long double y;
	long double b;
	long double m;

	//Pendiente Infinita
	if (x1 == x0){
		if (y0 < y1) {
			glBegin(GL_POINTS);
			for (y=y0;y<=y1;y++)
				glVertex2i(x0,y);
			glEnd();
		} else{
			glBegin(GL_POINTS);
			for (y=y0;y>=y1;y--)
				glVertex2i(x0,y);
			glEnd();
		}
	//Pendiente Real
	} else {
		m = (long double)(y1-y0) / (long double) (x1 - x0);
		b = y0 - m * x0;

		//Correccion de la direccion
		if (x0>x1) {
			dy = y0 -y1;
			dx = x0 -x1;
			y = y1;

			//Dibuja la linea
			glBegin(GL_POINTS);
			for (x=x1; x<=x0;x++){
				glVertex2i(x,y);
				y+=m;
			}
			glEnd();
		} else {
			dy = y1 -y0;
			dx = x1 -x0;
			y = y0;

			//Dibuja la linea
			glBegin(GL_POINTS);
			for (x=x0; x<=x1;x++){
				glVertex2i(x,y);
				y+=m;
			}
			glEnd();
		}
	}
}

//ALGORITMO 3: Incremental con mejoras
int linea_3 (int x0,int y0, int x1, int y1){
	long double deltax, deltay, x, y , l;
	int i;

	//"l" contiene la densidad mayor.
	l = abs(y1 - y0);
	if (l < abs(x1 - x0))
		l = abs(x1 - x0);

	deltax = (x1 - x0)/l;
	deltay = (y1 - y0)/l;
	x = x0;
	y = y0;

	//Dibuja la linea
	glBegin(GL_POINTS);
	for (i = 0; i <= l; i++)
	{
		glVertex2i(x,y);
		x = x + deltax;
		y = y + deltay;
	}

	glEnd();
}

void linea_Bresenham(int x0, int y0, int x1, int y1) {
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

void drawScene() {

	int i, j, times;
	clock_t time;

	pinta_blanco();

	glColor3f(.15, .15, .15);
	time = clock();
	for (j = 0; j < loop; j++)
		for (i = 0; i < cantidad; i++) {
			linea_1(lineas[i].x0, lineas[i].y0, lineas[i].x1, lineas[i].y1);
		}
	time = clock() - time;
	printf("Algoritmo 1 dura %.3f s con %i lineas %i veces\n", (double) time / CLK_TCK, cantidad, loop);

	glColor3f(.30, .30, .30);
	time = clock();
	for (j = 0; j < loop; j++)
		for (i = 0; i < cantidad; i++) {
			linea_2(lineas[i].x0, lineas[i].y0, lineas[i].x1, lineas[i].y1);
		}
	time = clock() - time;
	printf("Algoritmo 2 dura %.3f s con %i lineas %i veces\n", (double) time / CLK_TCK, cantidad, loop);

	glColor3f(.45, .45, .45);
	time = clock();
	for (j = 0; j < loop; j++)
		for (i = 0; i < cantidad; i++) {
			linea_3(lineas[i].x0, lineas[i].y0, lineas[i].x1, lineas[i].y1);
		}
	time = clock() - time;
	printf("Algoritmo 3 dura %.3f s con %i lineas %i veces\n", (double) time / CLK_TCK, cantidad, loop);

	glColor3f(.60, .60, .60);
	time = clock();
	for (j = 0; j < loop; j++)
		for (i = 0; i < cantidad; i++) {
			linea_Bresenham(lineas[i].x0, lineas[i].y0, lineas[i].x1, lineas[i].y1);
		}
	time = clock() - time;
	printf("Bresenham dura %.3f s con %i lineas %i veces\n", (double) time / CLK_TCK, cantidad, loop);

	/*
	* Esto es opcional.
	* Solamente le ordena al GLUT que cualquier cosa que tenga
	* en buffers y que no haya pintado aún, lo mande inmediatamente
	* a pintar.
	*/
	glFlush();
}

int main(int argc, char** argv) {
	int i, j;
	FILE *handle;

	if (argc == 4) { /* Asumimos que no hay errores ekn los parametros */
		resolucion = atoi(argv[1]);
		cantidad = atoi(argv[2]);
		loop = atoi(argv[3]);

		//Inicializando la semilla
		handle=fopen("/dev/random","r");
		fread(&i,sizeof(int),1,handle);
		fclose(handle);
		srand(i);

		//system("date");
		crea_lineas();
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

		glutInitWindowSize(resolucion,resolucion);

		glutCreateWindow("Tarea #1 (Lineas)");
		glClear(GL_COLOR_BUFFER_BIT);
		gluOrtho2D(-0.5, resolucion + 0.5, -0.5, resolucion + 0.5);

		glutDisplayFunc(drawScene);
		glutMainLoop();
	} else printf("Uso:\n\tlineas [resolucion] [cantidad] [loop]\n");
}
