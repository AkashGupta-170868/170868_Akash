/*
 * Descriptions: Modify the program entab and detab (written as exercises in Chapter 1) to
 accept a list of tab stops as arguments. Use the default tab settings if there are no arguments. 
 * Author : Akash Gupta
 * Created at : 03-04-2026
 * Modified at : 03-04-2026
 */

/* function name : detabSpaces();
 * Descriptions: this function takes command line argument like de and threshold value 2 then convert tap to 2 space.
 * Author : Akash Gupta
 * Created at : 03-04-2026
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ENTAB FUNCTION
void entabCLI(int argc, char *argv[])
{
    int ch;
    int column = 0;
    int spaces = 0;

    int tabstop = 8;

    if (argc >= 3) {
        tabstop = atoi(argv[2]);
        if (tabstop <= 0) tabstop = 8;
    }

    printf("TABSTOP = %d\n", tabstop);
    printf("Enter text (CTRL+D to exit): ");
    fflush(stdout);

    while ((ch = getchar()) != EOF) {

        if (ch == ' ') {
            spaces++;
        } else {

            while (spaces > 0) {
                int toTab = tabstop - (column % tabstop);

                if (spaces >= toTab) {
                    printf("\t");   // REAL TAB
                    column += toTab;
                    spaces -= toTab;
                } else {
                    putchar(' ');
                    column++;
                    spaces--;
                }
            }

            if (ch == '\t') {
                printf("\t");
                column += tabstop - (column % tabstop);
            }
            else if (ch == '\n') {
                putchar('\n');
                column = 0;
                printf("Enter text (CTRL+D to exit): ");
                fflush(stdout);
            }
            else {
                putchar(ch);
                column++;
            }
        }
    }
}

// DETAB FUNCTION
void detabCLI(int argc, char *argv[])
{
    int ch;
    int column = 0;

    int tabstop = 8;

    if (argc >= 3) {
        tabstop = atoi(argv[2]);
        if (tabstop <= 0) tabstop = 8;
    }

    printf("TABSTOP = %d\n", tabstop);
    printf("Enter text (CTRL+D to exit): ");
    fflush(stdout);

    while ((ch = getchar()) != EOF) {

        if (ch == '\t') {
            int spaces = tabstop - (column % tabstop);

            for (int i = 0; i < spaces; i++) {
                putchar('*');   // or ' ' if required
            }
            column += spaces;
        }
        else if (ch == '\n') {
            putchar('\n');
            column = 0;
            printf("Enter text (CTRL+D to exit): ");
            fflush(stdout);
        }
        else {
            putchar(ch);
            column++;
        }
    }
}


int ende_test(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: ./a.out en/de [tabstop]\n");
        return 1;
    }

    if (strcmp(argv[1], "en") == 0) {
        entabCLI(argc, argv);
    }
    else if (strcmp(argv[1], "de") == 0) {
        detabCLI(argc, argv);
    }
    else {
        printf("Invalid option. Use 'en' or 'de'\n");
    }

    return 0;
}
