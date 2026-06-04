#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "/home/akash/Data_Structure/170868_Akash_Data_Structure_Doubly_Linked_List_T011/include/header.h"
/*
   function name : createnode_cd
description   : create new node
 */
struct dnode* createnode_cd(int32_t data) {

	struct dnode* newnode =
		(struct dnode*)malloc(sizeof(struct dnode));

	if (newnode == NULL) {
		printf("memory allocation failed\n");
		return NULL;
	}

	newnode->data = data;
	newnode->next = newnode;
	newnode->prev = newnode;

	return newnode;
}

/*
   function name : insertatbegining_cd
description   : insert node at beginning
 */
void insertatbegining_cd(struct dnode** head, int32_t data) {

	struct dnode* newnode = createnode_cd(data);

	if (*head == NULL) {
		*head = newnode;
		return;
	}

	struct dnode* last = (*head)->prev;

	newnode->next = *head;
	newnode->prev = last;

	last->next = newnode;
	(*head)->prev = newnode;

	*head = newnode;
}

/*
   function name : append_cd
description   : insert node at end
 */
void append_cd(struct dnode** head, int32_t data) {

	struct dnode* newnode = createnode_cd(data);

	if (*head == NULL) {
		*head = newnode;
		return;
	}

	struct dnode* last = (*head)->prev;

	newnode->next = *head;
	newnode->prev = last;

	last->next = newnode;
	(*head)->prev = newnode;
}

/*
   function name : display_cd
description   : display circular doubly linked list
 */
void display_cd(struct dnode* head) {

	if (head == NULL) {
		printf("list is empty\n");
		return;
	}

	struct dnode* temp = head;

	printf("forward traversing\n");

	do {
		printf("%d ", temp->data);
		temp = temp->next;
	} while (temp != head);

	printf("\nbackward traversing\n");

	temp = head->prev;

	do {
		printf("%d ", temp->data);
		temp = temp->prev;
	} while (temp != head->prev);

	printf("\n");
}

/*
   function name : count_cd
description   : count total nodes
 */
int32_t count_cd(struct dnode* head) {

	if (head == NULL) {
		return 0;
	}

	int32_t count = 0;

	struct dnode* temp = head;

	do {
		count++;
		temp = temp->next;
	} while (temp != head);

	return count;
}

/*
   function name : delete_cd
description   : delete node by data
 */
void delete_cd(struct dnode** head, int32_t data) {

	if (*head == NULL) {
		printf("list is empty\n");
		return;
	}

	struct dnode* temp = *head;

	do {

		if (temp->data == data) {

			if (temp->next == temp) {
				free(temp);
				*head = NULL;
				return;
			}

			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;

			if (temp == *head) {
				*head = temp->next;
			}

			free(temp);
			return;
		}

		temp = temp->next;

	} while (temp != *head);

	printf("data not found\n");
}

int main_cd() {

	struct dnode* head = NULL;

	insertatbegining_cd(&head, 10);
	insertatbegining_cd(&head, 20);

	append_cd(&head, 30);
	append_cd(&head, 40);

	display_cd(head);

	printf("total nodes = %d\n", count_cd(head));
	printf("after deleting.......\n");
	delete_cd(&head, 20);

	display_cd(head);

	return 0;
}
