#include <stdio.h>
#include <string.h>

// Encoding function
void encode(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = str[i] + 3;
    }
}

// Decoding function
void decode(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = str[i] - 3;
    }
}

int test_5()
{
    char str[100];
    char original[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // remove newline
    str[strcspn(str, "\n")] = '\0';

    // store original input
    strcpy(original, str);

    // Encode
    encode(str);

    // Print in required format
    printf("\nInput:  %s\n", original);
    printf("Encoded: %s\n", str);

    // Decode
    decode(str);

    printf("Decoded: %s\n", str);

    return 0;
}
