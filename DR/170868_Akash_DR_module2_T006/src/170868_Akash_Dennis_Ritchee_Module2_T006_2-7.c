/*
 * Descriptions:Write a function invert(x,p,n) that returns x with the n bits that begin at position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged. 
 * Author : Akash Gupta
 * Created at : 23-02-2026
 * Modified at : 23-02-2026
 */

#include <stdio.h>
#include <stdint.h>

int16_t invert(int16_t x, int16_t p, int16_t n)
{
	int16_t mask = ((1 << n) - 1) << (p - n + 1);
	return x ^ mask;
}

int16_t invert_t()
{
	int16_t x, p, n;
	char choice;

	while (1)
	{
		while (1)
		{
			printf("Enter positive value of x: ");
			scanf("%hhd", &x);

			if (x >= 0)
				break;

			printf("Invalid input! x must be positive.\n");
		}
		while (1)
		{
			printf("Enter position p: ");
			scanf("%hhd", &p);

			if (p >= 0)
				break;

			printf("Invalid input! p must be >= 0.\n");
		}

		while (1)
		{
			printf("Enter number of bits n: ");
			scanf("%hhd", &n);

			if (n > 0 && n <= p + 1)
				break;

			printf("invalid input! n must be > 0 and <= p + 1\n");
		}

		int16_t result = invert(x, p, n);
		printf("result after invert = %d\n", result);

		printf("\nDo you want to continue? (y/n): ");
		scanf(" %c", &choice);

		if (choice == 'n' || choice == 'N')
		{
			printf("Program ends here.\n");
			break;
		}
	}

	return 0;
}
