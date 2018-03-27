/*
Archivo: comandos.c
*/

#include "comandos.h"

//LOW - PAN
int low_pan_left() {
	pan_window(-step_low_pan_x, .0);
}

int low_pan_right() {
	pan_window(step_low_pan_x , .0);
}

int low_pan_up(){
	pan_window(.0, step_low_pan_y);
}

int low_pan_down(){
	pan_window(.0, -step_low_pan_y);
}

//HIGH - PAN
int high_pan_left() {
	pan_window(-step_high_pan_x , .0);
}

int high_pan_right() {
	pan_window(step_high_pan_x , .0);
}

int high_pan_up(){
	pan_window(.0, step_high_pan_y);
}

int high_pan_down(){
	pan_window(.0, -step_high_pan_y);
}

//LOW - ZOOM
int low_zoom_in(){
	if((win.pmax.x - win.pmin.x) > limite && (win.pmax.y - win.pmin.y) > limite)
		zoom_window(-PORCENT_LOW_ZOOM);
}

int low_zoom_out(){
	if ((fabs(win.pmax.x - win.pmin.x) < 10963616.0) &&
	    (fabs(win.pmax.y - win.pmin.y) < 10963616.0))	
		zoom_window(PORCENT_LOW_ZOOM);
}

//HIGH - ZOOM
int high_zoom_in(){
	if((win.pmax.x - win.pmin.x) > limite && (win.pmax.y - win.pmin.y) > limite)
		zoom_window(-PORCENT_HIGH_ZOOM);
}

int high_zoom_out(){
	if ((fabs(win.pmax.x - win.pmin.x) < 10963616.0) &&
	    (fabs(win.pmax.y - win.pmin.y) < 10963616.0))
	zoom_window(PORCENT_HIGH_ZOOM);
}

//LOW - ROTACION
int low_rotation_dir() {
	rotate_maps(GRAD_LOW_ROTATION);
}

int low_rotation_inv() {
	rotate_maps(-GRAD_LOW_ROTATION);
}

//HIGH - ROTATION
int high_rotation_dir() {
	rotate_maps(GRAD_HIGH_ROTATION);
}

int high_rotation_inv() {
	rotate_maps(-GRAD_HIGH_ROTATION);
}

//MODALIDADES:
int set_mode_1() {
	mode=MODE_1;
	drawBuffer();
	//Indica que se debe redibujar
	glutPostRedisplay();
}

int set_mode_2() {
	mode=MODE_2;
	drawBuffer();
	//Indica que se debe redibujar
	glutPostRedisplay();
}
int set_mode_3() {
	mode=MODE_3;
	drawBuffer();
	//Indica que se debe redibujar
 glutPostRedisplay();
}

//EXIT
int exit_program() {
	exit(0);
}

//RESTART
int restart_program() {
	limpiaTrans();
	win = original_win;
	drawBuffer();
	//Indica que se debe redibujar
	glutPostRedisplay();
}
