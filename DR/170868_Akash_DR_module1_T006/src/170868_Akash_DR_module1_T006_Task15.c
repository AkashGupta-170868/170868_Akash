/*
 * Descriptions:this function is about that Rewrites the temperature conversion program to use a function for conversion
 * Author : Akash Gupta
 * Created at : 10-02-2026
 * Modified at : 10-02-2026
 */

#include <stdio.h>


void  f2c_function()
 {
	 
	 float fahr, celsius;
	 int status;
	 char choice = 'y' ;
	 do {
	printf("enter the value of fahrenheit:");
	status = scanf("%f",&fahr);

	// handle invalid input
	if (status != 1)
        {
            printf("Please enter valid\n");

            while (getchar() != '\n');
            continue;
        }

           printf("fahr\t celsius\n");

         celsius = (5.0/9.0) * (fahr-32.0);
         printf("%3.0f\t %6.1f\n", fahr, celsius);


	 printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice);
	 } while ( choice == 'y' || choice == 'Y');
 }
