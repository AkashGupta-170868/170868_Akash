/*
Description :
Rewrite readlines to store lines in an array supplied by main,
rather than calling alloc to maintain storage

Author : Akash Gupta
Created At : 01-04-2026
Modified At : 01-04-2026
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define MAX_LINES   100
#define MAX_LEN     1000
#define MAX_STORAGE 10000

static int32_t my_getline(char *buffer, int32_t limit)
{
    int32_t ch;
    char *start = buffer;

    while (limit > 1 && (ch = getchar()) != EOF && ch != '\n')
    {
        *buffer++ = ch;
        limit--;
    }

    if (ch == '\n')
        *buffer++ = ch;

    *buffer = '\0';

    return buffer - start;
}
/* Read input lines */
int32_t read_input_lines(char *line_pointers[], int32_t max_lines)
{
	int32_t length, line_count = 0;
	char temp_line[MAX_LEN];

	static char storage[MAX_STORAGE];
	char *current_ptr = storage;
	char *end_ptr = storage + MAX_STORAGE;

	while ((length = my_getline(temp_line, MAX_LEN)) > 0)
	{
		if (line_count >= max_lines || current_ptr + length > end_ptr)
			return -1;

		temp_line[length - 1] = '\0';

		strcpy(current_ptr, temp_line);
		line_pointers[line_count++] = current_ptr;

		current_ptr += length;
	}

	return line_count;
}

/* Swap lines */
static void swap_lines(char *lines[], int32_t idx1, int32_t idx2)
{
	char *temp = lines[idx1];
	lines[idx1] = lines[idx2];
	lines[idx2] = temp;
}

/* Quick sort lines */
static void quick_sort_lines(char *lines[], int32_t left, int32_t right)
{
	int32_t idx, last;

	if (left >= right)
		return;

	swap_lines(lines, left, (left + right) / 2);

	last = left;

	for (idx = left + 1; idx <= right; idx++)
	{
		if (strcmp(lines[idx], lines[left]) < 0)
			swap_lines(lines, ++last, idx);
	}

	swap_lines(lines, left, last);

	quick_sort_lines(lines, left, last - 1);
	quick_sort_lines(lines, last + 1, right);
}

/* Print output lines */
static void write_output_lines(char *line_pointers[], int32_t num_lines)
{
	for (int32_t idx = 0; idx < num_lines; idx++)
		printf("%s\n", line_pointers[idx]);
}

/* Test function */
int32_t readline_test(void)
{
	int32_t number_of_lines;
	char *line_pointers[MAX_LINES];

	number_of_lines = read_input_lines(line_pointers, MAX_LINES);

	if (number_of_lines >= 0)
	{
		quick_sort_lines(line_pointers, 0, number_of_lines - 1);

		printf("\nSorted Lines:\n");
		write_output_lines(line_pointers, number_of_lines);

		return 0;
	}

	printf("Error: input too large to sort\n");
	return 1;
}
