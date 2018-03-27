ESCENA
	TITULO	        "Shapes"     				//Título de la ventana
	VENTANA         (-100.0 -100.0) (100.0 100.0)   //(XMIN YMIN) (XMAX YMAX)
	COLOR_FONDO     0.0 0.0 0.0              		//R G B
	POSICION_OJO    (0.0 0.0 -300.0)   				//(Xe Ye Ze)
	LUZ_AMBIENTE    0.2                      		// [0..1] Ia
	FATT          	1.0 0.007 0.0006           		// C1 C2 C3
	RESOLUCION		300 300			// H_SIZE x V_SIZE

LUZ
	COLOR        1.0 1.0 1.0
	POSICION     (100.0 100.0 -150.0)
	INTENSIDAD   15.0
LUZ
	COLOR        1.0 1.0 1.0
	POSICION     (0.0 100.0 -150.0)
	INTENSIDAD   7.5
	
LUZ
	COLOR        1.0 1.0 1.0
	POSICION     (-100.0 100.0 -150.0)
	INTENSIDAD   15.0

/*
CILINDRO
	COLOR   0.823529 0.411764 0.117647
	KD 1.0 KA 0.2 KS 0.5 KN 50
	POSICION 0.0 0.0 0.0
	DIRECCION 0.0 1.0 0.0
	RADIO 10.0

CILINDRO
	COLOR   0.89 .15 .48
	KD 1.0 KA 0.2 KS 0.4 KN 45
	POSICION 0.0 0.0 0.0
	DIRECCION 1.0 0.0 0.0
	RADIO 10.0
*/

/*
ESFERA
	COLOR	0.5 0.7 0.6
	KD 0.9 KA 0.1 KS 0.5 KN 20
	POSICION 0.0 0.0 0.0
	RADIO 3.0

POLIGONO
	COLOR   0.78 0.75 0.8
	KD .75  KA 0.2 KS 0.85 KN 100
	(3.0 3.8 -5.0)
	(2.4 0.6 -5.0)
	(5.1 2.1 -5.0)
	(7.9 0.6 -5.0)
	(7.2 3.8 -5.0)
	(9.6 6.2 -5.0)
	(6.5 6.8 -5.0)
	(5.1 9.1 -5.0)
	(3.9 6.8 -5.0)
	(0.8 6.2 -5.0)

*/
POLIGONO
	COLOR   0.2 0.1 0.9
	KD 1.0  KA 0.2 KS 0.1 KN 300
	(-200.0 200.0 50.0)
	(-200.0 -200.0 50.0)
	(200.0 -200.0 50.0)
	(200.0 200.0 50.0)
	
/*
SUPERFICIE_2
	//Informacion General
	COLOR   0.1 0.9 0.2
	KD 1.0 KA 0.2 KS 1.0 KN 45


	//Describe la Ecuacion del Objeto = [A,B,D,E,F,G,H,J,K]
	[//CONO = Ax^2 +  By^2 + Dxy + Gx + Hy + K = 0
		0.00001,  0.00001 , 0.0 , -1.0 , 0.0 ,
		0.0 , 0.00001 , 0.0 , 0.0 , 1.0
	]
	TRASLADAR  [0.0,0.0,0.0]
	ESCALAR [1.0,1.0,1.0]
	
	ROTAR_X 0.0
	ROTAR_Y 0.0
	ROTAR_Z 0.0


SUPERFICIE_2
	//Informacion General
	COLOR   0.9 0.1 0.2
	KD 1.0 KA 0.2 KS 1.0 KN 45

	//Describe la Ecuacion del Objeto = [A,B,D,E,F,G,H,J,K]
	[//ESFERA= Ax^2 + BY^2 + CZ^2 + K = 0
		1.0 , 1.0 , 1.0 , 0.0 , 0.0 ,
		0.0 , 0.0 , 0.0 , 0.0 , -25.0
	]

	TRASLADAR  [0.0,0.0,-25.0]
	ESCALAR [1.025,1.025,1.025]
	ROTAR_X 0.0
	ROTAR_Y 0.0
	ROTAR_Z 0.0

*/
SUPERFICIE_2
	//Informacion General
	//COLOR   0.5 0.7 0.4
	COLOR   0.823529 0.411764 0.117647
	KD 1.0 KA 0.2 KS 1.0 KN 45

	//Describe la Ecuacion del Objeto = [A,B,D,E,F,G,H,J,K]
	/*
	[//ellipsoid (Real)
		1.5 , 1.0 , 1.05 , 0.0 , 0.0 ,
		0.0 , 0.0 , 0.0 , 0.0 , -10.2345345
	]
	TRASLADAR  [0.0,0.0,0.0]
	ESCALAR [1.0,1.0,1.0425]
	*/
	[//HYPERBOLOID OF TWO SHEETS
		1.0 , 1.0 , -1.0 , 0.0 , 0.0 ,
		0.0 , 0.0 , 0.0 , 0.0 , 0.5
	]
	TRASLADAR  [0.9,0.0,0.0]
	ESCALAR [0.425,0.425,1.0]
	ROTAR_X 0.0
	ROTAR_Y 0.0
	ROTAR_Z 0.0

/*
	[//Surface. Equation:  =
		0.0,  0.0 , 0.0 , 0.0 , 0.0 ,
		0.0 , 0.0 , 0.0 , 0.0 , 0.0
	]
	TRASLADAR  [0.0 , 0.0 , 0.0]
	ESCALAR [ 1.0 , 1.0 , 0.0]
*/

/*
	[//CILINDRO Direccion [0.0 0.0 1.0] ? 
		1.0 , 1.0 , 0.0 , 0.0 , 0.0 ,
		0.0 , 0.0 , 0.0 , 0.0 , -1.0
	]
	TRASLADAR  [0.9,0.0,0.0]
	ESCALAR [0.125,0.125,1.0]
	*/
	/*
	[//HYPERBOLOID OF TWO SHEETS
		1.0 , 1.0 , -1.0 , 0.0 , 0.0 ,
		0.0 , 0.0 , 0.0 , 0.0 , 0.5
	]
	TRASLADAR  [0.9,0.0,0.0]
	ESCALAR [0.425,0.425,1.0]
	*/
	/*
	[//ellipsoid (Real)
		1.5 , 1.0 , 1.05 , 0.0 , 0.0 ,
		0.0 , 0.0 , 0.0 , 0.0 , -10.2345345
	]
	TRASLADAR  [0.0,0.0,0.0]
	ESCALAR [1.0,1.0,1.0425]
	*/