#include <stdio.h>

char *xstrchr(char *string, char ch)
{
    while (*string != '\0')
    {
        if (*string == ch)
        {
            return string;
        }
        string++;
    }

    if (ch == '\0')
        return string;

    return NULL;
}

int test_1()
{
    char str[100];
    char ch;
    char *ptr;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("Enter character to search: ");
    scanf(" %c", &ch);

    ptr = xstrchr(str, ch);

    if (ptr != NULL)
        printf("Character found at position: %ld\n", ptr - str);
    else
        printf("Character not found\n");

    return 0;
}
