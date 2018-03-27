/*
Archivo: comandos.h
*/
#ifndef _COMANDOS_
#define _COMANDOS_
	
	//Bibliotecas
	#include <stdio.h>
	#include <stdlib.h>
	#include <math.h>
	
	#include "transf.h"
	
	//Valores
	//Cantidad de segmentos en que se avanza HIGH, para el PAN
	#define VAL_HIGH_PAN_STEP_X	50.0
	#define VAL_HIGH_PAN_STEP_Y	25.0
	
	//Desplazamiento para el PAN
	#define VAL_LOW_PAN_X		1.0
	#define VAL_LOW_PAN_Y		1.0
	
	//Escala para ZOOM
	#define VAL_LOW_ZOOM_IN		0.5
	#define VAL_LOW_ZOOM_OUT 	2.0
	
	#define VAL_HIGH_ZOOM_IN	0.2
	#define VAL_HIGH_ZOOM_OUT 	5.0
#endif