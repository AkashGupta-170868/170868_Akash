/*
 * Simple implementation of atof()
 * Converts string to floating-point number
 * Supports scientific notation
 */

#include <stdio.h>
#include <ctype.h>
#include <stdint.h>

#define MAXLINE 100

/* Function to calculate base^exp */
int32_t power(int32_t base, int32_t exp)
{
	int32_t result = 1;

	while (exp > 0)
	{
		result *= base;
		exp--;
	}

	return result;
}

/* Convert string to double */
double myatof(char s[])
{
	int32_t i = 0;
	int32_t sign = 1;
	int32_t exp = 0;
	int32_t esign = 1;

	double val = 0.0;
	double pow = 1.0;

	/* Skip spaces */
	while (isspace(s[i]))
		i++;

	/* Check sign */
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}

	/* Integer part */
	while (isdigit(s[i]))
	{
		val = 10 * val + (s[i] - '0');
		i++;
	}

	/* Fraction part */
	if (s[i] == '.')
		i++;

	while (isdigit(s[i]))
	{
		val = 10 * val + (s[i] - '0');
		pow *= 10;
		i++;
	}

	/* Exponent part */
	if (s[i] == 'e' || s[i] == 'E')
	{
		i++;

		if (s[i] == '-' || s[i] == '+')
		{
			if (s[i] == '-')
				esign = -1;
			i++;
		}

		while (isdigit(s[i]))
		{
			exp = 10 * exp + (s[i] - '0');
			i++;
		}
	}

	/* Apply exponent */
	if (esign == -1)
		return sign * (val / pow) / power(10, exp);
	else
		return sign * (val / pow) * power(10, exp);
}

/* Read input line */
int32_t mgetline(char line[], int32_t lim)
{
	int32_t i, c;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		line[i] = c;

	line[i] = '\0';

	return i;
}

int sci_main(void)
{
	char str[MAXLINE];
	double num;

	printf("Enter a number: ");
	mgetline(str, MAXLINE);

	num = myatof(str);

	printf("Converted value = %f\n", num);

	return 0;
}
