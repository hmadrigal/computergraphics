#ifndef _TRANS_
#define _TRANS_

#include <math.h>
#include "data_structures.h"
#include "proceso_datos.h"

Object * translate_object(Object *obj, double tx, double ty, double tz);

Point3D rotate_x(Point3D p, Point3D ancla, double angle);
Point3D rotate_y(Point3D p, Point3D ancla, double angle);
Point3D rotate_z(Point3D p, Point3D ancla, double angle);
Point3D translate(Point3D p, double tx, double ty, double tz);
Object * translate_object(Object *obj, double tx, double ty, double tz);
void rotar_planos_x(Point3D centro, double angle);
void rotar_planos_y(Point3D centro, double angle);
void rotar_planos_z(Point3D centro, double angle);
void trasladar_planos(double tx, double ty, double tz);

extern Point3D pdisk1, pdisk2, pdisk3, ptmp1, ptmp2, ptmp3, ultimo_centro, Udisk, Vdisk, P0disk;
extern lista_puntos_planos * puntos_planos;
#endif
