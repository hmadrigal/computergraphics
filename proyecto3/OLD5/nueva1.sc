
	//TITULO	        "Thinking In ThinMan!"     //Título de la ventana
	VENTANA         (-100.0 -75.0) (100.0 75.0)       //(XMIN YMIN) (XMAX YMAX)
	COLOR_FONDO     255.0 250.0 250.0              //R G B
	POSICION_OJO    (10.0 10.0 -500.0)              //(Xe Ye Ze)
	LUZ_AMBIENTE    0.1                      // [0..1] Ia
	FATT          	1.0 0.005 0.00005              // C1 C2 C3
	RESOLUCION 640 480
	ANTIALIASING  -10
	REFLEXION 4
	TRANSPARECIA 4

MAPAS_DE_TEXTURAS
	TEXTURA "INGNORENME!!!!"		// No se cuenta
	TEXTURA "Durer.avs"			// #0
	TEXTURA "binocle3.avs"			// #1
	TEXTURA "fracmusicx.avs"		// #2
	TEXTURA "shakira1.avs"			// #3
	TEXTURA "shakira2.avs"			// #4

LUZ
	COLOR        25.0 25.0 25.0
	POSICION     (0.0 25.0 -80)
	INTENSIDAD   0.75

LUZ
	COLOR        25.0 25.0 25.0
	POSICION     (-30.0 25.0 -60)
	INTENSIDAD   0.80

LUZ
	COLOR        25.0 25.0 25.0
	POSICION     (30.0 25.0 -60)
	INTENSIDAD   0.85
LUZ
	COLOR        25.0 25.0 25.0
	POSICION     (50.0 -50.0 10.0)
	INTENSIDAD   2.50

OBJETO
	COLOR   127 127 127
	KD 0.98  KA 0.5 KS 0.3 KN 4000  KT 0.8 O1 0.005 O2 0.9 O3 0.005
POLIGONO
	ANCLA (0.0 0.0 0.0)
	PUNTOS
	(-100.0 100.0 0.0)
	(100.0 100.0 0.0)
	(100.0 -100.0 0.0)
	(-100.0 -100.0 0.0)
	/*
	TEXTURA
                IMAGEN 1
		STRETCH
                //TILED  100 100 //75 50
	*/
	TRANSFORMACIONES
		//ROTAR_Z 15
		ROTAR_Y -10
		//ROTAR_X 45
		TRASLADAR [0.0 0.0 300.0]

OBJETO
	COLOR	21 55 131
	KD 0.9 KA 0.7 KS 0.99 KN 500 KT 0.1 O1 1.0 O2 0.0 O3 0.0
ESFERA
	POSICION (0.0 0.0 0.0)
	RADIO 30
	GREENWICH [ 0.0 1.0 0.0 ]
	NORTE [ 1.0 0.0 0.0 ]
	TEXTURA
                IMAGEN 5
		//STRETCH
		TILED  20 20 //75 50
	TRANSFORMACIONES
		TRASLADAR [35.0 0.0 0.0]
