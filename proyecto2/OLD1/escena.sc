ESCENA
	TITULO	        "La Navidad es la Libertad"     //Título de la ventana
	VENTANA         (1 2) (3 4)       //(XMIN YMIN) (XMAX YMAX)
	COLOR_FONDO     5 6 7              //R G B
	POSICION_OJO    (8 9 10)              //(Xe Ye Ze)
	LUZ_AMBIENTE    11                       // [0..1] Ia
	FATT          	12 13 14               // C1 C2 C3

LUZ
	COLOR        0.2 0.4 0.5 		//R G B
	POSICION     (0.0 500 0.0) 		//XpYp Zp
	INTENSIDAD   1.0         		//[0..1] Intensidad de la luz
	
ESFERA
	//Datos Generales
	COLOR   0.9 0.1 0.1 			//Color
	KD   0.2  KA   0.2 KS   0.2 KN   0.2	//Variables de Iluminacion
	
	//Datos Particulares
	POSICION 50 50 50 			//Xc Yc Zc, en la Esfera el Ancla es el Centro	
	RADIO    25				//Radio
	
	//Datos General [OPCIONAL]
	PLANOS_DE_CORTE
		0.0  25  30  30 		// A   B  C  D
		[30 20 5] (51.25 63.0 15) 	// [A B C]  (X Y Z)
		(32 150 35) (0 0 0) (61 34 54)  // (X1 Y1 Z1) (X2 Y2 Z2) (X3 Y3 Z3)

CILINDRO
	//Datos Generales
	COLOR   0.9 0.1 0.1 			//Color
	KD   0.2  KA   0.2 KS   0.2 KN   0.2	//Variables de Iluminacion
	
	//Datos Particulares
	POSICION 41 51 64 			// En el cilindro la posicion es sl "ancla"
	DIRECCION 32 15 2			// Direccion del Cilindro
	RADIO    25				// Radio
	
	//Datos General [OPCIONAL] 
	PLANOS_DE_CORTE				
		0.0  25  30  30 		// A   B  C  D		
		0.0  25  30  30 		// A   B  C  D
		0.0  25  30  30 		// A   B  C  D
		(32 150 35) (0 0 0) (61 34 54)  // (X1 Y1 Z1) (X2 Y2 Z2) (X3 Y3 Z3)

CONO
	//Datos Generales
	COLOR   0.9 0.1 0.1 			// Color
	KD   0.2  KA   0.2 KS   0.2 KN   0.2	// Variables de Iluminacion
	
	//Datos Particulares
	POSICION 41 51 64 			// En el cilindro la posicion es sl "ancla"
	DIRECCION 32 15 2			// Direccion del cono
	RADIO    25				// Radio
	
	//Datos General [OPCIONAL] 
	PLANOS_DE_CORTE				
		0.0  25  30  30 		// A   B  C  D		
		0.0  25  30  30 		// A   B  C  D
		0.0  25  30  30 		// A   B  C  D
		(32 150 35) (0 0 0) (61 34 54)  // (X1 Y1 Z1) (X2 Y2 Z2) (X3 Y3 Z3)
		
	//Datos General [OPCIONAL] 
	TRANSFORMACIONES			
		ROTAR 25			// Indica hacer una rotacion
	
POLIGONO
	//Datos Generales
	COLOR   0.9 0.1 0.1 			// Color
	KD   0.2  KA   0.2 KS   0.2 KN   0.2	// Variables de Iluminacion
	(0 0) (51 13) (12 44) (12 61)		// (X1 Y1) (X2 Y2) (X3 Y3).... (Xn Yn) para n>=3
	TRANSFORMACIONES
		TRASLADAR25 12 61		// Indica trasladar el objeto
LUZ
	COLOR        1.0 1.0 1.0 		//R G B
	POSICION     (0.0 500 0.0) 		//XpYp Zp
	INTENSIDAD   1.0         		//[0..1] Intensidad de la luz
	