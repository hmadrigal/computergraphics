	TITULO	        "Thinking In ThinMan!"     //T�tulo de la ventana
	VENTANA         (-100.0 -75.0) (100.0 75.0)       //(XMIN YMIN) (XMAX YMAX)
	COLOR_FONDO     5.0 15.0 20.0              //R G B
	POSICION_OJO    (10.0 10.0 -500.0)              //(Xe Ye Ze)
	LUZ_AMBIENTE    0.1                      // [0..1] Ia
	FATT          	1.0 0.005 0.00005              // C1 C2 C3
	RESOLUCION 640 480
	ANTIALIASING 	-10
	REFLEXION 	2
	TRANSPARECIA 	2

MAPAS_DE_TEXTURAS
	TEXTURA "INGNORENME!!!!"		// No se cuenta
	TEXTURA "Durer.avs"			// #0
	TEXTURA "binocle3.avs"			// #1
	TEXTURA "fracmusicx.avs"		// #2
	TEXTURA "shakira1.avs"			// #3
	TEXTURA "shakira2.avs"			// #4
	TEXTURA "espace_010.avs"		// #5


LUZ
	COLOR        25.0 25.0 25.0
	POSICION     (0.0 150.0 -80)
	INTENSIDAD   1.2

LUZ
	COLOR        25.0 255.0 255.0
	POSICION     (0.0 150.0 150)
	INTENSIDAD   1.2

LUZ
	COLOR        255.0 255.0 255.0
	POSICION     (0.0 150.0 350)
	INTENSIDAD  1.2

LUZ
	COLOR        255.0 255.0 255.0
	POSICION     (30.0 15.0 -50.0)
	INTENSIDAD  2.0

//---------------------------------------------------------------
OBJETO //PARED de Abajo
	COLOR   35 102 147
	KD 0.7  KA 0.1 KS 0.9 KN 500 KT 0.3 O1 1.0 O2 0.0 O3 0.0
POLIGONO
	ANCLA (0.0 0.0 100.0)
	PUNTOS
	(-150.0 1500.0 100.0)
	(150.0 1500.0 100.0)
	(150.0 -200.0 100.0)
	(-150.0 -200.0 100.0)
	//TEXTURA
                //IMAGEN 1
		//STRETCH
                //TILED 50 50

	TRANSFORMACIONES
	ROTAR_X 87
	TRASLADAR [0.0 -50.0 0.0]

OBJETO //PARED Fondo
	COLOR   143 143 188
	KD 0.7  KA 0.1 KS 0.9 KN 500 KT 0.3 O1 0.1 O2 0.8 O3 0.1
POLIGONO
	ANCLA (0.0 0.0 0.0)
	PUNTOS
	(-150.0 150.0 0.0)
	(150.0 150.0 0.0)
	(150.0 -50.0 0.0)
	(-150.0 -50.0 0.0)

	//TEXTURA
                //IMAGEN 0
		//STRETCH
                //TILED  100 100 //75 50
	TRANSFORMACIONES
		//ROTAR_Z 15
		ROTAR_Y -10
		//ROTAR_X 150
		TRASLADAR [0.0 0.0 500.0]


OBJETO	//PARED Derecha
	COLOR   143 143 188
	KD 0.7  KA 0.1 KS 0.9 KN 500 KT 0.3 O1 1.0 O2 0.0 O3 0.0
POLIGONO
	ANCLA (0.0 0.0 0.0)
	PUNTOS
	(0.0 150.0 0.0)
	(0.0 150.0 500.0)
	(0.0 -50.0 500.0)
	(0.0 -50.0 0.0)
	TRANSFORMACIONES
	TRASLADAR [150.0 0.0 0.0]

OBJETO //PARED Izquierda
	COLOR   143 143 188
	KD 0.7  KA 0.1 KS 0.9 KN 500 KT 0.3 O1 1.0 O2 0.0 O3 0.0
POLIGONO
	ANCLA (0.0 0.0 0.0)
	PUNTOS
	(0.0 150.0 0.0)
	(0.0 150.0 500.0)
	(0.0 -50.0 500.0)
	(0.0 -50.0 0.0)
	TRANSFORMACIONES
	TRASLADAR [-150.0 0.0 0.0]
//-------------------------------------------------------------------------------PAREDES
OBJETO
	COLOR	21 55 131
	KD 0.9 KA 0.7 KS 0.99 KN 500 KT 0.1 O1 1.0 O2 0.0 O3 0.0 //O1 0.475 O2 0.05 O3 0.475
ESFERA
	POSICION (0.0 0.0 0.0)
	RADIO 35
	GREENWICH [ 0.0 1.0 0.0 ]
	NORTE [ 1.0 0.0 0.0 ]
	TEXTURA
                IMAGEN 3
		//STRETCH
		TILED  20 20 //75 50
	//PLANOS_DE_CORTE  PLANO_TRANSFORMADO_X + {}
	TRANSFORMACIONES
		//ROTAR_X 45
		ROTAR_Y -35
		ROTAR_Z 45
		TRASLADAR [35.0 0.0 150.0]
