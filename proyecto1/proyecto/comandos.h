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

	//Numero de Pixeles para el PAN [0..infinito]
	//DOUBLE
	#define PIXEL_HIGH_PAN		0.1
	#define PIXEL_LOW_PAN		0.05

	//Cantidad de Grados en la ROTACION [0..360]
	//INT
	#define GRAD_HIGH_ROTATION	20
	#define GRAD_LOW_ROTATION 	5

	//Porcentaje de pixeles, para el ZOOM [0..100]
	//DOUBLE
	#define PORCENT_HIGH_ZOOM 	0.10
	#define PORCENT_LOW_ZOOM  	0.05

	//Modos de visualizacion del mapa
	#define MODE_1 0x01
	#define MODE_2 0x02
	#define MODE_3 0x03


	//Variables externas al moduloS
	extern double step_high_pan_x;
	extern double step_high_pan_y;
	extern double step_low_pan_x;
	extern double step_low_pan_y;

	extern int mode;
	
#endif
