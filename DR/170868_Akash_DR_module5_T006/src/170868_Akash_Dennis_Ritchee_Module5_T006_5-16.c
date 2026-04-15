/*
 * Description:
 * Sort lines using Bubble Sort with options:
 *  -f : case-insensitive
 *  -d : directory order (ignore symbols)
 *  -r : reverse order
 *
 * Author : Akash Gupta
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXLINES 100
#define MAXLEN 1000

extern char *lineptr[];

extern int fold;   // -f
extern int dir ;   // -d

/* Function declarations */
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines, int reverse);
void bubble_sort(char *lineptr[], int nlines, int (*comp)(char *, char *));
int dircmp(char *s1, char *s2);

/* Check valid directory character */
int dircmp_char(int c) {
    return isalnum(c) || c == ' ';
}

/* Comparison function */
int dircmp(char *s1, char *s2)
{
    char a, b;

    while (*s1 || *s2) {

        if (dir) {
            while (*s1 && !dircmp_char(*s1)) s1++;
            while (*s2 && !dircmp_char(*s2)) s2++;
        }

        a = *s1;
        b = *s2;

        if (fold) {
            a = tolower(a);
            b = tolower(b);
        }

        if (a != b)
            return a - b;

        if (a == '\0')
            return 0;

        s1++;
        s2++;
    }

    return 0;
}

int dir_main(int argc, char *argv[])
{
    int nlines;
    int reverse = 0;

    /* Parse arguments */
    for (int i = 2; i < argc; i++) {
        if (strcmp(argv[i], "-f") == 0)
            fold = 1;
        else if (strcmp(argv[i], "-d") == 0)
            dir = 1;
        else if (strcmp(argv[i], "-r") == 0)
            reverse = 1;
    }

    printf("-d=%d -f=%d -r=%d\n\n", dir, fold, reverse);

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        bubble_sort(lineptr, nlines, dircmp);
        writelines(lineptr, nlines, reverse);
        return 0;
    } else {
        printf("Error: too many lines\n");
        return 1;
    }
}

