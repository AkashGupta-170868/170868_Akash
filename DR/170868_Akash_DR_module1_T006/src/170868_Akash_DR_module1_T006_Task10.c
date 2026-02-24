/*
 * Descriptions:this function is about that if the escape charcter comes in the input then just replace by its notation like \t \b \\
 * Author : Akash Gupta
 * Created at : 09-02-2026
 * Modified at : 10-02-2026
 */



#include <stdio.h>

void add_escape() {
    int c; 
    while ((c = getchar()) != EOF) {
         if (c == '\b') {
            putchar('\\');
            putchar('b');
        }       
	else if (c == '\t') {
            putchar('\\');
            putchar('t');
        }
        else if (c == '\\') {
            putchar('\\');
            putchar('\\');
        }
       	else {
            putchar(c); 
        }
    }
}
