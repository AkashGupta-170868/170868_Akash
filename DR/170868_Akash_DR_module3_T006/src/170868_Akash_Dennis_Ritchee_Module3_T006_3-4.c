/*
description : In a two's complement number representation, our version of itoa
does not handle the largest negative number. Modify it to print that value
correctly regardless of machine.
Author:Akash Gupta
created At:26-02-2026
modified at:26-02-2026
*/

#include <stdio.h>
#include <stdint.h>
#include <limits.h>

/*
description : reverse string
Author:Akash Gupta
created At:26-02-2026
modified at:26-02-2026
*/
static void reverse(char s[])
{
    int i = 0, j = 0;
    char temp;

    while (s[j] != '\0')
        j++;

    j--;

    while (i < j)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}

/*
description : safe itoa for int32_t
Author:Akash Gupta
created At:26-02-2026
modified at:26-02-2026
*/
static void itoa(int32_t n, char s[])
{
    int i = 0;
    int32_t sign = n;

    do
    {
        int32_t digit = n % 10;

        if (digit < 0)
            digit = -digit;

        s[i++] = digit + '0';

    } while ((n /= 10) != 0);

    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';

    reverse(s);
}

/*
description : convert integer to string
Author:Akash Gupta
created At:26-02-2026
modified at:26-02-2026
*/
int32_t itoa_t(void)
{
    int64_t input;
    char str[50];

    printf("Enter value of x: ");
    scanf("%lld", &input);

    if (input < INT32_MIN || input > INT32_MAX)
    {
        printf("Entered number is not in range\n");
        return 0;
    }

    int32_t x = (int32_t)input;

    itoa(x, str);

    printf("x = %lld\n", input);
    printf("%s\n", str);

    return 0;
}
