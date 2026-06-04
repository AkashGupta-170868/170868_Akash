CC = gcc

CFLAGS = -Wall -Wextra \
-Iinclude \
-I170868_Akash_Data_Structure_Linkedlist_T011/include \
-I170868_Akash_Data_Structure_Queue_T011/include \
-I170868_Akash_Data_Structure_Stack_T011/include \
-I170868_Akash_Data_Structure_Binary_Tree_T011/include \
-I170868_Akash_Data_Structure_Circular_linked_list_T011/include \
-I170868_Akash_Data_Structure_Doubly_Linked_List_T011/include

TARGET = bin/output


# ================= ROOT =================

ROOT_SRC = $(wildcard src/*.c)

ROOT_OBJ = $(patsubst src/%.c,obj/%.o,$(ROOT_SRC))


# ================= LINKED LIST =================

LL_SRC = $(wildcard 170868_Akash_Data_Structure_Linkedlist_T011/src/*.c)

LL_OBJ = $(patsubst \
170868_Akash_Data_Structure_Linkedlist_T011/src/%.c,\
170868_Akash_Data_Structure_Linkedlist_T011/obj/%.o,\
$(LL_SRC))


# ================= QUEUE =================

Q_SRC = $(wildcard 170868_Akash_Data_Structure_Queue_T011/src/*.c)

Q_OBJ = $(patsubst \
170868_Akash_Data_Structure_Queue_T011/src/%.c,\
170868_Akash_Data_Structure_Queue_T011/obj/%.o,\
$(Q_SRC))


# ================= STACK =================

S_SRC = $(wildcard 170868_Akash_Data_Structure_Stack_T011/src/*.c)

S_OBJ = $(patsubst \
170868_Akash_Data_Structure_Stack_T011/src/%.c,\
170868_Akash_Data_Structure_Stack_T011/obj/%.o,\
$(S_SRC))


# ================= BINARY TREE =================

BT_SRC = $(wildcard 170868_Akash_Data_Structure_Binary_Tree_T011/src/*.c)

BT_OBJ = $(patsubst \
170868_Akash_Data_Structure_Binary_Tree_T011/src/%.c,\
170868_Akash_Data_Structure_Binary_Tree_T011/obj/%.o,\
$(BT_SRC))


# ================= CIRCULAR LINKED LIST =================

CLL_SRC = $(wildcard 170868_Akash_Data_Structure_Circular_linked_list_T011/src/*.c)

CLL_OBJ = $(patsubst \
170868_Akash_Data_Structure_Circular_linked_list_T011/src/%.c,\
170868_Akash_Data_Structure_Circular_linked_list_T011/obj/%.o,\
$(CLL_SRC))


# ================= DOUBLY LINKED LIST =================

DLL_SRC = $(wildcard 170868_Akash_Data_Structure_Doubly_Linked_List_T011/src/*.c)

DLL_OBJ = $(patsubst \
170868_Akash_Data_Structure_Doubly_Linked_List_T011/src/%.c,\
170868_Akash_Data_Structure_Doubly_Linked_List_T011/obj/%.o,\
$(DLL_SRC))


# ================= ALL OBJECT FILES =================

OBJ = $(ROOT_OBJ) \
$(LL_OBJ) \
$(Q_OBJ) \
$(S_OBJ) \
$(BT_OBJ) \
$(CLL_OBJ) \
$(DLL_OBJ)


all: $(TARGET)


$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)


# ================= ROOT =================

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@


# ================= LINKED LIST =================

170868_Akash_Data_Structure_Linkedlist_T011/obj/%.o: \
170868_Akash_Data_Structure_Linkedlist_T011/src/%.c
	$(CC) $(CFLAGS) -c $< -o $@


# ================= QUEUE =================

170868_Akash_Data_Structure_Queue_T011/obj/%.o: \
170868_Akash_Data_Structure_Queue_T011/src/%.c
	$(CC) $(CFLAGS) -c $< -o $@


# ================= STACK =================

170868_Akash_Data_Structure_Stack_T011/obj/%.o: \
170868_Akash_Data_Structure_Stack_T011/src/%.c
	$(CC) $(CFLAGS) -c $< -o $@


# ================= BINARY TREE =================

170868_Akash_Data_Structure_Binary_Tree_T011/obj/%.o: \
170868_Akash_Data_Structure_Binary_Tree_T011/src/%.c
	$(CC) $(CFLAGS) -c $< -o $@


# ================= CIRCULAR LINKED LIST =================

170868_Akash_Data_Structure_Circular_linked_list_T011/obj/%.o: \
170868_Akash_Data_Structure_Circular_linked_list_T011/src/%.c
	$(CC) $(CFLAGS) -c $< -o $@


# ================= DOUBLY LINKED LIST =================

170868_Akash_Data_Structure_Doubly_Linked_List_T011/obj/%.o: \
170868_Akash_Data_Structure_Doubly_Linked_List_T011/src/%.c
	$(CC) $(CFLAGS) -c $< -o $@


run: all
	./$(TARGET)


clean:
	rm -f obj/*.o
	rm -f 170868_Akash_Data_Structure_Linkedlist_T011/obj/*.o
	rm -f 170868_Akash_Data_Structure_Queue_T011/obj/*.o
	rm -f 170868_Akash_Data_Structure_Stack_T011/obj/*.o
	rm -f 170868_Akash_Data_Structure_Binary_Tree_T011/obj/*.o
	rm -f 170868_Akash_Data_Structure_Circular_linked_list_T011/obj/*.o
	rm -f 170868_Akash_Data_Structure_Doubly_Linked_List_T011/obj/*.o
	rm -f $(TARGET)
