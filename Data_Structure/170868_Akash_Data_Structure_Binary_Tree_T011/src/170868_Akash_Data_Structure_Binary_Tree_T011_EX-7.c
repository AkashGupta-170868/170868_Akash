/*
description : implementation of threaded binary search tree
author      : akash gupta
created at  : 27 may
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

/*
description : structure for threaded binary tree node
 */
struct tnode {
	int32_t data;

	struct tnode* left;
	struct tnode* right;

	bool lthread;
	bool rthread;
};

/*
   function name : createnode_t
description   : create new node
 */
struct tnode* createnode_t(int32_t data) {

	struct tnode* newnode =
		(struct tnode*)malloc(sizeof(struct tnode));

	if (newnode == NULL) {
		printf("memory allocation failed\n");
		return NULL;
	}

	newnode->data = data;

	newnode->left = NULL;
	newnode->right = NULL;

	newnode->lthread = true;
	newnode->rthread = true;

	return newnode;
}

/*
   function name : insert_t
description   : insert node in threaded bst
 */
struct tnode* insert_t(struct tnode* root, int32_t data) {

	struct tnode* ptr = root;
	struct tnode* parent = NULL;

	while (ptr != NULL) {

		if (data == ptr->data) {
			printf("duplicate data not allowed\n");
			return root;
		}

		parent = ptr;

		/* move left */
		if (data < ptr->data) {

			if (ptr->lthread == false) {
				ptr = ptr->left;
			}
			else {
				break;
			}
		}
		else {

			if (ptr->rthread == false) {
				ptr = ptr->right;
			}
			else {
				break;
			}
		}
	}

	struct tnode* newnode = createnode_t(data);

	if (parent == NULL) {
		root = newnode;
		return root;
	}

	if (data < parent->data) {

		newnode->left = parent->left;
		newnode->right = parent;

		parent->lthread = false;
		parent->left = newnode;
	}

	else {

		newnode->left = parent;
		newnode->right = parent->right;

		parent->rthread = false;
		parent->right = newnode;
	}

	return root;
}
/*
   function name : leftmost
description   : find leftmost node
 */
struct tnode* leftmost(struct tnode* node) {

	if (node == NULL) {
		return NULL;
	}

	while (node->lthread == false) {
		node = node->left;
	}

	return node;
}

/*
   function name : inorder_t
description   : inorder traversal using threads
 */
void inorder_t(struct tnode* root) {

	if (root == NULL) {
		printf("tree is empty\n");
		return;
	}

	struct tnode* temp = leftmost(root);

	while (temp != NULL) {

		printf("%d ", temp->data);

		/* move using thread */
		if (temp->rthread == true) {
			temp = temp->right;
		}

		/* go to leftmost node of right subtree */
		else {
			temp = leftmost(temp->right);
		}
	}
}

int main_t() {

	struct tnode* root = NULL;

	root = insert_t(root, 50);
	root = insert_t(root, 30);
	root = insert_t(root, 70);
	root = insert_t(root, 20);
	root = insert_t(root, 40);
	root = insert_t(root, 60);
	root = insert_t(root, 80);

	printf("inorder traversal\n");

	inorder_t(root);

	return 0;
}
