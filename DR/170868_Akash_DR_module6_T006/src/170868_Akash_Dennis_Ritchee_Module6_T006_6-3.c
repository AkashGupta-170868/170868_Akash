#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXWORD 100
#define N_NOISE 123

const char *noiseWords[N_NOISE] = {
"a","about","after","all","also","an","another","any","are","as","and","at","be",
"because","been","before","being","between","but","both","by","came","can","come","could",
"did","do","each","even","for","from","further","furthermore","get","got","has","had",
"he","have","her","here","him","himself","his","how","hi","however","i","if","in","into",
"is","it","its","indeed","just","like","made","many","me","might","more","moreover",
"most","much","must","my","never","not","now","of","on","only","other","our","out","or",
"over","said","same","see","should","since","she","some","still","such","take","than",
"that","the","their","them","then","there","these","therefore","they","this","those",
"through","to","too","thus","under","up","very","was","way","we","well","were","what",
"when","where","which","while","who","will","with","would","you","your"
};

struct Line {
    int lineNo;
    struct Line *next;
};

struct Node {
    char word[50];
    struct Line *lines;
    struct Node *left;
    struct Node *right;
};

/*  Description :convert into lower case.
Author: Akash Gupta
Modified At : 14-04-2026
Created At : 14-04-2026
 */
void toLowerStr(char *s) {
    for(int i = 0; s[i]; i++)
        s[i] = tolower(s[i]);
}

/*  Description :captalizing string
Author: Akash Gupta
Modified At : 14-04-2026
Created At : 14-04-2026
 */
void capitalize(char *dest, char *src) {
    strcpy(dest, src);
    dest[0] = toupper(dest[0]);
}

/*  Description :checks noise word from the array.
Author: Akash Gupta
Modified At : 14-04-2026
Created At : 14-04-2026
 */
int isNoise(char *word) {
    for(int i = 0; i < N_NOISE; i++) {
        if(strcmp(word, noiseWords[i]) == 0)
            return 1;
    }
    return 0;
}

/* Description : Add Line (no duplicate)
Author: Akash Gupta
Modified At : 14-04-2026
Created At : 14-04-2026
*/
struct Line* addLine(struct Line *head, int lineNo) {
    if(head == NULL) {
        struct Line *newNode = malloc(sizeof(struct Line));
        newNode->lineNo = lineNo;
        newNode->next = NULL;
        return newNode;
    }

    struct Line *curr = head;
    while(curr->next != NULL)
        curr = curr->next;

    if(curr->lineNo != lineNo) {
        struct Line *newNode = malloc(sizeof(struct Line));
        newNode->lineNo = lineNo;
        newNode->next = NULL;
        curr->next = newNode;
    }

    return head;
}

/* -------- Insert BST -------- */
/*  Description :insert bst
Author: Akash Gupta
Modified At : 14-04-2026
Created At : 14-04-2026
 */
struct Node* insertNode(struct Node *root, char *word, int lineNo) {
    if(root == NULL) {
        struct Node *newNode = malloc(sizeof(struct Node));
        strcpy(newNode->word, word);
        newNode->lines = NULL;
        newNode->lines = addLine(newNode->lines, lineNo);
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    int cmp = strcmp(word, root->word);

    if(cmp == 0) {
        root->lines = addLine(root->lines, lineNo);
    }
    else if(cmp < 0) {
        root->left = insertNode(root->left, word, lineNo);
    }
    else {
        root->right = insertNode(root->right, word, lineNo);
    }

    return root;
}
/*  Description :print lines
Author: Akash Gupta
Modified At : 14-04-2026
Created At : 14-04-2026
 */
void printLines(struct Line *head) {
    while(head != NULL) {
        printf("%d ", head->lineNo);
        head = head->next;
    }
}

/*  Description :print the tree.
Author: Akash Gupta
Modified At : 14-04-2026
Created At : 14-04-2026
 */
void printTree(struct Node *root) {
    if(root == NULL) return;

    printTree(root->left);

    printf("%s : ", root->word);
    printLines(root->lines);
    printf("\n");

    printTree(root->right);
}

/*  Description :handling flow control and call the function 
Author: Akash Gupta
Modified At : 14-04-2026
Created At : 14-04-2026
 */
int cross_main() {
    struct Node *root = NULL;
    char word[MAXWORD], temp[MAXWORD];
    int ch, i, lineNo = 1;

    while((ch = getchar()) != EOF) {

        if(ch == '\n')
            lineNo++;

        if(isalpha(ch)) {
            i = 0;
            word[i++] = ch;

            while(isalnum(ch = getchar()))
                word[i++] = ch;

            word[i] = '\0';

            toLowerStr(word);

            if(!isNoise(word)) {
                capitalize(temp, word);
                root = insertNode(root, temp, lineNo);
            }
        }
    }

    printf("\n--- Output ---\n");
    printTree(root);

    return 0;
}
