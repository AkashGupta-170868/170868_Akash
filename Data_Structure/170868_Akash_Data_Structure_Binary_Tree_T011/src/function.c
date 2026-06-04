#include <stdio.h>
#include <stdlib.h>

/*
   structure name : node
description    : represents each tree node
author : akash gupta
 */
struct node {
	int data;
	struct node *left;
	struct node *right;
};

/*
   function name : createNode()
description   : creates a new tree node
author : akash gupta
 */
struct node* createNode(int value) {
	struct node* newNode = (struct node*)malloc(sizeof(struct node));

	if(newNode == NULL) {
		printf("Memory allocation failed\n");
		exit(1);
	}

	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

/*
   function name : insert()
description   : inserts node in binary search tree
author : akash gupta
 */
struct node* insert(struct node* root, int value) {
	if(root == NULL)
		return createNode(value);

	if(value < root->data)
		root->left = insert(root->left, value);
	else
		root->right = insert(root->right, value);

	return root;
}

/*
   function name : inorder()
description   : displays tree in inorder traversal.
author : akash gupta
 */
void inorder(struct node* root) {
	if(root != NULL) {
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

/*
   function name : preorder()
description   : displays tree in preorder traversal.
author : akash gupta
 */
void preorder(struct node* root) {
	if(root != NULL) {
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

/*
   function name : postorder()
description   : displays tree in postorder traversal.
author : akash gupta
 */
void postorder(struct node* root) {
	if(root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
	}
}
/*
 * function name : search()
 * description   : searches element in BST
 * author        : Akash Gupta
 */
struct node* search(struct node* root, int key)
{
	if(root == NULL || root->data == key)
		return root;

	if(key < root->data)
		return search(root->left, key);

	return search(root->right, key);
}


/*
 * Function Name : deleteNode()
 * Description   : Delete a node from Binary Search Tree.
 * Author        : Akash Gupta
 */

struct node* deleteNode(struct node* root, int target)
{
	struct node *temp;

	/* Tree empty */
	if (root == NULL) {
		return NULL;
	}

	/* Search node */
	if (target < root->data) {

		root->left = deleteNode(root->left, target);

	} else if (target > root->data) {

		root->right = deleteNode(root->right, target);

	} else {
		/* Case 1 : No child */
		if (root->left == NULL && root->right == NULL) {

			free(root);
			return NULL;
		}

		/* Case 2 : One child */
		else if (root->left == NULL) {

			temp = root->right;
			free(root);
			return temp;
		}

		else if (root->right == NULL) {

			temp = root->left;
			free(root);
			return temp;
		}

		/* Case 3 : Two children */
		else {

			temp = root->right;

			/* Find smallest node in right subtree */
			while (temp->left != NULL) {
				temp = temp->left;
			}

			/* Replace value */
			root->data = temp->data;

			/* Delete duplicate node */
			root->right = deleteNode(root->right, temp->data);
		}
	}

	return root;
}		


/*---------------------------------------------------- tree using array -----------------------------------------------------*/

#include <stdio.h>
#include <stdint.h>

#define SIZE 100

int32_t tree[SIZE];

/*
 * Function Name : initializeTree()
 * Description   : Initialize all positions with -1
 * Author        : Akash Gupta
 */
void initializeTree(void)
{
	for(int32_t i = 0; i < SIZE; i++)
	{
		tree[i] = -1;
	}
}
/*
 * Function Name : insert_array()
 * Description   : Insert element into tree.
 * Author        : Akash Gupta
 */
void insert_array(int16_t value) {
	int16_t idx = 0;

	while (idx < SIZE) {
		if (tree[idx] == -1) {
			tree[idx] = value;
			return;
		}

		if (value < tree[idx])
			idx = 2*idx + 1;
		else
			idx = 2*idx + 2;
	}

	printf("Tree overflow\n");
}
/*
 * Function Name : display()
 * Description   : Display tree array
 * Author        : Akash Gupta
 */
void display() {
	for (int16_t idx = 0; idx < SIZE; idx++) {
		if (tree[idx] != -1)
			printf("Index %d: %d\n", idx, tree[idx]);
	}
}

/*
 * Function Name : inorder_array()
 * Description   : Display tree array
 * Author        : Akash Gupta
 */
void inorder_array(int16_t idx) {
	if (idx >= SIZE || tree[idx] == -1)
		return;

	inorder_array(2*idx + 1);
	printf("%d ", tree[idx]);
	inorder_array(2*idx + 2);
}
/*
 * Function Name : preorder_array()
 * Description   : Display tree array
 * Author        : Akash Gupta
 */
void preorder_array(int16_t idx) {
	if (idx >= SIZE || tree[idx] == -1)
		return;

	printf("%d ", tree[idx]);
	preorder_array(2*idx + 1);
	preorder_array(2*idx + 2);
}
/*
 * Function Name : postorder_array()
 * Description   : Display tree array
 * Author        : Akash Gupta
 */
void postorder_array(int16_t idx) {
	if (idx >= SIZE || tree[idx] == -1)
		return;

	postorder_array(2*idx + 1);
	postorder_array(2*idx + 2);
	printf("%d ", tree[idx]);
}

/*
 * Function Name : search_array()
 * Description   : Search element in BST array
 * Author        : Akash Gupta
 */
int search_array(int key)
{	int idx = 0;

	while(idx < SIZE && tree[idx] != -1)
	{
		if(tree[idx] == key)
		{
			return idx;
		}

		if(key < tree[idx])
		{
			idx = 2 * idx + 1;
		}
		else
		{
			idx = 2 * idx + 2;
		}
	}

	return -1;
}

