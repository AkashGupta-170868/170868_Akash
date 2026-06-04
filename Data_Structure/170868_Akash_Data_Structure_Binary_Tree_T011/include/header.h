#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define SIZE 100

/*----------------------------------------------------
  TREE USING LINKED LIST
  -----------------------------------------------------*/

/*
   structure name : node
description    : represents each tree node
 */
struct node {
	int data;
	struct node *left;
	struct node *right;
};

/*
   function name : createNode()
description   : creates a new tree node
author        : Akash Gupta
 */
struct node* createNode(int value);

/*
   function name : insert()
description   : inserts node in binary search tree
author        : Akash Gupta
 */
struct node* insert(struct node* root, int value);

/*
   function name : inorder()
description   : displays tree in inorder traversal
author        : Akash Gupta
 */
void inorder(struct node* root);

/*
   function name : preorder()
description   : displays tree in preorder traversal
author        : Akash Gupta
 */
void preorder(struct node* root);

/*
   function name : postorder()
description   : displays tree in postorder traversal
author        : Akash Gupta
 */
void postorder(struct node* root);

struct node* deleteNode(struct node* root , int target);
/*----------------------------------------------------
  TREE USING ARRAY
  -----------------------------------------------------*/

extern int32_t tree[SIZE];

/*
 * Function Name : initializeTree()
 * Description   : Initialize all positions with -1
 * Author        : Akash Gupta
 */
void initializeTree(void);

/*
 * Function Name : setRoot()
 * Description   : Insert root node
 * Author        : Akash Gupta
 */
void setRoot(int32_t value);

/*
 * Function Name : insert_array()
 * Description   : Insert node in array BST
 * Author        : Akash Gupta
 */
void insert_array(int16_t value);

/*
 * Function Name : display()
 * Description   : Display tree array
 * Author        : Akash Gupta
 */
void display(void);

/*
 * Function Name : inorder_array()
 * Description   : Inorder traversal of array tree
 * Author        : Akash Gupta
 */
void inorder_array(int16_t idx);

/*
 * Function Name : preorder_array()
 * Description   : Preorder traversal of array tree
 * Author        : Akash Gupta
 */
void preorder_array(int16_t idx);

/*
 * Function Name : postorder_array()
 * Description   : Postorder traversal of array tree
 * Author        : Akash Gupta
 */
void postorder_array(int16_t idx);

#endif
