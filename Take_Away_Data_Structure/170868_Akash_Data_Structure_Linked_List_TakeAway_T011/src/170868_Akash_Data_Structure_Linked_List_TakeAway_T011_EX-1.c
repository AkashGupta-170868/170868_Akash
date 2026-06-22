#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "header.h"
/* function name : initmt();
   description : initialize memory for a matrix and display message on screen.
   author : akash gupta
   created at: 26 may
*/
void initmat(){
	int32_t rows, columns;

	printf("Enter the number of rows\n");
	scanf("%d", &rows);

	printf("Enter the number of columns\n");
	scanf("%d", &columns);

	struct matrix* initmatrix = creatematrix(rows, columns);

	if(initmatrix != NULL){
		printf("Successfully initialized matrix\n");
		
	}else{
		printf("Memory allocation failed\n");
	}
}
