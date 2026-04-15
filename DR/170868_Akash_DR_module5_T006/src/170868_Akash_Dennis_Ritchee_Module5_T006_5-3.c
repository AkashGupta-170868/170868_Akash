#include <stdio.h>
#include <stdint.h>

void my_strcat(char *s, char *t) {
    // Move to end of string s
    while (*s != '\0') {
        s++;
    }

    // Copy t into s
    while (*t != '\0') {
        *s = *t;
        s++;
        t++;
    }

    // Null terminate
    *s = '\0';
}

int str_cat() {
    char s[100], t[100];

    printf("Enter first string: ");
    fgets(s, sizeof(s), stdin);

    printf("Enter second string: ");
    fgets(t, sizeof(t), stdin);

    // Remove newline from s
    char *p = s;
    while (*p != '\0') {
        if (*p == '\n') {
            *p = '\0';
            break;
        }
        p++;
    }

    // Remove newline from t
    p = t;
    while (*p != '\0') {
        if (*p == '\n') {
            *p = '\0';
            break;
        }
        p++;
    }

    my_strcat(s, t);

    printf("Concatenated string: %s\n", s);

    return 0;
}
