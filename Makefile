CC=gcc
CFLAGS=-c
LDFLAGS=
SOURCES=main.c \
		ternarysearchtree.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=stringfinder

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)
