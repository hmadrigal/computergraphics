/*
Archivo:
	firma.h
Creador: 
	Herberth Madrigal Bendless
*/

#ifndef FIRMA
#define FIRMA

//Biblioteca OpenGL
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <math.h>
#include <stdlib.h>

//#define DEBUG 		//Activar esta Macro para ver mensajes de depuración

//Estructuras
//COLOR
typedef struct {
	double r,g,b;
} tcolor;

//PUNTO
typedef struct {
	double x;
	double y;
} tpunto;

//TDA NODO-LINEA
typedef struct stlinea{
	tpunto p[4];		//Puntos que forman el Segmento
	tpunto *t;		//Puntos Discretos a partir del Segmento	
	
	struct stlinea *next;
}tlinea;


//TDA LISTA-LINEA
typedef struct stlista {
	tlinea *first;
} tlista;

#endif