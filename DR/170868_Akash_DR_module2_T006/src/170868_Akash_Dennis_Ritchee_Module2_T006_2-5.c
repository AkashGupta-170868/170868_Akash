/*
Descripton:Write the function any(s1,s2), which returns the first location in a string s1 where any character from the string s2 occurs, or -1 if s1 contains no characters from s2. (The standard library function strpbrk does the same job but returns a pointer to the location.) 
Author : Akash Gupta
Created At: 
Modified At: 
 */
#include <stdio.h>
#include<stdint.h>

/*Function name: any();
Descripton: find first occurrence in s1 of any character from s2
Author : Akash Gupta
Created At:
 */
int32_t any(char s1[], char s2[]) {
	int32_t i, j;

	for(i = 0; s1[i] != '\0'; i++) {
		for(j = 0; s2[j] != '\0'; j++) {
			if(s1[i] == s2[j]) {
				return i;   
			}
		}
	}

	return -1;   
}
/*Function name: check_duplicate();
Descripton: input two strings and check for first matching character.
Author : Akash Gupta
Created At: 
 */
int32_t check_duplicate() {
	char s1[100], s2[100];
	int32_t result;

	printf("Enter first string: ");
	scanf("%s", s1);

	printf("Enter second string: ");
	scanf("%s", s2);

	result = any(s1, s2);

	if(result != -1)
		printf("First matching character found at position %d\n", result);
	else
		printf("No matching character found\n");

	return 0;
}

