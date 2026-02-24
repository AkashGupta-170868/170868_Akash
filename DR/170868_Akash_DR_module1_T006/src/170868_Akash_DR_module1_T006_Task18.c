#include <stdio.h>
#define MAXLINE 1000

int remove_space()
{
    char line[MAXLINE];
    int c, i = 0;
    int j;

    printf("Enter the text (Ctrl+D to stop):\n");

    while ((c = getchar()) != EOF) {

        if (c != '\n') {
            line[i++] = c;
        } 
        else {
            /* Remove trailing spaces and tabs */
            j = i - 1;
            while (j >= 0 && (line[j] == ' ' || line[j] == '\t')) {
                j--;
            }

            /* Print only if line is not blank */
            if (j >= 0) {
                line[j + 1] = '\0';
                printf("%s\n", line);
            }

            i = 0;   // Reset for next line
        }
    }

    return 0;
}

