#ifndef DATA_STRUCTURES
#define DATA_STRUCTURES

#define SPHERE		0x01
#define CONE			0x02
#define CILINDER		0x03
#define POLYGON		0x04

#define EPSILON 		0.0001
#define RADIAN		57.29577951

#define TRUE 1
#define FALSE 0

#define MIN(x,y) ((x)<(y))?(x):(y)

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
	char adm; // Para el lugar que apunta la Norma y el punto es aceptado
	Plane plane;
	struct plane_node * next;
} PlaneNodeList;

// Cutting Planes List
typedef struct {
	PlaneNodeList * first, *last;
} PlaneList;

typedef struct {
	Point3D center;
	double radius;
} Sphere;

typedef struct {
	Point3D center;
	Vector direction;
	double radius;
} Cilinder;

/* Tengo que averiguar que es la k en la funcion.
Puede ser la distancia de [x0, y0, z0] a [xm, ym, zm].*/
typedef struct {
	Point3D center;
	Vector direction;
	double radius;
	double distance;	//Altura del Cono
} Cone;

typedef struct {
	PointList pl;
	Plane plane;
} Polygon;

typedef struct st_object {
	Color color;
	double Kd, Ka, Ks;
	int Kn;
	//PlaneList plane_list;
	void *object;
	char tipo;
	struct st_object * next;
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

ObjectList addObjectDone(ObjectList ol, Object *tmp);
LightList addLight(LightList ll, double intensity, double color_r, double color_g, double color_b,
						double pos_x, double pos_y, double pos_z);
IntersectionList getIntersections(Point3D origin, Point3D direction);
Color getColor(Point3D origin, Point3D direction);
Vector makeVector(Point3D origin, Point3D direction);
Point3D getNormal(Point3D p, Object *obj);
double getIntensity(Point3D point, Point3D normal, Object *obj);
double getPhong(Point3D point, Point3D direction, Point3D normal, Object *obj);

extern ObjectList lista_objetos;
extern Color background;
extern LightList luces;
extern double ia, c1, c2, c3;
#endif
