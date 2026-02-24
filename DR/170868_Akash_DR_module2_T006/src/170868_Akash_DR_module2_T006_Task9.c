/*
 * Descriptions:In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x. Explain why. Use this observation to write a faster version of bitcount.
 * Author : Akash Gupta
 * Created at : 23-02-2026
 * Modified at : 23-02-2026
 */

#include <stdio.h>
#include <stdint.h>
int8_t bitcount(unsigned int x){
    int8_t count = 0;

    while (x)
    {
        x &= (x - 1);
        count++;
    }

    return count;
}

int8_t bitcount_t()
{
    int8_t num;
    char choice;

    while (1)
    {
        printf("\nenter a positive number: ");
        scanf("%hhd", &num);

        if (num < 0)
        {
            printf("invalid input! Please enter a positive number.\n");
            continue;   // ask again
        }

        printf("number of 1 bits = %d\n", bitcount(num));

        printf("do you want to continue? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'n' || choice == 'N')
            break;
    }

    printf("program ends here\n");
    return 0;
}
