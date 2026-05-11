CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
LDFLAGS = -lcrypto

SRC = src/main.c src/function.c
OBJ = obj/main.o obj/function.o

TARGET = bin/main.out

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

obj/%.o: src/%.c include/header.h
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f obj/*.o bin/*

rebuild: clean all
