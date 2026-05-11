#include <stdio.h>
#include "src1.h"
#include "src2.h"
#include "src3.h"

int main() {
        float a , b;
        char choice ;
        do {

        printf( " enter the first number : ") ;
        scanf ( "%f", &a );

        printf( " enter the second number : " ) ;
        scanf ( "%f",&b);

        printf("addition = %.2f\n", add(a, b));
        printf("subtraction = %.2f\n", sub(a, b));
        printf("multiplication = %.2f\n", mul(a, b));
        if ( b != 0 ) {
        printf("division = %.2f\n", divide(a, b));
        } else {
                printf ( " cant divide by zero enter another number \n ") ;
        }
	greet();
        msg();
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice);
        
        }while (choice == 'y' || choice == 'Y');
}
