
CC = gcc
CFLAGS = -Wall
EXECUTABLE_NAME = target

COMPILER_CALL = $(CC) $(CFLAGS)

# Source and object discovery
SOURCES = main.c $(wildcard */*.c)
OBJECTS = $(patsubst %.c, %.o, $(SOURCES))

build: $(OBJECTS)
	$(COMPILER_CALL) $(OBJECTS) -o $(EXECUTABLE_NAME)

execute:
	./$(EXECUTABLE_NAME)

clean:
	rm -f *.o
	rm -f $(EXECUTABLE_NAME)

%.o: %.c
	$(COMPILER_CALL) -c $< -o $@
