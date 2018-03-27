/*
Archivo: univeresal_data.h
*/

#ifndef UNIVERSAL_DATA
#define UNIVERSAL_DATA

#include <stdio.h>
#include <string.h>
//#include "proyecto.h"

#define MAX_FILENAME_LENGTH 32
#define TRUE 1
#define FALSE 0

#define ADD_NEXT 			0x000
#define ADD_INTERSECTION	0x001
#define ADD_TWO			0x002
#define DO_NOT_ADD			0x003

#define RADIAN_VALUE		57.29577951

#define SWAP(x) ( ((x) << 24) | \
         (((x) << 8) & 0x00ff0000) | \
         (((x) >> 8) & 0x0000ff00) | \
         ((x) >> 24) )
#define FIX(x) (*(unsigned *)&(x) = \
         SWAP(*(unsigned *)&(x)))

typedef struct {
	unsigned char a, r, g, b;
} AVSPixel;

typedef struct {
	unsigned int ancho, alto;
} AVSHeader;

typedef struct {
	double x, y;
} UniversalPoint2D;

typedef struct {
	int x, y;
} PixelPoint2D;

typedef struct {
	UniversalPoint2D pmin, pmax, center;
} Window;

typedef struct {
	double r, g, b;
} Color;

typedef char Filename[MAX_FILENAME_LENGTH];

typedef struct {
	int width;
	int height;
	Color **buffer;
} Image;

typedef struct stlimite {
	UniversalPoint2D point;
	struct stlimite * next;
} Limite;

typedef struct stmapa {
	Color color;
	//Filename file;
	Image *image;
	Limite *first, *last;
	struct stmapa *next;
} Mapa;

typedef struct stlimitepix {
	PixelPoint2D point;
	struct stlimitepix * next;
} PixelLimite;

typedef struct stmapapix {
	Color color;
	//Filename file;
	Image *image;
	PixelLimite *first, *last;
	struct stmapapix *next;
} PixelMapa;

/* Prototipos */
UniversalPoint2D newUniversalPoint2D(double x, double y);
void setWindow(double x0, double y0, double x1, double y1);
void start_territory();
void set_color_map(double r, double g, double b);
void set_texture(char *str);
void addLimit(double x, double y);
int map_count();
Image * loadImage(char *file);
int test_xmax(UniversalPoint2D p1, UniversalPoint2D p2);
int test_xmin(UniversalPoint2D p1, UniversalPoint2D p2);
int test_ymax(UniversalPoint2D p1, UniversalPoint2D p2);
int test_ymin(UniversalPoint2D p1, UniversalPoint2D p2);
UniversalPoint2D xmax_intersect(UniversalPoint2D p1, UniversalPoint2D p2);
UniversalPoint2D xmin_intersect(UniversalPoint2D p1, UniversalPoint2D p2);
UniversalPoint2D ymax_intersect(UniversalPoint2D p1, UniversalPoint2D p2);
UniversalPoint2D ymin_intersect(UniversalPoint2D p1, UniversalPoint2D p2);
Mapa * clip_map_xmax(Mapa *mapa);
Mapa * clip_map_ymax(Mapa *mapa);
Mapa * clip_map_xmin(Mapa *mapa);
Mapa * clip_map_ymin(Mapa *mapa);
PixelMapa * clip_map(Mapa *mapa);
void clip_all_maps();
void free_tmp_map(Mapa *mapa);
void free_tmp_pixmap(PixelMapa *mapa);
void puntos(Mapa *mapa);
void puntosPixeles(PixelMapa *mapa);
PixelPoint2D Universal2Pixel(UniversalPoint2D p);
PixelMapa * Mapa2PixelMapa(Mapa *mapa);

/*Variables*/
extern Window win;
extern Mapa *first_map;
extern Mapa *last_map;
extern Mapa *first_transformed_map;
extern Mapa *last_transformed_map;
extern PixelMapa *first_clipped_map;
extern PixelMapa *last_clipped_map;
extern int H_SIZE;
extern int V_SIZE;
extern Color background;

#endif

