#
#Archivo:
#	Makefile
#Creador: 
#	Herberth Madrigal Bendless

OBJECTS=firma.o lex.yy.o y.tab.o
OUTPUT=firma

CFLAGS=
LDLIBS=-lX11 -lglut -lGLU -lGL -lm -lXext -lXmu
LDFLAGS=-L/usr/X11/lib

$(OUTPUT):$(OBJECTS)
	$(CC) $(LDLIBS) $(LDFLAGS) $(CFLAGS) -o $(OUTPUT) $(OBJECTS)
	$(RM) -f *.o lex.yy.c y.tab.* 

$(OBJECTS): firma.h y.tab.h

y.tab.c y.tab.h : parser.y
		yacc -d parser.y

lex.yy.c : scanner.l
		lex scanner.l

clean:
	$(RM) -f *.o firma lex.yy.c y.tab.* 