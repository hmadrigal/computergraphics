#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif
#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define yyclearin (yychar=(-1))
#define yyerrok (yyerrflag=0)
#define YYRECOVERING (yyerrflag!=0)
#define YYPREFIX "yy"
#line 2 "parser.y"
#include <stdio.h>
#include <string.h>
#include "proceso_datos.h"
#include "trans.h"

/* Variables externas*/
extern ObjectList lista_objetos;
extern Window ventana;
extern Color background;
extern double ia, c1, c2, c3;
extern Point3D peye;
extern LightList luces;
extern char *title;
extern int H_SIZE, V_SIZE;
extern Point3D peye;
extern lista_puntos_planos * puntos_planos;

extern char yytext[];
extern yylineno;
extern FILE *yyin;

/*Funciones externas*/
Object *tmp_obj = NULL;
Point3D pdisk1, pdisk2, pdisk3, ptmp1, ptmp2, ptmp3, ultimo_centro;
PointList lista_puntos;
double d_tmp;
Disco *dis;
Sphere *sph;
Cilinder *cil;
Cone *con;
Polygon *pol;
Superficie2 *spf;
Torus * tor;

#line 48 "parser.y"
typedef union {
	char *strval;
	double ldval;
} YYSTYPE;
#line 52 "y.tab.c"
#define ESCENA 257
#define LUZ 258
#define TITULO 259
#define CADENA 260
#define VENTANA 261
#define NUMERO 262
#define COLOR_FONDO 263
#define POSICION_OJO 264
#define LUZ_AMBIENTE 265
#define FATT 266
#define COLOR 267
#define POSICION 268
#define INTENSIDAD 269
#define ESFERA 270
#define POLIGONO 271
#define CILINDRO 272
#define CONO 273
#define DISCO 274
#define FACTOR_K 275
#define ANCLA 276
#define ROTAR_X 277
#define ROTAR_Y 278
#define ROTAR_Z 279
#define TRASLADAR 280
#define ESCALAR 281
#define KD 282
#define KA 283
#define KS 284
#define KN 285
#define KT 286
#define CENTRO 287
#define RADIO 288
#define O1 289
#define O2 290
#define O3 291
#define RESOLUCION 292
#define SUPERFICIE_2 293
#define ROTAR 294
#define DIRECCION 295
#define TRANSFORMACIONES 296
#define PLANOS_DE_CORTE 297
#define PLANO_TRANSFORMADO_X 298
#define PLANO_TRANSFORMADO_Y 299
#define PLANO_TRANSFORMADO_Z 300
#define REFLEXION 301
#define TRANSPARECIA 302
#define ANTIALIASING 303
#define OBJETO 304
#define PUNTOS 305
#define MAPAS_DE_TEXTURAS 306
#define MAPAS_DE_GRISES 307
#define TEXTURA 308
#define GRIS 309
#define IMAGEN 310
#define TILED 311
#define STRETCH 312
#define ALTURA 313
#define BRILLO 314
#define TRANSPARENCIA 315
#define PHONG 316
#define RANGO 317
#define TOROIDE 318
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    1,    1,    4,    4,    5,    5,    5,    5,    5,
    5,    5,    5,    5,    5,    2,    2,    6,    6,    7,
    7,    8,    8,   10,    9,    9,   11,   12,   14,   16,
   13,    3,    3,   20,   20,   21,   21,   22,   23,   25,
   24,   27,   27,   26,   28,   29,   30,   31,   15,   15,
   15,   15,   15,   15,   15,   18,   18,   32,   32,   33,
   33,   33,   33,   33,   33,   17,   17,   34,   34,   36,
   35,   38,   35,   39,   35,   40,   35,   41,   35,   42,
   35,   37,   37,   43,   43,   44,   44,   44,   44,   19,
   19,   45,   45,   47,   47,   46,   46,   46,   46,   46,
};
short yylen[] = {                                         2,
    3,    1,    0,    1,    2,    2,    9,    4,    6,    2,
    4,    3,    2,    2,    2,    1,    0,    1,    2,    2,
    2,    1,    2,    2,    1,    2,    2,   13,    0,    0,
   27,    1,    0,    1,    2,    1,    1,    4,    9,    0,
   12,    1,    2,    5,   11,   11,   22,   16,    1,    1,
    1,    1,    1,    1,    1,    2,    0,    1,    2,    2,
    2,    2,    6,    6,   18,    2,    0,    1,    2,    0,
    6,    0,    6,    0,    6,    0,    6,    0,    6,    0,
    6,    1,    0,    1,    2,    2,    2,    2,    6,    1,
    0,    1,    2,    1,    3,    4,    6,    3,    3,    3,
};
short yydefred[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    2,    0,    6,    0,    0,    0,   10,    0,
    0,   13,   14,   15,    0,    0,    0,    0,   18,    5,
    0,    0,    0,    0,   12,    0,    0,   22,    0,    0,
   25,    0,   29,    1,   36,   37,    0,   34,   19,    0,
    8,    0,   11,   24,   23,   27,   26,    0,    0,   35,
    0,    0,    0,    0,    0,    9,    0,    0,    0,    0,
    0,    0,    0,    0,    7,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   28,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   30,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   49,   50,   51,
   52,   53,   54,   55,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   68,    0,    0,    0,    0,    0,
    0,   38,    0,    0,   70,   72,   74,   76,   78,   80,
   69,    0,    0,    0,    0,    0,    0,   58,    0,    0,
    0,    0,    0,   31,    0,   92,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   60,    0,
   61,   62,    0,    0,   59,    0,    0,    0,    0,    0,
   93,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   98,   99,
  100,    0,   40,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   84,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   94,   96,    0,    0,    0,    0,    0,
    0,    0,   86,   87,   88,    0,   71,   85,   73,   75,
   77,   79,   81,    0,    0,    0,    0,    0,   39,    0,
    0,    0,    0,    0,    0,    0,   63,   64,   95,   97,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   46,   45,    0,    0,    0,    0,    0,    0,   41,    0,
    0,   89,    0,    0,   43,    0,    0,    0,   44,    0,
    0,    0,    0,    0,    0,    0,   48,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   65,   47,
};
short yydgoto[] = {                                      11,
   12,   27,   44,   13,   14,   28,   29,   37,   40,   38,
   41,   45,   46,   59,  107,   99,  123,  137,  164,   47,
   48,  108,  109,  110,  238,  288,  289,  111,  112,  113,
  114,  157,  158,  134,  135,  173,  222,  174,  175,  176,
  177,  178,  223,  224,  165,  166,  235,
};
short yysindex[] = {                                   -244,
 -247,  -24, -236,  -11, -230, -215, -213, -212, -210, -197,
    0, -264,    0, -244,    0, -196, -189, -183,    0, -182,
 -181,    0,    0,    0, -226, -225, -253, -264,    0,    0,
 -179, -177, -176, -175,    0, -172, -226,    0, -171, -225,
    0, -174,    0,    0,    0,    0, -253,    0,    0,   49,
    0, -170,    0,    0,    0,    0,    0, -168, -169,    0,
   51,   55, -167, -165, -163,    0, -162, -161, -160, -164,
 -159,   64,   66, -173,    0, -155, -154, -152, -166, -151,
 -150,   72, -158, -153, -148, -147, -157,    0, -144, -156,
 -143, -149, -142, -146, -141, -145, -140,    0, -262, -139,
 -138, -137, -136, -135,   34, -134, -133,    0,    0,    0,
    0,    0,    0,    0,   83,   84, -129, -127, -126, -125,
   87, -275, -130, -123, -121, -120, -119, -117,  103, -114,
   10,   32,   33, -275,    0, -217, -280, -113, -112, -111,
 -110,    0, -108, -107,    0,    0,    0,    0,    0,    0,
    0,  -91, -106, -105,   68,   69, -217,    0, -132, -128,
 -124, -122, -118,    0, -280,    0, -104, -101, -116, -115,
  118,  -99,   42,   45,   46,   47,   50,   52,    0,  -95,
    0,    0,  -90,  -88,    0,  -86,  -85,  -81,  -79,  -78,
    0,  144,  146,  -73,  -72,  -71,  152, -240, -240, -240,
 -240, -240, -240,  -68,  -67,  -66, -266, -109,    0,    0,
    0,  -89,    0,  -65,  -64,  156,  -94,  -60,  -59,  -58,
  114,   81, -240,    0,   82,   85,   86,   88,   89,  -53,
  -50,  -47,  -46,    0,    0,  -45,  -44,  -84,  -43,  -42,
  -40,  132,    0,    0,    0,  -38,    0,    0,    0,    0,
    0,    0,    0,  133,  134,  135,  -37,  -33,    0,  190,
  -57,  -41,  188,  -29,  -27,  -39,    0,    0,    0,    0,
  -26,  190,  -25,  -22,  -21,  -20,  -19,  147,  -18,  190,
    0,    0,  201,  -16,  154,  -14,  -13,  190,    0,  -12,
  158,    0,  -10,  212,    0,  210,  -32,   -7,    0,   -5,
   -4,  170,  220,    5,   -9,    6,    0,  175,  225,    9,
   11,   12,  231,   15,   16,  183,  186,    0,    0,
};
short yyrindex[] = {                                     30,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    2,    0,   44,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  280,    3,    0,    0,
    0,    0,    0,    0,    0,    0,   67,    0,    0,   74,
    0,    0,    0,    0,    0,    0,  281,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   14,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   41,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   27,    0,    0,    4,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   54,    0,    0,    0,
    0,    0,    0,    0,    7,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  157,  157,  157,
  157,  157,  157,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  159,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    1,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
    0,    0,    0,  269,    0,    0,  258,    0,    0,  250,
  249,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  243,    0,    0,    0,    0, -254,    8,    0,    0,    0,
    0,    0,  136,    0,  160,    0, -131,    0,    0,    0,
    0,    0,    0,   77,    0,  126,    0,
};
#define YYTABLESIZE 381
short yytable[] = {                                     180,
   42,   17,   16,   91,   42,  272,   90,  100,  101,  102,
  103,  104,   15,   67,    1,   16,    2,  280,    3,    4,
    5,    6,  131,  132,  133,   17,   66,  159,   18,    3,
  105,   19,  160,  161,  162,  163,  218,  219,  220,  221,
   57,   25,   26,    4,  233,  234,   20,    7,   21,   22,
   43,   23,  145,   56,  146,  106,    8,    9,   10,  152,
  153,  154,  155,  156,   24,   31,   20,  225,  226,  227,
  228,  229,   32,   21,  147,  149,  148,  150,   33,   34,
   35,   36,   50,   39,   51,   52,   53,   54,   56,   61,
   65,   62,   58,   63,   67,   66,   68,   64,   69,   70,
   71,   72,   74,   73,   75,   76,   78,   79,   77,   80,
   82,   83,   84,   87,   88,   86,   81,   90,   92,   94,
   96,   98,  124,  125,  120,   85,  130,   89,  115,   91,
  117,  118,  126,  121,  127,  128,  129,  116,  138,   93,
  139,  140,  141,   95,  142,   97,  143,  144,  167,  168,
  169,  170,  119,  171,  172,  181,  182,  192,  183,  184,
  193,  196,  197,  122,  198,  136,  204,  199,  200,  201,
  179,  205,  202,  206,  203,  207,  208,  186,  194,  195,
  209,  187,  210,  211,  212,  188,  213,  189,  214,  215,
  216,  190,  217,  230,  231,  232,  239,  240,  237,  241,
  242,  243,  244,  245,  246,  247,  249,  236,  254,  250,
  251,  255,  252,  253,  256,  257,  258,  259,  261,  262,
  260,  263,  264,  265,  269,  266,  267,  268,  270,  271,
  273,  275,  276,  274,  277,  279,  281,  286,  278,  282,
  283,  284,  285,  287,  290,  291,  292,  293,  294,  296,
  297,  298,  299,  300,  302,  301,  303,  304,   42,   17,
   16,   91,  305,  306,   90,  310,  307,  309,  311,  308,
  312,   67,  313,  314,  315,  318,  316,  317,  319,   33,
   32,   83,   30,   82,   66,   49,   55,    3,   57,   60,
  191,    0,  185,  151,    0,  295,   42,   42,   57,  248,
    0,    4,    0,    0,   42,   17,   16,   91,   42,   67,
   90,   56,    0,   42,   42,   42,   42,   67,    0,    0,
    0,   67,   66,    0,   20,    0,   67,   67,   67,   67,
   66,   21,    0,    3,   66,    3,    3,    0,    0,   66,
   66,   66,   66,    0,   57,    0,    0,    4,   57,    4,
    4,    0,    0,   57,   57,   57,   57,   56,    0,    0,
    0,   56,    0,    0,    0,    0,   56,   56,   56,   56,
   20,    0,   20,   20,    0,    0,    0,   21,    0,   21,
   21,
};
short yycheck[] = {                                      91,
    0,    0,    0,    0,  258,  260,    0,  270,  271,  272,
  273,  274,  260,    0,  259,   40,  261,  272,  263,  264,
  265,  266,  298,  299,  300,  262,    0,  308,   40,    0,
  293,  262,  313,  314,  315,  316,  277,  278,  279,  280,
    0,  306,  307,    0,  311,  312,  262,  292,  262,  262,
  304,  262,   43,    0,   45,  318,  301,  302,  303,  277,
  278,  279,  280,  281,  262,  262,    0,  199,  200,  201,
  202,  203,  262,    0,   43,   43,   45,   45,  262,  262,
  262,  308,  262,  309,  262,  262,  262,  260,  260,   41,
   40,  262,  267,  262,  262,   41,  262,  267,  262,  262,
  262,  262,  262,  268,   41,   40,  262,  262,  282,  262,
  262,  262,   41,  262,  262,  269,  283,  262,  262,  262,
  262,  262,   40,   40,   91,  284,   40,  285,  268,  286,
  268,  268,  262,  268,  262,  262,  262,  276,  262,  289,
  262,  262,  262,  290,  262,  291,   44,  262,  262,  262,
  262,  262,  288,  262,  262,  262,  262,  262,   91,   91,
  262,   44,  262,  297,  123,  296,  262,  123,  123,  123,
  262,  262,  123,  262,  123,  262,  262,  310,  295,  295,
  262,  310,  262,  262,   41,  310,   41,  310,  262,  262,
  262,  310,   41,  262,  262,  262,  262,  262,  288,   44,
  295,  262,  262,  262,   91,  125,  125,  317,  262,  125,
  125,  262,  125,  125,  262,  262,  262,  262,  262,  262,
  305,  262,   91,  262,  262,   93,   93,   93,  262,   40,
  288,   44,  262,  275,  262,  262,  262,   91,  278,  262,
  262,  262,  262,  262,   44,  262,   93,  262,  262,  262,
   93,  262,   41,   44,  262,  288,  262,  262,  258,  258,
  258,  258,   93,   44,  258,   91,  262,  262,   44,  279,
  262,  258,  262,  262,   44,   93,  262,  262,   93,    0,
    0,  125,   14,  125,  258,   28,   37,  258,   40,   47,
  165,   -1,  157,  134,   -1,  288,  296,  297,  258,  223,
   -1,  258,   -1,   -1,  304,  304,  304,  304,  308,  296,
  304,  258,   -1,  313,  314,  315,  316,  304,   -1,   -1,
   -1,  308,  296,   -1,  258,   -1,  313,  314,  315,  316,
  304,  258,   -1,  304,  308,  306,  307,   -1,   -1,  313,
  314,  315,  316,   -1,  304,   -1,   -1,  304,  308,  306,
  307,   -1,   -1,  313,  314,  315,  316,  304,   -1,   -1,
   -1,  308,   -1,   -1,   -1,   -1,  313,  314,  315,  316,
  304,   -1,  306,  307,   -1,   -1,   -1,  304,   -1,  306,
  307,
};
#define YYFINAL 11
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 318
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'",0,"'+'","','","'-'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,"ESCENA","LUZ","TITULO","CADENA","VENTANA","NUMERO","COLOR_FONDO",
"POSICION_OJO","LUZ_AMBIENTE","FATT","COLOR","POSICION","INTENSIDAD","ESFERA",
"POLIGONO","CILINDRO","CONO","DISCO","FACTOR_K","ANCLA","ROTAR_X","ROTAR_Y",
"ROTAR_Z","TRASLADAR","ESCALAR","KD","KA","KS","KN","KT","CENTRO","RADIO","O1",
"O2","O3","RESOLUCION","SUPERFICIE_2","ROTAR","DIRECCION","TRANSFORMACIONES",
"PLANOS_DE_CORTE","PLANO_TRANSFORMADO_X","PLANO_TRANSFORMADO_Y",
"PLANO_TRANSFORMADO_Z","REFLEXION","TRANSPARECIA","ANTIALIASING","OBJETO",
"PUNTOS","MAPAS_DE_TEXTURAS","MAPAS_DE_GRISES","TEXTURA","GRIS","IMAGEN",
"TILED","STRETCH","ALTURA","BRILLO","TRANSPARENCIA","PHONG","RANGO","TOROIDE",
};
char *yyrule[] = {
"$accept : inicia_gramatica",
"inicia_gramatica : escena mapas cuerpos",
"escena : lista_datos_escena",
"escena :",
"lista_datos_escena : dato_escena",
"lista_datos_escena : dato_escena lista_datos_escena",
"dato_escena : TITULO CADENA",
"dato_escena : VENTANA '(' NUMERO NUMERO ')' '(' NUMERO NUMERO ')'",
"dato_escena : COLOR_FONDO NUMERO NUMERO NUMERO",
"dato_escena : POSICION_OJO '(' NUMERO NUMERO NUMERO ')'",
"dato_escena : LUZ_AMBIENTE NUMERO",
"dato_escena : FATT NUMERO NUMERO NUMERO",
"dato_escena : RESOLUCION NUMERO NUMERO",
"dato_escena : REFLEXION NUMERO",
"dato_escena : TRANSPARECIA NUMERO",
"dato_escena : ANTIALIASING NUMERO",
"mapas : lista_mapas",
"mapas :",
"lista_mapas : textura_o_gris",
"lista_mapas : lista_mapas textura_o_gris",
"textura_o_gris : MAPAS_DE_TEXTURAS lista_texturas",
"textura_o_gris : MAPAS_DE_GRISES lista_grises",
"lista_texturas : textura",
"lista_texturas : lista_texturas textura",
"textura : TEXTURA CADENA",
"lista_grises : gris",
"lista_grises : lista_grises gris",
"gris : GRIS CADENA",
"luz : LUZ COLOR NUMERO NUMERO NUMERO POSICION '(' NUMERO NUMERO NUMERO ')' INTENSIDAD NUMERO",
"$$1 :",
"$$2 :",
"objeto : OBJETO $$1 COLOR NUMERO NUMERO NUMERO KD NUMERO KA NUMERO KS NUMERO KN NUMERO KT NUMERO O1 NUMERO O2 NUMERO O3 NUMERO $$2 objeto_real planos transformaciones images",
"cuerpos : lista_elementos",
"cuerpos :",
"lista_elementos : elemento",
"lista_elementos : lista_elementos elemento",
"elemento : luz",
"elemento : objeto",
"disco : DISCO RADIO NUMERO NUMERO",
"esfera : ESFERA POSICION '(' NUMERO NUMERO NUMERO ')' RADIO NUMERO",
"$$3 :",
"poligono : POLIGONO ANCLA '(' NUMERO NUMERO NUMERO ')' $$3 PUNTOS vertice vertice lista_vertices",
"lista_vertices : vertice",
"lista_vertices : vertice lista_vertices",
"vertice : '(' NUMERO NUMERO NUMERO ')'",
"cono : CONO POSICION NUMERO NUMERO NUMERO DIRECCION NUMERO NUMERO NUMERO FACTOR_K NUMERO",
"cilindro : CILINDRO POSICION NUMERO NUMERO NUMERO DIRECCION NUMERO NUMERO NUMERO RADIO NUMERO",
"superficie : SUPERFICIE_2 '[' NUMERO ',' NUMERO ',' NUMERO ',' NUMERO ',' NUMERO ',' NUMERO ',' NUMERO ',' NUMERO ',' NUMERO ',' NUMERO ']'",
"torus : TOROIDE POSICION '(' NUMERO NUMERO NUMERO ')' DIRECCION '[' NUMERO NUMERO NUMERO ']' RADIO NUMERO NUMERO",
"objeto_real : disco",
"objeto_real : esfera",
"objeto_real : poligono",
"objeto_real : cono",
"objeto_real : cilindro",
"objeto_real : superficie",
"objeto_real : torus",
"transformaciones : TRANSFORMACIONES lista_transformaciones",
"transformaciones :",
"lista_transformaciones : transformacion",
"lista_transformaciones : lista_transformaciones transformacion",
"transformacion : ROTAR_X NUMERO",
"transformacion : ROTAR_Y NUMERO",
"transformacion : ROTAR_Z NUMERO",
"transformacion : TRASLADAR '[' NUMERO NUMERO NUMERO ']'",
"transformacion : ESCALAR '[' NUMERO NUMERO NUMERO ']'",
"transformacion : ROTAR_X '[' NUMERO NUMERO NUMERO ']' ROTAR_Y '[' NUMERO NUMERO NUMERO ']' ROTAR_Z '[' NUMERO NUMERO NUMERO ']'",
"planos : PLANOS_DE_CORTE lista_planos",
"planos :",
"lista_planos : plano_de_corte",
"lista_planos : lista_planos plano_de_corte",
"$$4 :",
"plano_de_corte : PLANO_TRANSFORMADO_X '+' $$4 '{' tranformaciones_para_plano '}'",
"$$5 :",
"plano_de_corte : PLANO_TRANSFORMADO_X '-' $$5 '{' tranformaciones_para_plano '}'",
"$$6 :",
"plano_de_corte : PLANO_TRANSFORMADO_Y '+' $$6 '{' tranformaciones_para_plano '}'",
"$$7 :",
"plano_de_corte : PLANO_TRANSFORMADO_Y '-' $$7 '{' tranformaciones_para_plano '}'",
"$$8 :",
"plano_de_corte : PLANO_TRANSFORMADO_Z '+' $$8 '{' tranformaciones_para_plano '}'",
"$$9 :",
"plano_de_corte : PLANO_TRANSFORMADO_Z '-' $$9 '{' tranformaciones_para_plano '}'",
"tranformaciones_para_plano : trans_plano",
"tranformaciones_para_plano :",
"trans_plano : transforma_plano",
"trans_plano : trans_plano transforma_plano",
"transforma_plano : ROTAR_X NUMERO",
"transforma_plano : ROTAR_Y NUMERO",
"transforma_plano : ROTAR_Z NUMERO",
"transforma_plano : TRASLADAR '[' NUMERO NUMERO NUMERO ']'",
"images : image_list",
"images :",
"image_list : image",
"image_list : image_list image",
"tipo : STRETCH",
"tipo : TILED NUMERO NUMERO",
"image : TEXTURA IMAGEN NUMERO tipo",
"image : ALTURA IMAGEN NUMERO RANGO NUMERO NUMERO",
"image : BRILLO IMAGEN NUMERO",
"image : TRANSPARENCIA IMAGEN NUMERO",
"image : PHONG IMAGEN NUMERO",
};
#endif
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH 500
#endif
#endif
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short yyss[YYSTACKSIZE];
YYSTYPE yyvs[YYSTACKSIZE];
#define yystacksize YYSTACKSIZE
#line 423 "parser.y"

//Manejo de errores
yyerror(char *s)
{
	printf("YACC Says: Invalid \"%s\" in line %i.\n.", yytext, yylineno);
        fflush(stdout);
	yyerrok;
	exit(0);
}

//Inicia el Parseo de un archivo
int LoadUniversoFromFile (char *filename) {
	//arregla_trans();
	yyin = fopen(filename, "r+");
	if (! yyin) {
		printf("El archivo '%s'\n",filename);
		exit(0);
	}
	return yyparse();
}

void agrega_planos() {
	lista_puntos_planos *tmp;
	if(tmp = puntos_planos) {
		while(tmp) {
			if(tmp->chr)
				tmp_obj->plane_list = addPlaneObject(tmp_obj->plane_list, getPlane(ptmp1, ptmp2, ptmp3), TRUE);
			else
				tmp_obj->plane_list = addPlaneObject(tmp_obj->plane_list, getPlane(ptmp1, ptmp2, ptmp3), FALSE);
			tmp = tmp->next;
		}
	}
}
#line 523 "y.tab.c"
#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse()
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register char *yys;
    extern char *getenv();

    if (yys = getenv("YYDEBUG"))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if (yyn = yydefred[yystate]) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yyss + yystacksize - 1)
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;
#ifdef lint
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#ifdef lint
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yyss + yystacksize - 1)
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
case 1:
#line 59 "parser.y"
{printf("Termino el Parseo\n");}
break;
case 6:
#line 70 "parser.y"
{setTitle(yyvsp[0].strval);}
break;
case 7:
#line 71 "parser.y"
{setWindow(yyvsp[-6].ldval, yyvsp[-5].ldval, yyvsp[-2].ldval, yyvsp[-1].ldval);}
break;
case 8:
#line 72 "parser.y"
{setBackground((double) yyvsp[-2].ldval, (double) yyvsp[-1].ldval, (double)yyvsp[0].ldval);}
break;
case 9:
#line 73 "parser.y"
{setEye(yyvsp[-3].ldval, yyvsp[-2].ldval, yyvsp[-1].ldval);}
break;
case 10:
#line 74 "parser.y"
{setIntensidadAmbiente(yyvsp[0].ldval);}
break;
case 11:
#line 75 "parser.y"
{setFactoresAtenuacion(yyvsp[-2].ldval, yyvsp[-1].ldval, yyvsp[0].ldval);}
break;
case 12:
#line 76 "parser.y"
{setResolucion((int) yyvsp[-1].ldval, (int) yyvsp[0].ldval);}
break;
case 13:
#line 77 "parser.y"
{setReflexion((int) yyvsp[0].ldval);}
break;
case 14:
#line 78 "parser.y"
{setTransparencia((int) yyvsp[0].ldval);}
break;
case 15:
#line 79 "parser.y"
{setAnti((int) yyvsp[0].ldval);}
break;
case 20:
#line 90 "parser.y"
{loadTexturesList();}
break;
case 21:
#line 91 "parser.y"
{loadGrisesList();}
break;
case 24:
#line 98 "parser.y"
{texturas_names = addString(texturas_names, (char *) yyvsp[-1].strval);}
break;
case 27:
#line 105 "parser.y"
{grises_names = addString(grises_names, (char *) yyvsp[-1].strval);}
break;
case 28:
#line 111 "parser.y"
{
		luces = addLight(luces, (double) yyvsp[0].ldval,
							(double) yyvsp[-10].ldval / 255.0, (double) yyvsp[-9].ldval / 255.0, (double) yyvsp[-8].ldval / 255,
							(double) yyvsp[-5].ldval, (double) yyvsp[-4].ldval, (double) yyvsp[-3].ldval);
	}
break;
case 29:
#line 118 "parser.y"
{/*printf("Inicia Objeto\n");*/ nuevoObjeto();}
break;
case 30:
#line 127 "parser.y"
{
		tmp_obj->color.r = yyvsp[-18].ldval / 255;
		tmp_obj->color.g = yyvsp[-17].ldval / 255;
		tmp_obj->color.b = yyvsp[-16].ldval / 255;
		tmp_obj->Kd = yyvsp[-14].ldval;
		tmp_obj->Ka = yyvsp[-12].ldval;
		tmp_obj->Ks = yyvsp[-10].ldval;
		tmp_obj->Kn = yyvsp[-8].ldval;
		tmp_obj->Kt = yyvsp[-6].ldval;
		tmp_obj->fO1 = yyvsp[-4].ldval;
		tmp_obj->fO2 = yyvsp[-2].ldval;
		tmp_obj->fO3 = yyvsp[0].ldval;
		/*printf("*************** El kn es %i\n", tmp_obj->Kn);*/
	}
break;
case 31:
#line 144 "parser.y"
{
		if(tmp_obj->tipo == DISK) {
			dis->center = ultimo_centro;
			dis->plane = getPlane(pdisk1, pdisk2, pdisk3);
		}
		if(puntos_planos) {
			agrega_planos();
			puntos_planos = freeListaPlanosPuntos(puntos_planos);
		}
		/*printf("Vamos Agregar el Objeto\n");*/
		lista_objetos = addObjectDone(lista_objetos, tmp_obj);
		/*printf("Agregamos el Objeto\n");*/
		tmp_obj = NULL;
	}
break;
case 38:
#line 173 "parser.y"
{
		dis = (Disco *) calloc(1, sizeof(Disco));
		dis->radius1 = yyvsp[-1].ldval;
		dis->radius2 = yyvsp[0].ldval;
		tmp_obj->object = dis;
		tmp_obj->tipo = DISK;
		ultimo_centro.x = ultimo_centro.y = ultimo_centro.z = 0.0;
		pdisk1.x = pdisk1.y = pdisk1.z = 0.0;
		pdisk2.x = pdisk2.y = 1.0; pdisk2.z = 0.0;
		pdisk3.x = 1.0; pdisk3.y = pdisk3.z = 0.0;
		printf("Cargamos Datos Disco\n");
	}
break;
case 39:
#line 189 "parser.y"
{
		sph = (Sphere *) calloc(1, sizeof(Sphere));
		sph->center.x = yyvsp[-5].ldval;
		sph->center.y = yyvsp[-4].ldval;
		sph->center.z = yyvsp[-3].ldval;
		sph->radius = yyvsp[0].ldval;
		tmp_obj->object = sph;
		tmp_obj->tipo = SPHERE;
		ultimo_centro = sph->center;
		sph = NULL;
		printf("Cargamos Datos Esfera\n");
	}
break;
case 40:
#line 204 "parser.y"
{
		/*pol = (Sphere *) calloc(1, sizeof(Sphere));*/
		ultimo_centro.x = (double) yyvsp[-3].ldval;
		ultimo_centro.y = (double) yyvsp[-2].ldval;
		ultimo_centro.z = (double) yyvsp[-1].ldval;
		printf("Los datos son %.4f %.4f %.4f\n", ultimo_centro.x, ultimo_centro.y, ultimo_centro.z);
		lista_puntos.first = lista_puntos.last = NULL;
	}
break;
case 41:
#line 212 "parser.y"
{
		if(! (tmp_obj->object = makePolygon(ultimo_centro, lista_puntos))) {
			printf("Poligono Malo. No fue incluido\n");
			free(tmp_obj);
			freePointList(lista_puntos);
			tmp_obj = NULL;
		} else {
			tmp_obj->tipo = POLYGON;
			((Polygon *) tmp_obj->object)->ancla = ultimo_centro;
			/*lista_objetos = addObjectDone(lista_objetos, tmp_obj); // Agregamos el poligono*/
			printf("Cargamos Datos Poligono\n");
			}
	}
break;
case 44:
#line 231 "parser.y"
{lista_puntos = addPoint(lista_puntos, (double) yyvsp[-3].ldval, (double) yyvsp[-2].ldval, (double) yyvsp[-1].ldval);}
break;
case 45:
#line 237 "parser.y"
{
		con = (Cone *) calloc(1, sizeof(Cone));
		con->center.x = yyvsp[-8].ldval;
		con->center.y = yyvsp[-7].ldval;
		con->center.z = yyvsp[-6].ldval;
		d_tmp = sqrt(yyvsp[-4].ldval * yyvsp[-4].ldval + yyvsp[-3].ldval * yyvsp[-3].ldval + yyvsp[-2].ldval * yyvsp[-2].ldval);
		con->direction.direction.x = yyvsp[-4].ldval / d_tmp;
		con->direction.direction.y = yyvsp[-3].ldval / d_tmp;
		con->direction.direction.z = yyvsp[-2].ldval / d_tmp;
		con->fk = yyvsp[0].ldval;
		con->angle = cos(atan(con->fk));
		tmp_obj->tipo = CONE;
		tmp_obj->object = con;
		ultimo_centro = con->center;
		con = NULL;
		printf("Cargamos Datos Cono\n");
	}
break;
case 46:
#line 259 "parser.y"
{
		cil = (Cilinder *) calloc(1, sizeof(Cilinder));
		cil->center.x = yyvsp[-8].ldval;
		cil->center.y = yyvsp[-7].ldval;
		cil->center.z = yyvsp[-6].ldval;
		d_tmp = sqrt(yyvsp[-4].ldval * yyvsp[-4].ldval + yyvsp[-3].ldval * yyvsp[-3].ldval + yyvsp[-2].ldval * yyvsp[-2].ldval);
		cil->direction.direction.x = yyvsp[-4].ldval / d_tmp;
		cil->direction.direction.y = yyvsp[-3].ldval / d_tmp;
		cil->direction.direction.z = yyvsp[-2].ldval / d_tmp;
		cil->radius = yyvsp[0].ldval;
		tmp_obj->tipo = CILINDER;
		tmp_obj->object = cil;
		ultimo_centro = cil->center;
		cil = NULL;
		printf("Cargamos Datos Cilindro\n");
	}
break;
case 47:
#line 278 "parser.y"
{
		spf = (Superficie2 *) calloc(1, sizeof(Superficie2));
		spf->A = yyvsp[-19].ldval;  spf->B = yyvsp[-17].ldval;  spf->C = yyvsp[-15].ldval;
		spf->D = yyvsp[-13].ldval;  spf->E = yyvsp[-11].ldval; spf->F = yyvsp[-9].ldval;
		spf->G = yyvsp[-7].ldval; spf->H = yyvsp[-5].ldval; spf->J = yyvsp[-3].ldval;
		spf->K = yyvsp[-1].ldval;
		tmp_obj->tipo = SUPERFICIE2;
		tmp_obj->object = spf;
		spf = NULL;		/* No se cual es el centro en este*/
		printf("Cargamos Datos Superficie\n");
	}
break;
case 48:
#line 295 "parser.y"
{
		tor = (Torus *)calloc (1, sizeof (Torus));
		tor->center.x     = yyvsp[-12].ldval;
		tor->center.y     = yyvsp[-11].ldval;
		tor->center.z     = yyvsp[-10].ldval;
		tor->direction.x  =yyvsp[-6].ldval;
		tor->direction.y  =yyvsp[-5].ldval;
		tor->direction.z  =yyvsp[-4].ldval;
		tor->small_radius =yyvsp[-1].ldval;
		tor->big_radius   =yyvsp[0].ldval;
	}
break;
case 60:
#line 327 "parser.y"
{
	  	if(tmp_obj->tipo == DISK)
			rotar_disco_x((double) yyvsp[0].ldval / RADIAN);
		else tmp_obj = (Object *) rotate_x_object(tmp_obj, (double) yyvsp[0].ldval / RADIAN);}
break;
case 61:
#line 331 "parser.y"
{
	  	if(tmp_obj->tipo == DISK)
			rotar_disco_y((double) yyvsp[0].ldval / RADIAN);
		else tmp_obj = (Object *) rotate_y_object(tmp_obj, (double) yyvsp[0].ldval / RADIAN);}
break;
case 62:
#line 335 "parser.y"
{
	  	if(tmp_obj->tipo == DISK)
			rotar_disco_z((double) yyvsp[0].ldval / RADIAN);
		else tmp_obj = (Object *) rotate_z_object(tmp_obj, (double) yyvsp[0].ldval / RADIAN);}
break;
case 63:
#line 339 "parser.y"
{
	  	if(tmp_obj->tipo == DISK)
			trasladar_disco((double) yyvsp[-3].ldval, (double) yyvsp[-2].ldval, (double) yyvsp[-1].ldval);
		else tmp_obj = translate_object(tmp_obj, (double) yyvsp[-3].ldval, (double) yyvsp[-2].ldval, (double) yyvsp[-1].ldval);}
break;
case 70:
#line 358 "parser.y"
{ubica_plano_x();}
break;
case 71:
#line 358 "parser.y"
{
		puntos_planos = agregaPlano(puntos_planos, ptmp1, ptmp2, ptmp3, TRUE);
	}
break;
case 72:
#line 361 "parser.y"
{ubica_plano_x();}
break;
case 73:
#line 361 "parser.y"
{
		puntos_planos = agregaPlano(puntos_planos, ptmp1, ptmp2, ptmp3, FALSE);
	}
break;
case 74:
#line 364 "parser.y"
{ubica_plano_y();}
break;
case 75:
#line 364 "parser.y"
{
		puntos_planos = agregaPlano(puntos_planos, ptmp1, ptmp2, ptmp3, TRUE);
	}
break;
case 76:
#line 367 "parser.y"
{ubica_plano_y();}
break;
case 77:
#line 367 "parser.y"
{
		puntos_planos = agregaPlano(puntos_planos, ptmp1, ptmp2, ptmp3, FALSE);
	}
break;
case 78:
#line 370 "parser.y"
{ubica_plano_z();}
break;
case 79:
#line 370 "parser.y"
{
		puntos_planos = agregaPlano(puntos_planos, ptmp1, ptmp2, ptmp3, TRUE);
	}
break;
case 80:
#line 373 "parser.y"
{ubica_plano_z();}
break;
case 81:
#line 373 "parser.y"
{
		puntos_planos = agregaPlano(puntos_planos, ptmp1, ptmp2, ptmp3, FALSE);
	}
break;
case 86:
#line 386 "parser.y"
{
						ptmp1 = rotate_x(ptmp1, ultimo_centro, (double) yyvsp[0].ldval / RADIAN);
						ptmp2 = rotate_x(ptmp2, ultimo_centro, (double) yyvsp[0].ldval / RADIAN);
						ptmp3 = rotate_x(ptmp3, ultimo_centro, (double) yyvsp[0].ldval / RADIAN);}
break;
case 87:
#line 390 "parser.y"
{
						ptmp1 = rotate_y(ptmp1, ultimo_centro, (double) yyvsp[0].ldval / RADIAN);
						ptmp2 = rotate_y(ptmp2, ultimo_centro, (double) yyvsp[0].ldval / RADIAN);
						ptmp3 = rotate_y(ptmp3, ultimo_centro, (double) yyvsp[0].ldval / RADIAN);}
break;
case 88:
#line 394 "parser.y"
{
						ptmp1 = rotate_z(ptmp1, ultimo_centro, (double) yyvsp[0].ldval / RADIAN);
						ptmp2 = rotate_z(ptmp2, ultimo_centro, (double) yyvsp[0].ldval / RADIAN);
						ptmp3 = rotate_z(ptmp3, ultimo_centro, (double) yyvsp[0].ldval / RADIAN);}
break;
case 89:
#line 398 "parser.y"
{
						ptmp1 = translate(ptmp1, (double) yyvsp[-3].ldval, (double) yyvsp[-2].ldval, (double) yyvsp[-1].ldval);
						ptmp2 = translate(ptmp2, (double) yyvsp[-3].ldval, (double) yyvsp[-2].ldval, (double) yyvsp[-1].ldval);
						ptmp3 = translate(ptmp3, (double) yyvsp[-3].ldval, (double) yyvsp[-2].ldval, (double) yyvsp[-1].ldval);
		}
break;
#line 1015 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yyss + yystacksize - 1)
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    return (1);
yyaccept:
    return (0);
}
