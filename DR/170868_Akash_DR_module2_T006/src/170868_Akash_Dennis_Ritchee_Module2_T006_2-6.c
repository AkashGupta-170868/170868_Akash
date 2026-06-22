/*
 * Descriptions:Write a function setbits(x,p,n,y) that returns x with the n bits that begin at position p set to the rightmost n bits of y, leaving the other bits unchanged.
 * Author : Akash Gupta
 * Created at : 23-02-2026
 * Modified at : 23-02-2026
 */

#include <stdio.h>
#include <stdint.h>

uint32_t setbits(uint32_t x, int32_t p, int32_t n, uint32_t y)
{
	uint32_t right_bits;
	uint32_t mask;


	// Step 1: Extract rightmost n bits of y
	right_bits = y & ((1U << n) - 1U);

	// Step 2: Shift them to position p
	right_bits <<= (p - n + 1);

	// Step 3: Create mask to clear n bits in x
	mask = ~(((1U << n) - 1U) << (p - n + 1));

	// Step 4: Clear bits and insert new bits
	return (x & mask) | right_bits;
}

int setbits_t()
{
	uint32_t x, y;
	int32_t p, n;

	printf("Enter x: ");
	scanf("%u", &x);

	printf("Enter p: ");
	scanf("%d", &p);

	printf("Enter n: ");
	scanf("%d", &n);

	printf("Enter y: ");
	scanf("%u", &y);

	uint32_t result = setbits(x, p, n, y);

	printf("Result = %u\n", result);

	return 0;
}
