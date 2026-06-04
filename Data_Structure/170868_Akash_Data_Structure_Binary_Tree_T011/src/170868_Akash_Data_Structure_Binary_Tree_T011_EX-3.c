#include <stdio.h>
#include <stdint.h>

#include "/home/akash/Data_Structure/170868_Akash_Data_Structure_Binary_Tree_T011/include/header.h"
/*
 * Function Name : binary_search_linked_list();
 * Description   : search a element from the tree which is implemented by the linked list.
 * Author        : Akash Gupta
 */
void binary_search_linked_list() {
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

	int key;
	printf("\nenter the key for searching value in a tree\n");
	scanf("%d", &key);
	struct node* result = search(root, key);

	if(result != NULL)
		printf("Element %d found\n", key);
	else
		printf("Element not found\n");
}
/*
 * Function Name : binary_search_array();
 * Description   : search a element from the tree which is implemented by the array.
 * Author        : Akash Gupta
 */
void binary_search_array() {

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

	printf("enter the key for search in a tree\n");
	int key;
	scanf("%d",&key);
	int result = search_array(key);

	if(result != -1)
	{
		printf("\nElement %d found at index %d\n", key, result);
	}
	else
	{
		printf("\nElement not found\n");
	}
}

/*
 * Function Name : tree_test()
 * Description   : taking input from the user for the tree.
 * Author        : Akash Gupta
 */

int32_t delete_tree() {
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

        printf("Inorder Traversal: ");
        inorder(root);


        printf("\nenter the data to delete\n");
        int32_t data;
        scanf("%d", &data);
        deleteNode(root , data);

        printf("Inorder Traversal: ");
        inorder(root);
        return 0;
}
