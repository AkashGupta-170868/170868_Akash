/*
 * Descriptions:this function is about that Rewrites the temperature conversion program to use a function for conversion
 * Author : Akash Gupta
 * Created at : 10-02-2026
 * Modified at : 10-02-2026
 */

#include <stdio.h>
#define MAXLINE 1000

int reverse_string() {
    char line[MAXLINE];
    int i, j;
    char temp;

    printf("Enter text (Ctrl+D to stop):\n");

    while (fgets(line, MAXLINE, stdin) != NULL) {

        /* find length */
        i = 0;
        while (line[i] != '\0')
            i++;

        /* remove newline */
        if (line[i - 1] == '\n')
            i--;

        j = i - 1;   /* last character index */
        i = 0;

        /* reverse the line */
        while (i < j) {
            temp = line[i];
            line[i] = line[j];
            line[j] = temp;
            i++;
            j--;
        }

        printf("%s\n", line);
    }

    return 0;
}

