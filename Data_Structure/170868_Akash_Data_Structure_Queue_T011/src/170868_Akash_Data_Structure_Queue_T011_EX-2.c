#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct node {
	int32_t data;
	struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

/*
   function name : enqueue()
description : insert element into circular queue
 */
void enqueue(int32_t value)
{
	struct node *newNode = malloc(sizeof(struct node));

	newNode->data = value;

	if (front == NULL) {
		front = rear = newNode;
		rear->next = front;
	}
	else {
		newNode->next = front;
		rear->next = newNode;
		rear = newNode;
	}

	printf("%d inserted\n", value);
}

/*
   function name : dequeue()
description : delete element from circular queue
 */
void dequeue()
{
	if (front == NULL) {
		printf("Queue is Empty\n");
		return;
	}

	struct node *temp = front;

	printf("%d deleted\n", front->data);

	if (front == rear) {
		front = rear = NULL;
	}
	else {
		front = front->next;
		rear->next = front;
	}

	free(temp);
}

/*
   function name : display()
description : display circular queue
 */
void display1()
{
	if (front == NULL) {
		printf("Queue is Empty\n");
		return;
	}

	struct node *temp = front;

	do {
		printf("%d ", temp->data);
		temp = temp->next;
	} while (temp != front);

	printf("\n");
}
int main_test()
{
	int count = 0;

	for(int idx = 2; idx <= 24; idx += 2)
	{
		enqueue(idx);
		display1();

		count++;

		if(count == 3)
		{
			dequeue();
			display1();
			count = 0;
		}
	}

	return 0;
}
