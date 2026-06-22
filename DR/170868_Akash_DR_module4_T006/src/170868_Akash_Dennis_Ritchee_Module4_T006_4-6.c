#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAXOP 100
#define NUMBER '0'
#define BUFSIZE 100
#define MAXVAL 100

/* File-limited global variables */
static char buf[BUFSIZE];
static int32_t bufp = 0;
static int32_t sp = 0;
static double val[MAXVAL];

/* Function declarations */
static int32_t getop(char[]);
static void push(double);
static double pop(void);
static int32_t getch(void);
static void ungetch(int32_t);

/*
 * Main function
 *
 * Description:
 * Executes Reverse Polish Notation calculator
 * with support for variables A-Z.
 *
 * Parameters:
 * None
 *
 * Returns:
 * 0 on successful execution
 */
int main4_6(void)
{
	int32_t type, var = 0;
	double op2, v = 0.0;
	char s[MAXOP];
	double variable[26] = {0};

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

			case '=':
				pop();
				if (var >= 'A' && var <= 'Z')
					variable[var - 'A'] = pop();
				else
					printf("error: no variable name\n");
				break;

			case '\n':
				v = pop();
				printf("\t%.8g\n", v);
				break;

			default:
				if (type >= 'A' && type <= 'Z')
					push(variable[type - 'A']);
				else if (type == 'v')
					push(v);
				else
					printf("error: unknown command %s\n", s);
				break;
		}

		var = type;
	}

	return 0;
}

/*
 * Push function
 *
 * Description:
 * Pushes a value onto stack.
 *
 * Parameters:
 * f - value to push
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
 * Removes and returns top value
 * from stack.
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
 * Get Operator function
 *
 * Description:
 * Reads next operator or numeric operand
 * from input stream.
 *
 * Parameters:
 * s - string to store operand
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

	if (!isdigit(c) && c != '.')
		return c;

	i = 0;

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
 * Pushes character back into buffer.
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
