
/*description :Write a program to print a set of files, starting each new one on a new page, with a title and a running page count for each file. 
Author:Akash Gupta
created At:24-04-2026
modified at: 24-04-2026
 */
#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000
#define DEFAULT_PAGELEN 15

void printFile(const char *filename, int pageLen);
/*description :print_main(); function that handle cli argument and pass argument to the printFile function
Author:Akash Gupta
created At:24-04-2026
modified at: 24-04-2026
 */
int print_main(int argc, char *argv[]) {
	int i;
	int pageLen = DEFAULT_PAGELEN;

	if (argc < 3) {
		fprintf(stderr, "Usage: %s file1 file2 ...\n", argv[0]);
		exit(1);
	}

	for (i = 2; i < argc; i++) {
		printFile(argv[i], pageLen);
	}

	return 0;
}
/*description :printFile(); function that take filename and its lenthpage as a argument and print content of file till the pagelen not occurs .
Author:Akash Gupta
created At:24-04-2026
modified at: 24-04-2026
 */
void printFile(const char *filename, int pageLen) {
	FILE *fp;
	char line[MAXLINE];
	int lineCount = 0;
	int pageCount = 1;
	int c;

	if ((fp = fopen(filename, "r")) == NULL) {
		fprintf(stderr, "Error: can't open %s\n", filename);
		return;
	}
	printf("\f");

	printf("Title: %s\n\n", filename);

	while (fgets(line, MAXLINE, fp) != NULL) {
		printf("%s", line);
		lineCount++;

		if (lineCount == pageLen) {
			printf("\n--------------- Page %d ---------------\n", pageCount++);
			printf("\n-------------------- linecount %d --------------\n",lineCount);
			printf("\nPress Enter to continue to the next page...");
			while ((c = getchar()) != '\n' && c != EOF)
				;

			lineCount = 0;
		}
	}

	/* Last page (if not full) */
	if (lineCount > 0) {
		printf("\n--------------- Page %d ---------------\n", pageCount);
	}

	printf("\nEnd of File\n");

	fclose(fp);
}
