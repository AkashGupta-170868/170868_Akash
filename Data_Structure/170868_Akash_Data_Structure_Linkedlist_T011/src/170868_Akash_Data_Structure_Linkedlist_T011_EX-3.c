#include <stdio.h>
#include <stdint.h>
#include "header.h"

void DeleteListTest(void)
{
    struct node *myList = BuildOneTwoThree();

    printf("Before delete:\n");
    PrintList(myList);

    myList = DeleteList(myList);

    printf("After delete:\n");
    PrintList(myList);
}
