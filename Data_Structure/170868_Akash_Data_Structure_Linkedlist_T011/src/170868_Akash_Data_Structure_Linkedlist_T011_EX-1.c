#include <stdio.h>
#include <stdint.h>
#include "header.h"

/*
   function name : CountTest();
description : test Count() function
author      : akash Gupta
created at  : 13-05-2026
 */
void CountTest(void)
{
	struct node *myList = BuildOneTwoThree();

	PrintList(myList);

	int32_t count = Count(myList, 2);

	printf("Count of 2 = %d\n", count);

	myList = DeleteList(myList);
}
