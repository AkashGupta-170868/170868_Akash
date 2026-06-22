#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "header.h"
void  insertatbegin(struct matrix* , int row, int column , double value);
struct matrix* insert_mat();

/*function name : resize_mat();
   description : resize the matrix and copy the previous value.
   author : akash gupta
   created at: 1 june
*/

void resize_mat() {
	struct matrix* mat = insert_mat();
	printf("\nBefore Resize:\n");
	display(mat);
	if (resize(&mat) == 0){
       		printf("\nResize Successful\n");
	}else{
        	printf("\nResize Failed\n");
		return 1;
	}
	printf("\nafter Resize:\n");
        display(mat);
}	
