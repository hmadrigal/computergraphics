ESCENA
	TITULO	        "Que tuanis!!!"     //T�tulo de la ventana
	VENTANA         (-30.0 -30.0) (30.0 30.0)       //(XMIN YMIN) (XMAX YMAX)
	COLOR_FONDO     0.45 0.45 0.45              //R G B
	POSICION_OJO    (0.0 0.0 -500.0)              //(Xe Ye Ze)
	LUZ_AMBIENTE    0.1                      // [0..1] Ia
	FATT          	1.0 0.005 0.00001              // C1 C2 C3
	RESOLUCION 500 500

LUZ
	COLOR        0.2 0.4 0.5
	POSICION     (5.0 20.0 -5.0)
	INTENSIDAD   0.8

LUZ
	COLOR        0.2 0.4 0.5
	POSICION     (-5.0 5.0 -20.0)
	INTENSIDAD   0.9
/*
DISCO
	COLOR	0.25 0.85 0.95
	KD 0.85 KA 0.2 KS 0.5 KN 3000
	POSICION 0.0 0.0 0.0
	PLANO_PUNTOS (0.0 0.0 0.0) (1.0 0.0 0.0) (0.5 2.0 1.0)
	RADIO 18.0 20.0

CONO
	COLOR	0.0 1.0 0.0
	KD 0.95 KA 0.2 KS 0.7 KN 30
	POSICION 0.0 0.0 0.0
	DIRECCION 0.0 1.0 0.0
	FACTOR_K 0.1
	PLANOS_DE_CORTE
	PLANO_PUNTOS + (0.0 0.0 0.0) (1.0 0.0 0.0) (0.0 0.0 -1.0)

ESFERA
	COLOR	1.0 1.0 1.0
	KD 0.85 KA 0.2 KS 0.5 KN 100
	POSICION 0.0 0.0 0.0
	RADIO 12.0
	PLANOS_DE_CORTE
	PLANO_PUNTOS - (0.0 0.0 -10.0) (0.0 10.0 -10.0) (5.0 11.0 -10.0)

CILINDRO
	COLOR   0.737255 0.411764 0.117647
	KD 1.0 KA 0.2 KS 0.5 KN 30
	POSICION 0.0 0.0 0.0
	DIRECCION 0.0 1.0 0.0
	RADIO 1.0
	PLANOS_DE_CORTE
	PLANO_PUNTOS + (0.0 0.0 0.0) (1.0 0.0 0.0) (0.5 1.0 1.0)*/

/*
CILINDRO
	COLOR   0.823529 0.411764 0.117647
	KD 1.0 KA 0.2 KS 0.5 KN 35
	POSICION 0.0 0.0 0.0
	DIRECCION 1.0 0.0 0.0
	RADIO 1.0*/

/*
CILINDRO
	COLOR   0.823529 0.411764 0.117647
	KD 1.0 KA 0.2 KS 0.5 KN 35
	POSICION 0.0 0.0 0.0
	DIRECCION 0.0 0.0 1.0
	RADIO 1.0*/
/*
SUPERFICIE_2
	COLOR   0.1 0.9 0.2
	KD 0.2  KA 0.2 KS 0.85 KN 300
	[1.5 , 1.0 , 1.0 , 0.0 , 0.0 ,
	 0.0 , 0.0 , 0.0 , 0.0 , -225.0]
	PLANOS_DE_CORTE
	PLANO_PUNTOS + (0.0 0.0 0.0) (1.0 0.0 0.0) (0.5 0.2 1.0)
	//TRANSFORMACIONES
		//ROTAR_X [1.0  0.0  0.0]
		//ROTAR_Y [0.0  1.0  0.0]
		//ROTAR_Z [0.0  0.0  1.0]
		//ESCALAR [1.0155  1.0155  1.0155]
		//TRASLADAR  [0.0  10.0  0.0]*/

SUPERFICIE_2
	COLOR   1.0 0.1 0.2
	KD 0.8  KA 0.2 KS 0.85 KN 300
	[1.5 , 1.0 , 1.05 , 0.0 , 0.0 ,
	 0.0 , 0.0 , 0.0 , 0.0 , -10.2345345]
	PLANOS_DE_CORTE
	PLANO_PUNTOS - (0.0 0.0 0.0) (1.0 0.0 0.0) (0.0 0.0 1.0)
	TRANSFORMACIONES
	ESCALAR [1.0 1.0 0.0425]
