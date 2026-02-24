/*
 * Descriptions: function is about a C program to count the number of characters entered by the user and display the input text and character count.
 * Author : Akash Gupta
 * Created at : 10-02-2026
 * Modified at : 10-02-2026
 */

#include <stdio.h>

#define MAXLINE 1000

int longest_line()
{
    char line[MAXLINE];
    char longest[MAXLINE];
    int c, i = 0;
    int len = 0, max = 0;

    while ((c = getchar()) != EOF) {

        line[i] = c;
        i++;
        len++;

        if (c == '\n') {

            line[i] = '\0';

            if (len > max) {
                max = len;

                for (int j = 0; j <= i; j++)
                    longest[j] = line[j];
            }
            i = 0;
            len = 0;
        }
    }

    if (max > 0) {
        printf("Longest line:\n%s", longest);
        printf("Length = %d\n", max);
    }

    return 0;
}

