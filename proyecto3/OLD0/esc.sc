ESCENA
	TITULO	        "Shapes"     				//T�tulo de la ventana
	VENTANA         (-320.0 -240.0) (320.0 240.0)   //(XMIN YMIN) (XMAX YMAX)
	COLOR_FONDO     0.0 0.0 0.0              		//R G B
	POSICION_OJO    (0.0 -0.0 -400.0)   				//(Xe Ye Ze)
	LUZ_AMBIENTE    0.2                      		// [0..1] Ia
	FATT          	1.0 0.009 0.00025           		// C1 C2 C3
	RESOLUCION	1280 1024			// H_SIZE x V_SIZE

LUZ
	COLOR        1.0 0.0 0.0
	POSICION     (200.0 200.0 -325.0)
	INTENSIDAD   40.0
LUZ
	COLOR        1.0 0.0 0.0
	POSICION     (200.0 -200.0 -325.0)
	INTENSIDAD   40.0
LUZ
	COLOR        0.0 0.0 1.0
	POSICION     (-275.0 200.0 -325.0)
	INTENSIDAD   40.0
LUZ
	COLOR        0.0 0.0 1.0
	POSICION     (-275.0 -200.0 -325.0)
	INTENSIDAD   40.0

POLIGONO
	COLOR   0.2 0.2 0.65
	KD 0.3  KA 0.5 KS 0.9 KN 500
	ANCLA  ( 0.0 0.0 0.0)
		(-320.0 -240.0 10.0)
		(-320.0 240.0 10.0)
		(320.0 240.0 10.0)
		(320.0 -240.0 10.0)
	TRANSFORMACIONES
		TRASLADAR  [0.0  0.0  200.0]
/*
POLIGONO
	COLOR   0.5165 0.6516 0.468146
	KD 1.0  KA 0.4 KS 0.1 KN 200
	ANCLA  ( 0.0 0.0 0.0)
		(0.0 100.0 0.0)
		(50.0 60.0 0.0)
		(100.0 50.0 0.0)
		(70.0 -20.0 0.0)
		(65.0 -75.0 0.0)
		(0.0 -50.0 0.0)
		(-65.0 -75.0 0.0)
		(-70.0 -20.0 0.0)
		(-100.0 50.0 0.0)
		(-50.0 60.0 0.0)
	TRANSFORMACIONES
		ROTAR_X 0.0
		ROTAR_Y 0.0
		ROTAR_Z 0.0


CILINDRO
	COLOR   0.89 .15 .48
	KD 1.0 KA 0.2 KS 0.4 KN 45
	POSICION 0.0 0.0 0.0
	DIRECCION 0.0 1.0 0.0
	RADIO 15.0
	TRANSFORMACIONES
		ROTAR_X 0.0
		ROTAR_Y 0.0
		ROTAR_Z -45.0

CONO
	COLOR   0.89 .15 .48
	KD 1.0 KA 0.2 KS 0.4 KN 45
	POSICION 0.0 0.0 0.0
	DIRECCION 0.0 1.0 0.0
	FACTOR_K 3.0

	TRANSFORMACIONES
		ROTAR_X 0.0
		ROTAR_Y 0.0
		ROTAR_Z 45.0

*/

/*
SUPERFICIE_2
	COLOR   1.0 0.1 0.2
	KD 0.3  KA 0.5 KS 0.9 KN 500
	//#1
	[1.0 , 1.0 , 1.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 1.0]

	PLANOS_DE_CORTE
		PLANO_PUNTOS - (100.0 0.0 0.0) (100.0 1.0 0.0) (100.0 0.0 1.0)
		PLANO_PUNTOS - (-100.0 0.0 0.0) (-100.0 1.0 0.0) (-100.0 0.0 -1.0)

		PLANO_PUNTOS - (0.0 100.0 0.0) (1.0 100.0 0.0) (0.0 100.0 -1.0)
		PLANO_PUNTOS - (0.0 -100.0 0.0) (1.0 -100.0 0.0) (0.0 -100.0 1.0)

		PLANO_PUNTOS - (0.0 0.0 100.0) (1.0 0.0 100.0) (0.0 0.0 100.0)

	TRANSFORMACIONES
		ROTAR_X 0.0
		ROTAR_Y 0.0
		ROTAR_Z 0.0
		ESCALAR [1.007 1.007 1.007]
		TRASLADAR  [0.0  0.0  0.0]
*/

SUPERFICIE_2
	COLOR   1.0 0.1 0.2
	KD 0.3  KA 0.5 KS 0.9 KN 500
	 //#2
	//[1.0 , 0.0 , 1.0 , 0.0 , 0.0 , 0.0 , 0.0 , -2.0 , 0.0 , 0.0]
	[1.9 , 1.0 , 1.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 1.0]


	PLANOS_DE_CORTE

		PLANO_PUNTOS - (75.0 0.0 0.0) (75.0 1.0 0.0) (75.0 0.0 1.0)
		PLANO_PUNTOS - (-75.0 0.0 0.0) (-75.0 1.0 0.0) (-75.0 0.0 -1.0)

		PLANO_PUNTOS - (0.0 75.0 0.0) (1.0 75.0 0.0) (0.0 75.0 -1.0)
		PLANO_PUNTOS - (0.0 -75.0 0.0) (1.0 -75.0 0.0) (0.0 -75.0 1.0)

		//PLANO_PUNTOS - (0.0 0.0 -60.0) (1.0 0.0 -60.0) (0.0 -1.0 -60.0)
		//PLANO_PUNTOS - (0.0 0.0 -60.0) (-1.0 0.0 -60.0) (0.0 -1.0 -60.0)

	TRANSFORMACIONES
		ROTAR_X 39.0
		ROTAR_Y 39.0
		ROTAR_Z 39.0
		//#2
		//ESCALAR [1.005 1.005 1.005]
		ESCALAR [1.04 1.04 1.04]
		TRASLADAR  [0.0  0.0  0.0]

