#include <stdio.h>
#include <stdint.h>
#include "header.h"

/*
   function name : InsertNthTest();
description : test InsertNth() using BuildOneTwoThree()
author      : akash Gupta
created at  : 13-05-2026
 */
void InsertNthTest(void)
{
	struct node *head = BuildOneTwoThree();

	printf("Original List:\n");
	PrintList(head);

	head = InsertNth(head, 1, 13);

	printf("After InsertNth:\n");
	PrintList(head);

	head = DeleteList(head);
}
