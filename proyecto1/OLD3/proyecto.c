/*/////////////////////////////////////////////////////

ADMINISTRATIVO:
-------------------------------
	INTRODUCCION A LOS GRAFICOS POR COMPUTADORA
	Profesor:
		Fransisco Torres
	Estutiandes:
		Roberto Pineda
		Herberth Madrigal
	Objetivo:
		Implementacion de algoritmos para graficos en 2
		dimensiones.

PROGRAMA:
--------------------
	Nombre del programa:
	Nombre del archivo: proyecto.c
	Version : 1.0
	Release  :
	Fecha de inicio del proyecto: Lunes 09 diciembre 2002 (09/12/2002)
	Fecha de la ultima modificacion:


COMPILACION:
-------------------------
	El programa fue desarrollado y probado bajo (Linux)

	-> Sistema Operativo: 	Slackware 8.1.
	-> Compilador: 		GCC 2.95.3
	-> Bibliotecas: 		Mesa 3.4

	Para compilar ejecute el comando "make":

	$make


MANUAL:
----------------

NOTAS:
------------

BUGS:
---------

 /////////////////////////////////////////////////////*/

#include "proyecto.h"

/* Buffer Para recodar los colores */
Color **buffer;

int H_SIZE = 640;
int V_SIZE = 480;

double step_low_pan_x, step_low_pan_y, step_high_pan_y, step_high_pan_x;

void drawScene() {
	int i,j;

	glBegin(GL_POINTS);
	for (i = 0; i < H_SIZE; i++) {
		for (j = 0; j < V_SIZE; j++) {
			glColor3f(buffer[i][j].r,buffer[i][j].g,buffer[i][j].b);
			glVertex2i(i,j);
		}
	}
	glEnd();
	//Limpia el buffer
	glFlush();
}

/*EVENTO KEYBOARD TECLADO*/
void ev_keyboard(unsigned char key, int x, int y) {
	int modificador;	
	modificador = glutGetModifiers();
	switch (key) {
		/*SALIR*/
		case 27: /*ESC*/
			exit_program();
		break;
		case '+':			
			if (modificador == GLUT_ACTIVE_CTRL) {
				low_zoom_in();
			} else {
				high_zoom_in();
			}
		break;
		case '-':
			
			if (modificador == GLUT_ACTIVE_CTRL) {
				low_zoom_out();
			} else {
				high_zoom_out();
			}
		break;	
		//No Funcion
		default:
			//printf("ev_keyboard: %c [%i]=> No tiene función asignada.\n",key,(int)key);
		break;
		
	}
}

/*EVENTO KEYBOARD TECLADO*/
void ev_sp_keyboard (int key, int x, int y) {
	int modificador;
	switch (key) {
		case GLUT_KEY_LEFT:
			modificador = glutGetModifiers();
			if (modificador == GLUT_ACTIVE_CTRL) {
				low_pan_left();
			} else {
				high_pan_left();
			}
		break;
		case GLUT_KEY_RIGHT:
			modificador = glutGetModifiers();
			if (modificador == GLUT_ACTIVE_CTRL) {
				low_pan_right();
			} else {
				high_pan_right();
			}
		break;

		case GLUT_KEY_UP:
			modificador = glutGetModifiers();
			if (modificador == GLUT_ACTIVE_CTRL) {
				low_pan_up();
			} else {
				high_pan_up();
			}
		break;
		case GLUT_KEY_DOWN:
			modificador = glutGetModifiers();
			if (modificador == GLUT_ACTIVE_CTRL) {
				low_pan_down();
			} else {
				high_pan_down();
			}
		break;
		case GLUT_KEY_F1:
			set_mode_1();
		break;
		case GLUT_KEY_F2:
			set_mode_2();
		break;
		case GLUT_KEY_F3:
			set_mode_3();
		break;
		case GLUT_KEY_HOME:
			restart_program();
		break;
		case GLUT_KEY_PAGE_UP:
			modificador = glutGetModifiers();
			if (modificador == GLUT_ACTIVE_CTRL) {
				low_rotation_dir();
			} else {
				high_rotation_dir();
			}
		break;
		case GLUT_KEY_PAGE_DOWN:
			modificador = glutGetModifiers();
			if (modificador == GLUT_ACTIVE_CTRL) {
				low_rotation_inv();
			} else {
				high_rotation_inv();
			}
		break;
		//No Funcion
		default:
			//printf("ev_sp_keyboard: %c => No tiene función asignada.\n",key);
			glutPostRedisplay();
		break;
	}
}

/*EVENTO MOUSE RATON*/
void ev_mouse(int button, int state, int mousex, int mousey){
	printf("ev_mouse:\t");
}

/*PROCESAR SUBMENUS*/
void processMenuEvents(int option) {

	switch (option) {
		case MN_PAN_UP:
			high_pan_up();
		break;
		case MN_PAN_DOWN:
			high_pan_down();
		break;
		case MN_PAN_LEFT:
			high_pan_left();
		break;
		case MN_PAN_RIGHT:
			high_pan_right();
		break;

		case MN_ZOOM_IN: 
			high_zoom_in();
		break;
		case MN_ZOOM_OUT:
			high_zoom_out();
		break;
		
		case MN_MODE_1: 
			set_mode_1();
		break;
		case MN_MODE_2: 
			set_mode_2();
		break;
		case MN_MODE_3: 
			set_mode_3();
		break;
		
		case MN_RESTART: 
			restart_program();
		break;
		case MN_BLANK: 
			printf("Porque hacer click en una linea? :P \n");
		break;
		case MN_EXIT: 
			exit_program();
		break;
	
	}
}

/*CREAR MENUS - SUBMENUS*/
void createGLUTMenus(){
	int menu, sm_pan, sm_zoom, sm_mode;
	
	//Sun Menu MODALIDAD
	sm_mode = glutCreateMenu(processMenuEvents);
	glutAddMenuEntry("Sin Colorear",MN_MODE_1);
	glutAddMenuEntry("Coloreado",MN_MODE_2);
	glutAddMenuEntry("Texturas",MN_MODE_3);
	
	//Sub Menu PAN
	sm_pan = glutCreateMenu(processMenuEvents);
	glutAddMenuEntry("Arriba",MN_PAN_UP);
	glutAddMenuEntry("Abajo",MN_PAN_DOWN);
	glutAddMenuEntry("Izquieda",MN_PAN_LEFT);
	glutAddMenuEntry("Derecha",MN_PAN_RIGHT);
	
	//Sub Menu ZOOM
	sm_zoom = glutCreateMenu(processMenuEvents);
	glutAddMenuEntry("Dentro",MN_ZOOM_IN);
	glutAddMenuEntry("Fuera",MN_ZOOM_OUT);
	
	//POPUP Click-Right
	menu = glutCreateMenu(processMenuEvents);
	glutAddSubMenu("Modalidad",sm_mode);
	glutAddMenuEntry("-----------------",MN_BLANK);
	glutAddSubMenu("Pan",sm_pan);
	glutAddSubMenu("Zoom",sm_zoom);
	
	glutAddMenuEntry("-----------------",MN_BLANK);
	glutAddMenuEntry("Reiniciar",MN_RESTART);
	glutAddMenuEntry("Terminar",MN_EXIT);
	

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

//On_resize
void ev_reshape(int width, int height) {
}

//--------------------------------------
//PROGRAMA PRINCIPAL
//--------------------------------------
int main(int argc, char** argv) {
  int i, j;

  //Carga el Universo
  loadFile(argv[1]);
  clip_all_maps();

  //Crea el buffer para el dibujo
  buffer = (Color **)calloc(H_SIZE,sizeof(Color *));
  for (i = 0; i < H_SIZE; i++) {
    buffer[i] = (Color *)calloc(V_SIZE,sizeof(Color));
  }
  drawBuffer();
    //Fija El Tamano del STEP_PAN
  act_step_pan();

  // Inicialización del GLUT
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(H_SIZE,V_SIZE);
  glutInitWindowPosition(0,0);
  glutCreateWindow("Mi Costa Rica!");
  glClear(GL_COLOR_BUFFER_BIT);
  gluOrtho2D(-0.5, H_SIZE +0.5, -0.5, V_SIZE + 0.5);
  glutKeyboardFunc(ev_keyboard);
  glutSpecialFunc(ev_sp_keyboard);
  glutMouseFunc(ev_mouse);
  glutReshapeFunc(ev_reshape);
  glutDisplayFunc(drawScene);
  
  createGLUTMenus();
  glutMainLoop();
}
