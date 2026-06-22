/*
 * Description :Our version of getword does not properly handle underscores, string constants,
 comments, or preprocessor control lines. Write a better version.
Author: Akash Gupta
Modified At : 14-04-2026
Created At : 14-04-2026
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>

#define MAXWORD 100
#define BUFSIZE 100

struct key {
	char *word;
	int32_t count;
};

struct key keytab[] = {
	{"auto", 0}, {"break", 0}, {"case", 0}, {"char", 0},
	{"const", 0}, {"continue", 0}, {"default", 0}, {"do", 0},
	{"double", 0}, {"else", 0}, {"enum", 0}, {"extern", 0},
	{"float", 0}, {"for", 0}, {"goto", 0}, {"if", 0},
	{"int", 0}, {"long", 0}, {"register", 0}, {"return", 0},
	{"short", 0}, {"signed", 0}, {"sizeof", 0}, {"static", 0},
	{"struct", 0}, {"switch", 0}, {"typedef", 0}, {"union", 0},
	{"unsigned", 0}, {"void", 0}, {"volatile", 0}, {"while", 0}
};

#define NKEYS (sizeof(keytab) / sizeof(keytab[0]))

static char buf[BUFSIZE];
static int32_t bufp = 0;

int32_t getword(char *word, int32_t lim);
int32_t binsearch(char *word, struct key tab[], int32_t n);
static int32_t getch(void);
static void ungetch(int32_t);

/*
   Function Name : getword_main();
Description: its run the while untill the getword function is not eof and check the word is matching with the keytab array or not ? and simply print the count of word has been matched .
Author: Akash Gupta
Created At : 14-04-2026
 */
int getword_main(void)
{
	int32_t n;
	char word[MAXWORD];

	while (getword(word, MAXWORD) != EOF) {
		if (isalpha(word[0])) {
			n = binsearch(word, keytab, NKEYS);
			if (n >= 0)
				keytab[n].count++;
		}
	}

	printf("\nKeyword Count:\n");

	for (n = 0; n < NKEYS; n++) {
		if (keytab[n].count > 0)
			printf("%4d %s\n", keytab[n].count, keytab[n].word);
	}

	return 0;
}
/*
   Function Name : binsearch();
Description: it is used to search the kayword from the given keytab array .
Author: Akash Gupta
Created At : 14-04-2026
 */
int32_t binsearch(char *word, struct key tab[], int32_t n)
{
	int32_t low = 0, high = n - 1, mid, cond;

	while (low <= high) {
		mid = (low + high) / 2;
		cond = strcmp(word, tab[mid].word);

		if (cond < 0)
			high = mid - 1;
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;
	}

	return -1;
}
/*
   Function Name : getword();
Description: improved getword() function which has handle string comments and preprocessor . "" # \\ \* *\
Author: Akash Gupta
Created At : 14-04-2026
 */
int32_t getword(char *word, int32_t lim)
{
	int32_t c;
	char *w = word;

	while (isspace(c = getch()))
		;

	if (c == EOF)
		return EOF;

	if (c == '/') {
		int32_t d = getch();

		if (d == '/') {
			while ((c = getch()) != '\n' && c != EOF)
				;
			return getword(word, lim);
		}

		if (d == '*') {
			int32_t prev = 0;
			while ((c = getch()) != EOF) {
				if (prev == '*' && c == '/')
					break;
				prev = c;
			}
			return getword(word, lim);
		}

		ungetch(d);
	}

	if (c == '"') {
		while ((c = getch()) != '"' && c != EOF)
			;
		return getword(word, lim);
	}

	if (isalpha(c) || c == '_') {

		*w++ = c;

		while (--lim > 0) {
			c = getch();

			if (!(isalnum(c) || c == '_')) {
				ungetch(c);
				break;
			}

			*w++ = c;
		}

		*w = '\0';
		return word[0];
	}

	word[0] = c;
	word[1] = '\0';

	return c;
}
/*
   Function Name : getch();
Description:
Author: Akash Gupta
Created At : 14-04-2026
 */
static int32_t getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}
/*
   Function Name : ungetch();
Description:
Author: Akash Gupta
Created At : 14-04-2026
 */
static void ungetch(int32_t c)
{
	if (bufp < BUFSIZE)
		buf[bufp++] = c;
	else
		printf("ungetch: buffer full\n");
}

