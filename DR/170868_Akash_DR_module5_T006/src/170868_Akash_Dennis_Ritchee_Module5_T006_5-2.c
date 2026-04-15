/*
 * Descriptions:  Write getfloat, the floating-point analog of getint. What type does getfloat return as its function value? 
 * Author : Akash Gupta
 * Created at : 27-03-2026
 * Modified at : 27-03-2026
 */

#include <stdio.h>
#include <ctype.h>
#include <stdint.h>   

int32_t getch(void);
void ungetch(int32_t);

/*
  function name : getfloat();
 * Descriptions:getfloat returns int because it returns status/character, not the float value.
The floating-point number is returned through the pointer argument.
 * Author : Akash Gupta
 * Created at : 27-03-2026
 * Modified at : 27-03-2026
 */


int32_t getfloat(float *pn) {
    int32_t c, sign;
    float power = 1.0f; 

    // Skip whitespace
    while (isspace(c = getch()))
        ;

    // Check valid input
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    // Handle sign
    if (c == '+' || c == '-') {
        c = getch();
    }

    // Integer part
    for (*pn = 0.0f; isdigit(c); c = getch())
        *pn = 10.0f * (*pn) + (c - '0');

    // Fractional part
    if (c == '.') {
        c = getch();
        for (power = 1.0f; isdigit(c); c = getch()) {
            *pn = 10.0f * (*pn) + (c - '0');
            power *= 10.0f;
        }
    }

    *pn = sign * (*pn) / power;

    if (c != EOF)
        ungetch(c);

    return c;
}


int test_dr52() {
    float num;
    int32_t status;

    printf("Enter a float: ");

    status = getfloat(&num);

    if (status == 0) {
        printf("Not a valid number\n");
    } else {
        printf("Float value = %.2f\n", num);
    }

    return 0;
}
