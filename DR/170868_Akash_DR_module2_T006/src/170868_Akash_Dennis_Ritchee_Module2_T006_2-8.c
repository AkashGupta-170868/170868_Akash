/*
 * Descriptions:Write a function rightrot(x,n) that returns the value of the integer x rotated to the right by n positions.
 * Author : Akash Gupta
 * Created at : 23-02-2026
 * Modified at : 23-02-2026
 */

#include <stdio.h>
#include <stdint.h>
unsigned rightRotate(unsigned number, int32_t rotateCount)
{
	int32_t totalBits = sizeof(unsigned) * 8;
	rotateCount %= totalBits;

	return (number >> rotateCount) |
		(number << (totalBits - rotateCount));
}

int32_t rightRotate_t(void)
{
	printf("%u", rightRotate(8u, 1));
	return 0;
}
