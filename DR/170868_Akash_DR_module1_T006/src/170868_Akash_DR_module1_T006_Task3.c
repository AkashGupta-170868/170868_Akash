/*
 * Descriptions:this function is about that converts farenhite to celcius and print all the value
 * Author : Akash Gupta
 * Created at : 09-02-2026
 * Modified at : 10-02-2026
 */


#include <stdio.h>

void  f2c()
 {
	 float fahr, celsius;
 	float lower, upper, step;
	 lower = 0; 
 	upper = 300; 
	 step = 20; 
	 fahr = lower;

	   printf("fahr\t celsius\n");

 	while (fahr <= upper) {
	 celsius = (5.0/9.0) * (fahr-32.0);
	 printf("%3.0f\t %6.1f\n", fahr, celsius);
	 fahr = fahr + step;
 	}
 }
