/*
description : Create a program that simulates a to-do list manager using a queue. The program should allow users to perform the following operations:
1.Add a task to the to-do list.
2.If the task is already present in the list - then ignore the task
3.Display the current to-do list once all tasks have been added
author      : akash Gupta
created at  : 18-05-2026
 */
#include <stdio.h>
#include <stdint.h>
#include "header.h"

/*function name : ispresent();
description : check in the queue is the data/task present or not ?
author      : akash Gupta
created at  : 18-05-2026
 */
bool isPresent(struct queue *Q, int32_t task)
{
	struct node *temp = Q->front;

	while(temp != Q->back){
		if(temp->data == task){
			return true;
		}
		temp = temp->next;
	}

	return false;
}
/*
   function name : to_do_list();
description : if the task is not in an queue then do enqueue otherwise ignore it 
author      : akash Gupta
created at  : 18-05-2026
 */
void to_do_list() {

	struct queue *Q = createQueue();
	int data;

	for ( int idx = 0 ; idx <= 9; idx++){
		printf("enter data to add your to-do\n");
		scanf("%d",&data);
		if ( !isPresent(Q,data)){
			enQueue(Q,data); 

		}
	}

	displayQueue(Q);
}
