/*
 * Description:
 * Program to demonstrate single-character pushback using
 * modifiedgetch() and modifiedungetch().
 * It prints the first character of each input line until EOF.
 *
 * Author: Akash Gupta
 */

#include <stdio.h>
#include <stdint.h>

/*
 * Global buffer:
 * Stores one pushed-back character
 * -2 indicates buffer is empty
 */
int32_t buffer = -2;

/*
 * Function: modifiedgetch
 * -----------------------
 * Returns a character from input:
 * 1. If buffer has a character, return it
 * 2. Otherwise, read from standard input
 */
int32_t modifiedgetch(void)
{
	int32_t c;

	if (buffer != -2)   // check if buffer is not empty
	{
		c = buffer;     // get character from buffer
		buffer = -2;    // clear buffer after reading
		return c;
	}
	else
		return getchar();   // read from input
}

/*
 * Function: modifiedungetch
 * --------------------------
 * Pushes a character back into buffer
 * Only one character allowed
 */
void modifiedungetch(int32_t c)
{
	if (buffer != -2)
		printf("Error: buffer full\n");   // buffer already occupied
	else
		buffer = c;   // store character in buffer
}

/*
 * Function: EOF_Q9
 * ----------------
 * Reads input line by line:
 * - Prints first character of each line
 * - Skips remaining characters in that line
 * - Stops when EOF is encountered
 */
int32_t test_49(void)
{
	int32_t c;

	while ((c = modifiedgetch()) != EOF)
	{
		if (c != '\n')   
		{
			modifiedungetch(c);                 
			printf("%c\n", modifiedgetch());    


			while ((c = modifiedgetch()) != '\n' && c != EOF)
				;
		}
	}

	printf("EOF encountered.\n");
	return 0;
}
