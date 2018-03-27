#include "transf.h"

//Define cuanto debe ser el PAN-HIGH
double step_high_pan_x;
double step_high_pan_y;

// scale_at_center: T=>Trasladar , S=>Escalar
// [nx,ny] =  [x,y]*T(xc,yc) * S(alfa,alfa) * T(-xc,-yc)
void scale_at_center (double alfa, double xc, double yc, double x, double y,UniversalPoint2D *np) {
	np->x = (alfa * x) + ((-xc * alfa) + xc);
	np->y = (alfa * y) + ((-yc * alfa) + yc);
}

//Escala el Window desde el centro => Hace un Zoom.
void zoom_window(double alfa) {
	double xc,yc;
	UniversalPoint2D np;
	
	printf("OLD [Xmin=%f Ymin%f] [Xmax=%f Ymax%f]\n",win.pmin.x,win.pmin.y,win.pmax.x,win.pmax.y);
	
	// Calcula el centro
	xc = win.pmin.x + (win.pmax.x - win.pmin.x) / 2;
	yc = win.pmin.y + (win.pmax.y - win.pmin.y) / 2;
	
	//Calcula las transformaciones para cada punto
	scale_at_center (alfa,xc, yc, win.pmin.x, win.pmin.y, &np);
	win.pmin.x=np.x; win.pmin.y=np.y;
	
	scale_at_center (alfa,xc, yc, win.pmax.x, win.pmax.y, &np);
	win.pmax.x=np.x; win.pmax.y=np.y;
	
	printf("NEW [Xmin=%f Ymin%f] [Xmax=%f Ymax%f]\n",win.pmin.x,win.pmin.y,win.pmax.x,win.pmax.y);
}

//translate_at_point : T=>Trasladar
// [nx,ny] = [x,y]*T(tx,ty)
void translate_at_point (double tx,double ty,double x, double y, UniversalPoint2D *np) {
	np->x = x + tx;
	np->y = y + ty;
}

//Translador del window=> Hace Pan
void pan_window(double tx, double ty) {
	printf("OLD [Xmin=%f Ymin%f] [Xmax=%f Ymax%f]\n",win.pmin.x,win.pmin.y,win.pmax.x,win.pmax.y);
	win.pmin.x += tx; win.pmin.y += ty;
	win.pmax.x += tx; win.pmax.y += ty;
	printf("NEW [Xmin=%f Ymin%f] [Xmax=%f Ymax%f]\n",win.pmin.x,win.pmin.y,win.pmax.x,win.pmax.y);
}