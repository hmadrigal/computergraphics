/*
Archivo: proyecto.h
 */
#ifndef _PROYECTO_
#define _PROYECTO_

	//Biblioteca OpenGL
	#include <GL/gl.h>
	#include <GL/glu.h>
	#include <GL/glut.h>
	
	#include "draw.h"
	#include "universal_data.h"
	#include "transf.h"
	#include "comandos.h"

	//Códigos para los MENUS
	#define MN_PAN_UP     		0x001
	#define MN_PAN_DOWN	0x002
	#define MN_PAN_LEFT		0x003
	#define MN_PAN_RIGHT	0x004
	
	#define MN_ZOOM_IN     	0x005
	#define MN_ZOOM_OUT	0x006
	
	#define MN_MODE_1     	0x007
	#define MN_MODE_2		0x008
	#define MN_MODE_3     	0x009
	
	#define MN_RESTART    	0x00A
	#define MN_BLANK    		0x00B
	#define MN_EXIT    		0x00C
	
	extern Color **buffer;
	extern int H_SIZE;
	extern int V_SIZE;

#endif
