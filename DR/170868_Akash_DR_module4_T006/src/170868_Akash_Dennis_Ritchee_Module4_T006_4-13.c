/*
 * Descriptions:Write a recursive version of the function reverse(s), which reverses the
 string s in place. 
 * Author : Akash Gupta
 * Created at : 07-03-2026
 * Modified at : 07-03-2026
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>

void reverse(char s[], int32_t start, int32_t end);

int reverse_rec()
{
	char s[100];

	printf("Enter a string: ");
	fgets(s, sizeof(s), stdin);

	reverse_recursive(s, 0, strlen(s) - 1);

	printf("Reversed string: %s", s);

	return 0;
}

/* function name : reverse_recursive
Author : Akash Gupta
created at : 09-03-2026
modified at : 09-03-2026
 */

void reverse_recursive(char s[], int32_t start, int32_t end)
{
	char temp;

	if(start >= end)
		return;

	temp = s[start];
	s[start] = s[end];
	s[end] = temp;

	reverse_recursive(s, start + 1, end - 1);
}
