
/*description :Write a program to compare two files, printing the first line where they differ. 
Author:Akash Gupta
created At:23-04-2026
modified at: 23-04-2026
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000
/*description :filecompare();it compare two files, printing the first line where they differ. 
Author:Akash Gupta
created At:24-04-2026
modified at: 24-04-2026
*/
int filecompare(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <file1.txt> <file2.txt>\n", argv[0]);
        return 1;
    }
    FILE *fp1 = fopen(argv[2], "r");
    FILE *fp2 = fopen(argv[3], "r");

    if (fp1 == NULL) {
        printf("Error: Cannot open file %s\n", argv[1]);
        return 1;
    }
    if (fp2 == NULL) {
        printf("Error: Cannot open file %s\n", argv[2]);
        fclose(fp1);
        return 1;
    }

    char line1[MAXLINE];
    char line2[MAXLINE];
    int line_index = 1;
    int differ = 0;
    while (1) {
       
        char *read1 = fgets(line1, MAXLINE, fp1);
        char *read2 = fgets(line2, MAXLINE, fp2);
        if (read1 == NULL && read2 == NULL) {
            break; 
        }

        if (read1 == NULL || read2 == NULL || strcmp(line1, line2) != 0) {
            printf("Files differ at line %d:\n", line_index);
            printf("File 1: %s", read1 != NULL ? line1 : "(End of file)\n");
            printf("File 2: %s", read2 != NULL ? line2 : "(End of file)\n");
            
            differ = 1;
            
            break;
        }
        
        line_index++;
    }

    if (differ == 0) {
        printf("Files are identical.\n");
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}
