#include <stdio.h>
#include "proyecto.h"

/*
#define H_SIZE 200
#define V_SIZE	200
*/
int H_SIZE=200;
int V_SIZE=200;

Point3D pwin, pd, peye = {0.0,-90.0,-100.0};
Window ventana = {{-100.0, -100.0, 0.0}, {100.0, 100.0, 0.0}};
Color background = {0.0, 0.0, 0.0};
double ia, c1, c2, c3;
int Xmin=0,Ymin=0,Xmax=100,Ymax=100;
ObjectList lista_objetos = {NULL, NULL};	// La lista se encuentra vacIa al inicio.
LightList luces = {NULL, NULL};			// La lista de luces.
char * title;
int size /*= H_SIZE * V_SIZE*/;
FILE *output;

// Variables para la imagen
Color **buffer;

void drawScene() {
	int i,j;
	double L;
	Point3D ptemp;
	IntersectionList il;
	Color color;
	static int lastX = 0;

	//Redibuja una parte del buffer
	for (i = 0; i < lastX; i++)
 		for (j = 0; j < V_SIZE; j++) {
			glBegin(GL_POINTS);
      			glColor3f(buffer[i][j].r,buffer[i][j].g,buffer[i][j].b);
      			glVertex2i(i,j);
			glEnd();
			}

	//Dibuja la parte restante de la imagen
	ptemp.z = 0;
	for (i = lastX; i < H_SIZE; i++) {
		ptemp.x = ventana.pmin.x + ((ventana.pmax.x - ventana.pmin.x) * (i + 0.5)) / H_SIZE;
		for (j=0; j<V_SIZE; j++) {
			//Punto que toca el rayo
			ptemp.y = ventana.pmin.y + ((ventana.pmax.y - ventana.pmin.y) * (j + 0.5)) / V_SIZE;

			// Rayo que sale del ojo y pasa por un punto en la ventana
			// (peye.x, peye.y, peye.z) + t * (pd.x, pd.y, pd..z)
			L = (double) sqrt((ptemp.x - peye.x)*(ptemp.x - peye.x)
						+ (ptemp.y - peye.y)*(ptemp.y - peye.y)
						+ (ptemp.z - peye.z)*(ptemp.z - peye.z) );
			pd.x = (ptemp.x - peye.x) / L;
			pd.y = (ptemp.y - peye.y) / L;
			pd.z = (ptemp.z - peye.z) / L;
			buffer[i][j] = getColor(peye, pd);

			glBegin(GL_POINTS);
			glColor3f(buffer[i][j].r,buffer[i][j].g,buffer[i][j].b);
      			glVertex2i(i,j);
      			glEnd();
			//stats(i * V_SIZE + j);

			//Acualiza el valor de LastX
			lastX = i;
		}
	}
	glFlush();
}

void makeImage() {

}

void stats(int n) {
	int x, i;
	x = n * CHARS / size;
	fprintf(output, "%c", 13);
	for(i = 0; i < x; i++)
		fprintf(output, "%c", '*');
	for(i = x; i < CHARS; i++)
		fprintf(output, "%c", ' ');
	x = (int) x * 100 / CHARS;
	if(x < 10)
		fprintf(output, " ");
	fprintf(output, " %i%%", x);
}

//UNIVERSAL2PIXEL: Pasa un punto del universo (continuo) a su corespondiente
// en discreto.

//PROGRAMA PRINCIPAL
main(int argc, char *argv[]) {
	int i,j;

	//Loading file :-s
	if (!LoadUniversoFromFile((char *)argv[1])) {
		buffer = (Color **)calloc(H_SIZE,sizeof(Color *));
		for (i = 0; i < H_SIZE; i++)
			buffer[i] = (Color *) calloc(V_SIZE,sizeof(Color));
		output = stdout;

		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
		//glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
		glutInitWindowSize(H_SIZE,V_SIZE);
		glutInitWindowPosition(0, 0);
		glutCreateWindow(title);
		glClear(GL_COLOR_BUFFER_BIT);
		gluOrtho2D(-0.5, H_SIZE +0.5, -0.5, V_SIZE + 0.5);
		glutDisplayFunc(drawScene);
		glutMainLoop();
	}
}
