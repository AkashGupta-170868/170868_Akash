#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*
 * Function Name: mycalloc()
 * Function Description: memory intialized using malloc and set to zero
 * Author: Akash Gupta
 * Created: 30 April, 2026
 */
void *mycalloc(unsigned num, unsigned size)
{
	unsigned idx;
	char *mem;

	mem = (char *)malloc(num * size);

	if (mem == NULL)
		return NULL;

	for (idx = 0; idx < num * size; idx++)
		mem[idx] = 0;

	return mem;
}
/*
 * Function Name: calloc_main()
 * Function Description: take input from user and print conent in hex.
 * Author: Akash Gupta
 * Created: 30 April, 2026
 */
int32_t calloc_main()
{
	unsigned num, size, idx;
	unsigned char *ptr;

	printf("Enter the number of elements: ");
	scanf("%u", &num);

	printf("Enter the size of each element (in bytes): ");
	scanf("%u", &size);

	if (num == 0 || size == 0)
	{
		printf("Invalid input. Please enter a positive integer.\n");
		return 1;
	}

	ptr = (unsigned char *)mycalloc(num, size);

	if (ptr == NULL)
	{
		printf("Memory allocation failed.\n");
		return 1;
	}

	printf("\nMemory allocated and initialized to zero.\n");
	printf("Memory content (in hexadecimal):\n");

	for (idx = 0; idx < num * size; idx++)
	{
		printf("%02X ", ptr[idx]);

		if ((idx + 1) % size == 0)
			printf(" ");
	}

	printf("\n\nFreeing memory...\n");

	free(ptr);

	return 0;
}
