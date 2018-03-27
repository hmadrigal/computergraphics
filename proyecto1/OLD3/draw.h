#ifndef DRAW
#define DRAW

//Biblioteca OpenGL
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include "universal_data.h"
#include "comandos.h"
#include "proyecto.h"


typedef struct {
	PixelPoint2D *p1, *p2;
	double xold, m;
} Line;

typedef struct lnode {
	Line line;
	struct lnode * next;
} LineNode;

typedef struct {
	LineNode *first, *last;
} LineList;

typedef struct pnode {
	PixelPoint2D point;
	struct pnode *next;
} PointNode;

typedef struct {
	PointNode *first, *last;
}PointList;

typedef struct {
	int ymax, ymin;
} Yminmax;

void linea(int x0, int y0, int x1, int y1, Color color);
void draw_mode_1 ();
Color * getColor(Image *image, PixelPoint2D p);
LineList addLine(LineList llist, Line line);
LineList getLines(PixelMapa *pm);
void printLines(LineList llist);
PointList addPoint(PointList pl, PixelPoint2D point);
int hayMinimoIgual(LineList llist, int yminPar);
LineList removeYmins(LineList llist, int yminPar);
int lengthPL(PointList pl);
void drawLines(PointList pl, Color color);
void draw_textura (PointList pl, Image *img) ;
#endif
