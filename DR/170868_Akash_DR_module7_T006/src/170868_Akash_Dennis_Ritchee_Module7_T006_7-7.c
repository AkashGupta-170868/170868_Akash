/*  Description : Modify the pattern finding program of Chapter 5 to take its input from a set of
    named files or, if no files are named as arguments, from the standard input. Should the file
    name be printed when a matching line is found? 
Author: Akash Gupta
Modified At : 14-04-2026
Created At : 14-04-2026
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000 

/*description :search_pattern();
Author:Akash Gupta
created At:24-04-2026
modified at: 24-04-2026
 */
int searchPattern(FILE *fp, const char *sourceName, const char *pattern) {
	char line[MAXLINE];
	int line_number = 0;
	int found = 0;

	while (fgets(line, MAXLINE, fp) != NULL) {
		line_number++;

		if (strstr(line, pattern) != NULL) {
			printf("%s:%d:%s", sourceName, line_number, line);
			found++;
		}
	}

	return found;
}
/*description :search_main(); function that handle cli argument and pass argument to the printFile function
Author:Akash Gupta
created At:24-04-2026
modified at: 24-04-2026
 */
int search_main(int argc, char *argv[]) {
	int total_found = 0;

	if (argc < 2) {
		fprintf(stderr, "Usage: %s pattern [file ...]\n", argv[0]);
		return 1;
	}

	char *pattern = argv[1];

	if (argc == 2) {
		total_found = searchPattern(stdin, "stdin", pattern);
	} 
	else {
		for (int i = 2; i < argc; i++) {
			FILE *fp = fopen(argv[i], "r");

			if (fp == NULL) {
				fprintf(stderr, "Error: Cannot open file '%s'\n", argv[i]);
				continue;
			}

			total_found += searchPattern(fp, argv[i], pattern);

			fclose(fp);
		}
	}

	return total_found > 0 ? 0 : 1;
}
