#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "header.h"

/*
   function name : SortedInsertTest();
description : test SortedInsert() with user input
author      : akash Gupta
created at  : 13-05-2026
 */
void SortedInsertTest(void)
{
	struct node *head = NULL;
	struct node *newNode;
	int32_t value;

	head = addAtEnd(head, 10);
	head = addAtEnd(head, 20);
	head = addAtEnd(head, 30);

	printf("Sorted List:\n");
	PrintList(head);

	printf("Enter value to insert: ");
	scanf("%d", &value);

	newNode = malloc(sizeof(struct node));
	newNode->data = value;
	newNode->next = NULL;

	head = SortedInsert(head, newNode);

	printf("After Sorted Insert:\n");
	PrintList(head);

	head = DeleteList(head);
}
