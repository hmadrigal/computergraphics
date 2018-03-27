/*
Archivo: comandos.c
*/

#include "comandos.h"

//LOW - PAN 
int low_pan_left() {
	//printf("[LOW]Pan => LEFT\n");
	pan_window(-step_low_pan_x, .0);
}

int low_pan_right() {
	//printf("[LOW]Pan => RIGHT\n");
	pan_window(step_low_pan_x , .0);
}

int low_pan_up(){
	//printf("[LOW]Pan => UP\n");
	pan_window(.0, step_low_pan_y);
}

int low_pan_down(){
	//printf("[LOW]Pan => DOWN\n");
	pan_window(.0, -step_low_pan_y);
}

//HIGH - PAN
int high_pan_left() {
	//printf("[HIGH]Pan => LEFT\n");
	pan_window(-step_high_pan_x , .0);
}

int high_pan_right() {
	pan_window(step_high_pan_x , .0);
	//printf("[HIGH]Pan => RIGHT\n");
}

int high_pan_up(){
	pan_window(.0, step_high_pan_y);
	//printf("[HIGH]Pan => UP\n");
}

int high_pan_down(){
	pan_window(.0, -step_high_pan_y);
	//printf("[HIGH]Pan => DOWN\n");
}

//LOW - ZOOM
int low_zoom_in(){
	//printf("[LOW] Zoom IN\n");
	//zoom_window(porcent_low_zoom_in);
	zoom_window(-PORCENT_LOW_ZOOM);
}

int low_zoom_out(){
	//printf("[LOW] Zoom OUT\n");
	//zoom_window(porcent_low_zoom_out);
	zoom_window(PORCENT_LOW_ZOOM);
}

//HIGH - ZOOM
int high_zoom_in(){
	//printf("[HIGH] Zoom IN\n");
	//zoom_window(0.2,0.2);
	//zoom_window(porcent_high_zoom_out,porcent_high_zoom_out);
	zoom_window(PORCENT_HIGH_ZOOM);
}

int high_zoom_out(){
	//printf("[HIGH] Zoom OUT\n");
	//zoom_window(2.0,2.0);
	//zoom_window(porcent_high_zoom_in,porcent_high_zoom_in);
	zoom_window(-PORCENT_HIGH_ZOOM);
}

//LOW - ROTACION
int low_rotation_dir() {
	//printf("[LOW]Rotación Dir. Clock\n");
	rotate_maps(GRAD_LOW_ROTATION);
}

int low_rotation_inv() {
	//printf("[LOW]Rotación Inv. Clock\n");
	rotate_maps(-GRAD_LOW_ROTATION);
}

//HIGH - ROTATION
int high_rotation_dir() {
	//printf("[HIGH]Rotación Dir. Clock\n");
	rotate_maps(GRAD_HIGH_ROTATION);
}

int high_rotation_inv() {
	//printf("[HIGH]Rotación Inv. Clock\n");
	rotate_maps(-GRAD_HIGH_ROTATION);
}

//MODALIDADES:
int set_mode_1() {
	//printf("Modalidad 1: Sin Colorear.\n");
	mode=MODE_1;
	drawBuffer();
	//Indica que se debe redibujar
	glutPostRedisplay();
}

int set_mode_2() {
	//printf("Modalidad 2: Coloreado.\n");
	mode=MODE_2;
	drawBuffer();
	//Indica que se debe redibujar
	glutPostRedisplay();
}
int set_mode_3() {
	//printf("Modalidad 3: Texturas.\n");
	mode=MODE_3;
	drawBuffer();
	//Indica que se debe redibujar
 glutPostRedisplay();
}

//EXIT
int exit_program() {
	printf("Terminando el programa\n");
	exit(0);
}

//RESTART
int restart_program() {
	printf("Reiniciando el programa\n");
}
