OBJECTS=proyecto.o comandos.o universal_data.o lex.yy.o y.tab.o transf.o draw.o
OUTPUT=proyecto

CFLAGS=
LDLIBS=-lX11 -lglut -lGLU -lGL -lm -lXext -lXmu
LDFLAGS=-L/usr/X11/lib

$(OUTPUT): $(OBJECTS)
	$(CC) $(LDLIBS) $(LDFLAGS) $(CFLAGS) -o $(OUTPUT) $(OBJECTS)
	$(RM) -f *.o lex.yy.c y.tab.*

$(OBJECTS): proyecto.h comandos.h universal_data.h y.tab.h transf.h draw.h

y.tab.h y.tab.c: parser.y
	yacc -d parser.y

lex.yy.c: scanner.l
	lex scanner.l

clean:
	$(RM) -f *.o lex.yy.c y.tab.* proyecto
