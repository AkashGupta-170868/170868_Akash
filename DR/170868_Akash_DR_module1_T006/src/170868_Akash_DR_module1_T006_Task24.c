#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

char stack[MAX];
int top = -1;

/* Stack operations */
void push(char c) {
    if (top < MAX - 1)
        stack[++top] = c;
}

char pop() {
    if (top >= 0)
        return stack[top--];
    return '\0';
}

char peek() {
    if (top >= 0)
        return stack[top];
    return '\0';
}

int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

int syntax_checker() {
    FILE *inputFile;
    char fileName[256];
    int c, next;
    int line = 1;
    int errorCount = 0;

    int inString = 0;
    int inChar = 0;
    int inSingleComment = 0;
    int inMultiComment = 0;

    printf("Enter C file name to check: ");
    fgets(fileName, sizeof(fileName), stdin);
    fileName[strcspn(fileName, "\n")] = '\0';

    inputFile = fopen(fileName, "r");
    if (!inputFile) {
        printf("Cannot open file.\n");
        return 1;
    }

    while ((c = fgetc(inputFile)) != EOF) {

        if (c == '\n')
            line++;

        /* Handle single-line comment */
        if (inSingleComment) {
            if (c == '\n')
                inSingleComment = 0;
            continue;
        }

        /* Handle multi-line comment */
        if (inMultiComment) {
            if (c == '*') {
                next = fgetc(inputFile);
                if (next == '/')
                    inMultiComment = 0;
                else
                    ungetc(next, inputFile);
            }
            continue;
        }

        /* Handle string */
        if (inString) {
            if (c == '\\')
                fgetc(inputFile);   // skip escaped char
            else if (c == '"')
                inString = 0;
            continue;
        }

        /* Handle char constant */
        if (inChar) {
            if (c == '\\')
                fgetc(inputFile);
            else if (c == '\'')
                inChar = 0;
            continue;
        }

        /* Detect start of comment */
        if (c == '/') {
            next = fgetc(inputFile);
            if (next == '/')
                inSingleComment = 1;
            else if (next == '*')
                inMultiComment = 1;
            else
                ungetc(next, inputFile);
            continue;
        }

        /* Detect start of string */
        if (c == '"') {
            inString = 1;
            continue;
        }

        /* Detect start of char constant */
        if (c == '\'') {
            inChar = 1;
            continue;
        }

        /* Check brackets */
        if (c == '(' || c == '{' || c == '[') {
            push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (top == -1) {
                printf("Error: Unmatched closing '%c' at line %d\n", c, line);
                errorCount++;
            }
            else {
                char open = pop();
                if (!isMatchingPair(open, c)) {
                    printf("Error: Mismatched '%c' and '%c' at line %d\n",
                           open, c, line);
                    errorCount++;
                }
            }
        }
    }

    /* Check for remaining unmatched opening brackets */
    while (top != -1) {
        printf("Error: Unmatched opening '%c'\n", pop());
        errorCount++;
    }

    if (errorCount == 0)
        printf("No syntax errors found (rudimentary check).\n");

    fclose(inputFile);
    return 0;
}
