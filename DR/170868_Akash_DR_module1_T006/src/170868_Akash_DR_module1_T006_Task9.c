/*
 * Descriptions:this function is about that if the multiple blank spaces comes in the input then its replace by only single space
 * Author : Akash Gupta
 * Created at : 09-02-2026
 * Modified at : 10-02-2026
 */

#include <stdio.h>

int print_singal_space()
{
    int c;
    int in_ws = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t') {
            ++in_ws;
        }else {
            if (in_ws > 0) {
                printf(" ");
                in_ws = 0;
             
            }
            putchar(c);
    }}

    return 0;
}

