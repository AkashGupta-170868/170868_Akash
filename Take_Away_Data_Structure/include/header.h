#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


struct node {
	int32_t row;
	int32_t column;

	double value;

	struct node* rowptr;
	struct node* columnptr;
};


struct matrix {

	struct node** rowlist;
	struct node** columnlist;

	int32_t rows;
	int32_t columns;
};


struct node* createnode(int32_t row, int32_t column,double value);

struct matrix* creatematrix(int32_t rows, int32_t columns);

void initmat();
int32_t switch1(); 
int32_t resize(struct matrix **mat);
struct matrix* transpose(struct matrix **mat);


struct questionNode* buildtree(FILE *fp);
void playGame(struct questionNode *root);
void writetree(FILE *fp, struct questionNode *root);
int game(void);
#endif
