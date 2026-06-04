/*
 * Description   : rite a program to traverse a binary tree using preorder traversal method without using recursion.
 * Author        : Akash Gupta
 */
#include <stdio.h>
#include <stdint.h>

#include "/home/akash/Data_Structure/170868_Akash_Data_Structure_Binary_Tree_T011/include/header.h"
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
struct node* stack[SIZE];
static int32_t top = -1;

/*
 * Function Name : push()
 * Description   : Push node into stack.
 * Author        : Akash Gupta
 */
static void push(struct node *temp)
{
	stack[++top] = temp;
}

/*
 * Function Name : pop()
 * Description   : Remove node from stack.
 * Author        : Akash Gupta
 */
static struct node* pop(void)
{
	return stack[top--];
}

/*
 * Function Name : isEmpty()
 * Description   : Check stack empty or not.
 * Author        : Akash Gupta
 */
static int32_t isEmpty(void)
{
	return (top == -1);
}

/*
 * Function Name : preorder_stack()
 * Description   : Preorder traversal without recursion.
 *                  Root -> Left -> Right
 * Author        : Akash Gupta
 */
void preorder_stack(struct node *root)
{
	struct node *temp;

	if (root == NULL) {
		return;
	}

	push(root);

	while (!isEmpty()) {

		temp = pop();

		printf("%d ", temp->data);

		/* Push right first */
		if (temp->right != NULL) {
			push(temp->right);
		}

		/* Push left second */
		if (temp->left != NULL) {
			push(temp->left);
		}
	}
}
/*
 * Function Name : postorder_stack()
 * Description   : Postorder traversal without recursion.
 *                  Left -> Right -> root
 * Author        : Akash Gupta
 */
void postorder_stack(struct node *root)
{
	struct node *temp;
	struct node *str[100];

	int index = 0;

	if (root == NULL) {
		return;
	}

	push(root);

	while (!isEmpty()) {

		temp = pop();

		str[index++] = temp;

		if (temp->left != NULL) {
			push(temp->left);
		}

		if (temp->right != NULL) {
			push(temp->right);
		}
	}

	for (int i = index - 1; i >= 0; i--) {

		printf("%d ", str[i]->data);
	}
}
/*
 * Function Name : postorder_stack()
 * Description   : Postorder traversal without recursion and test it.
 *                    Left -> Right -> root
 * Author        : Akash Gupta
 */
void postorder_without_recursion() {
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


	printf("postorder Traversal: ");
	postorder_stack(root);

}
/*
 * Function Name : preorder_stack()
 * Description   : Preorder traversal without recursion and test it.
 *                  root -> Left -> Right
 * Author        : Akash Gupta
 */
void preorder_without_recursion() {
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


	printf("preorder Traversal: ");
	preorder_stack(root);

}
