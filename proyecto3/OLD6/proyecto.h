#ifndef _PROYECTO_
#define _PROYECTO_

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include "data_structures.h"

#define CHARS 60

typedef struct {
	Point3D pmin, pmax;
} Window;


extern StringList texturas_names, grises_names;
#endif
