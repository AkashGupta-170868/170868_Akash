/*
 * Descriptions:  As written, getint treats a + or - not followed by a digit as a valid representation of zero. Fix it to push such a character back on the input. 
 
 * Author : Akash Gupta
 * Created at : 27-03-2026
 * Modified at : 27-03-2026
 */

#include <stdio.h>
#include <ctype.h>
#include <stdint.h>   

#define size 100
char buffer[size];
int32_t idx = 0;


/*
 * function name : getch();
 * Descriptions: it is a function used to read one character at a time from input
 * 
 Author : Akash Gupta
 * Created at : 27-03-2026
 * Modified at : 27-03-2026
 */
int32_t getch(void) {
    return (idx > 0) ? buffer[--idx] : getchar();
}
/*
 * function name : ungetch();                                      * Descriptions: It stores the character in a buffer
 *
  Author : Akash Gupta
 * Created at : 27-03-2026
 * Modified at : 27-03-2026
 */
void ungetch(int32_t num) {
    if (idx < size) {
        buffer[idx++] = num;
    } else {
        printf("stack is overflow\n");
    }
}

/*
 * function name : getint();                                      * Descriptions: convert into integer and return it else zero*
 Author : Akash Gupta
 * Created at : 27-03-2026
 * Modified at : 27-03-2026
 */
int32_t getint(int32_t *pnum) {
    int32_t c;

    while (isspace(c = getch()))
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    int32_t sign = (c == '-') ? -1 : 1;

    // Check next character after sign
    if (c == '+' || c == '-') {
        int32_t next = getch();

        if (!isdigit(next)) {
            ungetch(next);
            ungetch(c);
            return 0;
        }

        c = next;
    }

    for (*pnum = 0; isdigit(c); c = getch()) {
        *pnum = 10 * (*pnum) + (c - '0');
    }

    *pnum = (*pnum) * sign;

    if (c != EOF) {
        ungetch(c);
    }

    return c;
}

int test_dr51() {
    int32_t n, status;

    printf("Enter input: ");

    status = getint(&n);

    if (status == 0) {
        printf("Not a valid number\n");
    } else {
        printf("Number = %d\n", n);
    }

    return 0;
}
