#include <stdio.h>
#include <ctype.h>
/*description :lower(); converts input to the lower case.
Author:Akash Gupta
created At:21-04-2026
modified at: 21-04-2026
*/
void Lower(int argc, char *argv[]) {
    int c;
    (void)argc; 
    (void)argv;

    while ((c = getchar()) != EOF) {
        putchar(tolower(c));
    }
}
/*description :lower(); converts input to the upper case.
Author:Akash Gupta
created At:21-04-2026
modified at: 21-04-2026
*/
void upper(int argc, char *argv[]) {
    int c;
    (void)argc; 
    (void)argv;

    while ((c = getchar()) != EOF) {
        putchar(toupper(c));
    }
}
