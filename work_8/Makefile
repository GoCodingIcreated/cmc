TARGET=main
CFILES=3.c
HFILES=
OBJECTS=$(CFILES:.c=.o)
CFLAGS=-g -std=gnu99 -Wall -Werror
LDFLAGS=-s
CC=gcc

all:$(TARGET)
$(TARGET):$(OBJECTS)
	$(CC) $(LDFLAGS) -o $(TARGET) $^
	rm -f $(OBJECTS)
deps.make:$(CFILES) $(HFILES)
	gcc -MM $(CFILES) > deps.make
include deps.make

clean:
	rm -f $(OBJECTS) $(TARGET) deps.make
