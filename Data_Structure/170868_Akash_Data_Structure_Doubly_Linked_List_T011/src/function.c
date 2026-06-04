#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "/home/akash/Data_Structure/170868_Akash_Data_Structure_Doubly_Linked_List_T011/include/header.h"
/*
   function name : createnode_d();
description : creating node from malloc and init the value
author      : akash gupta
created at  : 27 may
 */
struct dnode* createnode_d(int32_t data) {

	struct dnode* newnode = (struct dnode*)malloc(sizeof(struct dnode));

	if (newnode == NULL) {
		printf("memory is not init for the newnode\n");
		return NULL;
	}

	newnode->data = data;
	newnode->prev = NULL;
	newnode->next = NULL;

	return newnode;
}

/*
   function name : insertatbegining_d();
description : inserting node at the begining
author      : akash gupta
created at  : 27 may
 */
void insertatbegining_d(struct dnode** head, int32_t data) {

	struct dnode* newnode = createnode_d(data);

	if (newnode == NULL) {
		return;
	}

	if (*head == NULL) {
		*head = newnode;
		return;
	}

	newnode->next = *head;
	(*head)->prev = newnode;
	*head = newnode;
}

/*
   function name : append_d();
description : inserting node at the end of linked list.
author      : akash gupta
created at  : 27 may
 */
void append_d(struct dnode** head, int32_t data) {

	struct dnode* newnode = createnode_d(data);

	if (newnode == NULL) {
		return;
	}

	if (*head == NULL) {
		*head = newnode;
		return;
	}

	struct dnode* temp = *head;

	while (temp->next != NULL) {
		temp = temp->next;
	}

	temp->next = newnode;
	newnode->prev = temp;
}

/*
   function name : display_d();
description : display the data of doubly linked list.
author      : akash gupta
created at  : 27 may
 */
void display_d(struct dnode* head) {

	if (head == NULL) {
		printf("List is empty\n");
		return;
	}

	struct dnode* temp = head;

	printf("forward traversing\n");

	while (temp->next != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}

	printf("%d ", temp->data);

	printf("\nbackward traversing\n");

	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->prev;
	}

	printf("\n");
}

/*
   function name : count_d();
description : count the data of the doubly linked list.
author      : akash gupta
created at  : 27 may
 */
int32_t count_d(struct dnode* head) {

	struct dnode* temp = head;
	int32_t count = 0;

	while (temp != NULL) {
		count++;
		temp = temp->next;
	}

	return count;
}

/*
   function name : delete_d();
description : delete the node
author      : akash gupta
created at  : 27 may
 */
void delete_d(struct dnode** head, int32_t data) {

	if (*head == NULL) {
		printf("List is empty\n");
		return;
	}

	struct dnode* temp = *head;

	while (temp != NULL && temp->data != data) {
		temp = temp->next;
	}

	if (temp == NULL) {
		printf("Data not found\n");
		return;
	}

	if (temp == *head) {

		*head = temp->next;

		if (*head != NULL) {
			(*head)->prev = NULL;
		}

		free(temp);
		return;
	}

	/* Middle or Last node */
	temp->prev->next = temp->next;

	if (temp->next != NULL) {
		temp->next->prev = temp->prev;
	}

	free(temp);
}
