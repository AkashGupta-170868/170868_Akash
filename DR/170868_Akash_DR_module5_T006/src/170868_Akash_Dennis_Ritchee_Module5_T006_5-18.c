/*
 * Advanced dcl parser
 * Supports:
 *  - pointers
 *  - arrays
 *  - functions with parameters
 *  - multiple declarations
 *  - comments (//)
 *  - error handling & recovery
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100
#define NAME 1
#define PARENS 2
#define BRACKETS 3

int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];

int error = 0;

/* stack */
#define STACKSIZE 100
char input_stack[STACKSIZE];
int stack_top = 0;

/* function declarations */
int gettoken(void);
void dcl(void);
void dirdcl(void);
void recover(void);
int getch(void);
void ungetch(int);

int calling()
{
    while (1) {
        printf("\nEnter declaration: ");

        if (gettoken() == EOF)
            break;

        strcpy(datatype, token);

        do {
            error = 0;
            strcpy(out, "");
            strcpy(name, "");

            dcl();

            if (!error)
                printf("%s: %s %s\n", name, out, datatype);
            else {
                printf("Invalid declaration. Skipping...\n");
                recover();
                break;
            }

        } while (tokentype == ',');

        if (tokentype != '\n')
            recover();
    }

    return 0;
}

void dcl(void)
{
    int ns = 0;

    while (gettoken() == '*')
        ns++;

    dirdcl();

    while (ns-- > 0)
        strcat(out, " pointer to");
}

void dirdcl(void)
{
    int type;

    if (tokentype == '(') {
        dcl();
        if (tokentype != ')') {
            printf("Error: missing ')'\n");
            error = 1;
            return;
        }
    }
    else if (tokentype == NAME) {
        strcpy(name, token);
    }
    else {
        printf("Error: expected name or (dcl)\n");
        error = 1;
        return;
    }

    while ((type = gettoken()) == PARENS || type == BRACKETS || type == '(') {

        if (type == PARENS) {
            strcat(out, " function returning");
        }
        else if (type == BRACKETS) {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
        else if (type == '(') {
            strcat(out, " function taking ");

            /* collect parameters */
            while ((type = gettoken()) != ')') {
                if (type == EOF || type == '\n') {
                    printf("Error: missing ')' in function\n");
                    error = 1;
                    return;
                }
                strcat(out, token);
                strcat(out, " ");
            }

            strcat(out, "returning");
        }
    }

    if (type != '\n' && type != EOF && type != ',' && type != ')') {
        printf("Error: unexpected token '%s'\n", token);
        error = 1;
    }

    tokentype = type;
}

int gettoken(void)
{
    int c;
    char *p = token;

    while ((c = getch()) == ' ' || c == '\t')
        ;

    /* Handle comments */
    if (c == '/') {
        if ((c = getch()) == '/') {
            while ((c = getch()) != '\n' && c != EOF)
                ;
            return tokentype = '\n';
        } else {
            ungetch(c);
            return tokentype = '/';
        }
    }

    if (c == '(') {
        if ((c = getch()) == ')') {
            strcpy(token, "()");
            return tokentype = PARENS;
        } else {
            ungetch(c);
            token[0] = '(';
            token[1] = '\0';
            return tokentype = '(';
        }
    }
    else if (c == '[') {
        *p++ = c;
        while ((*p++ = getch()) != ']')
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    }
    else if (isalpha(c)) {
        *p++ = c;
        while (isalnum(c = getch()))
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    }
    else {
        token[0] = c;
        token[1] = '\0';
        return tokentype = c;
    }
}

int getch(void);

void ungetch(int c);

void recover(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}
