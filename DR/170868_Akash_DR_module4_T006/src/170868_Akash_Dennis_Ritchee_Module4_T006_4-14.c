/*
 * Descriptions:Define a macro swap(t,x,y) that interchanges two arguments of type t.
 * Author : Akash Gupta
 * Created at : 07-03-2026
 * Modified at : 07-03-2026
 */
#include <stdio.h>
#include <stdint.h>

#define SWAP(type, a, b) \
{ \
	type temp; \
	temp = a; \
	a = b; \
	b = temp; \
}

int macro_swap(void)
{
	char x, y;

	printf("Enter first character: ");
	scanf(" %c", &x);

	printf("Enter second character: ");
	scanf(" %c", &y);

	printf("\nBefore swap: x = %c , y = %c\n", x, y);

	SWAP(char, x, y);

	printf("After swap:  x = %c , y = %c\n", x, y);

	return 0;
}
