#include <stdio.h>

int any(char s1[], char s2[]) {
    int i, j;

    for(i = 0; s1[i] != '\0'; i++) {
        for(j = 0; s2[j] != '\0'; j++) {
            if(s1[i] == s2[j]) {
                return i;   
            }
        }
    }

    return -1;   
}

int check_duplicate() {
    char s1[100], s2[100];
    int result;

    printf("Enter first string: ");
    scanf("%s", s1);

    printf("Enter second string: ");
    scanf("%s", s2);

    result = any(s1, s2);

    if(result != -1)
        printf("First matching character found at position %d\n", result);
    else
        printf("No matching character found\n");

    return 0;
}

