/*
 * Descriptions:Write a function htoi(s), which converts a string of hexadecimal digits(including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0 through 9, a through f, and A through F
 * Author : Akash Gupta
 * Created at : 09-02-2026
 * Modified at : 10-02-2026
 */

#include <stdio.h>
#include <ctype.h>
#include <stdint.h>

uint32_t htoi(const char s[])
{
    uint32_t i = 0;
    uint32_t n = 0;
    uint32_t digit;

    while (isspace(s[i]))
        i++;

    if (s[i] == '0' && (s[i+1] == 'x' || s[i+1] == 'X'))
        i += 2;

    while (s[i] != '\0')
    {
        if (s[i] >= '0' && s[i] <= '9')
            digit = s[i] - '0';
        else if (s[i] >= 'a' && s[i] <= 'f')
            digit = s[i] - 'a' + 10;
        else if (s[i] >= 'A' && s[i] <= 'F')
            digit = s[i] - 'A' + 10;
        else
        {
            printf("Not a valid number\n");
            return 0;
        }

        n = 16 * n + digit;
        i++;
    }

    return n;
}

int  hex_2_int()
{
    char hex[100];

    printf("Enter hexadecimal number: ");
    scanf("%s", hex);

    uint32_t result = htoi(hex);

    if (result != 0)
        printf("Decimal: %u\n", result);

    return 0;
}
