/*description :Revise minprintf to handle more of the other facilities of printf
Author:Akash Gupta
created At:20-04-2026
modified at: 20-04-2026
*/
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

#define MAXLINE 100

void minscanf(char *fmt, ...);
/*description :scanf_main(); takes input from the user and pass to the function.
Author:Akash Gupta
created At:24-04-2026
modified at: 24-04-2026
*/
int scanf_main(void) {

    int i;
    printf("Enter integer: ");
    minscanf("%d", &i);
    printf("Integer: %d\n\n", i);

    unsigned int u;
    printf("Enter unsigned: ");
    minscanf("%u", &u);
    printf("Unsigned: %u\n\n", u);

    char c;
    printf("Enter character: ");
    minscanf("%c", &c);
    printf("Character: %c\n\n", c);

    char *str = malloc(MAXLINE);
    printf("Enter full line string: ");
    minscanf("%s", str);
    printf("String: %s\n\n", str);
    free(str);

    float f;
    printf("Enter float: ");
    minscanf("%f", &f);
    printf("Float: %f\n\n", f);

    int o;
    printf("Enter octal number: ");
    minscanf("%o", &o);
    printf("Octal: %o, Decimal: %d\n\n", o, o);

    int x;
    printf("Enter hex number: ");
    minscanf("%x", &x);
    printf("Hex: %x, Decimal: %d\n\n", x, x);


    return 0;
}
/*description :minscanf(); take multiple argument handled by varidic function and according to that pass to the switch case statement.
Author:Akash Gupta
created At:22-04-2026
modified at: 22-04-2026
*/
void minscanf(char *fmt, ...) {
    va_list ap;
    char *p;

    va_start(ap, fmt);

    for (p = fmt; *p; p++) {
        if (*p != '%')
            continue;

        switch (*++p) {

            case 'd': {
                int *ival = va_arg(ap, int *);
                scanf("%d", ival);
                break;
            }

            case 'u': {
                unsigned int *uval = va_arg(ap, unsigned int *);
                scanf("%u", uval);
                break;
            }

            case 'c': {
                char *cval = va_arg(ap, char *);
                scanf(" %c", cval);   // skip whitespace/newline
                break;
            }

            case 'f': {
                float *fval = va_arg(ap, float *);
                scanf("%f", fval);
                break;
            }

            case 's': {
                char *sval = va_arg(ap, char *);

                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF);

                fgets(sval, MAXLINE, stdin);
                for (int i = 0; sval[i] != '\0'; i++) {
                    if (sval[i] == '\n') {
                        sval[i] = '\0';
                        break;
                    }
                }
                break;
            }

            case 'o': {
                int *oval = va_arg(ap, int *);
                scanf("%o", oval);
                break;
            }

            case 'x': {
                int *xval = va_arg(ap, int *);
                scanf("%x", xval);
                break;
            }

            }
        }
  va_end(ap);
    }

