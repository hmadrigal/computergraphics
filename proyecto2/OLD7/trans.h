#ifndef _TRANS_
#define _TRANS_

#include <math.h>
#include "data_structures.h"

Object * translate_object(Object *obj, double tx, double ty, double tz);

Point3D rotate_x(Point3D p, Point3D ancla, double angle);
Point3D rotate_y(Point3D p, Point3D ancla, double angle);
Point3D rotate_z(Point3D p, Point3D ancla, double angle);
#endif
