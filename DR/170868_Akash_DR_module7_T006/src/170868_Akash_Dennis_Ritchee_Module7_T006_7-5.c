/*
description :Rewrite the postfix calculator of Chapter 4 to use scanf and/or sscanf
to do the input and number conversion.
Author:Akash Gupta
created At:22-04-2026
modified at: 22-04-2026
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>
#define MAXVAL 100

static int32_t sp = 0;
static int32_t val[MAXVAL];

static void push(int f)
{
	if (sp < MAXVAL)
	{
		val[sp++] = f;
	}
	else
	{
		printf("Error: stack full\n");
		exit(1);
	}
}

static int32_t pop(void)
{
	if (sp > 0)
	{
		return val[--sp];
	}
	else
	{
		printf("Error: stack empty\n");
		exit(1);
	}
}

/*
description :RNP_main(); taken operator and operand from scanf function
Author:Akash Gupta
created At:20-04-2026
modified at: 20-04-2026
 */

int32_t RPN_main(void)
{
	char s[100];
	int32_t op2;

	printf("Enter a postfix expression:\n");

	while (scanf("%99s", s) == 1)
	{
		if (isdigit(s[0]) || (s[0] == '-' && isdigit(s[1])))
		{
			int operand;
			sscanf(s, "%d", &operand);
			push(operand);
		}
		else
		{
			switch (s[0])
			{
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
					{
						printf("Error: Zero divisor.\n");
						return 1;
					}
					break;

				case '%':
					op2 = pop();
					if (op2 != 0)
						push(pop() % op2);
					else
					{
						printf("Error: Zero divisor for modulo.\n");
						return 1;
					}
					break;

				default:
					printf("Error: Unknown command '%s'.\n", s);
					return 1;
			}
		}
	}

	printf("Result: %d\n", pop());
	return 0;
}
