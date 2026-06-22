CC = gcc

CFLAGS = -Wall \
-Iinclude \
-I170868_Akash_Data_Structure_Linked_List_TakeAway_T011/include \
-I170868_Akash_Data_Structure_Binary_Tree_TakeAway_T011/include \
-I170868_Akash_Data_Structure_Queue_TakeAway_T011/include

OUT = bin/output

MAIN_SRC = $(wildcard src/*.c)

LL_SRC = $(wildcard 170868_Akash_Data_Structure_Linked_List_TakeAway_T011/src/*.c)

BT_SRC = $(wildcard 170868_Akash_Data_Structure_Binary_Tree_TakeAway_T011/src/*.c)

Q_SRC = $(wildcard 170868_Akash_Data_Structure_Queue_TakeAway_T011/src/*.c)

MAIN_OBJ = $(patsubst src/%.c,obj/%.o,$(MAIN_SRC))

LL_OBJ = $(patsubst \
170868_Akash_Data_Structure_Linked_List_TakeAway_T011/src/%.c,\
170868_Akash_Data_Structure_Linked_List_TakeAway_T011/obj/%.o,\
$(LL_SRC))

BT_OBJ = $(patsubst \
170868_Akash_Data_Structure_Binary_Tree_TakeAway_T011/src/%.c,\
170868_Akash_Data_Structure_Binary_Tree_TakeAway_T011/obj/%.o,\
$(BT_SRC))

Q_OBJ = $(patsubst \
170868_Akash_Data_Structure_Queue_TakeAway_T011/src/%.c,\
170868_Akash_Data_Structure_Queue_TakeAway_T011/obj/%.o,\
$(Q_SRC))

OBJ = $(MAIN_OBJ) $(LL_OBJ) $(BT_OBJ) $(Q_OBJ)

all: $(OUT)

$(OUT): $(OBJ)
	@mkdir -p bin
	$(CC) $(OBJ) -o $(OUT)

obj/%.o: src/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

170868_Akash_Data_Structure_Linked_List_TakeAway_T011/obj/%.o: \
170868_Akash_Data_Structure_Linked_List_TakeAway_T011/src/%.c
	@mkdir -p 170868_Akash_Data_Structure_Linked_List_TakeAway_T011/obj
	$(CC) $(CFLAGS) -c $< -o $@

170868_Akash_Data_Structure_Binary_Tree_TakeAway_T011/obj/%.o: \
170868_Akash_Data_Structure_Binary_Tree_TakeAway_T011/src/%.c
	@mkdir -p 170868_Akash_Data_Structure_Binary_Tree_TakeAway_T011/obj
	$(CC) $(CFLAGS) -c $< -o $@

170868_Akash_Data_Structure_Queue_TakeAway_T011/obj/%.o: \
170868_Akash_Data_Structure_Queue_TakeAway_T011/src/%.c
	@mkdir -p 170868_Akash_Data_Structure_Queue_TakeAway_T011/obj
	$(CC) $(CFLAGS) -c $< -o $@

run: $(OUT)
	./$(OUT)

clean:
	rm -f obj/*.o
	rm -f 170868_Akash_Data_Structure_Linked_List_TakeAway_T011/obj/*.o
	rm -f 170868_Akash_Data_Structure_Binary_Tree_TakeAway_T011/obj/*.o
	rm -f 170868_Akash_Data_Structure_Queue_TakeAway_T011/obj/*.o
	rm -f $(OUT)

rebuild: clean all

.PHONY: all run clean rebuild
