ESCENA
	TITULO	        "Shapes"     				//Título de la ventana
	VENTANA         (-320.0 -240.0) (320.0 240.0)   //(XMIN YMIN) (XMAX YMAX)
	COLOR_FONDO     0.2 0.2 0.5              		//R G B
	POSICION_OJO    (0.0 0.0 -500.0)   				//(Xe Ye Ze)
	LUZ_AMBIENTE    0.2                      		// [0..1] Ia
	FATT          	1.0 0.009 0.00025           		// C1 C2 C3
	RESOLUCION		640 480			// H_SIZE x V_SIZE

LUZ
	COLOR        1.0 0.0 0.0
	POSICION     (175.0 150.0 -125.0)
	INTENSIDAD   10.0
LUZ
	COLOR        0.0 1.0 0.0
	POSICION     (0.0 -120.0 -300.0)
	INTENSIDAD   15.0
LUZ
	COLOR        0.0 0.0 1.0
	POSICION     (-175.0 150.0 -125.0)
	INTENSIDAD   10.0

LUZ
	COLOR        1.0 1.0 1.0
	POSICION     (0.0 0.0 -600.0)
	INTENSIDAD   100.0


POLIGONO
	COLOR   0.2 0.2 0.65
	KD 0.3  KA 0.5 KS 0.9 KN 500
	(-320.0 -240.0 1.0)
	(-320.0 240.0 1.0)
	(320.0 240.0 1.0)
	(320.0 -240.0 1.0)


/*
POLIGONO
	COLOR   0.5165 0.6516 0.468146
	KD 1.0  KA 0.4 KS 0.1 KN 200
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
*/
/*
SUPERFICIE_2
	COLOR   0.9 0.9 0.1
	KD 0.2  KA 0.2 KS 0.85 KN 300
	[1.0 , 1.9 , 1.0 , 0.0 , 0.0 ,
	 0.0 , 0.0 , 0.0 , 0.0 , -30.0]
	TRANSFORMACIONES
		ROTAR_X [1.0 , 0.0 , 0.0]
		ROTAR_Y [0.0 , 1.0 , 0.0]
		ROTAR_Z [0.0 , 0.0 , 1.0]
		ESCALAR [1.0225 , 1.0225 , 1.0225]
		TRASLADAR  [0.0 , 10.0 , 0.0]

*/
/*
SUPERFICIE_2
	COLOR   0.1 0.9 0.9
	KD 0.2  KA 0.2 KS 0.85 KN 300
	[1.9 , 1.0 , 1.0 , 0.0 , 0.0 ,
	 0.0 , 0.0 , 0.0 , 0.0 , -30.0]
	TRANSFORMACIONES
		ROTAR_X [0.3 , 0.0 , 0.0]
		ROTAR_Y [0.0 , 1.0 , 0.0]
		ROTAR_Z [0.0 , 0.0 , 1.0]
		ESCALAR [1.0 , 1.0 , 1.0]
		TRASLADAR  [0.0 , 10.0 , 0.0]
*/

SUPERFICIE_2
	COLOR   0.1 0.9 0.2
	KD 0.2  KA 0.2 KS 0.85 KN 300
	[1.0 , 1.0 , 1.0 , 0.0 , 0.0 ,
	 0.0 , 0.0 , 0.0 , 0.0 , -30.0]
	TRANSFORMACIONES
		ROTAR_X [1.0 , 0.0 , 0.0]
		ROTAR_Y [0.0 , 1.0 , 0.0]
		ROTAR_Z [0.0 , 0.0 , 1.0]
		ESCALAR [1.0155 , 1.0155 , 1.0155]
		TRASLADAR  [0.0 , 10.0 , 0.0]


/*
SUPERFICIE_2 //CONO = Ax^2 +  By^2 + Dxy + Gx + Hy + K = 0
	COLOR   0.9 0.1 0.2
	KD 0.75  KA 0.3 KS 0.6 KN 100
	[
		0.1,  0.1 , 0.0 , -1.0 , 0.0 ,
		0.0 , 0.1 , 0.0 , 0.0 , 1.0
	]
	TRANSFORMACIONES
		ROTAR_X [1.0 , 0.0 , 0.0]
		ROTAR_Y [0.0 , 1.0 , 0.0]
		ROTAR_Z [0.0 , 0.0 , 1.0]
		ESCALAR [0.11 , 0.11 , 0.11]
		TRASLADAR  [0.0,0.0,0.0]
*/