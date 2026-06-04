#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "/home/akash/Data_Structure/170868_Akash_Data_Structure_Binary_Tree_T011/include/header.h"

struct node* copytree( struct node* root ) {
		
	if (root == NULL){
		return ;
	}
	
	struct node* copybst = createNode(root->data);
	
	copybst = copytree(root->left);

	copybst = copytree(root->right);

	return copybst;	
}

void test_copytree() {
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

        printf("Inorder Traversal:(before copied) ");
        inorder(root);

	copytree(root);
	printf("copied tree Traversal: ");
        inorder(root);

}
