/*
 * Description:
 * Modify the sort program to support:
 *  -f : case-insensitive sorting
 *  -r : reverse order
 * Implemented using Bubble Sort
 *
 * Author : Akash Gupta
 * Created at : 07-04-2026
 * Modified at : 07-04-2026
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdint.h>  

#define MAXLINES 100
#define MAXLEN 1000

extern char *lineptr[];

int16_t readlines(char *lineptr[], int16_t maxlines);
void writelines(char *lineptr[], int16_t nlines);

void bubble_sort(void *v[], int16_t n,
		int16_t (*comp)(void *, void *), int16_t reverse);

int16_t strcmp1(char *s1, char *s2);
int16_t strcmp_fold(char *s1, char *s2);
void swap(void *v[], int8_t i, int8_t j);

/*
 * function name : fold()
 * Description : main function handling -f and -r options
 */
int32_t fold_main(int8_t argc, char *argv[])
{
	int16_t nlines;
	int16_t fold_flag = 0;
	int16_t reverse_flag = 0;
	for (int16_t i = 2; i < argc; i++) {
		if (strcmp(argv[i], "-f") == 0)
			fold_flag = 1;
		else if (strcmp(argv[i], "-r") == 0)
			reverse_flag = 1;
	}
	printf("-f=%d -r=%d\n\n", fold_flag, reverse_flag);
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {

		int16_t (*comp)(void *, void *);

		if (fold_flag)
			comp = (int16_t (*)(void *, void *)) strcmp_fold;
		else
			comp = (int16_t (*)(void *, void *)) strcmp1;

		bubble_sort((void **)lineptr, nlines, comp, reverse_flag);

		writelines(lineptr, nlines);
		return 0;

	} else {
		printf("Error: input too big\n");
		return 1;
	}
}

/*function name : strcmp1
 * Description : normal string comparison
 */
int16_t strcmp1(char *s1, char *s2)
{
	return strcmp(s1, s2);
}

/*
 * function name : strcmp_fold()
 * Description : case-insensitive comparison (-f option)
 */
int16_t strcmp_fold(char *s1, char *s2)
{
	for (; tolower(*s1) == tolower(*s2); s1++, s2++) {
		if (*s1 == '\0')
			return 0;
	}
	return tolower(*s1) - tolower(*s2);
}

