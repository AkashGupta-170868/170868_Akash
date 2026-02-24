/*
 * Descriptions:this function is about that prints all input lines which are longer than 80 characters.
 * Author : Akash Gupta
 * Created at : 10-02-2026
 * Modified at : 10-02-2026
 */

#include <stdio.h>
#define MAXLINE 1000

void longest_gt_80()
{
    char line[MAXLINE];
    int c, i = 0;
    int len = 0;
printf("enter the line\n");
    while ((c = getchar()) != EOF) {

        line[i++] = c;
        len++;

        if (c == '\n') {
            line[i] = '\0';

            if (len > 80) {
                printf("%s", line);
	    }
	}

            i = 0;
            len = 0;
        }
    if( len < 80){
 printf("the line is not too long");
}
}

