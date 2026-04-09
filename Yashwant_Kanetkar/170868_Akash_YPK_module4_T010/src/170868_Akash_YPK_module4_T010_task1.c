/* Program to find determinant value of nxn matrix using recursion and calloc                                                                                                  
* Author: Akash Gupta
* Created: 25 March 2026
*/     
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
/* Function name: displayMatrix()                                                                                                   
 * Function Description: This function is used to display matrix of nxn elements
  * Author: Akash Gupta
  * Created: 25 March, 2026
  */
void displayMatrix(float **matrix, int8_t size) {
    printf("\nMatrix (%dx%d):\n", size, size);

    for (int8_t row = 0; row < size; row++) {
        for (int8_t col = 0; col < size; col++) {
            printf("%.2f  ", matrix[row][col]);
        }
        printf("\n");
    }
}

/* Function name:determinanat(float **,int)                                                                                         
 *  Function Description: This function is used to calculate determinant of nxn matrix using recursion and calloc.
  * Author: Akash Gupta
  * Created: 25 March, 2026
  */
float determinant(float **matrix, int8_t size) {
    float detValue = 0;
    int8_t sign = 1;

    if (size == 1)
        return matrix[0][0];

    if (size == 2)
        return (matrix[0][0] * matrix[1][1]) -
               (matrix[0][1] * matrix[1][0]);

    float **subMatrix = (float **)calloc(size, sizeof(float *));
    for (int8_t row = 0; row < size; row++)
        subMatrix[row] = (float *)calloc(size, sizeof(float));

    for (int8_t colToRemove = 0; colToRemove < size; colToRemove++) {

        int8_t subRow = 0;

        for (int8_t row = 1; row < size; row++) {
            int8_t subCol = 0;

            for (int8_t col = 0; col < size; col++) {
                if (col == colToRemove)
                    continue;

                subMatrix[subRow][subCol] = matrix[row][col];
                subCol++;
            }
            subRow++;
        }

        detValue += sign * matrix[0][colToRemove] *
                    determinant(subMatrix, size - 1);

        sign = -sign;
    }

    for (int8_t row = 0; row < size; row++)
        free(subMatrix[row]);
    free(subMatrix);

    return detValue;
}

/* Function name: displayDeterminant()                                                                                              
 * Function Description: This function is used to display determinant function.
  * Author: Akash Gupta
  * Created: 25 March, 2026
  */
void displayDeterminant() {
    int8_t size;

    printf("Enter size of matrix (n x n): ");
    scanf("%hhd", &size);

    float **matrix = (float **)calloc(size, sizeof(float *));
    for (int8_t row = 0; row < size; row++)
        matrix[row] = (float *)calloc(size, sizeof(float));

    printf("Enter matrix elements:\n");
    for (int8_t row = 0; row < size; row++) {
        for (int8_t col = 0; col < size; col++) {
            scanf("%f", &matrix[row][col]);
        }
    }

    displayMatrix(matrix, size);

    float det = determinant(matrix, size);
    printf("\nDeterminant = %.2f\n", det);

    for (int8_t row = 0; row < size; row++)
        free(matrix[row]);
    free(matrix);
}

