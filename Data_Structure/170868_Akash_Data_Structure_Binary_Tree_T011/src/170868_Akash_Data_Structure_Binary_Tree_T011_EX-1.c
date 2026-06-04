#include <stdio.h>
#include <stdint.h>

#include "/home/akash/Data_Structure/170868_Akash_Data_Structure_Binary_Tree_T011/include/header.h"
/*
 * Function Name : tree_test()
 * Description   : taking input from the user for the tree.
 * Author        : Akash Gupta
 */
int32_t tree_test() {
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

	return 0;
}
/*
 * Function Name : array_tree()
 * Description   : taking input from the user for the tree.(array implemented).
 * Author        : Akash Gupta
 */
int array_tree(void)
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

                                printf("\nBST (Array) Inorder Traversal (Sorted):\n");
                                inorder_array(0);
                                printf("\n");
                                display();
	return 0;
}
