#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "/home/akash/Take_Away_Data_Structure/include/header.h"

/*function name : createnode();
description : initilize matrix with default value.
author : akash gupta
created at: 26 may
 */
struct node* createnode(int32_t row, int32_t column, double value){
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	if ( newnode == NULL){
		printf("memory is not init\n");
		return NULL;
	}
	newnode->row = row;
	newnode->column = column;
	newnode->value = value;
	newnode->rowptr = NULL;
	newnode->columnptr = NULL;

	return newnode;

}

/*function name : creatematrix();
description : initialize matrix with default value.
author : akash gupta
created at: 26 may
 */
struct matrix* creatematrix (int32_t rows , int32_t columns){
	struct matrix* newmatrix = (struct matrix*)malloc(sizeof(struct matrix));
	if ( newmatrix == NULL){	
		printf("not init memory for it\n");
		return NULL;
	}

	newmatrix->rows = rows;
	newmatrix->columns = columns;

	newmatrix->rowlist = (struct node**)malloc(sizeof(struct node*)*rows);
	newmatrix->columnlist = (struct node**)malloc(sizeof(struct node*)*columns);

	for(int i = 0; i < rows || i < columns; i++){
		newmatrix->rowlist[i] = NULL;
		newmatrix->columnlist[i] = NULL;
	}


	return newmatrix;
}
/*function name : is_occupied();
description : check if the current place has any data or not .
author : akash gupta
created at: 01 june
 */
bool is_occupied(struct matrix *matrix, int row, int column)
{
	struct node *temp = matrix->rowlist[row];

	while (temp != NULL) {
		if (temp->row == row && temp->column == column)
			return true;

		temp = temp->rowptr;
	}

	return false;
}
/*function name : insertatbegin();
description : head is rowlit[i] or columnlist[i] which pointer the head of linked list.
author : akash gupta
created at: 27 may
 */
void insertatbegin(struct matrix* matrix, int32_t row,int32_t column,double value){
	if (is_occupied(matrix, row, column)){
		printf("position is ocuupied!\n");
		return;
	}
	struct node* newnode = createnode(row, column, value);

	newnode->rowptr = matrix->rowlist[row];
	matrix->rowlist[row] = newnode;

	newnode->columnptr = matrix->columnlist[column];
	matrix->columnlist[column] = newnode;
}

/*function name : dupvalue();
description : return 1 if value is already exist.
author : akash gupta
created at: 28 may
 */
bool dupvalue(struct matrix* matrix, double value){
	for ( int i =0; i < matrix-> rows ; i++){
		struct node * newnode = matrix->rowlist[i];
		while(newnode != NULL){
			if ( newnode->value == value ){
				return true;
			}
			newnode = newnode->rowptr;
		}
	}	
	return false;
}

/*function name : display();
description :  display linked list on screen .
author : akash gupta
created at: 28 may
 */
void display(struct matrix* m){
	for(int i = 0; i < m->rows; i++){
		struct node* temp = m->rowlist[i];

		printf("Row %d : ", i);

		while(temp != NULL){
			printf("(%d,%d,%0.1lf) -> ",temp->row,temp->column,temp->value);
			temp = temp->rowptr;
		}
		printf("NULL\n");
	}
}
/*function name : resize();
description : resize the matrix with double of its value and copy the old data into newmatrix.
author : akash gupta
created at: 01 june
 */

int32_t resize(struct matrix **mat){
	struct matrix *oldmat = *mat;
	struct matrix *newmat = creatematrix(oldmat->rows * 2, oldmat->columns * 2);

	if (newmat == NULL){
		return 1;	
	}

	for (int i = 0; i < oldmat->rows; i++){
		newmat->rowlist[i] = oldmat->rowlist[i];
	}

	for ( int i =0; i< oldmat->columns; i++){
		newmat->columnlist[i] = oldmat->columnlist[i];
	}
	free(oldmat->rowlist);
	free(oldmat->columnlist);
	free(oldmat);

	*mat = newmat;
	return 0;

}

/*function name : transpose();
description : transpose the matrix.
author : akash gupta
created at: 01 june
 */
struct matrix* transpose(struct matrix **mat){
	struct matrix *oldmat = *mat;

	struct matrix *newmat =creatematrix(oldmat->columns,oldmat->rows);

	if (newmat == NULL)
		return 1;

	for (int i = 0; i < oldmat->rows; i++){
		struct node *temp = oldmat->rowlist[i];

		while (temp != NULL){
			insertatbegin(newmat,temp->column, temp->row, temp->value);

			temp = temp->rowptr;
		}
	}

	free(oldmat->rowlist);
	free(oldmat->columnlist);
	free(oldmat);

	return newmat;
}
