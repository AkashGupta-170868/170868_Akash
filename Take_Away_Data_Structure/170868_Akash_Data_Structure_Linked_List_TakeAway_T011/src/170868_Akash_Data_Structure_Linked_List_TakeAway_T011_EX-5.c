#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "header.h"

void  insertatbegin(struct matrix* , int row, int column , double value);
struct matrix* insert_mat();
/*
function name : transpose_mat()
descirption : transpose the matrix 
author : akash gupta
created at : 01 june
*/
void transpose_mat() {
	struct matrix* mat = insert_mat();
	printf("before transpose\n");
	display(mat);	

	printf("after transpose\n");
	struct matrix* newmat = transpose(&mat);
	display(newmat);

}

