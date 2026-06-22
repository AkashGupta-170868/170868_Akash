/*
 * Description:
 * Rewrite appropriate programs from earlier chapters and exercises
 * with pointers instead of array indexing.
 *
 * 1. getline
 * 2. atoi
 * 3. itoa
 * 4. reverse
 * 5. strindex
 * 6. getop
 *
 * Author : Akash Gupta
 */

#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <stdlib.h>

#define NUM '0'
#define SIZE 100
#define MAXOP 100
#define MAXVAL 100

static int32_t getch(void);
static void ungetch(int32_t);

/* ================= getline ================= */
static int32_t my_getline(char *buf, int32_t lim)
{
    int32_t ch;
    char *start = buf;

    while (lim > 1 && (ch = getchar()) != EOF && ch != '\n')
    {
        *buf++ = ch;
        lim--;
    }

    if (ch == '\n')
        *buf++ = ch;

    *buf = '\0';

    return buf - start;
}

/* ================= atoi ================= */
static int32_t my_atoi(char *str)
{
    int32_t num = 0;
    int32_t sign = 1;

    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    else if (*str == '+')
        str++;

    while (*str >= '0' && *str <= '9')
    {
        num = 10 * num + (*str - '0');
        str++;
    }

    return sign * num;
}

/* ================= reverse ================= */
static void reverse(char *str)
{
    char *end = str;
    char temp;

    while (*end)
        end++;

    end--;

    while (str < end)
    {
        temp = *str;
        *str++ = *end;
        *end-- = temp;
    }
}

/* ================= itoa ================= */
static void my_itoa(int32_t num, char *buf)
{
    int32_t sign = num;
    char *start = buf;

    if (num < 0)
        num = -num;

    do
    {
        *buf++ = (num % 10) + '0';
    } while ((num /= 10) > 0);

    if (sign < 0)
        *buf++ = '-';

    *buf = '\0';

    reverse(start);
}

/* ================= strindex ================= */
static int32_t my_strindex(char *str, char *sub)
{
    char *ptr1, *ptr2;
    char *start = str;
    int32_t pos = -1;

    while (*str)
    {
        ptr1 = str;
        ptr2 = sub;

        while (*ptr2 && tolower(*ptr1) == tolower(*ptr2))
        {
            ptr1++;
            ptr2++;
        }

        if (*ptr2 == '\0')
            pos = (str - start) + 1;

        str++;
    }

    return pos;
}

/* ================= Stack ================= */
static int32_t sp = 0;
static double val[MAXVAL];

static void push(double num)
{
    if (sp < MAXVAL)
        val[sp++] = num;
    else
        printf("Error: stack full\n");
}

static double pop(void)
{
    if (sp > 0)
        return val[--sp];

    printf("Error: stack empty\n");
    return 0.0;
}

/* ================= getop ================= */
static int32_t my_getop(char *buf)
{
    int32_t ch;

    while ((*buf = ch = getch()) == ' ' || ch == '\t')
        ;

    *(buf + 1) = '\0';

    if (!isdigit(ch) && ch != '.')
        return ch;

    if (isdigit(ch))
        while (isdigit(*++buf = ch = getch()))
            ;

    if (ch == '.')
        while (isdigit(*++buf = ch = getch()))
            ;

    *buf = '\0';

    if (ch != EOF)
        ungetch(ch);

    return NUM;
}

func_test(void)
{
    int choice;
    char str1[SIZE], str2[SIZE];
    int32_t num, result;

    do
    {
        printf("\n===== MENU =====\n");
        printf("1. getline\n");
        printf("2. atoi\n");
        printf("3. itoa\n");
        printf("4. reverse\n");
        printf("5. strindex\n");
        printf("6. getop RPN calculator\n");
        printf("0. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Feature runs here\n");
        }

    } while (choice != 0);

    return 0;
}
