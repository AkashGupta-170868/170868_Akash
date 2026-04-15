/*
 * Descriptions: Write the function strend(s,t), which returns 1 if the string t occurs at the
end of the string s, and zero otherwise.
 * Author : Akash Gupta
 * Created at : 30-03-2026
 * Modified at : 30-03-2026
 */

#include <stdio.h>
#include <stdint.h>

/*
 * function name : strend();
 * Description : returns 1 if t is at the end of s, else 0
 * Author : Akash Gupta
 * Created at : 30-03-2026
 * Modified at : 30-03-2026
 */
int strend(char *s, char *t) {
    char *ps = s;
    char *pt = t;

    // move to end of both strings
    while (*ps != '\0') ps++;
    while (*pt != '\0') pt++;

    // compare backward
    while (pt > t) {
        if (*(--ps) != *(--pt)) {
            return 1;
        }
    }

    return 0;
}

/*
 * function name : rm_nl();
 * Descriptions: remove newline from fgets
 * Author : Akash Gupta
 * Created at : 30-03-2026
 * Modified at : 30-03-2026
 */
void rm_nl(char *str) {
    while (*str != '\0') {
        if (*str == '\n') {
            *str = '\0';
            break;
        }
        str++;
    }
}

int str_end_test() {
    char s[100], t[100];

    printf("Enter main string (s): ");
    fgets(s, sizeof(s), stdin);

    printf("Enter substring (t): ");
    fgets(t, sizeof(t), stdin);

    rm_nl(s);
    rm_nl(t);

    if (strend(s, t)) {
        printf("Result: t occurs at the end of s\n");
    } else {
        printf("Result: t does NOT occur at the end of s\n");
    }

    return 0;
}
