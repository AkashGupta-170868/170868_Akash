/**
 * Reverse Polish Calculator
 * Supports:
 * +, -, *, /, %
 * Negative numbers
 *
 * Example Input:
 * 10 10 + 100 + 2 *
 * Output:
 * 240
 */

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAXOP 100
#define NUMBER '0'
#define BUFSIZE 100
#define MAXVAL 100

/* File-limited global variables */
static int32_t sp = 0;
static int32_t bufp = 0;

static double val[MAXVAL];
static char buf[BUFSIZE];

/* File-limited function declarations */
static int32_t getch(void);
static void ungetch(int32_t);
static int32_t getop(char[]);
static void push(double);
static double pop(void);

/* Reverse Polish Calculator */
int rev_rpn_main(void)
{
	int32_t type;
	double op2;
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

/* Push value onto stack */
static void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* Pop value from stack */
static double pop(void)
{
	if (sp > 0)
		return val[--sp];

	printf("error: stack empty\n");
	return 0.0;
}

/* Get next operator or numeric operand */
static int32_t getop(char s[])
{
	int32_t i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;

	s[1] = '\0';

	if (!isdigit(c) && c != '.' && c != '-')
		return c;

	i = 0;

	if (c == '-' || isdigit(c))
		while (isdigit(s[++i] = c = getch()))
			;

	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;

	s[i] = '\0';

	if (c != EOF)
		ungetch(c);

	if (strcmp(s, "-") == 0)
		return '-';

	return NUMBER;
}

/* Push character back */
static void ungetch(int32_t c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

/* Get character */
static int32_t getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}
