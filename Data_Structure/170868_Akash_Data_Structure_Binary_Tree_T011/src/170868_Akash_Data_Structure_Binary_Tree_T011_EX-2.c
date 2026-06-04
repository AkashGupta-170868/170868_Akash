#include <stdio.h>
#include <stdint.h>

#include "/home/akash/Data_Structure/170868_Akash_Data_Structure_Binary_Tree_T011/include/header.h"
/*
 * Function Name : traversal_linked_list()
 * Description   : taking input from the user and inserted into a tree after that traversing on tree in all three manner.(implemented by linked list).
 * Author        : Akash Gupta
 */
int32_t traversal_linked_list() {
	struct node* root = NULL;
	printf(" enter the number of node\n");
	int32_t value;
	scanf("%d", &value);
	for ( int32_t i =0 ; i < value ; i++){
		printf("enter data\n");
		int32_t data;
		scanf("%d",&data);
		root = insert(root, data);
	}

	printf("Inorder Traversal:\n ");
	inorder(root);

	printf("\nPreorder Traversal:\n ");
	preorder(root);

	printf("\npostorder Traversal: \n");
	postorder(root);

	return 0;
}
/*
 * Function Name : traversal_array()
 * Description   : taking input from the user and inserted into a tree after that traversing on tree in all three order(iplemented by array).
 * Author        : Akash Gupta
 */
int traversal_array(void)
{
	int16_t number, value;

	initializeTree();

	printf("Enter number of nodes: ");
	scanf("%hd", &number);

	for (int16_t idx = 0; idx < number; idx++) {
		printf("Enter value: ");
		scanf("%hd", &value);

		insert_array(value);
	}

	printf("\nBST Inorder Traversal using array implementation of tree:\n");
	inorder_array(0);
	printf("\n");

	printf("\nBST preorder Traversal using array implementation of tree:\n");
	preorder_array(0);
	printf("\n");

	printf("\nBST postorder Traversal using array implementation of tree:\n");
	postorder_array(0);
	printf("\n");
	display();
	return 0;
}
