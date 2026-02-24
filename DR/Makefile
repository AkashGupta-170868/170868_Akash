CC = gcc
CFLAGS = -Wall -Iinclude

# ===== ROOT (DR) =====
DR_SRC = src
DR_OBJ = obj
DR_INC = include
DR_BIN = bin

# ===== MODULE-1 =====
MOD1_DIR = 170868_Akash_DR_module1_T006
MOD1_SRC = $(MOD1_DIR)/src
MOD1_OBJ = $(MOD1_DIR)/obj
MOD1_INC = $(MOD1_DIR)/include
MOD1_BIN = $(MOD1_DIR)/bin

# ===== MODULE-2 =====
MOD2_DIR = 170868_Akash_DR_module2_T006
MOD2_SRC = $(MOD2_DIR)/src
MOD2_OBJ = $(MOD2_DIR)/obj
MOD2_INC = $(MOD2_DIR)/include
MOD2_BIN = $(MOD2_DIR)/bin

# ===== Final Executable (choose where you want it) =====
EXECUTABLE = $(MOD1_BIN)/target

# ===== Source Files =====
DR_SOURCES   = $(wildcard $(DR_SRC)/*.c)
MOD1_SOURCES = $(wildcard $(MOD1_SRC)/*.c)
MOD2_SOURCES = $(wildcard $(MOD2_SRC)/*.c)

# ===== Object Files =====
DR_OBJECTS   = $(patsubst $(DR_SRC)/%.c,$(DR_OBJ)/%.o,$(DR_SOURCES))
MOD1_OBJECTS = $(patsubst $(MOD1_SRC)/%.c,$(MOD1_OBJ)/%.o,$(MOD1_SOURCES))
MOD2_OBJECTS = $(patsubst $(MOD2_SRC)/%.c,$(MOD2_OBJ)/%.o,$(MOD2_SOURCES))

OBJECTS = $(DR_OBJECTS) $(MOD1_OBJECTS) $(MOD2_OBJECTS)

# ===== Default Target =====
all: build

build: $(EXECUTABLE)

# ===== Linking =====
$(EXECUTABLE): $(OBJECTS) | $(MOD1_BIN)
	@$(CC) $(CFLAGS) $^ -o $@

# ===== Compile ROOT =====
$(DR_OBJ)/%.o: $(DR_SRC)/%.c | $(DR_OBJ)
	@$(CC) $(CFLAGS) -I$(DR_INC) -c $< -o $@

# ===== Compile MODULE-1 =====
$(MOD1_OBJ)/%.o: $(MOD1_SRC)/%.c | $(MOD1_OBJ)
	@$(CC) $(CFLAGS) -I$(MOD1_INC) -c $< -o $@

# ===== Cecho $(pwd)o;
# compile MODULE-2 =====
$(MOD2_OBJ)/%.o: $(MOD2_SRC)/%.c | $(MOD2_OBJ)
	@$(CC) $(CFLAGS) -I$(MOD2_INC) -c $< -o $@

# ===== Create Directories =====
$(DR_OBJ):
	mkdir -p $(DR_OBJ)

$(MOD1_OBJ):
	mkdir -p $(MOD1_OBJ)

$(MOD2_OBJ):
	mkdir -p $(MOD2_OBJ)

$(MOD1_BIN):
	mkdir -p $(MOD1_BIN)

# ===== Run =====
execute:
	./$(EXECUTABLE)

# ===== Clean =====
clean:
	rm -rf $(DR_OBJ)/*.o
	rm -rf $(MOD1_OBJ)/*.o
	rm -rf $(MOD2_OBJ)/*.o
	rm -rf $(EXECUTABLE)

.PHONY: all build execute clean

