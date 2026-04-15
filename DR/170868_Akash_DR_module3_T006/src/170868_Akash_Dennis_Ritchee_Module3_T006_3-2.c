/*
 * Descriptions:Write a function escape(s,t) that converts characters like newline and tab into
visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a
function for the other direction as well, converting escape sequences into the real characters
 * Author : Akash Gupta
 * Created at : 24-02-2026
 * Modified at : 24-02-2026
 */

#include <stdio.h>

#define MAXLINE 1000

void escape(char after_escape[], char before_escape[]);

int escape_t(void)
{
    char before_escape[MAXLINE], after_escape[MAXLINE];
    int index = 0, charcter;

    // Take input using while loop
    while (index < MAXLINE - 1 && (charcter = getchar()) != EOF)
    {
        before_escape[index] = charcter;
        index++;
    }
    before_escape[index] = '\0';

    escape(after_escape, before_escape);

    printf("%s", after_escape);

    return 0;
}

void escape(char after_escape[], char before_escape[])
{
    int i_index = 0, j_index = 0;

    while (before_escape[i_index] != '\0')
    {
        switch (before_escape[i_index])
        {
            case '\t':
                after_escape[j_index++] = '\\';
                after_escape[j_index] = 't';
                break;

            case '\n':
                after_escape[j_index++] = '\\';
                after_escape[j_index] = 'n';
                break;

            default:
                after_escape[j_index] = before_escape[i_index];
                break;
        }
        i_index++;
        j_index++;
    }

    after_escape[j_index] = '\0';
}
