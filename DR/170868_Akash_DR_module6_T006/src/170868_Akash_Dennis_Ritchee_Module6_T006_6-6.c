/*description :Implement a simple version of the #define processor (i.e., no arguments)
  suitable for use with C programs, based on the routines of this section. You may also find
  getch and ungetch helpful.
Author:Akash Gupta
created At:20-04-2026
modified at: 20-04-2026
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

#define HASHSIZE 101
#define MAXWORD 100

struct nlist {
	struct nlist *next;
	char *name;
	char *defn;
};

static struct nlist *hashtab[HASHSIZE];

/*description :return specific index for an array hashtab
Author:Akash Gupta
created At:20-04-2026
modified at: 20-04-2026
 */
static uint32_t hash(char *s)
{
	uint32_t hashval = 0;
	while (*s)
		hashval = (uint32_t)(*s++) + 31U * hashval;
	return hashval % HASHSIZE;
}
/*description :its check waether name is already exits or not ? if yes then update the defn. if not then create a new node and then add name and defn.
Author:Akash Gupta
created At:20-04-2026
modified at: 20-04-2026
 */
static struct nlist *lookup(char *s)
{
	struct nlist *np;
	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
		if (strcmp(s, np->name) == 0)
			return np;
	return NULL;
}
/*description :insert the name and defn into hashtab 
Author:Akash Gupta
created At:20-04-2026
modified at: 20-04-2026
 */
static struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	uint32_t hashval;

	if ((np = lookup(name)) == NULL) {
		np = (struct nlist *) malloc(sizeof(*np));
		np->name = strdup(name);
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	} else {
		free(np->defn);
	}

	np->defn = strdup(defn);
	return np;
}

static char buf[100];
static int32_t bufp = 0;

static int32_t getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

static void ungetch(int32_t c)
{
	if (bufp < 100)
		buf[bufp++] = (char)c;
}
/*description :skip white spaces and read char if # then read full word and return # and if not then read word .
Author:Akash Gupta
created At:20-04-2026
modified at: 20-04-2026
 */
static int32_t getword(char *word, int32_t lim)
{
	int32_t c;
	char *w = word;

	while (isspace(c = getch()))
		;

	if (c != EOF)
		*w++ = (char)c;

	if (!isalpha(c) && c != '#') {
		*w = '\0';
		return c;
	}

	if (c == '#') {
		while (--lim > 0) {
			c = getch();
			if (!isalpha(c)) {
				ungetch(c);
				break;
			}
			*w++ = (char)c;
		}
		*w = '\0';
		return '#';
	}

	while (--lim > 0) {
		c = getch();
		if (!isalnum(c)) {
			ungetch(c);
			break;
		}
		*w++ = (char)c;
	}

	*w = '\0';
	return word[0];
}
/*description :print the entire table available at hashmap.
Author:Akash Gupta
created At:20-04-2026
modified at: 20-04-2026
 */
static void printTable(void)
{
	for (int32_t i = 0; i < HASHSIZE; i++) {
		struct nlist *np = hashtab[i];
		while (np) {
			printf("%s->%s\n", np->name, np->defn);
			np = np->next;
		}
	}
}
/*description :main fuction to check if char is # then getting name and defn and then store into hashtable.
Author:Akash Gupta
created At:20-04-2026
modified at: 20-04-2026
 */
int define_main(void)
{
	char word[MAXWORD];
	char name[MAXWORD];
	char defn[MAXWORD];

	while (getword(word, MAXWORD) != EOF) {

		if (strcmp(word, "#define") == 0) {

			getword(name, MAXWORD);
			getword(defn, MAXWORD);

			install(name, defn);
		}
	}

	printTable();

	return 0;
}
