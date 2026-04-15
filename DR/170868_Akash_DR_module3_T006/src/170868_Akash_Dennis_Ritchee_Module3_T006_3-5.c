/*
 * Descriptions:Write the function itob(n,s,b) that converts the integer n into a base b
character representation in the string s. In particular, itob(n,s,16) formats s as a
hexadecimal integer in s
 * Author : Akash Gupta
 * Created at : 26-02-2026
 * Modified at : 26-02-2026
 */

#include <stdio.h>
#include <stdint.h>

/* Function name: itob (integer to any base )
*Function Description: convert any number into any base and store in buffer and then reverse that number and at the end print that number
*Author:Akash Gupta
*Created:26-02-2026 
*/


void itob(int32_t num, char buf[], int32_t base)
{
    int32_t idx = 0;
    uint32_t val = (num < 0) ? -num : num;

    do {
        int32_t rem = val % base;
        buf[idx++] = (rem < 10) ? (rem + '0') : (rem - 10 + 'A');
        val /= base;
    } while (val);

    if (num < 0)
        buf[idx++] = '-';

    buf[idx] = '\0';

    for (int32_t left = 0, right = idx - 1; left < right; left++, right--) {
        char tmp = buf[left];
        buf[left] = buf[right];
        buf[right] = tmp;
    }
}

int itob_t()
{
    int32_t num, base;
    char buf[50];

    printf("Digit = ");
    scanf("%d", &num);

    printf("Base = ");
    scanf("%d", &base);

    if (base < 2 || base > 16) {
        printf("Enter a valid base value\n");
        return 0;
    }

    itob(num, buf, base);
    printf("Ans = %s\n", buf);

    return 0;
}
