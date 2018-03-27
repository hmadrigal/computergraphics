ESCENA
	TITULO	        "Thinking In ThinMan!"     //T�tulo de la ventana
	VENTANA         (-100.0 -75.0) (100.0 75.0)       //(XMIN YMIN) (XMAX YMAX)
	COLOR_FONDO     114 114 114              //R G B
	POSICION_OJO    (0.0 0.0 -500.0)              //(Xe Ye Ze)
	LUZ_AMBIENTE    0.1                      // [0..1] Ia
	FATT          	1.0 0.005 0.00005              // C1 C2 C3
	RESOLUCION 320 240

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
/*
LUZ
	COLOR        255.0 255.0 255.0
	POSICION     (-70.0 39.5.0 60)
	INTENSIDAD  1.2

*/
POLIGONO
	COLOR   35 102 147
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
	COLOR   143 143 188
	KD 0.7  KA 0.5 KS 0.9 KN 500
	ANCLA (0.0 0.0 0.0)
	(-150.0 150.0 0.0)
	(150.0 150.0 0.0)
	(150.0 -50.0 0.0)
	(-150.0 -50.0 0.0)
	TRANSFORMACIONES
	TRASLADAR [0.0 0.0 500.0]

POLIGONO
	COLOR   143 143 188
	KD 0.7  KA 0.5 KS 0.9 KN 500
	ANCLA (0.0 0.0 0.0)
	(0.0 150.0 0.0)
	(0.0 150.0 500.0)
	(0.0 -50.0 500.0)
	(0.0 -50.0 0.0)
	TRANSFORMACIONES
	TRASLADAR [150.0 0.0 0.0]

POLIGONO
	COLOR   143 143 188
	KD 0.7  KA 0.5 KS 0.9 KN 500
	ANCLA (0.0 0.0 0.0)
	(0.0 150.0 0.0)
	(0.0 150.0 500.0)
	(0.0 -50.0 500.0)
	(0.0 -50.0 0.0)
	TRANSFORMACIONES
	TRASLADAR [-150.0 0.0 0.0]
/*
//YOGURT
//Cabeza
ESFERA  COLOR   156 251 135 KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 RADIO 7.75 TRANSFORMACIONES TRASLADAR [0.0 50.0 350.0]

// Brazo Izquierdo
ESFERA  COLOR   219 219 112 KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 RADIO 2.5 TRANSFORMACIONES TRASLADAR [-05.0 35.0 350.0]
ESFERA  COLOR   219 219 112 KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 RADIO 2.5 TRANSFORMACIONES TRASLADAR [-10.0 33.0 350.0]
ESFERA  COLOR   219 219 112 KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 RADIO 2.5 TRANSFORMACIONES TRASLADAR [-15.0 30.0 350.0]
ESFERA  COLOR   219 219 112 KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 RADIO 2.5 TRANSFORMACIONES TRASLADAR [-20.0 27.0 350.0]
ESFERA  COLOR   219 219 112 KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 RADIO 2.5 TRANSFORMACIONES TRASLADAR [-25.0 27.0 350.0]
ESFERA  COLOR   219 219 112 KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 RADIO 2.5 TRANSFORMACIONES TRASLADAR [-30.0 30.0 350.0]
ESFERA  COLOR   219 219 112 KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 RADIO 2.5 TRANSFORMACIONES TRASLADAR [-35.0 33.0 350.0]
ESFERA  COLOR   176 216 230 KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 RADIO 2.5 TRANSFORMACIONES TRASLADAR [-40.0 35.0 350.0]

//Brazo Derecho
ESFERA  COLOR   219 219 112 KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 RADIO 2.5 TRANSFORMACIONES TRASLADAR [02.0 35.0 350.0]
ESFERA  COLOR   219 219 112 KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 RADIO 2.5 TRANSFORMACIONES TRASLADAR [07.0 37.0 350.0]
ESFERA  COLOR   219 219 112 KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 RADIO 2.5 TRANSFORMACIONES TRASLADAR [12.0 39.0 350.0]
ESFERA  COLOR   219 219 112 KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 RADIO 2.5 TRANSFORMACIONES TRASLADAR [17.0 40.0 350.0]
ESFERA  COLOR   219 219 112 KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 RADIO 2.5 TRANSFORMACIONES TRASLADAR [22.0 40.0 350.0]
ESFERA  COLOR   219 219 112 KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 RADIO 2.5 TRANSFORMACIONES TRASLADAR [27.0 39.0 350.0]
ESFERA  COLOR   219 219 112 KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 RADIO 2.5 TRANSFORMACIONES TRASLADAR [32.0 37.0 350.0]
ESFERA  COLOR   176 216 230 KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 RADIO 2.5 TRANSFORMACIONES TRASLADAR [37.0 35.0 350.0]

//Torso
ESFERA  COLOR   219 219 112 KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 RADIO 2.5 TRANSFORMACIONES TRASLADAR [-2.0 40.0 350.0]
ESFERA  COLOR   219 219 112 KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 RADIO 2.5 TRANSFORMACIONES TRASLADAR [-3.0 35.0 350.0]
ESFERA  COLOR   219 219 112 KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 RADIO 2.5 TRANSFORMACIONES TRASLADAR [-5.0 30.0 350.0]
ESFERA  COLOR   219 219 112 KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 RADIO 2.5 TRANSFORMACIONES TRASLADAR [-5.0 25.0 350.0]
ESFERA  COLOR   219 219 112 KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 RADIO 2.5 TRANSFORMACIONES TRASLADAR [-3.0 20.0 350.0]
ESFERA  COLOR   219 219 112 KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 RADIO 2.5 TRANSFORMACIONES TRASLADAR [-1.0 15.0 350.0]
ESFERA  COLOR   219 219 112 KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 RADIO 2.5 TRANSFORMACIONES TRASLADAR [0.0 10.0 350.0]
ESFERA  COLOR   219 219 112 KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 RADIO 2.5 TRANSFORMACIONES TRASLADAR [0.0 05.0 350.0]
ESFERA  COLOR   176 216 230 KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 RADIO 4.0 TRANSFORMACIONES TRASLADAR [0.0 00.0 350.0]


//Pierna Derecha
ESFERA  COLOR   219 219 112 KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 RADIO 2.5 TRANSFORMACIONES TRASLADAR [05.0 00.0 350.0]
ESFERA  COLOR   219 219 112 KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 RADIO 2.5 TRANSFORMACIONES TRASLADAR [10.0 -5.0 350.0]
ESFERA  COLOR   219 219 112 KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 RADIO 2.5 TRANSFORMACIONES TRASLADAR [15.0 -10.0 350.0]
ESFERA  COLOR   219 219 112 KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 RADIO 2.5 TRANSFORMACIONES TRASLADAR [20.0 -15.0 350.0]
ESFERA  COLOR   219 219 112 KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 RADIO 2.5 TRANSFORMACIONES TRASLADAR [20.0 -20.0 350.0]
ESFERA  COLOR   219 219 112 KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 RADIO 2.5 TRANSFORMACIONES TRASLADAR [19.0 -25.0 350.0]
ESFERA  COLOR   219 219 112 KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 RADIO 2.5 TRANSFORMACIONES TRASLADAR [17.0 -30.0 350.0]
ESFERA  COLOR   176 216 230  KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 RADIO 2.5 TRANSFORMACIONES TRASLADAR [15.0 -35.0 350.0]

//Pierna Izquierda
ESFERA  COLOR   219 219 112 KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 RADIO 2.5 TRANSFORMACIONES TRASLADAR [0.0 00.0 350.0]
ESFERA  COLOR   219 219 112 KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 RADIO 2.5 TRANSFORMACIONES TRASLADAR [1.0 -5.0 350.0]
ESFERA  COLOR   219 219 112 KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 RADIO 2.5 TRANSFORMACIONES TRASLADAR [2.0 -10.0 350.0]
ESFERA  COLOR   219 219 112 KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 RADIO 2.5 TRANSFORMACIONES TRASLADAR [3.0 -15.0 350.0]
ESFERA  COLOR   219 219 112 KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 RADIO 2.5 TRANSFORMACIONES TRASLADAR [3.0 -20.0 350.0]
ESFERA  COLOR   219 219 112 KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 RADIO 2.5 TRANSFORMACIONES TRASLADAR [2.0 -25.0 350.0]
ESFERA  COLOR   219 219 112 KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 RADIO 2.5 TRANSFORMACIONES TRASLADAR [1.0 -30.0 350.0]
ESFERA  COLOR   176 216 230 KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 RADIO 2.5 TRANSFORMACIONES TRASLADAR [0.0 -35.0 350.0]

//Esfera Anaranjada
ESFERA  COLOR   255 165 0 KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 RADIO 6.5 TRANSFORMACIONES TRASLADAR [-40.0 40.0 350.0]


//Tablero
//Vertical
CILINDRO COLOR   255 165 0 KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 DIRECCION 0.0 1.0 0.0 RADIO 3.0
	PLANOS_DE_CORTE PLANO_TRANSFORMADO - { ROTAR_X 90 TRASLADAR [150.0 85.0 350.0] } TRANSFORMACIONES  ROTAR_Z 8.0 TRASLADAR [150.0 -35.0 350.0]
//Horizontal
CILINDRO COLOR   255 165 0 KD 0.95 KA 0.2 KS 0.5 KN 20 POSICION 0.0 0.0 0.0 DIRECCION 0.0 0.0 1.0 RADIO 3.0  TRANSFORMACIONES  TRASLADAR [135.0 85.0 350.0]

//Tabla
POLIGONO COLOR   255 255 255 KD 0.7  KA 0.5 KS 0.9 KN 500 ANCLA (0.0 0.0 0.0) (-18.0 15.0 0.0) (18.0 15.0 0.0) (18.0 -15.0 0.0) (-18.0 -15.0 0.0)
	TRANSFORMACIONES   ROTAR_Y 90 TRASLADAR [130.5 85.0 350.0]
POLIGONO COLOR   0 0 0 KD 0.7  KA 0.5 KS 0.9 KN 500 ANCLA (0.0 0.0 0.0) (-15.0 12.0 0.0) (15.0 12.0 0.0) (15.0 -12.0 0.0) (-15.0 -12.0 0.0)
	TRANSFORMACIONES   ROTAR_Y 90 TRASLADAR [130.0 85.0 350.0]
POLIGONO COLOR   255 255 255 KD 0.7  KA 0.5 KS 0.9 KN 500 ANCLA (0.0 0.0 0.0) (-07.0 10.0 0.0) (07.0 10.0 0.0) (07.0 -10.0 0.0) (-07.0 -10.0 0.0)
	TRANSFORMACIONES   ROTAR_Y 90 TRASLADAR [129.5 85.0 350.0]

CONO COLOR   258 92 66 KD 1.0 KA 0.2 KS 0.4 KN 45 POSICION 0.0 0.0 0.0 DIRECCION 0.0 1.0 0.0 FACTOR_K  0.5
	PLANOS_DE_CORTE
		PLANO_TRANSFORMADO - { ROTAR_X 90 TRASLADAR [0.0 30.0 350.0] TRASLADAR [114.0 50.0 350.0]}
		PLANO_TRANSFORMADO + { ROTAR_X 90 TRASLADAR [0.0 28.0 350.0] TRASLADAR [114.0 50.0 350.0]}
	TRANSFORMACIONES TRASLADAR [114.0 50.0 350.0]

//Estrella en el Suelo
POLIGONO
	COLOR   127.0 127.0 127.0 KD 1.0  KA 0.4 KS 0.1 KN 200
	ANCLA  ( 0.0 0.0 0.0) (0.0 100.0 0.0) (50.0 60.0 0.0) (100.0 50.0 0.0) (70.0 -20.0 0.0) (65.0 -75.0 0.0) (0.0 -50.0 0.0) (-65.0 -75.0 0.0) (-70.0 -20.0 0.0) (-100.0 50.0 0.0) (-50.0 60.0 0.0)
	TRANSFORMACIONES ROTAR_X 87.0 TRASLADAR [0 -51.0 80.0]

POLIGONO
	COLOR   99 174 255 KD 1.0  KA 0.4 KS 0.1 KN 200
	ANCLA  ( 0.0 0.0 0.0) (0.0 100.0 0.0) (50.0 60.0 0.0) (100.0 50.0 0.0) (70.0 -20.0 0.0) (65.0 -75.0 0.0) (0.0 -50.0 0.0) (-65.0 -75.0 0.0) (-70.0 -20.0 0.0) (-100.0 50.0 0.0) (-50.0 60.0 0.0)
	TRANSFORMACIONES ROTAR_Z 42.0 ROTAR_X 87.0 TRASLADAR [0 -51.0 79.9]

POLIGONO
	COLOR   255.0 0.0 0.0 KD 1.0  KA 0.4 KS 0.1 KN 200
	ANCLA  ( 0.0 0.0 0.0) (0.0 100.0 0.0) (50.0 60.0 0.0) (100.0 50.0 0.0) (70.0 -20.0 0.0) (65.0 -75.0 0.0) (0.0 -50.0 0.0) (-65.0 -75.0 0.0) (-70.0 -20.0 0.0) (-100.0 50.0 0.0) (-50.0 60.0 0.0)
	TRANSFORMACIONES ROTAR_Z 82.0 ROTAR_X 87.0 TRASLADAR [0 -51.0 79.8]

// Estrellas pequen~as en la pared
POLIGONO COLOR   255.0 255.0 255.0 KD .75  KA 0.2 KS 0.85 KN 100
	ANCLA  ( 0.0 0.0 0.0)  	(3.0 3.8 0.0) (2.4 0.6 0.0) (5.1 2.1 0.0) (7.9 0.6 0.0) (7.2 3.8 0.0) 	(9.6 6.2 0.0) (6.5 6.8 0.0) (5.1 9.1 0.0) (3.9 6.8 0.0) (0.8 6.2 0.0)
	TRANSFORMACIONES TRASLADAR [0.0 90.0 499.98]

POLIGONO COLOR   255.0 255.0 255.0 KD .75  KA 0.2 KS 0.85 KN 100
	ANCLA  ( 0.0 0.0 0.0)  	(3.0 3.8 0.0) (2.4 0.6 0.0) (5.1 2.1 0.0) (7.9 0.6 0.0) (7.2 3.8 0.0) 	(9.6 6.2 0.0) (6.5 6.8 0.0) (5.1 9.1 0.0) (3.9 6.8 0.0) (0.8 6.2 0.0)
	TRANSFORMACIONES TRASLADAR [30.0 110.0 499.98]
POLIGONO COLOR   255.0 255.0 255.0 KD .75  KA 0.2 KS 0.85 KN 100
	ANCLA  ( 0.0 0.0 0.0)  	(3.0 3.8 0.0) (2.4 0.6 0.0) (5.1 2.1 0.0) (7.9 0.6 0.0) (7.2 3.8 0.0) 	(9.6 6.2 0.0) (6.5 6.8 0.0) (5.1 9.1 0.0) (3.9 6.8 0.0) (0.8 6.2 0.0)
	TRANSFORMACIONES TRASLADAR [-30.0 110.0 499.98]
POLIGONO COLOR   255.0 255.0 255.0 KD .75  KA 0.2 KS 0.85 KN 100
	ANCLA  ( 0.0 0.0 0.0)  	(3.0 3.8 0.0) (2.4 0.6 0.0) (5.1 2.1 0.0) (7.9 0.6 0.0) (7.2 3.8 0.0) 	(9.6 6.2 0.0) (6.5 6.8 0.0) (5.1 9.1 0.0) (3.9 6.8 0.0) (0.8 6.2 0.0)
	TRANSFORMACIONES TRASLADAR [0.0 120.0 499.98]

// 										MESA

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
		TRASLADAR [-63.0 0.0 0.0]
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
	TRASLADAR [-70.0 -45.0 85.0]
//									TERMINA MESA

// Inicia el Globo
*/
// Primer esfera
ESFERA
	COLOR	54 100 139
	KD 0.70 KA 0.2 KS 0.3 KN 15
	POSICION 0.0 0.0 0.0
	RADIO 15.0
	TRANSFORMACIONES
	TRASLADAR [-40.0 -1.0 57.5]

// America del norte
ESFERA
	COLOR	131 111 255
	KD 0.95 KA 0.2 KS 0.9 KN 45
	POSICION 0.0 0.0 0.0
	RADIO 15.01
	PLANOS_DE_CORTE
	PLANO_TRANSFORMADO - {
		ROTAR_X 90
		ROTAR_Z 10
		TRASLADAR [-5.0 10.0 0.0]
	TRASLADAR [-40.0 -1.0 57.5]
	}
	PLANO_TRANSFORMADO + {
		ROTAR_Y 90
		ROTAR_Z -15
		TRASLADAR [0.0 5.0 0.0]
	TRASLADAR [-40.0 -1.0 57.5]
	}
	PLANO_TRANSFORMADO - {
		ROTAR_Y 90
		ROTAR_Z 35
		TRASLADAR [-5.0 5.0 0.0]
	TRASLADAR [-40.0 -1.0 57.5]
	}
	TRANSFORMACIONES
	TRASLADAR [-40.0 -1.0 57.5]

// America del sur
ESFERA
	COLOR	139 26 26
	KD 0.95 KA 0.2 KS 0.9 KN 45
	POSICION 0.0 0.0 0.0
	RADIO 15.02
	PLANOS_DE_CORTE
	PLANO_TRANSFORMADO - {
		ROTAR_Y 90
		ROTAR_Z 8
		TRASLADAR [-1.5 0.0 0.0]
		TRASLADAR [-40.0 -1.0 57.5]
	}
	PLANO_TRANSFORMADO + {
		ROTAR_Y 90
		ROTAR_Z 80
		TRASLADAR [-40.0 -1.0 57.5]
	}
	PLANO_TRANSFORMADO + {
		ROTAR_Y 90
		ROTAR_Z -35
		TRASLADAR [10.0 0.0 0.0]
		TRASLADAR [-40.0 -1.0 57.5]
	}
	TRANSFORMACIONES
	TRASLADAR [-40.0 -1.0 57.5]

// Palillo del centro
CILINDRO
	COLOR  255 255 200
	KD 1.0 KA 0.2 KS 0.5 KN 30
	POSICION 0.0 0.0 0.0
	DIRECCION 1.0 0.0 0.0
	RADIO 0.5
	PLANOS_DE_CORTE
	PLANO_TRANSFORMADO - {
		ROTAR_X 90
		TRASLADAR [0.0 20.0 0.0]
		TRASLADAR [0.0 -1.0 0.0]
	}
	PLANO_TRANSFORMADO + {
		ROTAR_X 90
		TRASLADAR [0.0 -20.0 0.0]
		TRASLADAR [0.0 -2.0 0.0]
	}
	TRANSFORMACIONES
	ROTAR_Z -75.0
	TRASLADAR [-40.0 -1.0 57.5]

// Lo que rodea el globo
DISCO
	COLOR	255 106 106
	KD 0.9 KA 0.2 KS 0.1 KN 5
	RADIO 16.0 18.0
	ROTAR_Z -75.0
	TRASLADAR [-40.0 -1.0 57.5]
	PLANOS_DE_CORTE
	PLANO_TRANSFORMADO - {
		ROTAR_X 90
		ROTAR_Z -75
		TRASLADAR [-60.0 0.0 0.0]
	}

// Para la base
ESFERA
	COLOR	0.0 0.0 0.0
	KD 0.85 KA 0.2 KS 0.5 KN 15
	POSICION 0.0 0.0 0.0
	RADIO 10.0
	PLANOS_DE_CORTE
	PLANO_TRANSFORMADO - {
		ROTAR_Y 90
		ROTAR_Z 90
		ROTAR_X -3
		TRASLADAR [0.0 5.0 0.0]
		TRASLADAR [0.0 -33.0 0.0]
	}
	TRANSFORMACIONES
	TRASLADAR [-35.0 -31.0 60.0]

// Para la base
CILINDRO
	COLOR  0.0 0.0 0.0
	KD 1.0 KA 0.2 KS 0.5 KN 30
	POSICION 0.0 0.0 0.0
	DIRECCION 0.0 1.0 0.0
	RADIO 8.0
	PLANOS_DE_CORTE
	PLANO_TRANSFORMADO - {
		ROTAR_X 87
		TRASLADAR [0.0 5.0 0.0]
		TRASLADAR [0.0 -33.0 0.0]
	}
	PLANO_TRANSFORMADO + {
		ROTAR_X 87
		TRASLADAR [0.0 2.0 0.0]
		TRASLADAR [0.0 -33.0 0.0]
	}
	TRANSFORMACIONES
	TRASLADAR [-35.0 -33.0 60.0]
// 								Termina el globo

// La lampara
CONO
	COLOR 100.0 200.0 150.0
	KD 0.7 KA 0.2 KS 0.9 KN 70
	POSICION 0.0 0.0 0.0
	DIRECCION 0.0 1.0 0.0
	FACTOR_K 1.0
	PLANOS_DE_CORTE
	PLANO_TRANSFORMADO - {
		ROTAR_X 90
		TRASLADAR [0.0 70.0 0.0]

	}
	PLANO_TRANSFORMADO + {
		ROTAR_X 90
		TRASLADAR [0.0 -20.0 0.0]
		TRASLADAR [0.0 70.0 0.0]

	}
	TRANSFORMACIONES
	TRASLADAR [-40.0 70.0 60.0]

// Lo que sostiene la lampara
CILINDRO
	COLOR  150.0 25.0 225.0
	KD 1.0 KA 0.2 KS 0.9 KN 50
	POSICION 0.0 0.0 0.0
	DIRECCION 0.0 1.0 0.0
	RADIO 0.75
	PLANOS_DE_CORTE
	PLANO_TRANSFORMADO + {
		ROTAR_X 90
		TRASLADAR [0.0 69.0 0.0]
	}
	TRANSFORMACIONES
	TRASLADAR [-40.0 70.0 60.0]
// 										ARBOL DE NAVIDAD

/*
// Copa #1 del arbol
CONO
	COLOR 0.0 255.0 125.0
	KD 0.6 KA 0.2 KS 0.3 KN 100
	POSICION 0.0 0.0 0.0
	DIRECCION 0.0 1.0 0.0
	FACTOR_K 0.2
	PLANOS_DE_CORTE
	PLANO_TRANSFORMADO - {
		ROTAR_X 90
		TRASLADAR [0.0 90.0 0.0]

	}
	PLANO_TRANSFORMADO + {
		ROTAR_X 90
		TRASLADAR [0.0 -20.0 0.0]
		TRASLADAR [0.0 87.0 0.0]

	}
	TRANSFORMACIONES
	TRASLADAR [0.0 90.0 0.0]
	TRASLADAR [-85.0 0.0 475.0]

// Copa #2 del arbol
CONO
	COLOR 0.0 255.0 125.0
	KD 0.6 KA 0.2 KS 0.3 KN 100
	POSICION 0.0 0.0 0.0
	DIRECCION 0.0 1.0 0.0
	FACTOR_K 0.3
	PLANOS_DE_CORTE
	PLANO_TRANSFORMADO - {
		ROTAR_X 90
		TRASLADAR [0.0 80.0 0.0]

	}
	PLANO_TRANSFORMADO + {
		ROTAR_X 90
		TRASLADAR [0.0 55.0 0.0]
	}
	TRANSFORMACIONES
	TRASLADAR [0.0 80.0 0.0]
	TRASLADAR [-85.0 0.0 475.0]

// Copa #3 del arbol
CONO
	COLOR 0.0 255.0 125.0
	KD 0.6 KA 0.2 KS 0.3 KN 100
	POSICION 0.0 0.0 0.0
	DIRECCION 0.0 1.0 0.0
	FACTOR_K 0.5
	PLANOS_DE_CORTE
	PLANO_TRANSFORMADO - {
		ROTAR_X 90
		TRASLADAR [0.0 68.0 0.0]

	}
	PLANO_TRANSFORMADO + {
		ROTAR_X 90
		TRASLADAR [0.0 45.0 0.0]
	}
	TRANSFORMACIONES
	TRASLADAR [0.0 68.0 0.0]
	TRASLADAR [-85.0 0.0 475.0]

// Copa #4 del arbol
CONO
	COLOR 0.0 255.0 125.0
	KD 0.6 KA 0.2 KS 0.3 KN 100
	POSICION 0.0 0.0 0.0
	DIRECCION 0.0 1.0 0.0
	FACTOR_K 0.65
	PLANOS_DE_CORTE
	PLANO_TRANSFORMADO - {
		ROTAR_X 90
		TRASLADAR [0.0 60.0 0.0]
	}
	PLANO_TRANSFORMADO + {
		ROTAR_X 90
		TRASLADAR [0.0 35.0 0.0]
	}
	TRANSFORMACIONES
	TRASLADAR [0.0 60.0 0.0]
	TRASLADAR [-85.0 0.0 475.0]

// Copa #5 del arbol
CONO
	COLOR 0.0 255.0 125.0
	KD 0.6 KA 0.2 KS 0.3 KN 100
	POSICION 0.0 0.0 0.0
	DIRECCION 0.0 1.0 0.0
	FACTOR_K 0.85
	PLANOS_DE_CORTE
	PLANO_TRANSFORMADO - {
		ROTAR_X 90
		TRASLADAR [0.0 50.0 0.0]
	}
	PLANO_TRANSFORMADO + {
		ROTAR_X 90
		TRASLADAR [0.0 20.0 0.0]
	}
	TRANSFORMACIONES
	TRASLADAR [0.0 50.0 0.0]
	TRASLADAR [-85.0 0.0 475.0]

// Copa #6 del arbol
CONO
	COLOR 0.0 255.0 125.0
	KD 0.6 KA 0.2 KS 0.3 KN 100
	POSICION 0.0 0.0 0.0
	DIRECCION 0.0 1.0 0.0
	FACTOR_K 1.25
	PLANOS_DE_CORTE
	PLANO_TRANSFORMADO - {
		ROTAR_X 90
		TRASLADAR [0.0 35.0 0.0]

	}
	PLANO_TRANSFORMADO + {
		ROTAR_X 90
		TRASLADAR [0.0 5.0 0.0]

	}
	TRANSFORMACIONES
	TRASLADAR [0.0 35.0 0.0]
	TRASLADAR [-85.0 0.0 475.0]

// Copa #7 del arbol
CONO
	COLOR 0.0 255.0 125.0
	KD 0.6 KA 0.2 KS 0.3 KN 100
	POSICION 0.0 0.0 0.0
	DIRECCION 0.0 1.0 0.0
	FACTOR_K 1.45
	PLANOS_DE_CORTE
	PLANO_TRANSFORMADO - {
		ROTAR_X 90
		TRASLADAR [0.0 20.0 0.0]
	}
	PLANO_TRANSFORMADO + {
		ROTAR_X 90
		TRASLADAR [0.0 -10.0 0.0]
	}
	TRANSFORMACIONES
	TRASLADAR [0.0 20.0 0.0]
	TRASLADAR [-85.0 0.0 475.0]

// Copa #8 del arbol
CONO
	COLOR 0.0 255.0 125.0
	KD 0.6 KA 0.2 KS 0.3 KN 100
	POSICION 0.0 0.0 0.0
	DIRECCION 0.0 1.0 0.0
	FACTOR_K 1.75
	PLANOS_DE_CORTE
	PLANO_TRANSFORMADO - {
		ROTAR_X 90
		TRASLADAR [0.0 5.0 0.0]
	}
	PLANO_TRANSFORMADO + {
		ROTAR_X 90
		TRASLADAR [0.0 -30 0.0]
	}
	TRANSFORMACIONES
	TRASLADAR [0.0 5.0 0.0]
	TRASLADAR [-85.0 0.0 475.0]

// Esferas del arbolito

// Para la base
ESFERA
	COLOR	205 133 122
	KD 0.9 KA 0.2 KS 0.3 KN 20
	POSICION 0.0 0.0 0.0
	RADIO 3.0
	TRANSFORMACIONES
	TRASLADAR [6.0 60.0 0.0]
	TRASLADAR [-85.0 0.0 475.0]

ESFERA
	COLOR	255.0 0.0 255.0
	KD 0.7 KA 0.3 KS 0.8 KN 20
	POSICION 0.0 0.0 0.0
	RADIO 3.0
	TRANSFORMACIONES
	TRASLADAR [-6.0 65.0 0.0]
	TRASLADAR [-85.0 0.0 475.0]

ESFERA
	COLOR	131 11 255
	KD 0.4 KA 0.3 KS 0.3 KN 20
	POSICION 0.0 0.0 0.0
	RADIO 3.0
	TRANSFORMACIONES
	TRASLADAR [0.0 50.0 -11.0]
	TRASLADAR [-85.0 0.0 475.0]

ESFERA
	COLOR	255 250 250
	KD 0.5 KA 0.3 KS 0.9 KN 48
	POSICION 0.0 0.0 0.0
	RADIO 3.0
	TRANSFORMACIONES
	TRASLADAR [-8.0 52.0 -3.0]
	TRASLADAR [-85.0 0.0 475.0]

ESFERA
	COLOR	139 179 139
	KD 0.9 KA 0.3 KS 0.7 KN 25
	POSICION 0.0 0.0 0.0
	RADIO 3.0
	TRANSFORMACIONES
	TRASLADAR [-3.0 45.0 10.0]
	TRASLADAR [-85.0 0.0 475.0]

ESFERA
	COLOR	220 150 200
	KD 0.95 KA 0.1 KS 0.1 KN 5
	POSICION 0.0 0.0 0.0
	RADIO 3.0
	TRANSFORMACIONES
	TRASLADAR [10.0 43.0 -3.0]
	TRASLADAR [-85.0 0.0 475.0]

ESFERA
	COLOR	255 127 0.0
	KD 0.3 KA 0.1 KS 0.6 KN 40
	POSICION 0.0 0.0 0.0
	RADIO 3.0
	TRANSFORMACIONES
	TRASLADAR [-6.0 37.0 -19.0]
	TRASLADAR [-85.0 0.0 475.0]

ESFERA
	COLOR	125 30 169
	KD 0.8 KA 0.1 KS 0.8 KN 40
	POSICION 0.0 0.0 0.0
	RADIO 3.0
	TRANSFORMACIONES
	TRASLADAR [6.0 38.0 -17.0]
	TRASLADAR [-85.0 0.0 475.0]

ESFERA
	COLOR	255 250 250
	KD 0.85 KA 0.1 KS 0.3 KN 40
	POSICION 0.0 0.0 0.0
	RADIO 3.0
	TRANSFORMACIONES
	TRASLADAR [-15.0 26.0 -23.0]
	TRASLADAR [-85.0 0.0 475.0]

ESFERA
	COLOR	141 182 205
	KD 1.0 KA 0.1 KS 1.0 KN 80
	POSICION 0.0 0.0 0.0
	RADIO 4.0
	TRANSFORMACIONES
	TRASLADAR [12.0 27.0 -21.0]
	TRASLADAR [-85.0 0.0 475.0]

ESFERA
	COLOR	178 34 34
	KD 0.8 KA 0.1 KS 0.99 KN 80
	POSICION 0.0 0.0 0.0
	RADIO 3.0
	TRANSFORMACIONES
	TRASLADAR [2.0 21.0 -25.0]
	TRASLADAR [-85.0 0.0 475.0]

ESFERA
	COLOR	125 38 205
	KD 0.85 KA 0.1 KS 0.2 KN 6
	POSICION 0.0 0.0 0.0
	RADIO 3.0
	TRANSFORMACIONES
	TRASLADAR [-15.0 13.0 -30.0]
	TRASLADAR [-85.0 0.0 475.0]

ESFERA
	COLOR	205 140 149
	KD 0.3 KA 0.1 KS 0.8 KN 50
	POSICION 0.0 0.0 0.0
	RADIO 3.0
	TRANSFORMACIONES
	TRASLADAR [0.0 15.0 -30.0]
	TRASLADAR [-85.0 0.0 475.0]

ESFERA
	COLOR	255 69 0.0
	KD 0.2 KA 0.1 KS 0.98 KN 50
	POSICION 0.0 0.0 0.0
	RADIO 3.0
	TRANSFORMACIONES
	TRASLADAR [15.0 10.0 -30.0]
	TRASLADAR [-85.0 0.0 475.0]

ESFERA
	COLOR	255.0 0.0 0.0
	KD 0.95 KA 0.1 KS 0.90 KN 50
	POSICION 0.0 0.0 0.0
	RADIO 3.0
	TRANSFORMACIONES
	TRASLADAR [20.0 5.0 -30.0]
	TRASLADAR [-85.0 0.0 475.0]

ESFERA
	COLOR	0.0 255.0 0.0
	KD 0.7 KA 0.1 KS 0.6 KN 50
	POSICION 0.0 0.0 0.0
	RADIO 3.0
	TRANSFORMACIONES
	TRASLADAR [-20.0 1.0 -30.0]
	TRASLADAR [-85.0 0.0 475.0]

ESFERA
	COLOR	255 105 180
	KD 0.5 KA 0.1 KS 0.7 KN 50
	POSICION 0.0 0.0 0.0
	RADIO 3.0
	TRANSFORMACIONES
	TRASLADAR [-12.0 -3.0 -35.0]
	TRASLADAR [-85.0 0.0 475.0]

ESFERA
	COLOR	138 43 226
	KD 0.8 KA 0.1 KS 0.9 KN 120
	POSICION 0.0 0.0 0.0
	RADIO 3.0
	TRANSFORMACIONES
	TRASLADAR [0.0 0.0 -35.0]
	TRASLADAR [-85.0 0.0 475.0]

ESFERA
	COLOR	255 22 173
	KD 0.8 KA 0.1 KS 0.9 KN 120
	POSICION 0.0 0.0 0.0
	RADIO 3.0
	TRANSFORMACIONES
	TRASLADAR [16.0 -6.0 -35.0]
	TRASLADAR [-85.0 0.0 475.0]
	
*/
/*
POLIGONO COLOR   0.0 0.0 0.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0)  (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [-20.0 -40.0 499.99]
POLIGONO COLOR 255.0 255.0 255.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [-20.0 -20.0 499.99]
POLIGONO COLOR   0.0 0.0 0.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [-20.0 0.0 499.99]
POLIGONO COLOR   255.0 255.0 255.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 15.0 0.0) (20.0 15.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [-20.0 20.0 499.99]
	
POLIGONO COLOR   255.0 255.0 255.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [-40.0 -40.0 499.99]
POLIGONO COLOR   0.0 0.0 0.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [-40.0 -20.0 499.99]
POLIGONO COLOR   255.0 255.0 255.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [-40.0 0.0 499.99]
POLIGONO COLOR   0.0 0.0 0.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 15.0 0.0) (20.0 15.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [-40.0 20.0 499.99]

POLIGONO COLOR   0.0 0.0 0.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [-60.0 -40.0 499.99]
POLIGONO COLOR   255.0 255.0 255.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [-60.0 -20.0 499.99]
POLIGONO COLOR   0.0 0.0 0.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0)  (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [-60.0 0.0 499.99]
POLIGONO COLOR   255.0 255.0 255.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 15.0 0.0) (20.0 15.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [-60.0 20.0 499.99]

POLIGONO COLOR   255.0 255.0 255.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [-80.0 -40.0 499.99]
POLIGONO COLOR   0.0 0.0 0.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [-80.0 -20.0 499.99]
POLIGONO COLOR   255.0 255.0 255.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [-80.0 0.0 499.99]
POLIGONO COLOR   0.0 0.0 0.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 15.0 0.0) (20.0 15.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [-80.0 20.0 499.99]

POLIGONO COLOR   0.0 0.0 0.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [-100.0 -40.0 499.99]
POLIGONO COLOR   255.0 255.0 255.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [-100.0 -20.0 499.99]
POLIGONO COLOR   0.0 0.0 0.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [-100.0 0.0 499.99]
POLIGONO COLOR   255.0 255.0 255.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 15.0 0.0) (20.0 15.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [-100.0 20.0 499.99]

POLIGONO COLOR   255.0 255.0 255.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [-120.0 -40.0 499.99]
POLIGONO COLOR   0.0 0.0 0.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [-120.0 -20.0 499.99]
POLIGONO COLOR   255.0 255.0 255.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [-120.0 0.0 499.99]
POLIGONO COLOR   0.0 0.0 0.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 15.0 0.0) (20.0 15.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [-120.0 20.0 499.99]

POLIGONO COLOR   0.0 0.0 0.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [-140.0 -40.0 499.99]
POLIGONO COLOR   255.0 255.0 255.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [-140.0 -20.0 499.99]
POLIGONO COLOR   0.0 0.0 0.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [-140.0 0.0 499.99]
POLIGONO COLOR   255.0 255.0 255.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 15.0 0.0) (20.0 15.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [-140.0 20.0 499.99]

POLIGONO COLOR   255.0 255.0 255.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [-160.0 -40.0 499.99]
POLIGONO COLOR   0.0 0.0 0.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [-160.0 -20.0 499.99]
POLIGONO COLOR   255.0 255.0 255.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [-160.0 0.0 499.99]
POLIGONO COLOR   0.0 0.0 0.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 15.0 0.0) (20.0 15.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [-160.0 20.0 499.99]
//----
POLIGONO COLOR   255.0 255.0 255.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [0.0 -40.0 499.99]
POLIGONO COLOR   0.0 0.0 0.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [0.0 -20.0 499.99]
POLIGONO COLOR   255.0 255.0 255.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [0.0 0.0 499.99]
POLIGONO COLOR   0.0 0.0 0.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 15.0 0.0) (20.0 15.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [0.0 20.0 499.99]

POLIGONO COLOR   0.0 0.0 0.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [20.0 -40.0 499.99]
POLIGONO COLOR 255.0 255.0 255.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [20.0 -20.0 499.99]
POLIGONO COLOR   0.0 0.0 0.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [20.0 0.0 499.99]
POLIGONO COLOR   255.0 255.0 255.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 15.0 0.0) (20.0 15.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [20.0 20.0 499.99]
	
POLIGONO COLOR   255.0 255.0 255.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [40.0 -40.0 499.99]
POLIGONO COLOR   0.0 0.0 0.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [40.0 -20.0 499.99]
POLIGONO COLOR   255.0 255.0 255.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [40.0 0.0 499.99]
POLIGONO COLOR   0.0 0.0 0.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 15.0 0.0) (20.0 15.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [40.0 20.0 499.99]

POLIGONO COLOR   0.0 0.0 0.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [60.0 -40.0 499.99]
POLIGONO COLOR   255.0 255.0 255.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [60.0 -20.0 499.99]
POLIGONO COLOR   0.0 0.0 0.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [60.0 0.0 499.99]
POLIGONO COLOR   255.0 255.0 255.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 15.0 0.0) (20.0 15.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [60.0 20.0 499.99]

POLIGONO COLOR   255.0 255.0 255.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [80.0 -40.0 499.99]
POLIGONO COLOR   0.0 0.0 0.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [80.0 -20.0 499.99]
POLIGONO COLOR   255.0 255.0 255.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [80.0 0.0 499.99]
POLIGONO COLOR   0.0 0.0 0.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 15.0 0.0) (20.0 15.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [80.0 20.0 499.99]
	
POLIGONO COLOR   0.0 0.0 0.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [100.0 -40.0 499.99]
POLIGONO COLOR   255.0 255.0 255.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [100.0 -20.0 499.99]
POLIGONO COLOR   0.0 0.0 0.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [100.0 0.0 499.99]
POLIGONO COLOR   255.0 255.0 255.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 15.0 0.0) (20.0 15.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [100.0 20.0 499.99]

POLIGONO COLOR   255.0 255.0 255.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [120.0 -40.0 499.99]
POLIGONO COLOR   0.0 0.0 0.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [120.0 -20.0 499.99]
POLIGONO COLOR   255.0 255.0 255.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0)  (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [120.0 0.0 499.99]
POLIGONO COLOR   0.0 0.0 0.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 15.0 0.0) (20.0 15.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [120.0 20.0 499.99]

POLIGONO COLOR   0.0 0.0 0.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [140.0 -40.0 499.99]
POLIGONO COLOR   255.0 255.0 255.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0)  (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [140.0 -20.0 499.99]
POLIGONO COLOR   0.0 0.0 0.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0)  (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [140.0 0.0 499.99]
POLIGONO COLOR   255.0 255.0 255.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 15.0 0.0) (20.0 15.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [140.0 20.0 499.99]

POLIGONO COLOR   255.0 255.0 255.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [160.0 -40.0 499.99]
POLIGONO COLOR   0.0 0.0 0.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0)  (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [160.0 -20.0 499.99]
POLIGONO COLOR   255.0 255.0 255.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 20.0 0.0) (20.0 20.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [160.0 0.0 499.99]
POLIGONO COLOR   0.0 0.0 0.0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0) (0.0 15.0 0.0) (20.0 15.0 0.0) (20.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [160.0 20.0 499.99]



//Letras
POLIGONO COLOR   50 204 50 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0)
	(0.0 0.0 0.0) 
	(0.0 50.0 0.0)
	(50.0 50.0 0.0) 
	(50.0 30.0 0.0)
	(40.0 30.0 0.0) 
	(40.0 40.0 0.0)
	(10.0 40.0 0.0) 
	(10.0 10.0 0.0)
	(40.0 10.0 0.0) 
	(40.0 20.0 0.0)
	(50.0 20.0 0.0) 
	(50.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [-10.0 -10.0 495.0]
		ROTAR_Z 45
POLIGONO COLOR  142 35 35  KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) 
	(0.0 0.0 0.0)
	(0.0 50.0 0.0) 
	(50.0 50.0 0.0)
	(50.0 30.0 0.0) 
	(40.0 30.0 0.0)
	(40.0 40.0 0.0) 
	(10.0 40.0 0.0)
	(10.0 10.0 0.0)
	(40.0 10.0 0.0)
	(40.0 15.0 0.0)
	(25.0 15.0 0.0)
	(25.0 25.0 0.0) 
	(40.0 25.0 0.0)
	(50.0 25.0 0.0) 
	(50.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [20.0 -20.0 495.0]
	ROTAR_Z 45
POLIGONO COLOR   142 35 35 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) 
	(0.0 0.0 0.0)
	(0.0 50.0 0.0) 
	(10.0 50.0 0.0)
	(10.0 0.0 0.0)
	TRANSFORMACIONES TRASLADAR [20.0 -20.0 494.9]
	ROTAR_Z 45*/

//Regalo
//TRANSFORMACIONES TRASLADAR [0.0 0.0 493.9]
/*POLIGONO COLOR   255 69 0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0) (0.0 0.0 0.0)  (0.0 25.0 0.0)  (25.0 25.0 0.0)  (25.0 0.0 0.0) 
	TRANSFORMACIONES ROTAR_Y -45 ROTAR_X -3 TRASLADAR [0.0 -30.0 440.9]*/
/*
POLIGONO COLOR   127 255 0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  ( 0.0 0.0 0.0)  (0.0 0.0 50.0)  (0.0 25.0 50.0)  (25.0 25.0 50.0)  (25.0 0.0 50.0) 
	TRANSFORMACIONES ROTAR_Y -45 ROTAR_X -3 TRASLADAR [0.0 -30.0 440.9]*/
/*
POLIGONO COLOR   255 193 193 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  (0  0 0) ( 25.0 25.0 0.0)  (25.0 25.0 50.0)  (25.0 0.0 50.0)  (25.0 0.0 0.0) 
	TRANSFORMACIONES ROTAR_Y -45 ROTAR_X -3 TRASLADAR [0.0 -30.0 440.9]*/
	/*
POLIGONO COLOR   139 90 0 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  (0  0 0) (25.0 0.0 0.0)  (0.0 0.0 0.0)  (0.0 0.0 50.0)  (25.0 0.0 50.0) 
	TRANSFORMACIONES ROTAR_Y -45 ROTAR_X -3 TRASLADAR [0.0 -30.0 440.9]*/
/*
POLIGONO COLOR   255 160 105 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  (0  0 0) (0.0 25.0 0.0)  (25.0 25.0 50.0)  (0.0 0.0 50.0)  (0.0 0.0 0.0) 
	TRANSFORMACIONES ROTAR_Y -45 ROTAR_X -3 TRASLADAR [0.0 -30.0 440.9]*/
/*
POLIGONO COLOR   255 0 255 KD .75  KA 0.2 KS 0.85 KN 500
	ANCLA  (0  0 0) (0.0 25.0 0.0)  (0.0 25.0 50.0)  (25.0 25.0 50.0)  (25.0 25.0 0.0)
	TRANSFORMACIONES ROTAR_Y -45 ROTAR_X -3 TRASLADAR [0.0 -30.0 440.9]*/

