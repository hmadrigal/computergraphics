OBJECTS=proyecto.o lex.yy.o y.tab.o data_structures.o
OUTPUT=raytracer

CFLAGS=
LDLIBS=-lX11 -lglut -lGLU -lGL -lm -lXext -lXmu
LDFLAGS=-L/usr/X11/lib

$(OUTPUT): $(OBJECTS)
	$(CC) $(LDLIBS) $(LDFLAGS) $(CFLAGS) -o $(OUTPUT) $(OBJECTS)
	$(RM) -f *.o lex.yy.c y.tab.*

$(OBJECTS): proyecto.h y.tab.h data_structures.h

y.tab.h y.tab.c: parser.y
	yacc -d parser.y

lex.yy.c: scanner.l
	lex scanner.l

clean:
	$(RM) -f *.o lex.yy.c y.tab.* proyecto
