#include <stdio.h>
#include <stdint.h>
#include "header.h"



/*
   function name : MoveNode();
description : move front node from source to destination
author      : akash Gupta
created at  : 13-05-2026
 */
void MoveNode(struct node **destRef, struct node **sourceRef)
{
	struct node *temp;

	if(*sourceRef == NULL)
		return;

	temp = *sourceRef;
	*sourceRef = (*sourceRef)->next;

	temp->next = *destRef;
	*destRef = temp;
}
/*
   function name : MoveNodeTest();
description : test MoveNode()
author      : akash Gupta
created at  : 13-05-2026
 */
void MoveNodeTest(void)
{
	struct node *a = BuildOneTwoThree();
	struct node *b = BuildOneTwoThree();

	printf("Before Move:\n");

	printf("List A: ");
	PrintList(a);

	printf("List B: ");
	PrintList(b);

	MoveNode(&a, &b);

	printf("\nAfter Move:\n");

	printf("List A: ");
	PrintList(a);

	printf("List B: ");
	PrintList(b);

	a = DeleteList(a);
	b = DeleteList(b);
}
