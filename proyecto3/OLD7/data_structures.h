#ifndef DATA_STRUCTURES
#define DATA_STRUCTURES

#define SPHERE		0x01
#define CONE			0x02
#define CILINDER		0x03
#define POLYGON		0x04
#define DISK			0x05
#define SUPERFICIE2	0x06

#define EPSILON 		0.0001
#define RADIAN		57.29577951
#define PI			3.14159

#define TRUE 1
#define FALSE 0

#define MAX_X 		0x01
#define MAX_Y 		0x02
#define MAX_Z 		0x03

#define FILL_TILED		0x01
#define FILL_STRETCH		0x02

#define MIN(x,y) ((x)<(y))?(x):(y)
#define MAX(x,y) ((x)<(y))?(y):(x)

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
	double A,B,C,D,E,F,G,H,J,K;
} Superficie2;

typedef struct {
	double r, g, b;
} Color;

typedef struct {
	double x, y, z;
} Point3D;

typedef struct pl_node {
	Point3D point;
	struct pl_node * next;
} PointNodeList;

typedef struct {
	PointNodeList * first, * last;
} PointList;

typedef struct {
	Point3D direction;
} Vector;

typedef struct lg {
	double intensity;
	Point3D location;
	Color color;
	struct lg * next;
} Light;

typedef struct {
	Light *first, *last;
} LightList;

typedef struct {
	double A, B, C, D;
} Plane;

// Un nodo para la lista de planos
typedef struct plane_node {
	char adm; // 0 si el resultado en la evaluacion de la ecuacion es negativo
	Plane plane;
	struct plane_node * next;
} PlaneNodeList;

// Cutting Planes List
typedef struct {
	PlaneNodeList * first, *last;
} PlaneList;

typedef struct {
	Point3D center, north, greenwich;
	double radius;
	Plane plane;
} Sphere;

typedef struct {
	Point3D center, greenwich, north;
	Vector direction;
	double radius, distancia;
	Plane plane;
} Cilinder;

typedef struct {
	Point3D center, U, V, P0;
	Plane plane;
	double radius1, radius2;
} Disco;

/* Tengo que averiguar que es la k en la funcion.
Puede ser la distancia de [x0, y0, z0] a [xm, ym, zm].*/
typedef struct {
	Point3D center, greenwich, north;
	Vector direction;
	double fk, angle, distancia;
	Plane plane;
} Cone;

typedef struct {
	Point3D ancla;
	PointList pl;
	Plane plane;
	Point3D U;
	Point3D V;
	Point3D p0;
	double ancho;
	double alto;
} Polygon;

typedef struct p2d {
	double u, v;
	struct p2d *next;
} Point2D;

typedef struct {
	Point2D *first, *last;
} P2DList;

// Para el manejo de texturas
typedef struct sl {
	char *str;
	struct sl *next;
} str_list;

typedef struct {
	str_list *first, *last;
	char size;
} StringList;

typedef struct {
	int width, height;
	Color **image;
} Textura;

typedef struct {
	int width, height;
	double **grises;
} Mapa_Grises;


typedef struct {
	int index;		// El indice de la textura
	char tipo;		// Si es Tiled o Stretch
	int alto, ancho; // En caso de ser Stretch
} TexturaObjeto;

typedef struct {
	int index;
	char tipo;		// Si es Tiled o Stretch
	int alto, ancho; // En caso de ser Stretch
	double max, min;
} MapaAlturaObjeto;

typedef struct st_object {
	Color color;													// Color del Objeto
	double Kd, Ka, Ks, Kt, fO1, fO2, fO3;									// Factores
	int Kn;														// Otro Factor
	PlaneList plane_list;											// Lista de planos de corte
	TexturaObjeto *textura;											// Textura Asociada
	MapaAlturaObjeto *mapa;									// Mapa de Altura
	int mapa_brillo,mapa_altura, mapa_transparencia, mapa_calado, mapa_especular;		// Otros mapas
	char tipo;														// Tipo del objeto
	void *object;													// Datos del objeto
	struct st_object * next;											// Puntero al proximo objeto
} Object;

typedef struct {
	Object *first, *last;
} ObjectList;

typedef struct il {
	double t;
	Object * obj;
	struct il * next;
} Intersection;

typedef struct {
	Intersection * first, *last;
} IntersectionList;

typedef struct {
	double intensity, phong, Fatt;
} IP_st;

typedef struct {
	double u,v;
} UV_st;


PointList addPoint(PointList pl, double x, double y, double z);
ObjectList addObjectDone(ObjectList ol, Object *tmp);
LightList addLight(LightList ll, double intensity, double color_r, double color_g, double color_b,
						double pos_x, double pos_y, double pos_z);
IntersectionList getIntersections(Point3D origin, Point3D direction);
Color getColor(Point3D origin, Point3D direction, int nivel);
Vector makeVector(Point3D origin, Point3D direction);
Point3D getNormal(Point3D p, Object *obj);
double getIntensity(Point3D point, Point3D normal, Object *obj);
double getPhong(Point3D point, Point3D direction, Point3D normal, Object *obj);
Plane getPlane(Point3D p1, Point3D p2, Point3D p3);
Polygon * makePolygon(Point3D center, PointList pl);
int intersectPolygon(Point3D point, Polygon *pol);
PlaneList addPlaneObject(PlaneList plane_list, Plane plane, char sign);
PlaneList addPlane(PlaneList plane_list, double A, double B, double C, double D, char sign);
int isAccepted(double t, Point3D origin, Point3D direction, PlaneList plane_list);
P2DList addPoint2D(P2DList pl, double u, double v);
Color getTransparencia(Intersection *inter, int nivel, Point3D origin, Point3D direccion);
IP_st getIntensityAndPhong(Point3D point, Point3D direction, Point3D normal, Object *obj);
Color getTransparenciaMejorada(int nivel, Point3D point, Point3D origin, Point3D direction, Intersection *next_int, double Fatt);

UV_st getUV(Object *obj , Point3D pi , char mapeo);

// Para el manejo de texturas
StringList addString(StringList strl, char *str);
Textura *loadTextura(char *file);
Mapa_Grises * loadGris(char *file);
StringList freeStringList(StringList strl);
//int esAVS(FILE *f, AVSHeader h);

extern ObjectList lista_objetos;
extern Color background;
extern LightList luces;
extern double ia, c1, c2, c3;
extern int nivel_reflexion, nivel_transparencia, nivel_anti;
#endif
