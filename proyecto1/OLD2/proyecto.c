/*
 */

#include "proyecto.h"

/* Buffer Para recodar los colores */
Color **buffer;

void drawScene() {
  static int lastX = 0;
  int i, j;
  Color *color;

  //Redibuja lo calculado hasta el momento
  for (i = 0; i < lastX; i++) {
    for (j = 0; j < V_SIZE; j++) {
      glColor3f(buffer[i][j].r,buffer[i][j].g,buffer[i][j].b);
      glBegin(GL_POINTS);
      glVertex2i(i,j);
      glEnd();
    }
  }

  //Se dibuja parte de la escena que no ha sido calculada
  color = (Color *)calloc(1,sizeof(Color));
  for (i = lastX; i < H_SIZE; i++) {
    for (j = 0; j < V_SIZE; j++) {

      // Guarda el color calculado en el buffer.
      buffer[i][j].r = color->r;
      buffer[i][j].g = color->g;
      buffer[i][j].b = color->b;

      // Idem (en el "for" anterior).
      glColor3f(color->r,color->g,color->b);
      glBegin(GL_POINTS);
      glVertex2i(i,j);
      glEnd();

      // Actualiza el valor de lastX calculado.
      lastX = i;
    }
  }
  free(color);

  //Limpia el buffer
  glFlush();
}

/*EVENTO KEYBOARD TECLADO*/
static void ev_keyboard(unsigned char key, int x, int y) {
	int modificador;	
	printf("ev_keyboard:\t");
	switch (key) {
		/*SALIR*/
		case 27: /*ESC*/
			printf("exit.... bye bye :P\n");
			exit(0);		
		break;
		case '+':
			modificador = glutGetModifiers();
			if (modificador == GLUT_ACTIVE_CTRL) {
				printf("[LOW] Zoom IN\n");
			} else {
				printf("[HIGH] Zoom IN\n");
			}
		break;
		case '-':
			modificador = glutGetModifiers();
			if (modificador == GLUT_ACTIVE_CTRL) {
				printf("[LOW] Zoom OUT\n");
			} else {
				printf("[HIGH] Zoom OUT\n");
			}
		break;
		//No Funcion
		default:
			printf("%c [%i]=> No tiene función asignada.\n",key,(int)key);
		break;
		
	}
}

/*EVENTO KEYBOARD TECLADO*/
static void ev_sp_keyboard (int key, int x, int y) {
	int modificador;
	printf("ev_sp_keyboard:\t");
	switch (key) {
		case GLUT_KEY_LEFT:
			modificador = glutGetModifiers();
			if (modificador == GLUT_ACTIVE_CTRL) {
				printf("[LOW]Pan => LEFT\n");
			} else {
				printf("[HIGH]Pan => LEFT\n");
			}
		break;
		case GLUT_KEY_RIGHT:
			modificador = glutGetModifiers();
			if (modificador == GLUT_ACTIVE_CTRL) {
				printf("[LOW]Pan => RIGHT\n");
			} else {
				printf("[HIGH]Pan => RIGHT\n");
			}
		break;
		
		case GLUT_KEY_UP:
			modificador = glutGetModifiers();
			if (modificador == GLUT_ACTIVE_CTRL) {
				printf("[LOW]Pan => UP\n");
			} else {
				printf("[HIGH]Pan => UP\n");
			}
		break;
		case GLUT_KEY_DOWN:
			modificador = glutGetModifiers();
			if (modificador == GLUT_ACTIVE_CTRL) {
				printf("[LOW]Pan => DOWN\n");
			} else {
				printf("[HIGH]Pan => DOWN\n");
			}
		break;
		case GLUT_KEY_F2:
			printf("F2 => Modalidad 1: Sin Colorear.\n");
			
		break;
		case GLUT_KEY_F3:
			printf("F3 => Modalidad 2: Coloreado.\n");
			
		break;
		case GLUT_KEY_F4:
			printf("F4 => Modalidad 3: Texturas.\n");			
		break;
		case GLUT_KEY_PAGE_UP:
			modificador = glutGetModifiers();
			if (modificador == GLUT_ACTIVE_CTRL) {
				printf("[LOW]Rotación Dir. Clock\n");
			} else {
				printf("[HIGH]Rotación Dir. Clock\n");
			}
		break;
		case GLUT_KEY_PAGE_DOWN:
			modificador = glutGetModifiers();
			if (modificador == GLUT_ACTIVE_CTRL) {
				printf("[LOW]Rotación Inv. Clock\n");
			} else {
				printf("[HIGH]Rotación Inv. Clock\n");
			}
		break;		
		//No Funcion
		default:
			printf("%c => No tiene función asignada.\n",key);
			glutPostRedisplay();
		break;		
	}
}

/*EVENTO MOUSE RATON*/
static void ev_mouse(int button, int state, int mousex, int mousey){
	printf("ev_mouse:\t");
}

/*PROCESAR SUBMENUS*/
void processMenuEvents(int option) {
	switch (option) {
		case MN_PAN_UP: 
		break;
		case MN_PAN_DOWN: 
		break;
		case MN_PAN_LEFT: 
		break;
		case MN_PAN_RIGHT: 
		break;
		
		case MN_ZOOM_IN: 
		break;
		case MN_ZOOM_OUT: 
		break;
		
		case MN_MODE_1: 
		break;
		case MN_MODE_2: 
		break;
		case MN_MODE_3: 
		break;
		
		case MN_RESTART: 
		break;
		case MN_BLANK: 
		break;
		case MN_EXIT: 
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
	
	
	glutAddMenuEntry("Pequeno",MN_BLANK);
	
	glutAddMenuEntry("-----------------",MN_BLANK);
	glutAddMenuEntry("Reiniciar",MN_RESTART);
	glutAddMenuEntry("Terminar",MN_EXIT);
	

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}


int main(int argc, char** argv) {
  int i, j;

  //Crea el buffer para el dibujo
  buffer = (Color **)calloc(H_SIZE,sizeof(Color *));
  for (i = 0; i < H_SIZE; i++) {
    buffer[i] = (Color *)calloc(V_SIZE,sizeof(Color));
  }
  
  // Inicialización del GLUT
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  // Tamaño de la ventana.
  glutInitWindowSize(H_SIZE,V_SIZE);

  // Título de la ventana.
  glutCreateWindow("Mi Costa Rica!");
  glClear(GL_COLOR_BUFFER_BIT);
  gluOrtho2D(-0.5, H_SIZE +0.5, -0.5, V_SIZE + 0.5);

  /*Asignando Rutinas a eventos del tecldo y Mouse*/
  glutKeyboardFunc(ev_keyboard);
  glutSpecialFunc(ev_sp_keyboard);
  glutMouseFunc(ev_mouse);
  
  // Se le dice al GLUT cual es la función que debe llamar
  // para la generación de la escena.
  glutDisplayFunc(drawScene);

  //Crear los menús
  createGLUTMenus();

  // Este metodo inicia al proceso de dibujado.
  glutMainLoop();
}
