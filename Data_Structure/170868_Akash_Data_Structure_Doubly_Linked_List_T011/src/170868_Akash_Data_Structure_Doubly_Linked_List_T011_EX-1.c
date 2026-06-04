#include <stdio.h>
#include <stdint.h>

#include "/home/akash/Data_Structure/170868_Akash_Data_Structure_Doubly_Linked_List_T011/include/header.h"

void doubly_linked_list() {

	struct dnode* head = NULL;
	int32_t data;
	int32_t node;

	printf("enter the total number of node in a linked list\n");
	scanf("%d", &node);

	for (int32_t i = 0; i < node; i++) {

		printf("enter the data in linked list\n");
		scanf("%d", &data);

		insertatbegining_d(&head, data);
	}

	printf("enter the data to insert at the end\n");
	scanf("%d", &data);

	append_d(&head, data);

	printf("\nDoubly Linked List\n");
	display_d(head);

	printf("\nenter the data to delete\n");
	scanf("%d", &data);

	delete_d(&head, data);

	printf("\nAfter deletion\n");
	display_d(head);

	printf("\ntotal number of node is : %d\n", count_d(head));
}
