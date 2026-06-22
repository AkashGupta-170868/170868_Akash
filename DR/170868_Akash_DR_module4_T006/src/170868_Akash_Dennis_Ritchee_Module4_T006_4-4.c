#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAXOP 100
#define NUMBER '0'
#define BUFSIZE 100
#define MAXVAL 100

/* File-limited global variables */
static int32_t bufp = 0;
static int32_t sp = 0;
static double val[MAXVAL];
static char buf[BUFSIZE];

/* Function declarations */
static int32_t getch(void);
static void ungetch(int32_t);
static int32_t getop(char[]);
static void push(double);
static double pop(void);
static void clearsp(void);

/*
 * Main function
 *
 * Description:
 * Executes the Reverse Polish Notation calculator.
 * Reads input continuously, processes operators and operands,
 * and prints the result.
 *
 * Parameters:
 * None
 *
 * Returns:
 * 0 on successful execution
 */
int main4_4(void)
{
	int32_t type;
	double op2, op1;
	char s[MAXOP];

	while ((type = getop(s)) != EOF)
	{
		switch (type)
		{
			case NUMBER:
				push(atof(s));
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
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;

			case '%':
				op2 = pop();
				if (op2 != 0.0)
					push(fmod(pop(), op2));
				else
					printf("error: zero divisor\n");
				break;

			case '?':
				op2 = pop();
				printf("\t%.8g\n", op2);
				push(op2);
				break;

			case 'c':
				clearsp();
				break;

			case 'd':
				op2 = pop();
				push(op2);
				push(op2);
				break;

			case 's':
				op1 = pop();
				op2 = pop();
				push(op1);
				push(op2);
				break;

			case '\n':
				printf("\t%.8g\n", pop());
				break;

			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}

	return 0;
}

/*
 * Push function
 *
 * Description:
 * Pushes a floating-point value onto the stack.
 *
 * Parameters:
 * f - value to be pushed
 *
 * Returns:
 * None
 */
static void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/*
 * Pop function
 *
 * Description:
 * Removes and returns the top value from the stack.
 *
 * Parameters:
 * None
 *
 * Returns:
 * Top stack value
 */
static double pop(void)
{
	if (sp > 0)
		return val[--sp];

	printf("error: stack empty\n");
	return 0.0;
}

/*
 * Clear Stack function
 *
 * Description:
 * Clears all elements from the stack.
 *
 * Parameters:
 * None
 *
 * Returns:
 * None
 */
static void clearsp(void)
{
	sp = 0;
}

/*
 * Get Operator function
 *
 * Description:
 * Reads next operator or numeric operand
 * from input stream.
 *
 * Parameters:
 * s - character array to store operand
 *
 * Returns:
 * NUMBER if operand
 * operator character otherwise
 */
static int32_t getop(char s[])
{
	int32_t i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;

	s[1] = '\0';
	i = 0;

	if (!isdigit(c) && c != '.' && c != '-')
		return c;

	if (c == '-')
	{
		if (isdigit(c = getch()) || c == '.')
			s[++i] = c;
		else
		{
			if (c != EOF)
				ungetch(c);
			return '-';
		}
	}

	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()))
			;

	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;

	s[i] = '\0';

	if (c != EOF)
		ungetch(c);

	return NUMBER;
}

/*
 * Get Character function
 *
 * Description:
 * Returns next character from buffer
 * or standard input.
 *
 * Parameters:
 * None
 *
 * Returns:
 * Character read
 */
static int32_t getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

/*
 * Unget Character function
 *
 * Description:
 * Pushes character back into buffer
 * for future reading.
 *
 * Parameters:
 * c - character to push back
 *
 * Returns:
 * None
 */
static void ungetch(int32_t c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
