/*
 * Descriptions:this function is about that converts the celsius to ferenhite and print all the value
 * Author : Akash Gupta
 * Created at : 09-02-2026
 * Modified at : 10-02-2026
 */





#include <stdio.h>

void  c2f()
 {
         float fahr, celsius;
        float lower, upper, step;
         lower = 0;
        upper = 300;
         step = 20;
         celsius = lower;

           printf("celsius\t fahr\n");

        while (celsius <= upper) {
         fahr =( (9.0/5.0)*celsius)+32;
         printf("%6.1f\t %3.0f\n", celsius, fahr);
         celsius = celsius + step;
        }
 }

