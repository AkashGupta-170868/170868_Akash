/*
 * Descriptions:this function is about that prints a histogram of the lengths of words in its input.
 * Author : Akash Gupta
 * Created at : 10-02-2026
 * Modified at : 10-02-2026
 */


#include <stdio.h>
#include <stdint.h>
void makehistogram() {
 
int8_t c, len = 0;
 
    while ((c = getchar()) != EOF) {

        if (c==' ' || c=='\n' || c=='\t') {

            if (len > 0) {

                for (int8_t i = 0; i < len; i++) printf("*");

                printf("\n");

                len = 0;

            }

        } else {

            len++;
	}
    }
}
