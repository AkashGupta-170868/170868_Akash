/*Description :Write a program that reads a C program and prints in alphabetical order each
  group of variable names that are identical in the first 6 characters, but different somewhere
  thereafter. Don't count words within strings and comments. Make 6 a parameter that can be set
  from the command line
Author :Akash Gupta
Created at:21-04-2026
Modified at:21-04-2026
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAXWORD 100

/* Tree Node */
struct tnode {
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};

static int getword(char *word, int lim);
static struct tnode *addtree(struct tnode *p, char *w);
static void treeprint(struct tnode *p);
static struct tnode *talloc(void);
static char *strdup_local(const char *s);
static void similarWord(struct tnode *p, int16_t len);
void variableCount(int argc, char *argv[]);


void variableCount(int argc, char *argv[]) {
	struct tnode *root = NULL;
	char word[MAXWORD];
	int16_t compLength = 6;

	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			root = addtree(root, word);

	if (argc == 2)
		compLength = atoi(argv[1]);

	printf("\nComparison Length: %d\n", compLength);

	printf("\nWord Frequency:\n");
	treeprint(root);

	printf("\nSimilar Words:\n");
	similarWord(root, compLength);
}

/* Description : ADD TREE NODE
Author:Akash Gupta
created At:20-04-2026
modified at: 20-04-2026
 */
static struct tnode *addtree(struct tnode *p, char *w) {
	int cond;

	if (p == NULL) {
		p = talloc();
		p->word = strdup_local(w);
		p->count = 1;
		p->left = p->right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0)
		p->count++;
	else if (cond < 0)
		p->left = addtree(p->left, w);
	else
		p->right = addtree(p->right, w);

	return p;
}

/* Description : PRINT TREE 
Author:Akash Gupta
created At:20-04-2026
modified at: 20-04-2026
 */
static void treeprint(struct tnode *p) {
	if (p != NULL) {
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}

/* Description : allocate memory for node
Author:Akash Gupta
created At:20-04-2026
modified at: 20-04-2026
 */
static struct tnode *talloc(void) {
	return (struct tnode *) malloc(sizeof(struct tnode));
}

/*description :STRING DUPLICATE 
Author:Akash Gupta
created At:20-04-2026
modified at: 20-04-2026
 */
static char *strdup_local(const char *s) {
	char *p = (char *) malloc(strlen(s) + 1);
	if (p != NULL)
		strcpy(p, s);
	return p;
}

/*
Description:SIMILAR WORD GROUPING
Author:Akash Gupta
created At:20-04-2026
modified at: 20-04-2026
 */
static void similarWord(struct tnode *p, int16_t len) {
	static char prev[MAXWORD] = "";
	static int prevCount = 0;
	static int groupSize = 0;

	if (p != NULL) {
		similarWord(p->left, len);

		if (prev[0] == '\0' || strncmp(prev, p->word, len) != 0) {
			strcpy(prev, p->word);
			prevCount = p->count;
			groupSize = 1;
		} else {
			if (groupSize == 1) {
				printf("\n%s\n", prev);
				printf("%4d %s\n", prevCount, prev);
			}
			printf("%4d %s\n", p->count, p->word);
			groupSize++;
		}

		similarWord(p->right, len);
	}
}
/*description :skip white spaces and read word from stdinput .
Author:Akash Gupta
created At:20-04-2026
modified at: 20-04-2026
 */
static int getword(char *word, int lim) {
	int c;
	char *w = word;

	while (isspace(c = getchar()))
		;

	if (c != EOF)
		*w++ = c;

	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}

	for (; --lim > 0; w++) {
		if (!isalnum(*w = getchar())) {
			ungetc(*w, stdin);
			break;
		}
	}

	*w = '\0';
	return word[0];
}
