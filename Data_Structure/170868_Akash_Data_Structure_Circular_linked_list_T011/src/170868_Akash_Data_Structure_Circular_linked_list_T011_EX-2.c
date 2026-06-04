
/*
description : implementing the circular linked list and find sum of even data of the linked list.
Author : akash gupta
create at : 26 may
 */

#include <stdio.h>
#include <stdint.h>

#include "/home/akash/Data_Structure/170868_Akash_Data_Structure_Circular_linked_list_T011/include/header.h"

int32_t cir_sum() {

	struct Node* head = NULL;

	insertAtBeginning(&head, 1);
	insertAtEnd(&head, 2);
	insertAtEnd(&head, 3);
	insertAtBeginning(&head, 4);

	printf("Circular Linked List: ");
	display_c(head);

	int sum = 0;
	struct Node* temp = head;

	do {

		if (!(temp->data & 1)) {
			sum = sum + temp->data;
		}

		temp = temp->next;

	} while (temp != head);

	printf("The even nodes sum is %d\n", sum);

	return 0;
}
