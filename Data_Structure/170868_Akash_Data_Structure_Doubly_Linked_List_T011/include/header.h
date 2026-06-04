#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*
description : structure for doubly linked list node
*/
struct dnode {
        int32_t data;
        struct dnode* prev;
        struct dnode* next;
};

struct noded {
	int data;
	struct noded* prev;
	struct noded* next;
};

/* function declarations */

struct dnode* createnode_d(int32_t data);

void insertatbegining_d(struct dnode** head, int32_t data);

void append_d(struct dnode** head, int32_t data);

void display_d(struct dnode* head);

int32_t count_d(struct dnode* head);

void delete_d(struct dnode** head, int32_t data);

#endif
