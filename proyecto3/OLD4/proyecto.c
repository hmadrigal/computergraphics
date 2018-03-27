#include <stdio.h>
#include "proyecto.h"
#include "trans.h"
#include "proceso_datos.h"

#define EPSILIN_ANTIALIASING 1800.0000

Point3D pd, peye;
Window ventana;
Color background;
double ia, c1, c2, c3;
ObjectList lista_objetos = {NULL, NULL};	// La lista se encuentra vacIa al inicio.
LightList luces = {NULL, NULL};			// La lista de luces.
char * title;
int H_SIZE, V_SIZE;
FILE *output;
int nivel_reflexion, nivel_transparencia, nivel_anti;

Plane plane;

// Variables para la imagen
Color **buffer;
Color *actfila;

//Abtiene el color del pixel considerando el AntiAliasign
Color getColor_AntiAliasign(Color a, Color b , Color c, Color d, double i, double j , int level, double factor) {
	double L;
	Color rate = {(a.r+b.r+c.r+d.r) /4.0,
			(a.g+b.r+c.g+d.g) /4.0,
			(a.b+b.b+c.b+d.b) /4.0};

	//Calcula la diferencia entre los colores
 	L = 	(sqrt(  pow(a.r-b.r,2.0)+ pow(a.g-b.g,2.0)+pow(a.b-b.b,2.0))) +
		(sqrt(  pow(a.r-c.r,2.0)+ pow(a.g-c.g,2.0)+pow(a.b-c.b,2.0))) +
		(sqrt(  pow(a.r-d.r,2.0)+ pow(a.g-d.g,2.0)+pow(a.b-d.b,2.0))) +
		(sqrt(  pow(b.r-c.r,2.0)+ pow(b.g-c.g,2.0)+pow(b.b-c.b,2.0))) +
		(sqrt(  pow(b.r-d.r,2.0)+ pow(b.g-d.g,2.0)+pow(b.b-d.b,2.0))) ;

	//Si la diferencia es menor que el epsilon, regresa el promedio
	if (L < EPSILIN_ANTIALIASING) {
		//Promedio y es el nuevo color
		//printf ("[%f][%f]Promedio en Nivel (%i) \n",i,j,level);
		return rate;
	} else {
		Point3D ptemp;
		Color c1,c2,c3,c4,d,e,f,g,h,k;
		// Si no hay niveles regresa el promedio
		if (!level) return rate;

		//Calcular el E:Arriba
		ptemp.x = ventana.pmin.x + ((ventana.pmax.x - ventana.pmin.x) * (i + factor)) / H_SIZE;
  		ptemp.y = ventana.pmin.y + ((ventana.pmax.y - ventana.pmin.y) * (j )) / V_SIZE;
		L = (double) sqrt((ptemp.x - peye.x)*(ptemp.x - peye.x)	+ (ptemp.y - peye.y)*(ptemp.y - peye.y)
				+ (ptemp.z - peye.z)*(ptemp.z - peye.z) );
		pd.x = (ptemp.x - peye.x) / L;
		pd.y = (ptemp.y - peye.y) / L;
		pd.z = (ptemp.z - peye.z) / L;
		e = getColor(peye, pd, nivel_reflexion);


		//Calcular el F:izquierda
		ptemp.x = ventana.pmin.x + ((ventana.pmax.x - ventana.pmin.x) * (i )) / H_SIZE;
		ptemp.y = ventana.pmin.y + ((ventana.pmax.y - ventana.pmin.y) * (j - factor)) / V_SIZE;
		L = (double) sqrt((ptemp.x - peye.x)*(ptemp.x - peye.x)	+ (ptemp.y - peye.y)*(ptemp.y - peye.y)
				+ (ptemp.z - peye.z)*(ptemp.z - peye.z) );
		pd.x = (ptemp.x - peye.x) / L;
		pd.y = (ptemp.y - peye.y) / L;
		pd.z = (ptemp.z - peye.z) / L;
		f = getColor(peye, pd, nivel_reflexion);

		//Calcular el g:centro
		ptemp.x = ventana.pmin.x + ((ventana.pmax.x - ventana.pmin.x) * (i + factor)) / H_SIZE;
		ptemp.y = ventana.pmin.y + ((ventana.pmax.y - ventana.pmin.y) * (j - factor)) / V_SIZE;
		L = (double) sqrt((ptemp.x - peye.x)*(ptemp.x - peye.x)	+ (ptemp.y - peye.y)*(ptemp.y - peye.y)
				+ (ptemp.z - peye.z)*(ptemp.z - peye.z) );
		pd.x = (ptemp.x - peye.x) / L;
		pd.y = (ptemp.y - peye.y) / L;
		pd.z = (ptemp.z - peye.z) / L;
		g = getColor(peye, pd, nivel_reflexion);

		//Calcular el h:derecha
		ptemp.x = ventana.pmin.x + ((ventana.pmax.x - ventana.pmin.x) * (i + 2.0 * factor)) / H_SIZE;
		ptemp.y = ventana.pmin.y + ((ventana.pmax.y - ventana.pmin.y) * (j - factor)) / V_SIZE;
		L = (double) sqrt((ptemp.x - peye.x)*(ptemp.x - peye.x)	+ (ptemp.y - peye.y)*(ptemp.y - peye.y)
				+ (ptemp.z - peye.z)*(ptemp.z - peye.z) );
		pd.x = (ptemp.x - peye.x) / L;
		pd.y = (ptemp.y - peye.y) / L;
		pd.z = (ptemp.z - peye.z) / L;
		h = getColor(peye, pd, nivel_reflexion);

		//Calcular el J:abajo
		ptemp.x = ventana.pmin.x + ((ventana.pmax.x - ventana.pmin.x) * (i + factor)) / H_SIZE;
		ptemp.y = ventana.pmin.y + ((ventana.pmax.y - ventana.pmin.y) * (j - 2.0 * factor)) / V_SIZE;
		L = (double) sqrt((ptemp.x - peye.x)*(ptemp.x - peye.x)	+ (ptemp.y - peye.y)*(ptemp.y - peye.y)
				+ (ptemp.z - peye.z)*(ptemp.z - peye.z) );
		pd.x = (ptemp.x - peye.x) / L;
		pd.y = (ptemp.y - peye.y) / L;
		pd.z = (ptemp.z - peye.z) / L;
		k = getColor(peye, pd, nivel_reflexion);


		//Calcular cada MetaPixel... factor, i , j  diferentes
		c1 = getColor_AntiAliasign(a,e,f,g, i,j,level-1, factor / 2.0);
		c2 = getColor_AntiAliasign(e,b,g,h, i+factor,j,level-1, factor / 2.0);
		c3 = getColor_AntiAliasign(f,g,c,k, i,j-factor,level-1, factor / 2.0);
		c4 = getColor_AntiAliasign(g,h,k,d, i+factor,j-factor,level-1, factor / 2.0 );

		// Promedio Metapixeles
		//printf ("[%f][%f]Cuadrante en Nivel (%i) \n",i,j,level);
		rate.r = (c1.r+c2.r+c3.r+c4.r) / 4.0;
		rate.g = (c1.g+c2.g+c3.g+c4.g) / 4.0;
		rate.r = (c1.b+c2.b+c3.b+c4.b) / 4.0;

		return rate;
	}
}

void drawScene() {
	int i,j,k;
	double L;
	Point3D ptemp;
	IntersectionList il;
	Color c,d;
	static int lastX = 0;

	if (nivel_anti > -1) {
		//---------------

		//Redibuja una parte del buffer
		for (j = 0; j < lastX; j++) {
			for (i = 0; i < H_SIZE; i++) {
				glBegin(GL_POINTS);
				glColor3f(buffer[i][j].r,buffer[i][j].g,buffer[i][j].b);
				glVertex2i(i,j);
				glEnd();
			}
		}

		ptemp.z = 0;
		//RayTRacing Con AntiAliasing
		for (j=lastX;j<V_SIZE;j++){
			/*D = Obtener el punto (0,J-1)*/
			ptemp.x = ventana.pmin.x + ((ventana.pmax.x - ventana.pmin.x) * (i      )) / H_SIZE;
			ptemp.y = ventana.pmin.y + ((ventana.pmax.y - ventana.pmin.y) * (j - 1.0)) / V_SIZE;
			L = (double) sqrt((ptemp.x - peye.x)*(ptemp.x - peye.x)	+ (ptemp.y - peye.y)*(ptemp.y - peye.y)
					+ (ptemp.z - peye.z)*(ptemp.z - peye.z) );
			pd.x = (ptemp.x - peye.x) / L;
			pd.y = (ptemp.y - peye.y) / L;
			pd.z = (ptemp.z - peye.z) / L;
			d = getColor(peye, pd, nivel_reflexion);

			for (i=0,k=0;i<H_SIZE;i++,k++){
				Color a = actfila[k];
				Color b = actfila[k+1];
				c = d;

				//D = Obtener el punto (i+1,j+1)
				ptemp.x = ventana.pmin.x + ((ventana.pmax.x - ventana.pmin.x) * (i + 1.0)) / H_SIZE;
				ptemp.y = ventana.pmin.y + ((ventana.pmax.y - ventana.pmin.y) * (j - 1.0)) / V_SIZE;
				L = (double) sqrt((ptemp.x - peye.x)*(ptemp.x - peye.x)	+ (ptemp.y - peye.y)*(ptemp.y - peye.y)
						+ (ptemp.z - peye.z)*(ptemp.z - peye.z) );
				pd.x = (ptemp.x - peye.x) / L;
				pd.y = (ptemp.y - peye.y) / L;
				pd.z = (ptemp.z - peye.z) / L;
				d = getColor(peye, pd, nivel_reflexion);

				/*-- CALCULO EL COLOR--*/
				L = 	(sqrt(  pow(a.r-b.r,2.0)+ pow(a.g-b.g,2.0)+pow(a.b-b.b,2.0))) +
					(sqrt(  pow(a.r-c.r,2.0)+ pow(a.g-c.g,2.0)+pow(a.b-c.b,2.0))) +
					(sqrt(  pow(a.r-d.r,2.0)+ pow(a.g-d.g,2.0)+pow(a.b-d.b,2.0))) +
					(sqrt(  pow(b.r-c.r,2.0)+ pow(b.g-c.g,2.0)+pow(b.b-c.b,2.0))) +
					(sqrt(  pow(b.r-d.r,2.0)+ pow(b.g-d.g,2.0)+pow(b.b-d.b,2.0))) +
					(sqrt(  pow(c.r-d.r,2.0)+ pow(c.g-d.g,2.0)+pow(c.b-d.b,2.0))) ;


				if (L < EPSILIN_ANTIALIASING) {
				Color rate = {	(actfila[k].r+actfila[k+1].r+c.r+d.r) /4.0,
						(actfila[k].g+actfila[k+1].r+c.g+d.g) /4.0,
						(actfila[k].b+actfila[k+1].b+c.b+d.b) /4.0};
					buffer[i][j].r = rate.r;
					buffer[i][j].g = rate.g;
					buffer[i][j].b = rate.b;

					//printf ("[%i][%i]Promedio\t",i,j);
				} else {
					buffer[i][j] = getColor_AntiAliasign(actfila[k], actfila[k+1] , c, d, i, j , nivel_anti, 0.5);
					//printf ("[%i][%i]Cuadrantes\t",i,j);
				}
				//printf ("[%i][%i].... L=%f\n",i,j,L);
				//Pinta el pixel
				glBegin(GL_POINTS);
				glColor3f(buffer[i][j].r,buffer[i][j].g,buffer[i][j].b);
				glVertex2i(i,j);
				glEnd();

				/* prefila[k] = C */
				actfila[k].r = c.r;
				actfila[k].g = c.g;
				actfila[k].b = c.b;

				//Acutaliza el buffer
				lastX =j;
			}
		}
		lastX =j;
	}else {
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
				buffer[i][j] = getColor(peye, pd, nivel_reflexion);


				glBegin(GL_POINTS);
				glColor3f(buffer[i][j].r,buffer[i][j].g,buffer[i][j].b);
				glVertex2i(i,j);
				glEnd();
				//stats(i * V_SIZE + j);

				//Acualiza el valor de LastX
				lastX = i;
			}
		}

	}

	glFlush();
}


// Calcula La primera fila para el AntiAliasign
void pre_buffering (void) {
	int i , j=0;
	double L;
	Point3D ptemp;

	//Buffer Para AntiAliasing, Pide una columna + para el k+1 elemento
	actfila = (Color *) calloc(H_SIZE+1,sizeof(Color));
	ptemp.y = ventana.pmin.y + ((ventana.pmax.y - ventana.pmin.y) * (j )) / V_SIZE;

	//Calcula la fila actual
	for (i = 0; i <= H_SIZE; i++){
		ptemp.x = ventana.pmin.x + ((ventana.pmax.x - ventana.pmin.x) * (i + 1.0)) / H_SIZE;
		L = (double) sqrt((ptemp.x - peye.x)*(ptemp.x - peye.x)
					+ (ptemp.y - peye.y)*(ptemp.y - peye.y)
					+ (ptemp.z - peye.z)*(ptemp.z - peye.z) );
		pd.x = (ptemp.x - peye.x) / L;
		pd.y = (ptemp.y - peye.y) / L;
		pd.z = (ptemp.z - peye.z) / L;
		actfila[i] = getColor(peye, pd, nivel_reflexion);
	}
}


//PROGRAMA PRINCIPAL
main(int argc, char *argv[]) {
	int i,j;

	defaults();
	//Loading file :-s
	if (!LoadUniversoFromFile((char *)argv[1])) {
		pre_buffering();
		buffer = (Color **)calloc(H_SIZE,sizeof(Color *));
		for (i = 0; i < H_SIZE; i++)
			buffer[i] = (Color *) calloc(V_SIZE,sizeof(Color));
		printf("Objetos %i\n", countObjects(lista_objetos));
		printObjectList(lista_objetos);
		//printLightList(luces);
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
		//glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
		glutInitWindowSize(H_SIZE,V_SIZE);
		glutInitWindowPosition(800, 600);
		glutCreateWindow(title);
		glClear(GL_COLOR_BUFFER_BIT);
		gluOrtho2D(-0.5, H_SIZE +0.5, -0.5, V_SIZE + 0.5);
		glutDisplayFunc(drawScene);
		glutMainLoop();
	}
}
