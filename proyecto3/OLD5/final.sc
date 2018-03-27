
	TITULO	        "Thinking In ThinMan!"     //T�tulo de la ventana
	VENTANA         (-100.0 -75.0) (100.0 75.0)       //(XMIN YMIN) (XMAX YMAX)
	COLOR_FONDO    125 125 124            //R G B
	POSICION_OJO    (0.0 0.0 -500.0)              //(Xe Ye Ze)
	LUZ_AMBIENTE    0.1                      // [0..1] Ia
	FATT          	1.0 0.005 0.00005              // C1 C2 C3
	RESOLUCION 800 600
	ANTIALIASING -1
	TRANSPARECIA 	3
	REFLEXION 	3

MAPAS_DE_TEXTURAS
	TEXTURA "INGNORENME!!!!"		// No se cuenta
	TEXTURA "Durer.avs"			// #0
	TEXTURA "binocle3.avs"			// #1
	TEXTURA "fracmusicx.avs"		// #2
	TEXTURA "shakira1.avs"			// #3
	TEXTURA "shakira2.avs"			// #4

LUZ
	COLOR        25.0 25.0 25.0
	POSICION     (0.0 200.0 -130)
	INTENSIDAD   1.5

OBJETO
	COLOR   255.0 0.0 0.0
	KD 0.7  KA 0.5 KS 0.9 KN 325  KT 0.0 O1 1.0 O2 0.0 O3 0.6
ESFERA
	POSICION (0.0 0.0 0.)
	RADIO 10
	GREENWICH [ 0.0 1.0 0.0 ]
	NORTE [ 1.0 0.0 0.0 ]
	TRANSFORMACIONES
	TRASLADAR [0.0 15.0 0.0]

OBJETO
	COLOR   125.0 220.0 35.0
	KD 0.7  KA 0.5 KS 0.9 KN 500  KT 0.8 O1 0.6 O2 0.4 O3 0.6
ESFERA
	POSICION (0.0 0.0 0.)
	RADIO 15
	GREENWICH [ 0.0 1.0 0.0 ]
	NORTE [ 1.0 0.0 0.0 ]
	TRANSFORMACIONES
	TRASLADAR [30.0 -20.0 -100.0]

OBJETO
	COLOR   0.0 0.0 0.0
	KD 0.7  KA 0.5 KS 0.9 KN 500  KT 0.8 O1 1.0 O2 0.0 O3 0.6
ESFERA
	POSICION (0.0 0.0 0.)
	RADIO 20
	GREENWICH [ 0.0 1.0 0.0 ]
	NORTE [ 1.0 0.0 0.0 ]
	TRANSFORMACIONES
	TRASLADAR [-60.0 -5.0 -25.0]


OBJETO
	COLOR   255.0 255.0 255.0
	KD 0.98  KA 0.5 KS 0.3 KN 4000  KT 0.8 O1 0.0 O2 1.0 O3 0.6
POLIGONO
	ANCLA (0.0 0.0 0.0)
	PUNTOS
	(-300.0 -300.0 150.0)
	(300.0 -300.0 150.0)
	(300.0 300.0 150.0)
	(-300.0 300.0 150.0)