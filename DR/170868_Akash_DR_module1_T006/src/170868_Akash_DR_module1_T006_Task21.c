#include <stdio.h>

#define TABWIDTH 8

int entab() {
    int c;
    int space_count = 0;

    while ((c = getchar()) != EOF) {

        if (c == ' ') {
            space_count++;

            if (space_count == TABWIDTH) {
                printf("\t");   
                space_count = 0;
            }
        }

	putchar(c);

    }

    return 0;
}

