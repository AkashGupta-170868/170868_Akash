/*
 * Description:
 * Print first character of each input line
 * using single-character pushback getch/ungetch
 *
 * Author: Akash Gupta
 */

#include <stdio.h>
#include <stdint.h>

static int32_t pushbackCharacter = -1;

/* getch */
int32_t getch(void)
{
	if (pushbackCharacter != -1) {
		int32_t tempChar = pushbackCharacter;
		pushbackCharacter = -1;
		return tempChar;
	}
	return getchar();
}

/* ungetch */
void ungetch(int32_t character)
{
	if (pushbackCharacter != -1) {
		printf("Error: pushback buffer full\n");
	} else {
		pushbackCharacter = character;
	}
}

int test_48(void)
{
	int32_t character;
	int32_t isNewLine = 1;   // flag for new line start

	printf("Enter text (Ctrl+D to end):\n");

	while ((character = getch()) != EOF) {

		if (isNewLine && character != '\n') {
			printf("%c\n", character);   // print first char
			isNewLine = 0;
		}

		if (character == '\n') {
			isNewLine = 1;   // next is new line start
		}
	}

	return 0;
}
