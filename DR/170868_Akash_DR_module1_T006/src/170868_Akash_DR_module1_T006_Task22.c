#include <stdio.h>

#define MAXLINE 1000
#define FOLD 20   // change this value to set column width

int fold_line() {
    char line[MAXLINE];
    int c;
    int pos = 0;
    int i, break_pos;

    while ((c = getchar()) != EOF) {

        line[pos++] = c;

        if (c == '\n') {
            for (i = 0; i < pos; i++)
                putchar(line[i]);
            pos = 0;
        }
        else if (pos >= FOLD) {

            // find last blank before FOLD
            break_pos = -1;
            for (i = pos - 1; i >= 0; i--) {
                if (line[i] == ' ' || line[i] == '\t') {
                    break_pos = i;
                    break;
                }
            }

            if (break_pos >= 0) {
                // print up to break position
                for (i = 0; i < break_pos; i++)
                    putchar(line[i]);
                putchar('\n');

                // shift remaining characters
                pos = pos - break_pos - 1;
                for (i = 0; i < pos; i++)
                    line[i] = line[break_pos + 1 + i];
            }
            else {
                // no blank found, force break
                for (i = 0; i < pos; i++)
                    putchar(line[i]);
                putchar('\n');
                pos = 0;
            }
        }
    }

    return 0;
}

