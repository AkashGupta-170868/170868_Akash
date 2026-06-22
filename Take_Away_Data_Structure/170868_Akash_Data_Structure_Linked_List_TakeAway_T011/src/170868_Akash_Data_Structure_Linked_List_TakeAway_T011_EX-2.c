#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "header.h"
void  insertatbegin(struct matrix* , int row, int column , double value);
bool dupvalue(struct matrix* matrix, double value);

/*function name : insert_mat();
description : inserting element by taking input from user.
author : akash gupta
created at: 26 may
 */

struct matrix* insert_mat(){
	struct matrix* mat = NULL;
	int32_t rows, columns;
	int32_t row, column;
	int32_t elements;
	double data;

	printf("Enter number of rows: ");
	scanf("%d", &rows);

	printf("Enter number of columns: ");
	scanf("%d", &columns);

	mat = creatematrix(rows, columns);

	printf("Enter number of non-zero elements: ");
	scanf("%d", &elements);

	for (int32_t i = 0; i < elements; i++) {

		printf("\nElement %d\n", i + 1);

		printf("Enter row index: ");
		scanf("%d", &row);

		printf("Enter column index: ");
		scanf("%d", &column);

		printf("Enter value: ");
		scanf("%lf", &data);

		insertatbegin(mat, row, column, data);
	}

	display(mat);
	return mat;
}
