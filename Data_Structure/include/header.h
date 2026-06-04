#ifndef HEADER_H
#define HEADER_H

#include <stdint.h>
#include <stdbool.h>
/* Linked List Node Structure */
struct node
{
	int32_t data;
	struct node *next;
};

/* Function Declarations */

struct node* push(struct node *head, int32_t value);

struct node* addAtEnd(struct node *head, int32_t value);

int32_t length(struct node *head);

struct node* ChangeToNull(struct node *head);

void PrintList(struct node *head);

int32_t Count(struct node *head, int32_t target);

int32_t getnth(struct node *head, int32_t idx);

struct node* DeleteList(struct node *head);

struct node* BuildOneTwoThree(void);

struct node* pop(struct node *head);

struct node* InsertNth(struct node *head, int32_t index, int32_t data);

struct node* SortedInsert(struct node *head, struct node *newNode);

/* Test Function */
void DeleteListTest(void);


struct queue
{
	struct node *front;
	struct node *back;
};

/* ---------------- Queue Functions ---------------- */

bool is_segment(struct node *front, struct node *back);

bool is_acyclic(struct node *front);

bool is_queue(struct queue *Q);

bool isQueueEmpty(struct queue *Q);

struct queue* createQueue(void);

void enQueue(struct queue *Q, int32_t data);

int32_t deQueue(struct queue *Q);

void displayQueue(struct queue *Q);
/* ------------------------- stack function ------------*/

#endif
