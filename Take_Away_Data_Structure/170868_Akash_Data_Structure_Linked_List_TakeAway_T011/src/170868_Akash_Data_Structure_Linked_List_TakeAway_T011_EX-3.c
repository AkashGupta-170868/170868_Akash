#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "header.h"
void  insertatbegin(struct matrix* , int row, int column , double value);
bool dupvalue(struct matrix* matrix, double value);
struct matrix* insert_mat();

/*function name : duplicate();
   description : if element already exist inside in the matrix then return true , else fase.
   author : akash gupta
   created at: 29 may
*/
void duplicate(){
	struct matrix* mat = insert_mat();
	int num;
	printf("enter the number to check weather it is inside or not .");
	scanf("%d",&num);
	printf("%d",dupvalue(mat,num));
}
