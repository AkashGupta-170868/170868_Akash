/*
 * Descriptions:Extend entab and detab to accept the shorthand
 entab -m +n
to mean tab stops every n columns, starting at column m. Choose convenient (for the user)
default behavior.
 * Author : Akash Gupta
 * Created at : 06-04-2026
 * Modified at : 06-04-2026
 */

#include <stdio.h>
#include <stdlib.h>
/*
 * function name : test_entab();
 * Descriptions: it is a function used to read one character at a time from input
 *
 Author : Akash Gupta
 * Created at : 06-04-2026
 */
void test_entab(int argc, char *argv[]) {
    int m = 1;   // default starting column
    int n = 8;   // default interval

    // Parse CLI arguments
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            m = atoi(&argv[i][1]);
        } else if (argv[i][0] == '+') {
            n = atoi(&argv[i][1]);
        }
    }

    int c;
    int col = 1;        // current column
    int space_count = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            space_count++;
            col++;

            // Check tab stop
            if (col >= m && ((col - m) % n == 0)) {
                putchar('#');   // 👈 replaced \t with '#'
                space_count = 0;
            }
        } 
        else {
            // Print remaining spaces
            while (space_count > 0) {
                putchar(' ');
                space_count--;
            }

            putchar(c);

            if (c == '\n') {
                col = 1;
            } else {
                col++;
            }
        }
    }

}

/*
 * function name : test_detab();
 * Descriptions: it is a function used to read one character at a time from input
 *
 Author : Akash Gupta
 * Created at : 06-04-2026
 */

#include <stdio.h>
#include <stdlib.h>

void test_detab(int argc, char *argv[]) {
    int m = 1;   // default starting column
    int n = 8;   // default interval

    // Parse CLI arguments
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            m = atoi(&argv[i][1]);
        } else if (argv[i][0] == '+') {
            n = atoi(&argv[i][1]);
        }
    }

    int c;
    int col = 1;   // current column

    while ((c = getchar()) != EOF) {

        if (c == '\t') {
            int spaces;

            if (col < m) {
                spaces = m - col;  // reach starting column
            } else {
                spaces = n - ((col - m) % n);
            }

            for (int i = 0; i < spaces; i++) {
                putchar(' ');
                col++;
            }
        }
        else {
            putchar(c);

            if (c == '\n') {
                col = 1;
            } else {
                col++;
            }
        }
    }
}
