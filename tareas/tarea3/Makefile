
OBJECTS=dodecaedro.o
OUTPUT=dodecaedro


CFLAGS=
LDLIBS=-lX11 -lglut -lGLU -lGL -lm -lXext -lXmu
LDFLAGS=-L/usr/X11/lib

$(OUTPUT): $(OBJECTS)
	cc $(LDLIBS) $(LDFLAGS) $(CFLAGS) -o $(OUTPUT) $(OBJECTS)
	rm -f *.o
