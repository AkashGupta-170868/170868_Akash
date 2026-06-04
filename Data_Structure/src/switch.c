/*
   function name : switch1();
description : menu for linked list exercises
author      : akash Gupta
created at  : 13-05-2026
 */

#include <stdio.h>
#include <stdint.h>
#include "header.h"

void ex1(void)
{
	int8_t choice;

	printf("\n===== linked list exercises =====\n");
	printf("1. count element\n");
	printf("2. get nth element\n");
	printf("3. delete list test\n");
	printf("4. pop the element from head\n");
	printf("5. insert element at nth position\n");
	printf("6. insert element at appropreate position in sorted manner\n");
	printf("7. sorting the linked list\n");
	printf("8. append the list onto another\n");
	printf("10. renove duplicate element from the ll\n");
	printf("11. move first node from source to destination.\n");
	printf("0. back\n");
	printf("enter choice: ");

	if(scanf("%hhd", &choice) != 1)
	{
		while(getchar() != '\n');
		printf("Invalid input\n");
		return;
	}

	switch(choice)
	{
		case 1: CountTest(); break;
		case 2: GetNthTest(); break;
		case 3: DeleteListTest(); break;
		case 4: PopTest(); break;
		case 5: InsertNthTest(); break;
		case 6: SortedInsertTest(); break;
		case 7: InsertSortTest(); break;
		case 8: AppendTest(); break;
		case 10: RemoveDuplicatesTest(); break;
		case 11: MoveNodeTest(); break;
		case 0: return;
		default: printf("Invalid choice\n");
	}
}

void ex2()
{
	int8_t choice;

	printf("\n===== Queue exercises =====\n");
	printf("1. is palindrome\n");
	printf("2. circular queue\n");
	printf("3. to-do list\n");
	printf("0. back\n");
	printf("enter choice: ");

	if(scanf("%hhd", &choice) != 1)
	{
		while(getchar() != '\n');
		printf("Invalid input\n");
		return;
	}

	switch(choice)
	{
		case 1:
			while(getchar() != '\n');
			is_palindrome();
			break;
		case 2: main_test(); break;
		case 3:  to_do_list(); break;

		case 0:
			 return;

		default:
			 printf("Invalid choice\n");
	}
}

void ex3(void)
{
	int8_t choice;

	printf("\n===== Stack exercises =====\n");
	printf("1. Bracket Matching\n");
	printf("0. back\n");
	printf("enter choice: ");

	if(scanf("%hhd", &choice) != 1)
	{
		while(getchar() != '\n');
		printf("Invalid input\n");
		return;
	}

	switch(choice)
	{
		case 1:
			BracketMatching();
			break;
		case 0:
			return;

		default:
			printf("Invalid choice\n");
	}
}
void ex4(void)
{
	int8_t choice;

	printf("\n===== Tree exercises =====\n");
	printf("1. tree using linked list\n");
	printf("2. tree using array.\n");
	printf("3. traversal on tree (linked list implemented).\n");
	printf("4. traversal on tree (array implemented.\n");
	printf("5. search in a tree (linked list implemented )\n");
	printf("6. search in a tree (array implemented.)\n");
	printf("7. delete element from a tree ( linked list implemented\n");
	printf("8. preorder without using recursion\n");
	printf("9. postorder without using recursion\n");
	printf("10. copy the tree\n");
	printf("11. compare the tree\n");
	printf("12. threaded binary tree\n");
	printf("enter choice: ");

	if(scanf("%hhd", &choice) != 1)
	{
		while(getchar() != '\n');
		printf("Invalid input\n");
		return;
	}

	switch(choice)
	{
		case 1: tree_test();break;
		case 2: array_tree(); break;
		case 3: traversal_linked_list(); break;
		case 4: traversal_array(); break;
		case 5: binary_search_linked_list() ; break;
		case 6: binary_search_array(); break;
		case 7: delete_tree(); break;
		case 8: preorder_without_recursion(); break;
		case 9: postorder_without_recursion(); break;
		case 10: test_copytree(); break;
		case 11: test_comparetree(); break;
		case 12: main_t(); break;
		case 0:  return;

		default:
			 printf("Invalid choice\n");
	}
}
void ex5(){
	int8_t choice;

	printf("\n===== circular linked list exercises =====\n");
	printf("1. implement circular linked list\n");
	printf("2. sum of even data of node\n");
	printf("0. back\n");
	printf("enter choice: ");

	if(scanf("%hhd", &choice) != 1)
	{
		while(getchar() != '\n');
		printf("Invalid input\n");
		return;
	}

	switch(choice)
	{
		case 1:cir_main();break;
		case 2: cir_sum(); break;
		case 0:
			return;

		default:
			printf("Invalid choice\n");
	}	

}
void ex6(){	
	int8_t choice;

	printf("\n===== Doubly linked list exercises =====\n");
	printf("1. doubly linked list\n");
	printf("2. circular doubly linked list\n");
	printf("0. back\n");
	printf("enter choice: ");

	if(scanf("%hhd", &choice) != 1)
	{
		while(getchar() != '\n');
		printf("Invalid input\n");
		return;
	}

	switch(choice)
	{
		case 1:doubly_linked_list();break;
		case 2:main_cd(); break;
		case 0:
		       return;

		default:
		       printf("Invalid choice\n");
	}


}
int32_t switch1(void)
{
	int8_t module;

	while(1)
	{
		printf("\n===== MAIN MENU =====\n");
		printf("1. linked list\n");
		printf("2. queue\n");
		printf("3. stack\n");
		printf("4. binary tree\n");
		printf("5. circular linked list\n");
		printf("6. doubly linked list\n");
		printf("0. exit\n");
		printf("enter choice: ");

		if(scanf("%hhd", &module) != 1)
		{
			while(getchar() != '\n');
			printf("Invalid input\n");
			continue;
		}

		switch(module)
		{
			case 1: ex1(); break;
			case 2: ex2(); break;
			case 3: ex3(); break;
			case 4: ex4(); break;
			case 5: ex5(); break;
			case 6: ex6(); break;
			case 0: return 0;
			default: printf("Invalid choice\n");
		}
	}
}
