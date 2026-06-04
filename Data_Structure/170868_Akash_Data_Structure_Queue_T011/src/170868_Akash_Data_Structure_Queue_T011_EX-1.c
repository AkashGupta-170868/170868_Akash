/*
description : A palindrome is a string that reads the same backward as forward, e.g. "ABCBA" or "Madam, I'm Adam". Your application will read strings from the user, and for each string the user inputs, it should print a message indicating to the user whether or not the string is a palindrome. 
author      : akash Gupta
created at  : 18-05-2026
 */

#include <stdio.h>
#include <stdint.h>
#include "header.h"
#include <ctype.h>

/*
   function name : is_palindrome();
description : checks is string is palindrome or not ?
author      : akash Gupta
created at  : 18-05-2026
 */
char str[1000];

void is_palindrome()
{
	struct queue *Q = createQueue();
	int32_t idx = 0;
	int32_t ch;

	printf("Enter a string: ");

	while ((ch = getchar()) != '\n') {
		if (isalpha(ch)) {
			ch = tolower(ch);
			enQueue(Q, ch);
			str[idx++] = ch;
		}
	}
	str[idx] = '\0';
	displayQueue(Q);
	printf("\n");
	int32_t start = 0;
	int32_t end = idx - 1;

	while (start < end) {
		if (str[start] != str[end]) {
			printf("Not Palindrome\n");
			return;
		}
		start++;
		end--;
	}

	printf(" Palindrome\n");
}
