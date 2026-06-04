#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;
/*
 * Function Name : craeteNode()
 * Description   : initialize memory for newnode
 * Author        : Akash Gupta
 * created at    : 26 may
 */
struct Node* createNode_c(int data) {

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	if (newNode == NULL) {
		printf("Memory allocation failed\n");
		exit(1);
	}

	newNode->data = data;
	newNode->next = NULL;

	return newNode;
}
/*
 * Function Name : insertAtBeginning()
 * Description   : inserting a newnode at begining
 * Author        : Akash Gupta
 * created at    : 26 may
 */
void insertAtBeginning(struct Node** head, int data) {

	struct Node* newNode = createNode_c(data);

	/* If list is empty */
	if (*head == NULL) {
		newNode->next = newNode;
		*head = newNode;
		return;
	}

	struct Node* temp = *head;

	/* Move to last node */
	while (temp->next != *head) {
		temp = temp->next;
	}

	newNode->next = *head;
	temp->next = newNode;
	*head = newNode;
}
/*
 * Function Name : insertAtEnd()
 * Description   : insert a newnode at the end
 * Author        : Akash Gupta
 * created at    : 26 may
 */
void insertAtEnd(struct Node** head, int data) {

	struct Node* newNode = createNode_c(data);

	/* If list is empty */
	if (*head == NULL) {
		newNode->next = newNode;
		*head = newNode;
		return;
	}

	struct Node* temp = *head;

	/* Move to last node */
	while (temp->next != *head) {
		temp = temp->next;
	}

	temp->next = newNode;
	newNode->next = *head;
}
/*
 * Function Name : deleteNode_c()
 * Description   : delete node from the linked list
 * Author        : Akash Gupta
 * created at    : 26 may
 */
void deleteNode_c(struct Node** head, int data) {

	if (*head == NULL) {
		return;
	}

	struct Node *current = *head;
	struct Node *prev = NULL;

	/* Delete head node */
	if (current->data == data) {

		/* Only one node */
		if (current->next == *head) {
			free(current);
			*head = NULL;
			return;
		}

		struct Node* last = *head;

		while (last->next != *head) {
			last = last->next;
		}

		*head = current->next;
		last->next = *head;

		free(current);
		return;
	}

	prev = current;
	current = current->next;

	while (current != *head) {

		if (current->data == data) {
			prev->next = current->next;
			free(current);
			return;
		}

		prev = current;
		current = current->next;
	}

	printf("Node not found\n");
}
/*
 * Function Name : display_c()
 * Description   : displaying the linked list
 * Author        : Akash Gupta
 * created at    : 26 may
 */
void display_c(struct Node* head) {

	struct Node* current = head;

	if (head == NULL) {
		printf("List is empty\n");
		return;
	}

	do {
		printf("%d ", current->data);
		current = current->next;
	} while (current != head);

	printf("\n");
}
