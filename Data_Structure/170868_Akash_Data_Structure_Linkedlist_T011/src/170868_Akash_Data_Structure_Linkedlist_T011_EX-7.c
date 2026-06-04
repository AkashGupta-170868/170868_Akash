#include <stdio.h>
#include "header.h"
/*
   function name : InsertSort();
description : sort linked list in increasing order
author      : akash Gupta
created at  : 13-05-2026
 */
struct node* InsertSort(struct node *head)
{
	struct node *sorted = NULL;
	struct node *current;
	struct node *next;

	current = head;

	while(current != NULL)
	{
		next = current->next;

		sorted = SortedInsert(sorted, current);

		current = next;
	}

	return sorted;
}

/*
   function name : InsertSortTest();
description : test InsertSort()
author      : akash Gupta
created at  : 13-05-2026
 */
void InsertSortTest(void)
{
	struct node *head = NULL;

	head = addAtEnd(head, 30);
	head = addAtEnd(head, 10);
	head = addAtEnd(head, 20);
	head = addAtEnd(head, 5);

	printf("Before Sorting:\n");
	PrintList(head);

	head = InsertSort(head);

	printf("After Sorting:\n");
	PrintList(head);

	head = DeleteList(head);
}
