/*
 * Descriptions:Write the program tail, which prints the last n lines of its input. By default, n
is set to 10, let us say, but it can be changed by an optional argument so that
 tail -n
prints the last n lines. The program should behave rationally no matter how unreasonable the
input or the value of n. Write the program so it makes the best use of available storage; lines
should be stored as in the sorting program of Section 5.6, not in a two-dimensional array of
fixed size. 
  * Author : Akash Gupta
 * Created at : 27-03-2026
 * Modified at : 27-03-2026
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000
#define DEFAULT 10

int tail_n(int argc, char *argv[]) {
    int n = DEFAULT;

    // Get n from CLI (e.g., -3)
    if (argc == 3) {
        n = atoi(argv[2] + 1);
        if (n <= 0)
            n = DEFAULT;
    }

    char line[MAXLINE];
    char **lines = NULL;   // dynamic array of pointers
    int count = 0;

    // Read all lines
    while (fgets(line, MAXLINE, stdin) != NULL) {
        // increase size of array
        lines = realloc(lines, (count + 1) * sizeof(char *));
        
        // allocate memory for line
        lines[count] = (char *)malloc(strlen(line) + 1);
        
        // copy line
        strcpy(lines[count], line);

        count++;
    }

    // find start index
    int start = (count > n) ? count - n : 0;

    // print last n lines
    for (int i = start; i < count; i++) {
        printf("%s", lines[i]);
        free(lines[i]);   // free each line
    }

    free(lines);  // free pointer array
    return 0;
}
