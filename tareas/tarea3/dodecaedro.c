
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define H_SIZE 500
#define V_SIZE 500

#define DIR_X 0x00
#define DIR_Y 0x01
#define DIR_Z 0x02
#define MAX_GIRO 360
#define PI			3.14159
#define GRADOS_45 0.785398
#define DIFERENCIA 0.0349066

char dir=DIR_Z;
double  rotate=0.0;
double rfac = 0.0349066;


// Estructuras
typedef struct {
	double x, y, z;
} Point3D;

typedef struct {
	Point3D * puntos[5];
} Lado;

typedef struct {
	int x, y;
} Point2D;

typedef struct pln {
	Point2D point;
	struct pln *next;
} PointListNode;

typedef struct {
	PointListNode *first, *last;
} PointList;

typedef struct {
	Point2D *inicio, *fin;
} Linea;

typedef struct {
	double r, g, b;
} Color;

// Prototipos
//PointList addPoint(PointList pl, Point2D p);
int length(PointList pl);
PointList freePointList(PointList pl);
void draw_line(Linea line);
void linea(int x0, int y0, int x1, int y1);
void drawScene();
void rotar(double angulo, char coordenada);

// Variables globales
int i,j;
Color **buffer;
Color blanco, negro;

Lado dodecaedro[12];

Point3D punto0 = {0.309017,  0.951057, 1.2};
Point3D punto1 = {-0.809017,  0.587785, 1.2};
Point3D punto2 = {-0.809017, -0.587785, 1.2};
Point3D punto3 = {0.309017, -0.951056, 1.2};
Point3D punto4 = {1.0, 0.0, 1.2};
Point3D punto5 = {0.437012, 1.344984, 0.41};
Point3D punto6 = {-1.144112, 0.831246, 0.41};
Point3D punto7 = {-1.144112, -0.831246, 0.41};
Point3D punto8 = {0.437012, -1.344984, 0.41};
Point3D punto9 = {1.414200,  0.0, 0.41};
Point3D punto10 = {-0.309017, -0.951057, -1.2};
Point3D punto11 = {0.809017, -0.587785, -1.2};
Point3D punto12 = {0.809017,  0.587785, -1.2};
Point3D punto13 = {-0.309017,  0.951056, -1.2};
Point3D punto14 = {-1.0, 0.0, -1.2};
Point3D punto15 = {-0.437012, -1.344984, -0.41};
Point3D punto16 = {1.144112, -0.831246, -0.41};
Point3D punto17 = {1.144112,  0.831246, -0.41};
Point3D punto18 = {-0.437012,  1.344984, -0.41};
Point3D punto19 = {-1.414200,  0.0, -0.41};

Point3D window_min = {-2.0, -2.0, 0.0};
Point3D window_max = {2.0, 2.0, 0.0};
Point3D ojo = {0.0, 0.0, 3.0};

void inicializa() {
	dodecaedro[0].puntos[0] = &punto0;
	dodecaedro[0].puntos[1] = &punto1;
	dodecaedro[0].puntos[2] = &punto2;
	dodecaedro[0].puntos[3] = &punto3;
	dodecaedro[0].puntos[4] = &punto4;

	dodecaedro[1].puntos[0] = &punto4;
	dodecaedro[1].puntos[1] = &punto9;
	dodecaedro[1].puntos[2] = &punto17;
	dodecaedro[1].puntos[3] = &punto5;
	dodecaedro[1].puntos[4] = &punto0;

	dodecaedro[2].puntos[0] = &punto0;
	dodecaedro[2].puntos[1] = &punto5;
	dodecaedro[2].puntos[2] = &punto18;
	dodecaedro[2].puntos[3] = &punto6;
	dodecaedro[2].puntos[4] = &punto1;

	dodecaedro[3].puntos[0] = &punto2;
	dodecaedro[3].puntos[1] = &punto1;
	dodecaedro[3].puntos[2] = &punto6;
	dodecaedro[3].puntos[3] = &punto19;
	dodecaedro[3].puntos[4] = &punto7;

	dodecaedro[4].puntos[0] = &punto4;
	dodecaedro[4].puntos[1] = &punto3;
	dodecaedro[4].puntos[2] = &punto8;
	dodecaedro[4].puntos[3] = &punto16;
	dodecaedro[4].puntos[4] = &punto9;

	dodecaedro[5].puntos[0] = &punto3;
	dodecaedro[5].puntos[1] = &punto2;
	dodecaedro[5].puntos[2] = &punto7;
	dodecaedro[5].puntos[3] = &punto15;
	dodecaedro[5].puntos[4] = &punto8;

	dodecaedro[6].puntos[0] = &punto17;
	dodecaedro[6].puntos[1] = &punto12;
	dodecaedro[6].puntos[2] = &punto13;
	dodecaedro[6].puntos[3] = &punto18;
	dodecaedro[6].puntos[4] = &punto5;

	dodecaedro[7].puntos[0] = &punto17;
	dodecaedro[7].puntos[1] = &punto9;
	dodecaedro[7].puntos[2] = &punto16;
	dodecaedro[7].puntos[3] = &punto11;
	dodecaedro[7].puntos[4] = &punto12;

	dodecaedro[8].puntos[0] = &punto16;
	dodecaedro[8].puntos[1] = &punto8;
	dodecaedro[8].puntos[2] = &punto15;
	dodecaedro[8].puntos[3] = &punto10;
	dodecaedro[8].puntos[4] = &punto11;

	dodecaedro[9].puntos[0] = &punto15;
	dodecaedro[9].puntos[1] = &punto7;
	dodecaedro[9].puntos[2] = &punto19;
	dodecaedro[9].puntos[3] = &punto14;
	dodecaedro[9].puntos[4] = &punto10;

	dodecaedro[10].puntos[0] = &punto19;
	dodecaedro[10].puntos[1] = &punto6;
	dodecaedro[10].puntos[2] = &punto18;
	dodecaedro[10].puntos[3] = &punto13;
	dodecaedro[10].puntos[4] = &punto14;

	dodecaedro[11].puntos[0] = &punto14;
	dodecaedro[11].puntos[1] = &punto13;
	dodecaedro[11].puntos[2] = &punto12;
	dodecaedro[11].puntos[3] = &punto11;
	dodecaedro[11].puntos[4] = &punto10;
}

Point3D rotate_x(Point3D p, double angle) {
	Point3D new;

	new.x = p.x;
	new.y = p.y * cos(angle) - p.z * sin(angle);
	new.z = p.y * sin(angle) + p.z * cos(angle);
	return new;
}

Point3D rotate_y(Point3D p, double angle) {
	Point3D new;

	new.y = p.y;
	new.x = p.x * cos(angle) + p.z * sin(angle);
	new.z = p.z * cos(angle) - p.x * sin(angle);
	return new;
}

Point3D rotate_z(Point3D p, double angle) {
	Point3D new;
	new.z = p.z;
	new.x = p.x * cos(angle) - p.y * sin(angle);
	new.y = p.x * sin(angle) + p.y * cos(angle);
	return new;
}


// Funciones
PointList addPoint(PointList pl, Point2D p) {
	PointListNode *tmp;

	tmp = (PointListNode *) calloc(1, sizeof(PointListNode));
	tmp->point = p;
	if(! pl.first)
		pl.first = pl.last = tmp;
	else
		pl.last = pl.last->next = tmp;
	return pl;
}

int length(PointList pl) {
	int len = 0;
	PointListNode *tmp;
	tmp = pl.first;
	while(tmp) {
		len++;
		tmp = tmp->next;
	}
	return len;
}

void printPoints(PointList pl) {
	PointListNode *tmp;

	tmp = pl.first;
	while(tmp) {
		printf("[%i,%i]\n", tmp->point.x, tmp->point.x);
		tmp = tmp->next;
	}
}

PointList freePointList(PointList pl) {
	PointListNode *tmp1, *tmp2;

	tmp1 = pl.first;
	while(tmp1) {
		tmp2 = tmp1->next;
		free(tmp1);
		tmp1 = tmp2;
	}
	pl.last = pl.first = NULL;
	return pl;
}

// Recibe una lista de puntos
// Dibujas las lineas denotadas entre puntos
void drawLines(PointList pl) {
	PointListNode *tmp, *tmp2;
	Linea line;

	tmp = pl.first;
	while(tmp->next) {
		linea(tmp->point.x, tmp->point.y, tmp->next->point.x, tmp->next->point.y);
		tmp = tmp->next;
	}
	if(pl.first) {
		linea(pl.last->point.x, pl.last->point.y, pl.first->point.x, pl.first->point.y);
	}
}

void draw_line(Linea line) {
	linea(line.inicio->x, line.inicio->y, line.fin->x, line.fin->y);
}

void linea(int x0, int y0, int x1, int y1) {
	int tmp;
	int d0, dL, dDL;
	int xP, yP;

	//glColor3f((double) (x0 + y0) / (H_SIZE + V_SIZE), (double) (x0 + y1) / (H_SIZE + V_SIZE), (double) (x1 + y1) / (H_SIZE + V_SIZE));
	negro.r = (double) (x0 + y0) / (H_SIZE + V_SIZE);
	negro.g = (double) (x0 + y1) / (H_SIZE + V_SIZE);
	negro.b = (double) (x1 + y1) / (H_SIZE + V_SIZE);
	//negro.r = negro.g = negro.b = 1.0;
	if ((y1 - y0) >= 0 && (x1 - x0) >= 0) { // Son los Octantes 1 y 2
		if (abs(x1 - x0) >= abs(y1 - y0)) { // El Octante 1
			d0 = 2 * (y1 - y0) - (x1 - x0);
			dL = 2 * (y1 - y0);
			dDL = 2 * ((y1 - y0) - (x1 - x0));

			//glBegin(GL_POINTS);
			for (; x0 <= x1 && y0 <= y1;) {
				//glVertex2i(x0, y0);
				buffer[x0][y0] = negro;
				if(d0 < 0)
					d0 += dL;
				else {
					y0++;
					d0 += dDL;
				}
				x0++;
			}
			//glEnd();
		}
		else { // El Octante 2
			d0 = (y1 - y0) - 2 * (x1 - x0);
			dL = -2 * (x1 - x0);
			dDL = 2 * (y1 - y0) - 2 * (x1 - x0);

			//glBegin(GL_POINTS);
			for (; x0 <= x1 && y0 <= y1;) {
				//glVertex2i(x0, y0);
				buffer[x0][y0] = negro;
				if(d0 > 0)
					d0 += dL;
				else {
					x0++;
					d0 += dDL;
				}
				y0++;
			}
			//glEnd();
		}
	}
	else if ((y1 - y0) <=0 && (x1 - x0) >= 0) { // Los Octantes 7 y 8
		if (abs(x1 - x0) > abs(y1 - y0)) { // El Octante 8
			d0 = 2 * (y1 - y0) + (x1 - x0);
			dL = 2 * (y1 - y0);
			dDL = 2 * (y1 - y0) + 2 * (x1 - x0);

			//glBegin(GL_POINTS);
			for (; x0 <= x1 && y0 >= y1;) {
				//glVertex2i(x0, y0);
				buffer[x0][y0] = negro;
				if(d0 > 0)
					d0 += dL;
				else {
					y0--;
					d0 += dDL;
				}
				x0++;
			}
			//glEnd();
		}
		else { // El Octante 7
			d0 = (y1 - y0) + 2 * (x1 - x0);
			dL = 2 * (x1 - x0);
			dDL = 2 * (y1 - y0) + 2 * (x1 - x0);

			//glBegin(GL_POINTS);
			for (;x0 <= x1 && y0 >= y1;) {
				//glVertex2i(x0, y0);
				buffer[x0][y0] = negro;
				if(d0 < 0)
					d0 += dL;
				else {
					x0++;
					d0 += dDL;
				}
				y0--;
			}
			//glEnd();
		}
	}
	else if ((y1 - y0) >= 0 && (x1 - x0) <= 0) { // Son los Octantes 3 y 4
		if (abs(x1 - x0) < abs(y1 - y0)) { // El Octante 3
			d0 = -(y1 - y0) - 2 * (x1 - x0);
			dL = -2 * (x1 - x0);
			dDL = -2 * (y1 - y0) - 2 * (x1 - x0);

			//glBegin(GL_POINTS);
			for (; x0 >= x1 && y0 <= y1;) {
				//glVertex2i(x0, y0);
				buffer[x0][y0] = negro;
				if(d0 < 0)
					d0 += dL;
				else {
					x0--;
					d0 += dDL;
				}
				y0++;
			}
			//glEnd();
		}
		else { // El Octante 4
			d0 = -2 * (y1 - y0) - (x1 - x0);
			dL = -2 * (y1 - y0);
			dDL = -2 * (y1 - y0) - 2 * (x1 - x0);

			//glBegin(GL_POINTS);
			for (; x0 >= x1 && y0 <= y1;) {
				//glVertex2i(x0, y0);
				buffer[x0][y0] = negro;
				if(d0 > 0)
					d0 += dL;
				else {
					y0++;
					d0 += dDL;
				}
				x0--;
			}
			//glEnd();
		}
	}
	else if ((y1 - y0) <= 0 && (x1 - x0) <= 0) { // Son los Octantes 5 y 6
		if (abs(x1 - x0) > abs(y1 - y0)) { // El Octante 5
			d0 = -2 * (y1 - y0) + (x1 - x0);
			dL = -2 * (y1 - y0);
			dDL = -2 * (y1 - y0) + 2 * (x1 - x0);

			//glBegin(GL_POINTS);
			for (; x0 >= x1 && y0 >= y1;) {
				//glVertex2i(x0, y0);
				buffer[x0][y0] = negro;
				if(d0 < 0)
					d0 += dL;
				else {
					y0--;
					d0 += dDL;
				}
				x0--;
			}
			//glEnd();
		}
		else { // El Octante 6
			d0 = -(y1 - y0) + 2 * (x1 - x0);
			dL = 2 * (x1 - x0);
			dDL = -2 * (y1 - y0) + 2 * (x1 - x0);

			//glBegin(GL_POINTS);
			for (; x0 >= x1 && y0 >= y1;) {
				//glVertex2i(x0, y0);
				buffer[x0][y0] = negro;
				if(d0 > 0)
					d0 += dL;
				else {
					x0--;
					d0 += dDL;
				}
				y0--;
			}
			//glEnd();
		}
	}
}

void drawBuffer() {
	glBegin(GL_POINTS);
	for(i = 0; i < H_SIZE; i++)
		for(j = 0; j < V_SIZE; j++) {
				glColor3f(buffer[i][j].r, buffer[i][j].g, buffer[i][j].b);
				glVertex2i(i, j);
			}
	glEnd();
}

void whiteBuffer() {
	for(i = 0; i < H_SIZE; i++)
		for(j = 0; j < V_SIZE; j++)
			buffer[i][j] = blanco;
}

void drawScene() {
	//printf("Hola\n");
	drawBuffer();
	glFlush();
	glutSwapBuffers();
	rotar(0.0, 1);
	/*while(1)
		glutPostRedisplay();*/
}

int round_int(double n) {
	int r = (int) n;

	if((double) n - r > 0.5)
		r++;
	return r;
}

void drawDodecaedro() {
	int i,j;
	Point2D punto;
	PointList lista = {NULL, NULL};
	Point3D temporal;
	double factor;
	double fact_ancho = H_SIZE / (window_max.x - window_min.x);
	double fact_alto = V_SIZE / (window_max.y - window_min.y);

	whiteBuffer();
	for (i = 0; i < 12; i++) {
		for(j = 0; j < 5; j++) {
			factor = (double) (-dodecaedro[i].puntos[j]->z / (ojo.z - dodecaedro[i].puntos[j]->z));
			temporal.x = dodecaedro[i].puntos[j]->x + factor * (ojo.x - dodecaedro[i].puntos[j]->x);
			temporal.y = dodecaedro[i].puntos[j]->y + factor * (ojo.y - dodecaedro[i].puntos[j]->y);
			punto.x = (int) (H_SIZE * (temporal.x - window_min.x)) / (window_max.x -window_min.x);
			punto.y = (int) (V_SIZE * (temporal.y - window_min.y)) / (window_max.y -window_min.y);
			lista = addPoint(lista, punto);
		}
		drawLines(lista);
		lista = freePointList(lista);
	}
}

void rotar(double angulo, char coordenada) {
			//rotate -= rfac;
			if (fabs(rotate) < DIFERENCIA) {
				rotate = ((((double)random()) / RAND_MAX) < 0.5)?
						(((double)random()) / RAND_MAX) * GRADOS_45 :
						- (((double)random()) / RAND_MAX) * GRADOS_45;
				dir = ((int) ((double) random()))%3;
			}
			rotate += (rotate < 0.0)? DIFERENCIA : -DIFERENCIA;
				//printf("Rotar %.4f direccion %i\n", rotate, dir);
			switch (dir) {
				case DIR_X:
					punto0 = rotate_x (punto0, rfac );
					punto1= rotate_x (punto1, rfac );
					punto2= rotate_x (punto2, rfac );
					punto3= rotate_x (punto3, rfac );
					punto4= rotate_x (punto4, rfac );
					punto5= rotate_x (punto5, rfac );
					punto6= rotate_x (punto6, rfac );
					punto7= rotate_x (punto7, rfac );
					punto8= rotate_x (punto8, rfac );
					punto9= rotate_x (punto9, rfac );
					punto10= rotate_x (punto10, rfac );
					punto11= rotate_x (punto11, rfac );
					punto12= rotate_x (punto12, rfac );
					punto13= rotate_x (punto13, rfac );
					punto14= rotate_x (punto14, rfac );
					punto15= rotate_x (punto15, rfac );
					punto16= rotate_x (punto16, rfac );
					punto17= rotate_x (punto17, rfac );
					punto18= rotate_x (punto18, rfac );
					punto19= rotate_x (punto19,rfac );
				break;
				case DIR_Y:
					punto0= rotate_y (punto0, rfac );
					punto1= rotate_y (punto1, rfac );
					punto2= rotate_y (punto2, rfac );
					punto3= rotate_y (punto3, rfac );
					punto4= rotate_y (punto4, rfac );
					punto5= rotate_y (punto5, rfac );
					punto6= rotate_y (punto6, rfac );
					punto7= rotate_y (punto7, rfac );
					punto8= rotate_y (punto8, rfac );
					punto9= rotate_y (punto9, rfac );
					punto10= rotate_y (punto10, rfac );
					punto11= rotate_y (punto11, rfac );
					punto12= rotate_y (punto12, rfac );
					punto13= rotate_y (punto13, rfac );
					punto14= rotate_y (punto14, rfac );
					punto15= rotate_y (punto15, rfac );
					punto16= rotate_y (punto16, rfac );
					punto17= rotate_y (punto17, rfac );
					punto18= rotate_y (punto18, rfac );
					punto19= rotate_y (punto19,rfac );
				break;
				case DIR_Z:
					punto0= rotate_z (punto0, rfac );
					punto1= rotate_z (punto1, rfac );
					punto2= rotate_z (punto2, rfac );
					punto3= rotate_z (punto3, rfac );
					punto4= rotate_z (punto4, rfac );
					punto5= rotate_z (punto5, rfac );
					punto6= rotate_z (punto6, rfac );
					punto7= rotate_z (punto7, rfac );
					punto8= rotate_z (punto8, rfac );
					punto9= rotate_z (punto9, rfac );
					punto10= rotate_z (punto10, rfac );
					punto11= rotate_z (punto11, rfac );
					punto12= rotate_z (punto12, rfac );
					punto13= rotate_z (punto13, rfac );
					punto14= rotate_z (punto14, rfac );
					punto15= rotate_z (punto15, rfac );
					punto16= rotate_z (punto16, rfac );
					punto17= rotate_z (punto17, rfac );
					punto18= rotate_z (punto18, rfac );
					punto19= rotate_z (punto19,rfac );
				break;
			}
		drawDodecaedro();
		//system("sleep 1");
		glutPostRedisplay();
}

int main(int argc, char** argv) {
	FILE *handle;
	int i;
	buffer = (Color **)calloc(H_SIZE,sizeof(Color *));
	for (i = 0; i < H_SIZE; i++)
		buffer[i] = (Color *) calloc(V_SIZE,sizeof(Color));
	blanco.r = blanco.g = blanco.b = 0.0;
	negro.r = negro.g = negro.b = 0.0;
        handle=fopen("/dev/random","r");
        fread(&i,sizeof(int),1,handle);
        fclose(handle);
        srand(i);

	whiteBuffer();
	inicializa();
	drawDodecaedro();
	//doLines();
	glutInit(&argc, argv);
	//glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(H_SIZE,V_SIZE);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Dodecaedro");
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(-0.5, H_SIZE +0.5, -0.5, V_SIZE + 0.5);
	glutDisplayFunc(drawScene);
	glutMainLoop();
}
