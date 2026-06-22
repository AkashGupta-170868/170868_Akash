
/*description :Write a program that will print arbitrary input in a sensible way. As a minimum,
               it should print non-graphic characters in octal or hexadecimal according to local custom, and
               break long text lines
Author:Akash Gupta
created At:20-04-2026
modified at: 20-04-2026
*/
#include <stdio.h>
#include <ctype.h>
#include <stdint.h>

#define MAXLINE 80
#define HEXLEN 4

/* Function to handle line wrapping */
int inc(int pos, int n) {
    if (pos + n >= MAXLINE) {
        putchar('\n');
        return n;
    } else {
        return pos + n;
    }
}
/*description :nongraphical_main();
Author:Akash Gupta
created At:20-04-2026
modified at: 20-04-2026
*/
int nongraphical_main() {
    char buffer[MAXLINE + 1];
    int pos;

    while (1) {
        printf("Enter text (press Enter to print, or Ctrl+D/Ctrl+Z to exit):\n");

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            break;
        }

        printf("Output:\n");

        pos = 0;

        for (int i = 0; buffer[i] != '\0'; i++) {
            unsigned char c = buffer[i];

            if (!isprint(c)) {

                pos = inc(pos, HEXLEN + 7);

                printf("[%02x]", c);

                if (c == '\n') {
                    pos = 0;
                }

            } else {

                pos = inc(pos, 1);

                putchar(c);
            }
        }

        printf("\n\n");
    }

    return 0;
}
