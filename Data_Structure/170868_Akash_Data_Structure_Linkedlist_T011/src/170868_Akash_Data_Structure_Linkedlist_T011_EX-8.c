#include <stdio.h>
#include "header.h"

/*
   function name : Append();
description : append list b at end of list a
author      : akash Gupta
created at  : 13-05-2026
 */
struct node* Append(struct node *a, struct node *b)
{
	struct node *temp;

	if(a == NULL)
		return b;

	temp = a;

	while(temp->next != NULL)
		temp = temp->next;

	temp->next = b;

	return a;
}

/*
   function name : AppendTest();
description : test Append()
author      : akash Gupta
created at  : 13-05-2026
 */
void AppendTest(void)
{
	struct node *a = BuildOneTwoThree();
	struct node *b = NULL;

	b = addAtEnd(b, 4);
	b = addAtEnd(b, 4);

	printf("List A:\n");
	PrintList(a);

	printf("List B:\n");
	PrintList(b);

	a = Append(a, b);
	b = NULL;

	printf("After Append:\n");
	PrintList(a);

	printf("List B:\n");
	PrintList(b);

	a = DeleteList(a);
}
