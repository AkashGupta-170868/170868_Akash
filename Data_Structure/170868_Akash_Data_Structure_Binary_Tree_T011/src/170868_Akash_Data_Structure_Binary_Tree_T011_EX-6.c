#include <stdio.h>
#include <stdint.h>

#include "/home/akash/Data_Structure/170868_Akash_Data_Structure_Binary_Tree_T011/include/header.h"

int32_t compareTree(struct node *root1, struct node *root2)
{
	if (root1 == NULL && root2 == NULL) {
		return 1;
	}

	if (root1 == NULL || root2 == NULL) {
		return 0;
	}

	if (root1->data == root2->data &&
			compareTree(root1->left, root2->left) &&
			compareTree(root1->right, root2->right)) {

		return 1;
	}

	return 0;
}

void test_comparetree() {
	        struct node* root1 = NULL;
        printf(" enter the number of node\n");
        int32_t value1;
        scanf("%d", &value1);
        for ( int32_t i =0 ; i < value1 ; i++){
                printf("enter data\n");
                int32_t data1;
                scanf("%d",&data1);
                root1 = insert(root1, data1);
        }

	printf("Inorder Traversal:(first tree) ");
        inorder(root1);

        struct node* root2 = NULL;
        printf(" enter the number of node\n");
        int32_t value2;
        scanf("%d", &value2);
        for ( int32_t i =0 ; i < value2 ; i++){
                printf("enter data\n");
                int32_t data2;
                scanf("%d",&data2);
                root2 = insert(root2, data2);
        }

	printf("Inorder Traversal: (second tree) ");
        inorder(root2);
	
	if ( compareTree(root1, root2) ){
		printf("\nboth tree are same\n");
	}else printf("\n both tree are not same\n");


}
		

	

