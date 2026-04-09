# Compiler
CC = gcc

# Flags
CFLAGS = -Wall -Wextra -Iinclude \
         -I170868_Akash_YPK_module3_T010/include \
         -I170868_Akash_YPK_module4_T010/include

# Directories
SRC = src
OBJ = obj
BIN = bin

MOD3 = 170868_Akash_YPK_module3_T010
MOD4 = 170868_Akash_YPK_module4_T010

# Main sources
MAIN_SRC = $(SRC)/main.c $(SRC)/switch.c
MAIN_OBJ = $(OBJ)/main.o $(OBJ)/switch.o

# Module 3 sources
MOD3_SRC = $(wildcard $(MOD3)/src/*.c)
MOD3_OBJ = $(patsubst $(MOD3)/src/%.c,$(MOD3)/obj/%.o,$(MOD3_SRC))

# Module 4 sources
MOD4_SRC = $(wildcard $(MOD4)/src/*.c)
MOD4_OBJ = $(patsubst $(MOD4)/src/%.c,$(MOD4)/obj/%.o,$(MOD4_SRC))

# Final executable
TARGET = $(BIN)/app

# Default target
all: $(TARGET)

# Linking
$(TARGET): $(MAIN_OBJ) $(MOD3_OBJ) $(MOD4_OBJ)
	@mkdir -p $(BIN)
	$(CC) $^ -o $@

# Compile main
$(OBJ)/%.o: $(SRC)/%.c
	@mkdir -p $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile module 3
$(MOD3)/obj/%.o: $(MOD3)/src/%.c
	@mkdir -p $(MOD3)/obj
	$(CC) $(CFLAGS) -c $< -o $@

# Compile module 4
$(MOD4)/obj/%.o: $(MOD4)/src/%.c
	@mkdir -p $(MOD4)/obj
	$(CC) $(CFLAGS) -c $< -o $@

# Clean
clean:
	rm -rf $(OBJ)/*.o $(BIN)/*
	rm -rf $(MOD3)/obj/*.o
	rm -rf $(MOD4)/obj/*.o

# Rebuild
re: clean all

.PHONY: all clean re
