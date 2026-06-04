#include <stdio.h>
#include <stdint.h>
#include "header.h"

/*
   function name : PopTest();
   description : test pop() function
   author      : akash Gupta
   created at  : 13-05-2026
*/
void PopTest(void)
{
    struct node *head = BuildOneTwoThree();

    printf("Original List:\n");
    PrintList(head);

    head = pop(head);
    printf("After first pop:\n");
    PrintList(head);

    head = pop(head);
    printf("After second pop:\n");
    PrintList(head);

    head = pop(head);
    printf("After third pop:\n");
    PrintList(head);

    printf("Length = %d\n", length(head));
}
