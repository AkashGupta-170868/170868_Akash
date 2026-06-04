/*
description : implementing the circular linked list
Author : akash gupta
create at : 26 may 
*/
#include <stdio.h>
#include <stdint.h>
#include <stdint.h>
#include "/home/akash/Data_Structure/170868_Akash_Data_Structure_Circular_linked_list_T011/include/header.h"

int32_t cir_main() {

	struct Node* head = NULL;

	insertAtBeginning(&head, 1);
	insertAtEnd(&head, 2);
	insertAtEnd(&head, 3);
	insertAtBeginning(&head, 4);

	printf("Circular Linked List: ");
	display_c(head);

	deleteNode_c(&head, 2);

	printf("Circular Linked List after deleting 2: ");
	display_c(head);

	return 0;
}
