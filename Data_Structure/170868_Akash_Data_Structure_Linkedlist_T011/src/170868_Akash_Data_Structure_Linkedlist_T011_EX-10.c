#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "header.h"

/*
   function name : RemoveDuplicates();
description : remove duplicate nodes from sorted linked list
author      : akash Gupta
created at  : 14-05-2026
 */
void RemoveDuplicates(struct node *head)
{
	struct node *current;
	struct node *temp;

	current = head;

	while(current != NULL && current->next != NULL)
	{
		if(current->data == current->next->data)
		{
			temp = current->next;
			current->next = temp->next;
			free(temp);
		}
		else
		{
			current = current->next;
		}
	}
}



/*
   function name : RemoveDuplicatesTest();
description : test RemoveDuplicates()
author      : akash Gupta
created at  : 14-05-2026
 */
void RemoveDuplicatesTest(void)
{
	struct node *head = NULL;

	head = addAtEnd(head, 1);
	head = addAtEnd(head, 1);
	head = addAtEnd(head, 2);
	head = addAtEnd(head, 2);
	head = addAtEnd(head, 3);
	head = addAtEnd(head, 3);

	printf("Before Removing Duplicates:\n");
	PrintList(head);

	RemoveDuplicates(head);

	printf("After Removing Duplicates:\n");
	PrintList(head);

	head = DeleteList(head);
}
