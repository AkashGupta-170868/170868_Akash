# ================= COMPILER =================
CC = gcc

# ================= FLAGS =================
CFLAGS = -Wall -Wextra \
         -Iinclude \
         -I170868_Akash_DR_module1_T006/include \
         -I170868_Akash_DR_module2_T006/include \
         -I170868_Akash_DR_module3_T006/include \
         -I170868_Akash_DR_module4_T006/include \
         -I170868_Akash_DR_module5_T006/include \
         -I170868_Akash_DR_module6_T006/include

# ================= DIRECTORIES =================
SRC = src
OBJ = obj
BIN = bin

MOD1 = 170868_Akash_DR_module1_T006
MOD2 = 170868_Akash_DR_module2_T006
MOD3 = 170868_Akash_DR_module3_T006
MOD4 = 170868_Akash_DR_module4_T006
MOD5 = 170868_Akash_DR_module5_T006
MOD6 = 170868_Akash_DR_module6_T006

# ================= MAIN =================
MAIN_SRC = $(SRC)/main.c $(SRC)/switch.c
MAIN_OBJ = $(OBJ)/main.o $(OBJ)/switch.o

# ================= MODULE SOURCES =================
MOD1_SRC = $(wildcard $(MOD1)/src/*.c)
MOD2_SRC = $(wildcard $(MOD2)/src/*.c)
MOD3_SRC = $(wildcard $(MOD3)/src/*.c)
MOD4_SRC = $(wildcard $(MOD4)/src/*.c)
MOD5_SRC = $(wildcard $(MOD5)/src/*.c)
MOD6_SRC = $(wildcard $(MOD6)/src/*.c)

# ================= MODULE OBJECTS =================
MOD1_OBJ = $(patsubst $(MOD1)/src/%.c,$(MOD1)/obj/%.o,$(MOD1_SRC))
MOD2_OBJ = $(patsubst $(MOD2)/src/%.c,$(MOD2)/obj/%.o,$(MOD2_SRC))
MOD3_OBJ = $(patsubst $(MOD3)/src/%.c,$(MOD3)/obj/%.o,$(MOD3_SRC))
MOD4_OBJ = $(patsubst $(MOD4)/src/%.c,$(MOD4)/obj/%.o,$(MOD4_SRC))
MOD5_OBJ = $(patsubst $(MOD5)/src/%.c,$(MOD5)/obj/%.o,$(MOD5_SRC))
MOD6_OBJ = $(patsubst $(MOD6)/src/%.c,$(MOD6)/obj/%.o,$(MOD6_SRC))

# ================= TARGET =================
TARGET = $(BIN)/app

# ================= DEFAULT =================
all: $(TARGET)

# ================= LINKING =================
$(TARGET): $(MAIN_OBJ) $(MOD1_OBJ) $(MOD2_OBJ) $(MOD3_OBJ) $(MOD4_OBJ) $(MOD5_OBJ) $(MOD6_OBJ)
        @mkdir -p $(BIN)
        $(CC) $^ -o $@

# ================= COMPILE MAIN =================
$(OBJ)/%.o: $(SRC)/%.c
        @mkdir -p $(OBJ)
        $(CC) $(CFLAGS) -c $< -o $@

# ================= COMPILE MODULES =================
$(MOD1)/obj/%.o: $(MOD1)/src/%.c
        @mkdir -p $(MOD1)/obj
        $(CC) $(CFLAGS) -c $< -o $@

$(MOD2)/obj/%.o: $(MOD2)/src/%.c
        @mkdir -p $(MOD2)/obj
        $(CC) $(CFLAGS) -c $< -o $@

$(MOD3)/obj/%.o: $(MOD3)/src/%.c
        @mkdir -p $(MOD3)/obj
        $(CC) $(CFLAGS) -c $< -o $@

$(MOD4)/obj/%.o: $(MOD4)/src/%.c
        @mkdir -p $(MOD4)/obj
        $(CC) $(CFLAGS) -c $< -o $@

$(MOD5)/obj/%.o: $(MOD5)/src/%.c
        @mkdir -p $(MOD5)/obj
        $(CC) $(CFLAGS) -c $< -o $@

$(MOD6)/obj/%.o: $(MOD6)/src/%.c
        @mkdir -p $(MOD6)/obj
        $(CC) $(CFLAGS) -c $< -o $@

# ================= CLEAN =================
clean:
	rm -rf $(MOD1)/obj/*.o
	rm -rf $(MOD2)/obj/*.o
	rm -rf $(MOD3)/obj/*.o
	rm -rf $(MOD4)/obj/*.o
	rm -rf $(MOD5)/obj/*.o
	rm -rf $(MOD6)/obj/*.o

# ================= REBUILD =================
re: clean all

.PHONY: all clean re
