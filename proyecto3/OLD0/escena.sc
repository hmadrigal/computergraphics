ESCENA
	TITULO	        "Que tuanis!!!"     //T�tulo de la ventana
	VENTANA         (-100.0 -75.0) (100.0 75.0)       //(XMIN YMIN) (XMAX YMAX)
	COLOR_FONDO     0.45 0.45 0.45              //R G B
	POSICION_OJO    (10.0 10.0 -500.0)              //(Xe Ye Ze)
	LUZ_AMBIENTE    0.1                      // [0..1] Ia
	FATT          	1.0 0.005 0.00005              // C1 C2 C3
	RESOLUCION 320 420
/*
LUZ
	COLOR        0.2 0.4 0.5
	POSICION     (0.0 200.0 -80)
	INTENSIDAD   0.85

LUZ
	COLOR        0.2 0.4 0.5
	POSICION     (0.0 150.0 150)
	INTENSIDAD   0.85

LUZ
	COLOR        0.2 0.4 0.5
	POSICION     (0.0 200.0 350)
	INTENSIDAD  0.85


LUZ
	COLOR        0.2 0.4 0.5
	POSICION     (0.0 -30.0 0.0)
	INTENSIDAD  0.85

*/
LUZ
	COLOR        0.2 0.4 0.5
	POSICION     (0.0 0.0 -80.0)
	INTENSIDAD  0.85

LUZ
	COLOR        0.2 0.4 0.5
	POSICION     (-70.0 0.0 -80.0)
	INTENSIDAD  0.85

LUZ
	COLOR        0.2 0.4 0.5
	POSICION     (70.0 0.0 -80.0)
	INTENSIDAD  0.85

/*
POLIGONO
	COLOR  255 250 250
	KD 0.7  KA 0.5 KS 0.9 KN 500
	ANCLA (0.0 0.0 100.0)
	(-150.0 1500.0 100.0)
	(150.0 1500.0 100.0)
	(150.0 -200.0 100.0)
	(-150.0 -200.0 100.0)
	TRANSFORMACIONES
	ROTAR_X 87
	TRASLADAR [0.0 -50.0 0.0]

POLIGONO
	COLOR   255 250 250
	KD 0.7  KA 0.5 KS 0.9 KN 500
	ANCLA (0.0 0.0 0.0)
	(-150.0 150.0 0.0)
	(150.0 150.0 0.0)
	(150.0 -50.0 0.0)
	(-150.0 -50.0 0.0)
	TRANSFORMACIONES
	TRASLADAR [0.0 0.0 500.0]

POLIGONO
	COLOR   255 250 250
	KD 0.7  KA 0.5 KS 0.9 KN 500
	ANCLA (0.0 0.0 0.0)
	(0.0 150.0 0.0)
	(0.0 150.0 500.0)
	(0.0 -50.0 500.0)
	(0.0 -50.0 0.0)
	TRANSFORMACIONES
	TRASLADAR [150.0 0.0 0.0]

POLIGONO
	COLOR  255 250 250
	KD 0.7  KA 0.5 KS 0.9 KN 500
	ANCLA (0.0 0.0 0.0)
	(0.0 150.0 0.0)
	(0.0 150.0 500.0)
	(0.0 -50.0 500.0)
	(0.0 -50.0 0.0)
	TRANSFORMACIONES
	TRASLADAR [-150.0 0.0 0.0]
*/

/*
CILINDRO
	COLOR  50 50 50
	KD 1.0 KA 0.2 KS 0.5 KN 30
	POSICION 0.0 0.0 0.0
	DIRECCION 0.0 1.0 0.0
	RADIO 1.0

CILINDRO
	COLOR  50 50 50
	KD 1.0 KA 0.2 KS 0.5 KN 30
	POSICION 0.0 0.0 0.0
	DIRECCION 1.0 0.0 0.0
	RADIO 1.0

CILINDRO
	COLOR  50 50 50
	KD 1.0 KA 0.2 KS 0.5 KN 30
	POSICION 0.0 0.0 0.0
	DIRECCION 0.0 0.0 1.0
	RADIO 1.0*/
/*
ESFERA
	COLOR	150.0 230.0 52.0
	KD 0.85 KA 0.2 KS 0.5 KN 100
	POSICION 0.0 0.0 0.0
	RADIO 25.0
	PLANOS_DE_CORTE
	PLANO_TRANSFORMADO + {
		ROTAR_X 60
	}
	PLANO_TRANSFORMADO - {
		ROTAR_X 115
	}
	
DISCO
	COLOR	200.0 30.0 12.0
	KD 0.85 KA 0.2 KS 0.5 KN 3000
	POSICION 0.0 30.0 0.0
	PLANO_PUNTOS (0.0 0.0 0.0) (1.0 0.0 0.0) (0.5 2.0 1.0)
	RADIO 18.0 20.0*/

// 										MESA
/*
POLIGONO
	COLOR  255.0 127.0 0.0
	KD 0.9  KA 0.5 KS 0.5 KN 500
	ANCLA (0.0 0.0 0.0)
	(0.0 0.0 0.0)
	(50.0 0.0 0.0)
	(50.0 75.0 0.0)
	(0.0 75.0 0.0)
	TRANSFORMACIONES
	ROTAR_X 87
	ROTAR_Y 15
	TRASLADAR [-70.0 -30.0 20.0]
	
POLIGONO
	COLOR  255.0 127.0 0.0
	KD 0.9  KA 0.5 KS 0.5 KN 500
	ANCLA (0.0 0.0 0.0)
	(0.0 0.0 0.0)
	(50.0 0.0 0.0)
	(50.0 5.0 0.0)
	(0.0 5.0 0.0)
	TRANSFORMACIONES
	ROTAR_Y 15
	TRASLADAR [-70.0 -35.0 20.0]
	
POLIGONO
	COLOR  255.0 127.0 0.0
	KD 0.9  KA 0.5 KS 0.5 KN 500
	ANCLA (0.0 0.0 0.0)
	(0.0 0.0 0.0)
	(0.0 0.0 75.0)
	(0.0 5.0 75.0)
	(0.0 5.0 0.0)
	TRANSFORMACIONES
	ROTAR_X -3
	ROTAR_Y 15
	TRASLADAR [-22.0 -35.0 10.0]

CILINDRO
	COLOR  255.0 127.0 0.0
	KD 1.0 KA 0.2 KS 0.5 KN 30
	POSICION 0.0 0.0 0.0
	DIRECCION 0.0 1.0 0.0
	RADIO 3.0
	PLANOS_DE_CORTE
	PLANO_TRANSFORMADO - {
		ROTAR_X 90
		TRASLADAR [.0 -35.0 0.0]
	}
	TRANSFORMACIONES
	TRASLADAR [-25.0 -35.0 15.0]

CILINDRO
	COLOR  255.0 127.0 0.0
	KD 1.0 KA 0.2 KS 0.5 KN 30
	POSICION 0.0 0.0 0.0
	DIRECCION 0.0 1.0 0.0
	RADIO 3.0
	PLANOS_DE_CORTE
	PLANO_TRANSFORMADO - {
		ROTAR_X 90
		TRASLADAR [.0 -35.0 0.0]
	}
	TRANSFORMACIONES
	TRASLADAR [-63.0 -35.0 25.0]

CILINDRO
	COLOR  255.0 127.0 0.0
	KD 1.0 KA 0.2 KS 0.5 KN 30
	POSICION 0.0 0.0 0.0
	DIRECCION 0.0 1.0 0.0
	RADIO 3.0
	PLANOS_DE_CORTE
	PLANO_TRANSFORMADO - {
		ROTAR_X 90
		TRASLADAR [0.0 -30.0 0.0]
	}
	TRANSFORMACIONES
	TRASLADAR [-12.0 -35.0 70.0]

CILINDRO
	COLOR  255.0 127.0 0.0
	KD 1.0 KA 0.2 KS 0.5 KN 30
	POSICION 0.0 0.0 0.0
	DIRECCION 0.0 1.0 0.0
	RADIO 3.0
	PLANOS_DE_CORTE
	PLANO_TRANSFORMADO - {
		ROTAR_X 90
		TRASLADAR [0.0 -30.0 0.0]
	}
	TRANSFORMACIONES
	TRASLADAR [-47.0 -35.0 80.0]

CILINDRO
	COLOR  255.0 127.0 0.0
	KD 1.0 KA 0.2 KS 0.5 KN 30
	POSICION 0.0 0.0 0.0
	DIRECCION 1.0 0.0 0.0
	RADIO 1.0
	PLANOS_DE_CORTE
	PLANO_TRANSFORMADO + {
		ROTAR_X 90
		ROTAR_Z 90
		TRASLADAR [-25.0 0.0 0.0]
	}
	PLANO_TRANSFORMADO - {
		ROTAR_X 90
		ROTAR_Z 90
		TRASLADAR [-60.0 0.0 0.0]
	}
	TRANSFORMACIONES
	ROTAR_Y 15
	TRASLADAR [-70.0 -45.0 27.0]
	
CILINDRO
	COLOR  255.0 127.0 0.0
	KD 1.0 KA 0.2 KS 0.5 KN 30
	POSICION 0.0 0.0 0.0
	DIRECCION 1.0 0.0 0.0
	RADIO 1.0
	PLANOS_DE_CORTE
	PLANO_TRANSFORMADO + {
		ROTAR_X 90
		ROTAR_Z 90
		TRASLADAR [-15.0 0.0 0.0]
	}
	PLANO_TRANSFORMADO - {
		ROTAR_X 90
		ROTAR_Z 90
		TRASLADAR [-48.0 0.0 0.0]
	}
	TRANSFORMACIONES
	ROTAR_Y 15
	TRASLADAR [-70.0 -45.0 85.0]*/
//									TERMINA MESA


ESFERA
	COLOR	54 100 139
	KD 0.85 KA 0.2 KS 0.5 KN 15
	POSICION 0.0 0.0 0.0
	RADIO 15.0

ESFERA
	COLOR	131 111 255
	KD 0.85 KA 0.2 KS 0.5 KN 15
	POSICION 0.0 0.0 0.0
	RADIO 15.1
	PLANOS_DE_CORTE
	PLANO_TRANSFORMADO - {
		ROTAR_X 90
		ROTAR_Z 10
		TRASLADAR [-5.0 10.0 0.0]
	}
	PLANO_TRANSFORMADO + {
		ROTAR_Y 90
		ROTAR_Z -15
		TRASLADAR [0.0 5.0 0.0]
	}
	PLANO_TRANSFORMADO - {
		ROTAR_Y 90
		ROTAR_Z 35
		TRASLADAR [-5.0 5.0 0.0]
	}
	
DISCO
	COLOR	255 106 106
	KD 0.85 KA 0.2 KS 0.5 KN 15
	RADIO 20.0 30.0
	ROTAR_X 45
	ROTAR_Z 45