/*
 * Description:
 * RPN Calculator using modified getop() (no ungetch)
 * Supports +, -, *, /, % with correct positive modulo
 *
 * Author: Akash Gupta
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>

#define MAXVAL 100
#define NUMBER '0'

static int32_t stack[MAXVAL];
static int32_t stackPointer = 0;

static void push(int32_t value)
{
	if (stackPointer < MAXVAL)
		stack[stackPointer++] = value;
	else
		printf("Error: stack full\n");
}

static int32_t pop(void)
{
	if (stackPointer > 0)
		return stack[--stackPointer];
	else
	{
		printf("Error: stack empty\n");
		return 0;
	}
}

static int32_t getop(char str[])
{
	int32_t idx = 0;
	int32_t character;
	static int32_t lastCharacter = ' ';

	while ((str[0] = character = lastCharacter) == ' ' || character == '\t')
		lastCharacter = getchar();

	str[1] = '\0';

	if (character == '-')
	{
		int32_t nextChar = getchar();

		if (!isdigit(nextChar))
		{
			lastCharacter = nextChar;
			return '-';
		}

		str[idx++] = character;
		character = nextChar;
	}

	if (!isdigit(character))
		return character;

	do
	{
		str[idx++] = character;
		character = getchar();
	} while (isdigit(character));

	str[idx] = '\0';
	lastCharacter = character;

	return NUMBER;
}

int32_t test_411(void)
{
	int32_t type;
	int32_t op2;
	char str[100];

	printf("Enter RPN expressions (Ctrl+D to end):\n");

	while ((type = getop(str)) != EOF)
	{
		switch (type)
		{
			case NUMBER:
				push(atoi(str));
				break;

			case '+':
				push(pop() + pop());
				break;

			case '*':
				push(pop() * pop());
				break;

			case '-':
				op2 = pop();
				push(pop() - op2);
				break;

			case '/':
				op2 = pop();

				if (op2 != 0)
					push(pop() / op2);
				else
					printf("Error: divide by zero\n");

				break;

			case '%':
				{
					op2 = pop();
					int32_t op1 = pop();

					if (op2 != 0)
					{
						int32_t result = op1 % op2;

						if (result < 0)
							result += (op2 > 0 ? op2 : -op2);

						push(result);
					}
					else
						printf("Error: modulo by zero\n");

					break;
				}

			case '\n':
				printf("%d\n", pop());
				break;

			default:
				printf("Error: unknown command %c\n", type);
				break;
		}
	}

	return 0;
}
