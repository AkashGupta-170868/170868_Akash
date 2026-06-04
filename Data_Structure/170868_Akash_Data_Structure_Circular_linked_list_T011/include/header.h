#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>

/* Structure Definition */
typedef struct Node {
    int data;
    struct Node* next;
} Node;

struct Node* createNode(int data);

void insertAtBeginning(struct Node** head, int data);

void insertAtEnd(struct Node** head, int data);

void deleteNode(struct Node** head, int data);

void display(struct Node* head);

#endif
