#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101

/*Description: Node structure 
  created at : 17-04-2026
*/
struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

struct nlist *hashtab[HASHSIZE];
/*description :return specific index for an array hashtab
Author:Akash Gupta
created At:20-04-2026
modified at: 20-04-2026
 */
unsigned hash(char *s)
{
    unsigned hashval = 0;
    while (*s)
        hashval = *s++ + 31 * hashval;
    return hashval % HASHSIZE;
}
/*description :its check waether name is already exits or not ? if yes then update the defn. if not then create a new node and then add name and defn.
Author:Akash Gupta
created At:20-04-2026
modified at: 20-04-2026
 */
struct nlist *lookup(char *s)
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
struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) {
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL)
            return NULL;

        np->name = strdup(name);
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else {
        free(np->defn);  // update existing
    }

    np->defn = strdup(defn);
    return np;
}

/* Undef function (DELETE) 
*description :delete entry from hashtable
Author:Akash Gupta
created At:20-04-2026
modified at: 20-04-2026
 */
void undef(char *name)
{
    unsigned hashval = hash(name);
    struct nlist *curr = hashtab[hashval];
    struct nlist *prev = NULL;

    while (curr != NULL) {
        if (strcmp(name, curr->name) == 0) {

            if (prev == NULL)
                hashtab[hashval] = curr->next;
            else
                prev->next = curr->next;

            free(curr->name);
            free(curr->defn);
            free(curr);
            return;
        }

        prev = curr;
        curr = curr->next;
    }
}

/* Print table *description :skip white spaces and read char if # then read full word and return # and if not then read word .
Author:Akash Gupta
created At:20-04-2026
modified at: 20-04-2026
 */
void printTable()
{
    for (int i = 0; i < HASHSIZE; i++) {
        struct nlist *np = hashtab[i];
        while (np != NULL) {
            printf("%-15s %s\n", np->name, np->defn);
            np = np->next;
        }
    }
}

void init()
{
    for (int i = 0; i < HASHSIZE; i++)
        hashtab[i] = NULL;
}
/*description :main function that handle input and output.
Author:Akash Gupta
created At:20-04-2026
modified at: 20-04-2026
 */
int hash_main()
{
    init();

    char name[100], defn[200];

    for (int i = 0; i < 3; i++) {
        printf("Name : ");
        scanf(" %[^\n]", name);

        printf("Definition : ");
        scanf(" %[^\n]", defn);

        install(name, defn);
    }

    printf("\nOutput :\n\n");
    printTable();

    printf("\nRemove Entry : ");
    scanf(" %[^\n]", name);

    undef(name);

    printf("\nOutput :\n\n");
    printTable();

    return 0;
}
