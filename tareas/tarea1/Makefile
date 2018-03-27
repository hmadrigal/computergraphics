OBJECTS=tarea1.o
OUTPUT=tarea1

CFLAGS=
LDLIBS=-lX11 -lglut -lGLU -lGL -lm -lXext -lXmu
LDFLAGS=-L/usr/X11/lib

$(OUTPUT): $(OBJECTS)
	$(CC) $(LDLIBS) $(LDFLAGS) $(CFLAGS) -o $(OUTPUT) $(OBJECTS)

$(OBJECTS):

clean:
	rm -f *.o tarea1