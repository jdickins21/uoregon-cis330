SOURCES = maze.c move.c
HEADERS = move.h
OBJECTS = $(SOURCES:.c=.o)

maze:
	gcc -o maze -std=c99 maze.c move.c

clean: 
	$(RM) maze $(OBJECTS)
