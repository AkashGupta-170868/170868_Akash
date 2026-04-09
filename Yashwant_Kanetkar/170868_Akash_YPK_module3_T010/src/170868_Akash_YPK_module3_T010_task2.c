#include <stdio.h>
char *my_strstr(char *mainStr, char *subStr)
{
    char *start, *mPtr, *sPtr;
    while (*mainStr != '\0')
    {
        start = mainStr;  
        mPtr = mainStr;
        sPtr = subStr;

        while (*mPtr == *sPtr && *sPtr != '\0')
        {
            mPtr++;
            sPtr++;
        }

        if (*sPtr == '\0')
        {
            return start;
        }

        mainStr++;  
    }

    return NULL;  
}

int test_2()
{
    char mainStr[100], subStr[50];
    char *result;

    printf("Enter main string: ");
    fgets(mainStr, sizeof(mainStr), stdin);

    printf("Enter substring: ");
    fgets(subStr, sizeof(subStr), stdin);


    for (int i = 0; mainStr[i] != '\0'; i++)
        if (mainStr[i] == '\n') mainStr[i] = '\0';

    for (int i = 0; subStr[i] != '\0'; i++)
        if (subStr[i] == '\n') subStr[i] = '\0';

    result = my_strstr(mainStr, subStr);
if (result != NULL)
{
    printf("Substring found at address: %p\n", (void *)result);
}
else
{
    printf("Substring not found\n");
}

    return 0;
}
