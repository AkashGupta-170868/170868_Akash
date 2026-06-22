/*
 * Descriptions:Write an alternative version of squeeze(s1,s2) that deletes each character in s1 that matches any character in the string s2. 
 * Author : Akash Gupta
 * Created at : 21-02-2026
 * Modified at : 21-02-2026
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
void deletec() {
	char s1[100] ;
	char s2[100] ;
	int8_t i, j;
	printf("enter the first string\n");
	if (fgets(s1, sizeof(s1), stdin) == NULL) {
		printf("Error reading first string.\n");
		return 1;
	}
	printf("enter the second string\n");
	if (fgets(s2, sizeof(s2), stdin) == NULL) {
		printf("Error reading first string.\n");
		return 1;
	}

	for (i = 0; s1[i] != '\0'; i++) {
		for (j = 0; s2[j] != '\0'; j++) {
			if (tolower(s1[i]) == tolower(s2[j])) {

				s1[i] = '_';
				s2[j] = '_';
				break;
			}
		}
	}

	printf("After deletion('_' indicates same char occurs ):\n");
	printf("s1: %s\n", s1);
	printf("s2: %s\n", s2);
}

