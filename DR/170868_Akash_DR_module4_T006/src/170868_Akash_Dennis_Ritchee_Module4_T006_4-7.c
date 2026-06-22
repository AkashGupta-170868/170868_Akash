/**
 * Program to push back an entire string into input buffer
 * using ungets().
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define MAXBUF 100
#define MAXLINE 100

/* File-limited global variables */
static int32_t bufp = 0;
static int32_t buf[MAXBUF];

/* Function declarations */
static int32_t getch(void);
static void ungetch(int32_t c);
static void ungets(char s[]);
static int32_t mgetline(char line[], int32_t maxline);

/*
 * Main function
 *
 * Description:
 * Reads a line of input, pushes it back into the input buffer
 * using ungets(), then reads it again and prints it.
 *
 * Parameters:
 * None
 *
 * Returns:
 * 0 on successful execution
 */
int main4_7(void)
{
	char line[MAXLINE];
	int32_t c;

	mgetline(line, MAXLINE);

	ungets(line);

	while ((c = getch()) != EOF)
		putchar(c);

	return 0;
}

/*
 * Get Line function
 *
 * Description:
 * Reads a line of input from standard input.
 *
 * Parameters:
 * s   - character array to store input
 * lim - maximum number of characters
 *
 * Returns:
 * Length of input line
 */
static int32_t mgetline(char s[], int32_t lim)
{
	int32_t i, c;

	for (i = 0; i < lim - 1 &&
			(c = getchar()) != EOF &&
			c != '\n'; ++i)
	{
		s[i] = c;
	}

	if (c == '\n')
		s[i++] = c;

	s[i] = '\0';

	return i;
}

/*
 * Ungets function
 *
 * Description:
 * Pushes an entire string back into the input buffer
 * character by character.
 *
 * Parameters:
 * s - string to push back
 *
 * Returns:
 * None
 */
static void ungets(char s[])
{
	int32_t i;

	i = strlen(s);

	while (i > 0)
		ungetch(s[--i]);
}

/*
 * Unget Character function
 *
 * Description:
 * Pushes one character back into input buffer.
 *
 * Parameters:
 * c - character to push back
 *
 * Returns:
 * None
 */
static void ungetch(int32_t c)
{
	if (bufp >= MAXBUF)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

/*
 * Get Character function
 *
 * Description:
 * Returns next character from buffer
 * or standard input.
 *
 * Parameters:
 * None
 *
 * Returns:
 * Character read
 */
static int32_t getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}
