# ================= COMPILER =================
CC = gcc


# ================= FLAGS =================
CFLAGS = -Wall -Wextra \
         -Iinclude \
         $(foreach dir,$(MODULES),-I$(dir)/include)


LDFLAGS = -lssl -lcrypto -lm



# ================= DIRECTORIES =================
SRC = src
OBJ = obj
BIN = bin



# ================= MODULES =================
MODULES = \
170868_Akash_DR_module1_T006 \
170868_Akash_DR_module2_T006 \
170868_Akash_DR_module3_T006 \
170868_Akash_DR_module4_T006 \
170868_Akash_DR_module5_T006 \
170868_Akash_DR_module6_T006 \
170868_Akash_DR_module7_T006 \
170868_Akash_DR_module8_T006



# ================= MAIN FILES =================
MAIN_SRC = $(SRC)/main.c $(SRC)/switch.c

MAIN_OBJ = $(OBJ)/main.o $(OBJ)/switch.o



# ================= MODULE SOURCE =================
MODULE_SRC = $(foreach mod,$(MODULES),$(wildcard $(mod)/src/*.c))


MODULE_OBJ = $(patsubst %.c,%.o,$(MODULE_SRC))
MODULE_OBJ := $(patsubst %/src/%,%/obj/,$(MODULE_OBJ))



# ================= TARGET =================
TARGET = $(BIN)/app



# ================= DEFAULT =================
all: $(TARGET)



# ================= LINK =================
$(TARGET): $(MAIN_OBJ) $(MODULE_OBJ)

	@mkdir -p $(BIN)

	$(CC) $^ -o $@ $(LDFLAGS)



# ================= COMPILE MAIN =================
$(OBJ)/%.o: $(SRC)/%.c

	@mkdir -p $(OBJ)

	$(CC) $(CFLAGS) -c $< -o $@



# ================= COMPILE ALL MODULES =================
%/obj/%.o: %/src/%.c

	@mkdir -p $(dir $@)

	$(CC) $(CFLAGS) -c $< -o $@



# ================= RUN =================
execute: $(TARGET)

	./$(TARGET) $(ARGS)



# ================= CLEAN =================
clean:

	rm -rf $(OBJ)/*.o
	
	rm -rf $(SRC)/*.o

	rm -rf $(BIN)/*

	rm -rf $(foreach mod,$(MODULES),$(mod)/obj/*.o)

	find . -name "*.o" -delete
	rm -rf $(BIN)/*

# ================= REBUILD =================
re: clean all



.PHONY: all clean re execute
