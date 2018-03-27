OBJECTS=proyecto.o
OUTPUT=proyecto

CFLAGS=
LDLIBS=-lX11 -lglut -lGLU -lGL -lm -lXext -lXmu
LDFLAGS=-L/usr/X11/lib

$(OUTPUT): $(OBJECTS)
	$(CC) $(LDLIBS) $(LDFLAGS) $(CFLAGS) -o $(OUTPUT) $(OBJECTS)

$(OBJECTS): proyecto.h

clean:
	rm -f *.o proyecto