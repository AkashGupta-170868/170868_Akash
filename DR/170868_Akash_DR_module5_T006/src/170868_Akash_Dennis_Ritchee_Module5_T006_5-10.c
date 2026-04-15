/*
 * Descriptions:Write the program expr, which evaluates a reverse Polish expression from the
command line, where each operator or operand is a separate argument
 * Author : Akash Gupta
 * Created at : 03-04-2026
 * Modified at : 03-04-2026
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/header.h"

#define MAXSTACK 100

static int stack[MAXSTACK];
static int sp = 0;
/* function name : stack_push();
 * Descriptions: push element into stack.
 * Author : Akash Gupta
 * Created at : 03-04-2026*/
static void stack_push(int val) {
    if (sp < MAXSTACK)
        stack[sp++] = val;
    else {
        printf("Error: Stack full\n");
        exit(1);
    }
}
/* function name : stack_pop();
 * Descriptions: pop the element from stack.
 * Author : Akash Gupta
 * Created at : 03-04-2026*/
static int stack_pop() {
    if (sp > 0)
        return stack[--sp];
    else {
        printf("Error: Stack empty\n");
        exit(1);
    }
}
/* function name : is_number();
 * Descriptions: get the line input by user till Eof and \n
 * Author : Akash Gupta
 * Created at : 03-04-2026*/
static int is_number(char *s) {
    if (*s == '-' || *s == '+') s++;
    if (*s == '\0') return 0;

    while (*s) {
        if (!isdigit(*s)) return 0;
        s++;
    }
    return 1;
}
/* function name : expr();
 * Descriptions: evalute the expression taken by the command line argument .
 * Author : Akash Gupta
 * Created at : 03-04-2026*/
void expr(int argc, char *argv[]) {
    int op2;

    for (int i = 2; i < argc; i++) {
        if (is_number(argv[i])) {
            stack_push(atoi(argv[i]));
        } else if (strlen(argv[i]) == 1) {
            switch (argv[i][0]) {

                case '+':
                    stack_push(stack_pop() + stack_pop());
                    break;

                case '*':
                    stack_push(stack_pop() * stack_pop());
                    break;

                case '-':
                    op2 = stack_pop();
                    stack_push(stack_pop() - op2);
                    break;

                case '/':
                    op2 = stack_pop();
                    if (op2 != 0)
                        stack_push(stack_pop() / op2);
                    else {
                        printf("Error: Division by zero\n");
                        return;
                    }
                    break;

                default:
                    printf("Error: Unknown operator %s\n", argv[i]);
                    return;
            }
        } else {
            printf("Error: Invalid input %s\n", argv[i]);
            return;
        }
    }

    if (sp == 1)
        printf("Result = %d\n", stack_pop());
    else
        printf("Error: Invalid expression\n");
}
