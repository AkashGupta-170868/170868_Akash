#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int remove_comments() {
    FILE *inputFile, *outputFile;
    char inputFileName[256];
    char outputFileName[256];
    int currentChar, nextChar;

    /* Take input file name */
    printf("Enter input C file name: ");
    fgets(inputFileName, sizeof(inputFileName), stdin);
    inputFileName[strcspn(inputFileName, "\n")] = '\0';   // remove newline

    /* Take output file name */
    printf("Enter output file name: ");
    fgets(outputFileName, sizeof(outputFileName), stdin);
    outputFileName[strcspn(outputFileName, "\n")] = '\0';  // remove newline

    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error: Cannot open input file.\n");
        return 1;
    }

    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error: Cannot open output file.\n");
        fclose(inputFile);
        return 1;
    }

    while ((currentChar = fgetc(inputFile)) != EOF) {

        /* Handle string literals */
        if (currentChar == '"') {
            fputc(currentChar, outputFile);

            while ((currentChar = fgetc(inputFile)) != EOF) {
                fputc(currentChar, outputFile);

                if (currentChar == '\\') {   // escape sequence
                    currentChar = fgetc(inputFile);
                    fputc(currentChar, outputFile);
                }
                else if (currentChar == '"')
                    break;
            }
        }

        /* Handle character constants */
        else if (currentChar == '\'') {
            fputc(currentChar, outputFile);

            while ((currentChar = fgetc(inputFile)) != EOF) {
                fputc(currentChar, outputFile);

                if (currentChar == '\\') {
                    currentChar = fgetc(inputFile);
                    fputc(currentChar, outputFile);
                }
                else if (currentChar == '\'')
                    break;
            }
        }

        /* Handle comments */
        else if (currentChar == '/') {
            nextChar = fgetc(inputFile);

            /* Single-line comment */
            if (nextChar == '/') {
                while ((currentChar = fgetc(inputFile)) != EOF && currentChar != '\n');
                if (currentChar == '\n')
                    fputc('\n', outputFile);
            }

            /* Multi-line comment */
            else if (nextChar == '*') {
                while ((currentChar = fgetc(inputFile)) != EOF) {
                    if (currentChar == '*') {
                        nextChar = fgetc(inputFile);
                        if (nextChar == '/')
                            break;
                        else
                            ungetc(nextChar, inputFile);
                    }
                }
            }

            /* Not a comment */
            else {
                fputc(currentChar, outputFile);
                ungetc(nextChar, inputFile);
            }
        }

        /* Normal characters */
        else {
            fputc(currentChar, outputFile);
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Comments removed successfully.\n");
    return 0;
}
