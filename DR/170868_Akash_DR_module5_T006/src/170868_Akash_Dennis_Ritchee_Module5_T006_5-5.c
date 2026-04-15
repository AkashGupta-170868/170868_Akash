/*
 * Descriptions: Write versions of the library functions strncpy, strncat, and strncmp, which
operate on at most the first n characters of their argument strings. For example,
strncpy(s,t,n) copies at most n characters of t to s
 * Author : Akash Gupta
 * Created at : 30-03-2026
 * Modified at : 30-03-2026
 */

#include <stdio.h>
#include <stdint.h>

/*
 * function name : my_strncpy;
 * Descriptions: copy the string from source string to destination string but copy only nth chracter should be copied and n is taken by the user.
 * Author : Akash Gupta
 * Created at : 30-03-2026
 * Modified at : 30-03-2026
 */
void my_strncpy(char *dst, const char *src, uint32_t n) {
    uint32_t i = 0;

    while (i < n && src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }
    while (i < n) {
        dst[i++] = '\0';
    }
}

/*
 * function name : my_strncat;
 * description : concenate the from source to destination and store into string source but the nth charcter should be concanate only that would be taken by the user.
 * Author : Akash Gupta
 * Created at : 30-03-2026
 * Modified at : 30-03-2026
 */
void my_strncat(char *dst, const char *src, uint32_t n) {
    uint32_t i = 0, j = 0;

    while (dst[i] != '\0') i++;

    while (j < n && src[j] != '\0') {
        dst[i + j] = src[j];
        j++;
    }
    dst[i + j] = '\0';
}

/*
 * function name : my_strncmp;
 * Descriptions: compare the string till nth character and n is taken by the user then return 1 if the string matched else return 0.
 * Author : Akash Gupta
 * Created at : 30-03-2026
 * Modified at : 30-03-2026
 */
int32_t my_strncmp(const char *s1, const char *s2, uint32_t n) {
    uint32_t i = 0;

    while (i < n) {
        if (s1[i] != s2[i])
            return (int32_t)(s1[i] - s2[i]);

        if (s1[i] == '\0')
            return 0;

        i++;
    }
    return 0;
}

int str_test() {
    char s1[100], s2[100];
    uint32_t n;
    uint32_t op;

    printf("1:strncat 2:strncmp 3:strncpy\n");
    scanf("%u", &op);

    printf("Str1: ");
    scanf(" %[^\n]", s1);
    printf("Str2: ");
    scanf(" %[^\n]", s2);

    printf("n: ");
    scanf("%u", &n);

    if (op == 1) {
        my_strncat(s1, s2, n);
        printf("Result: %s\n", s1);
    }
    else if (op == 2) {
        if (my_strncmp(s1, s2, n) == 0)
            printf("Result: match found\n");
        else
            printf("Result: no match\n");
    }
    else if (op == 3) {
        my_strncpy(s1, s2, n);
        printf("Result: %s\n", s1);
    }
    else {
        printf("Invalid\n");
    }

    return 0;
}
