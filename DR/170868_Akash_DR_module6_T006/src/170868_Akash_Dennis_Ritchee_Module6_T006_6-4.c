#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXWORDS 100
#define MAXLEN 50

struct word {
    char w[MAXLEN];
    int count;
};

struct word arr[MAXWORDS];
int n = 0;

/* Convert word to lowercase (optional but good) */
void toLower(char *s) {
    for (int i = 0; s[i]; i++)
        s[i] = tolower(s[i]);
}

/*description: Add or update word
Author: Akash Gupta
Modified At : 14-04-2026
Created At : 14-04-2026
 */
void addWord(char *w) {
    toLower(w);

    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i].w, w) == 0) {
            arr[i].count++;
            return;
        }
    }

    strcpy(arr[n].w, w);
    arr[n].count = 1;
    n++;
}

/* description: Bubble sort (descending by count)
Author: Akash Gupta
Modified At : 14-04-2026
Created At : 14-04-2026
 */
void sortWords() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].count < arr[j + 1].count) {
                struct word temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/*  Description :print result
Author: Akash Gupta
Modified At : 14-04-2026
Created At : 14-04-2026
*/
void printWords() {
    for (int i = 0; i < n; i++) {
        printf("%d : %s\n", arr[i].count, arr[i].w);
    }
}
/*  Description :handling flow control and calling the function
Author: Akash Gupta
Modified At : 14-04-2026
Created At : 14-04-2026
 */
int freq_count_main() {
    char word[MAXLEN];

    /* Read words until EOF */
    while (scanf("%s", word) != EOF) {
        addWord(word);
    }

    sortWords();
    printWords();

    return 0;
}
