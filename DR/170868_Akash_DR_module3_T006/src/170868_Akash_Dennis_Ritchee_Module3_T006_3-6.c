/*
 * Descriptions:Write a version of itoa that accepts three arguments instead of two. The third
argument is a minimum field width; the converted number must be padded with blanks/star on the
left if necessary to make it wide enough.
 * Author : Akash Gupta
 * Created at : 27-02-2026
 * Modified at : 27-02-2026
 */


#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define MAX_LEN 100

void itoa_width(int32_t num, char str[], int32_t width);
void rev_str(char str[]);

int itoa_width_t(void)
{
    int32_t num;
    int32_t width;
    char str[MAX_LEN];

    printf("enter digit: ");
    scanf("%d", &num);

    printf("enter minimum field width: ");
    scanf("%d", &width);

    itoa_width(num, str, width);

    printf("Output: %s\n", str);

    return 0;
}


void itoa_width(int32_t num, char str[], int32_t width)
{
    int32_t idx = 0;
    int32_t sign = num;

    if (num < 0)
        num = -num;

    do
    {
        str[idx++] = (num % 10) + '0';
    } while ((num /= 10) > 0);

    if (sign < 0){
        str[idx++] = '-';
}
    while (idx < width){
        str[idx++] = '*';
}
    str[idx] = '\0';

    rev_str(str);
}

void rev_str(char str[])
{
    int32_t i = 0;
    int32_t j = strlen(str) - 1;
    char temp;

    while (i < j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}
