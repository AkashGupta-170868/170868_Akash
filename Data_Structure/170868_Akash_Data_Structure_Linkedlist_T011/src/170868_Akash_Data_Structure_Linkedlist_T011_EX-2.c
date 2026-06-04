#include <stdio.h>
#include <stdint.h>
#include "header.h"

/*
   function name : GetNthTest();
description : test getnth() function
author      : akash Gupta
created at  : 13-05-2026
 */
void GetNthTest(void)
{
	struct node *myList = BuildOneTwoThree();

	PrintList(myList);

	int32_t lastNode = getnth(myList, 2);

	printf("Value at index 2 = %d\n", lastNode);

	myList = DeleteList(myList);
}
