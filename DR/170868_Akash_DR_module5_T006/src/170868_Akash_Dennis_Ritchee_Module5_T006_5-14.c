/* * Descriptions: Modify the sort program to handle a -r flag, which indicates sorting in reverse * (decreasing) order. Be sure that -r works with -n. * Implemented using Bubble Sort instead of Quick Sort. * * Author : Akash Gupta * Created at : 07-04-2026 * Modified at : 07-04-2026 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAXLINES 5000

extern char *lineptr[];

int32_t readlines(char *lineptr[], int32_t maxlines);
void writelines(char *lineptr[], int32_t nlines);
void bubble_sort(void *v[], int32_t n, int32_t (*comp)(void *, void *), int32_t reverse);
int32_t numcmp(char *, char *);
void swap(void *v[], int32_t, int32_t);

/* * function name : nr() 
* Description : main driver function with -n and -r support */
int nr(int argc, char *argv[])
{
    int32_t nlines;
    int32_t numeric = 0; // -n flag
    int32_t reverse = 0; // -r flag

    argv++;
    argc--;

    // 🔹 Parse arguments
    while (--argc > 0 && (*++argv)[0] == '-') {
        char *p = *argv;
        while (*++p) {
            if (*p == 'n') numeric = 1;
            else if (*p == 'r') reverse = 1;
        }
    }

    // 🔹 Select comparison function
    int32_t (*comp)(void *, void *);
    if (numeric)
        comp = (int32_t (*)(void *, void *)) numcmp;
    else
        comp = (int32_t (*)(void *, void *)) strcmp;

    // 🔹 Read input
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {

        // 🔹 Sort using Bubble Sort
        bubble_sort((void **)lineptr, nlines, comp, reverse);

        // 🔹 Print output
        writelines(lineptr, nlines);

        return 0;
    } else {
        printf("Input too big\n");
        return 1;
    }
}
/* * function name : bubble_sort() 
* Description : Bubble sort with reverse logic */
void bubble_sort(void *v[], int32_t n, int32_t (*comp)(void *, void *), int32_t reverse)
{
    int32_t i, j;

    for (i = 0; i < n - 1; i++) {
        int32_t swapped = 0;

        for (j = 0; j < n - i - 1; j++) {
            int32_t cmp = comp(v[j], v[j + 1]);

            if (reverse) cmp = -cmp;

            if (cmp > 0) {
                swap(v, j, j + 1);
                swapped = 1;
            }
        }

        if (!swapped) break;
    }
}

/* * function name : numcmp() 
* Description : compare numbers numerically */
int32_t numcmp(char *s1, char *s2)
{
    double v1 = atof(s1);
    double v2 = atof(s2);

    if (v1 < v2) return -1;
    if (v1 > v2) return 1;
    return 0;
}

/* * function name : swap() 
* Description : swap two elements */
void swap(void *v[], int32_t i, int32_t j)
{
    void *temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* * function name : readlines() 
* Description : read input lines */
int32_t readlines(char *lineptr[], int32_t maxlines)
{
    int32_t len, nlines = 0;
    char line[1000];

    while (fgets(line, sizeof(line), stdin)) {
        len = (int32_t)strlen(line);

        if (line[len - 1] == '\n') line[len - 1] = '\0';

        lineptr[nlines] = (char *)malloc(len + 1);
        if (lineptr[nlines] == NULL) return -1;

        strcpy(lineptr[nlines], line);
        nlines++;
    }
    return nlines;
}

/* * function name : writelines() 
* Description : print output lines */
void writelines(char *lineptr[], int32_t nlines)
{
    for (int32_t i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}
