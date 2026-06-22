/*
 * Description:
 * As written, getint treats a + or - not followed by a digit
 * as a valid representation of zero. Fixed to push such
 * character back on the input.
 *
 * Author : Akash Gupta
 * Created at : 27-03-2026
 * Modified at : 27-03-2026
 */

#include <stdio.h>
#include <ctype.h>
#include <stdint.h>

#define SIZE 100

static char buffer[SIZE];
static int32_t idx = 0;

/*
 * Function Name : getch()
 * Description   : Reads one character at a time from input
 */
static int32_t getch(void)
{
    return (idx > 0) ? buffer[--idx] : getchar();
}

/*
 * Function Name : ungetch()
 * Description   : Stores character in buffer
 */
static void ungetch(int32_t num)
{
    if (idx < SIZE)
        buffer[idx++] = num;
    else
        printf("Stack overflow\n");
}

/*
 * Function Name : getint()
 * Description   : Converts input into integer and returns it
 */
static int32_t getint(int32_t *pnum)
{
    int32_t character;

    while (isspace(character = getch()))
        ;

    if (!isdigit(character) && character != EOF &&
        character != '+' && character != '-')
    {
        ungetch(character);
        return 0;
    }

    int32_t sign = (character == '-') ? -1 : 1;

    if (character == '+' || character == '-')
    {
        int32_t nextChar = getch();

        if (!isdigit(nextChar))
        {
            ungetch(nextChar);
            ungetch(character);
            return 0;
        }

        character = nextChar;
    }

    for (*pnum = 0; isdigit(character); character = getch())
        *pnum = 10 * (*pnum) + (character - '0');

    *pnum *= sign;

    if (character != EOF)
        ungetch(character);

    return character;
}

int32_t test_dr51(void)
{
    int32_t number, status;

    printf("Enter input: ");

    status = getint(&number);

    if (status == 0)
        printf("Not a valid number\n");
    else
        printf("Number = %d\n", number);

    return 0;
}
