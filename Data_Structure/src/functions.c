#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
/*--------------------------------linked list ----------------------------------------------------------------*/
struct node
{
	int32_t data;
	struct node *next;
};

/*function name : push();
description : push element at beginning of linked list
author      : akash Gupta
created at  : 13-05-2026
 */
struct node* push(struct node *head, int32_t value)
{
	struct node *newNode = malloc(sizeof(struct node));

	newNode->data = value;
	newNode->next = head;

	return newNode;
}

/*function name : addAtEnd();
description : add element at end of linked list
author      : akash Gupta
created at  : 13-05-2026
 */
struct node* addAtEnd(struct node *head, int32_t value)
{
	struct node *newNode = malloc(sizeof(struct node));
	struct node *temp = head;

	newNode->data = value;
	newNode->next = NULL;

	if(head == NULL)
		return newNode;

	while(temp->next != NULL)
		temp = temp->next;

	temp->next = newNode;

	return head;
}

/*function name : length();
description : get length of linked list
author      : akash Gupta
created at  : 13-05-2026
 */
int32_t length(struct node *head)
{
	int32_t count = 0;

	while(head != NULL)
	{
		count++;
		head = head->next;
	}

	return count;
}

/*function name : ChangeToNull();
description : set head to NULL
author      : akash Gupta
created at  : 13-05-2026
 */
struct node* ChangeToNull(struct node *head)
{
	return NULL;
}

/*function name : PrintList();
description : display entire linked list
author      : akash Gupta
created at  : 13-05-2026
 */
void PrintList(struct node *head)
{
	while(head != NULL)
	{
		printf("%d -> ", head->data);
		head = head->next;
	}

	printf("NULL\n");
}

/*function name : Count();
description : count occurrence of target element
author      : akash Gupta
created at  : 13-05-2026
 */
int32_t Count(struct node *head, int32_t target)
{
	int32_t count = 0;

	while(head != NULL)
	{
		if(head->data == target)
			count++;

		head = head->next;
	}

	return count;
}

/* function name : getnth();
description : get nth node data
author      : akash Gupta
created at  : 13-05-2026
 */
int32_t getnth(struct node *head, int32_t idx)
{
	int32_t i = 0;

	while(head != NULL)
	{
		if(i == idx)
			return head->data;

		head = head->next;
		i++;
	}

	return -1;
}

/*function name : DeleteList();
description : delete complete linked list
author      : akash Gupta
created at  : 13-05-2026
 */
struct node* DeleteList(struct node *head)
{
	struct node *temp;

	while(head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}

	return NULL;
}

/*function name : BuildOneTwoThree();
description : create linked list 1->2->3
author      : akash Gupta
created at  : 13-05-2026
 */
struct node* BuildOneTwoThree(void)
{
	struct node *head = NULL;

	head = addAtEnd(head, 1);
	head = addAtEnd(head, 2);
	head = addAtEnd(head, 3);

	return head;
}

/*function name : pop();
description : remove first node
author      : akash Gupta
created at  : 13-05-2026
 */
struct node* pop(struct node *head)
{
	struct node *temp;

	if(head == NULL)
		return NULL;

	temp = head;
	head = head->next;
	free(temp);

	return head;
}

/*function name : InsertNth();
description : insert node at nth position
author      : akash Gupta
created at  : 13-05-2026
 */
struct node* InsertNth(struct node *head, int32_t index, int32_t data)
{
	struct node *newNode = malloc(sizeof(struct node));
	struct node *temp = head;

	newNode->data = data;

	if(index == 0)
	{
		newNode->next = head;
		return newNode;
	}

	for(int32_t i = 0; i < index - 1 && temp != NULL; i++)
		temp = temp->next;

	if(temp == NULL)
		return head;

	newNode->next = temp->next;
	temp->next = newNode;

	return head;
}

/*function name : SortedInsert();
description : insert node in sorted order
author      : akash Gupta
created at  : 13-05-2026
 */
struct node* SortedInsert(struct node *head, struct node *newNode)
{
	struct node *temp = head;

	if(head == NULL || head->data >= newNode->data)
	{
		newNode->next = head;
		return newNode;
	}

	while(temp->next != NULL && temp->next->data < newNode->data)
		temp = temp->next;

	newNode->next = temp->next;
	temp->next = newNode;

	return head;
}
/*----------------------------------------------------------------- queue ----------------------------------------------*/
#include <stdbool.h>

struct queue{
	struct node *front;
	struct node *back;
};

/*function name : is_segment();
description : travel on linked list and check if the front == back then return 1.
author      : akash Gupta
created at  : 15-05-2026
 */
bool is_segment(struct node *front , struct node *back){
	struct node *temp = front ;

	while( temp != NULL){
		if ( temp == back){
			return true;
		}
		temp = temp->next;
	}
	return false ;
}

/* function name : is_acyclic();
description : return 0 if cycle found other wise 1.
author      : akash Gupta
created at  : 15-05-2026
 */
bool is_acyclic(struct node *front)
{
	struct node *slow = front;
	struct node *fast = front;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;          // move 1 step
		fast = fast->next->next;    // move 2 steps

		if (slow == fast)
		{
			return false;   // cycle found
		}
	}

	return true;   // no cycle
}

/*function name : is_queue();
description : check whether queue is valid
author      : akash Gupta
created at  : 15-05-2026
 */
bool is_queue(struct queue* Q) {
	return Q != NULL
		&& is_acyclic(Q->front)
		&& is_segment(Q->front, Q->back);      // start and end check
}

/*function name : isQueueEmpty();
description : return 1 if queue is empty.
author      : akash Gupta
created at  : 15-05-2026
 */
bool isQueueEmpty(struct queue *Q){
	return  Q->front == Q->back;
}

/* function name : createQueue();
description : creating queue.
author      : akash Gupta
created at  : 15-05-2026
 */

struct queue* createQueue()
{
	struct queue *Q = malloc(sizeof(struct queue));
	struct node *dummyNode = malloc(sizeof(struct node));

	dummyNode->next = NULL;

	Q->front = dummyNode;
	Q->back = dummyNode;

	return Q;
}

/*function name : enQueue();
description : add queue at the end of queue
author      : akash Gupta
created at  : 15-05-2026
 */
void enQueue(struct queue* Q , int32_t data)
{
	struct node* newNode = (struct node*)malloc(sizeof(struct node));

	newNode->next = NULL;

	Q->back->data = data;
	Q->back->next = newNode;
	Q->back = newNode;
}

/*function name : deQueue();
description : pop queue from the front .
author      : akash Gupta
created at  : 15-05-2026
 */
int32_t deQueue(struct queue* Q)
{
	if (isQueueEmpty(Q)){
		printf("queue is empty\n");
		return -1;
	}

	struct node *qTemp = Q->front;
	Q->front = Q->front->next;

	int32_t data = qTemp->data;

	free(qTemp);

	return data;
}

/*function name : displayQueue();
description : print the all node of queue.
author      : akash Gupta
created at  : 15-05-2026
 */
void displayQueue(struct queue *Q){
	struct node *temp = Q->front;

	while ( temp != Q->back){

		printf("%d-> ", temp->data);
		temp = temp->next;
	}
	printf("->Dummy");
}
/*---------------------------------------------------- stack -------------------------------------------------------------*/






/*-------------------------------------------- Binary tree ------------------------------------------------------------*/








