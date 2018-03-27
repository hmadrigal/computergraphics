// Archivo de ejemplo para el scanner
// Las cadenas de caracteres deben ser en minusculas
// El indice de las texturas debe ser > 0.


TITULO				"Thinking In ThinMan!"    	//Título de la ventana
VENTANA			(-100.0 -75.0) (100.0 75.0)       //(XMIN YMIN) (XMAX YMAX)
COLOR_FONDO		1.0 1.0 1.0           			//R G B
POSICION_OJO		(0.0 0.0 -500.0)			//(Xe Ye Ze)
LUZ_AMBIENTE		0.1						// [0..1] Ia
FATT				1.0 0.005 0.00005			// C1 C2 C3
RESOLUCION			640 480
REFLEXION			1						// Niveles de reflexion
TRANSPARECIA		1						// Niveles de transparencia
ANTIALIASING		0						// Niveles de antialiasing


MAPAS_DE_TEXTURAS
	TEXTURA "rl dia fresco.avs"
	TEXTURA "textura 2.avs"

MAPAS_DE_GRISES
	GRIS "image.avs"
	GRIS "xx1.avs"

LUZ
	COLOR			25.0 25.0 25.0
	POSICION		(0.0 50.0 -50)
	INTENSIDAD		1.2


OBJETO
	COLOR   35 102 147
	KD 0.7
	KA 0.5
	KS 0.9
	KN 500
	KT 0.6
	O1 0.3
	O2 0.3
	O3 0.4
	POLIGONO
		ANCLA (0.0 0.0 0.0)
		PUNTOS
			(0.0 0.0 0.0)
			(10.0 0.0 0.0)
			(10.0 10.0 0.0)
			(0.0 10.0 0.0)
	TRANSFORMACIONES
		ROTAR_X 15
		ROTAR_Y 10
	TEXTURA
		IMAGEN 1
		TILED 15.0 20.0
	ALTURA
		IMAGEN 1
		RANGO -0.5 0.5
	BRILLO
		IMAGEN 1
	TRANSPARENCIA
		IMAGEN 1
	PHONG
		IMAGEN 1

OBJETO
	COLOR   255.0 255.0 255.0
	KD 0.7
	KA 0.5
	KS 0.9
	KN 500
	KT 0.6
	O1 0.3
	O2 0.3
	O3 0.4
	DISCO
		RADIO 15.0 20.0
	TRANSFORMACIONES
		ROTAR_X 15
		ROTAR_Y 10
		TRASLADAR [0.0 0.0 30.0]
	TEXTURA
		IMAGEN 2
		STRETCH

OBJETO
	COLOR   35 102 147
	KD 0.7
	KA 0.5
	KS 0.9
	KN 500
	KT 0.6
	O1 0.3
	O2 0.3
	O3 0.4
	CONO
		POSICION 15.0 20.0 16.0
		DIRECCION 20.0 12.0 20.0
		FACTOR_K 0.9
	PLANOS_DE_CORTE
		PLANO_TRANSFORMADO_Z + {
		}
	TRANSFORMACIONES
		TRASLADAR [-5.0 0.0 30.0]
