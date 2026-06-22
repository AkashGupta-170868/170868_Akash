#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define MAXLEN 100

void itoa(int32_t n, char s[]);

int int_to_string(void)
{
	int32_t n;
	char s[MAXLEN];

	printf("Enter a number: ");
	scanf("%d", &n);

	test_412(n, s);

	printf("String = %s\n", s);

	return 0;
}

void test_412(int32_t n, char s[])
{
	static int i;

	if (n / 10 != 0)
		test_412(n / 10, s);
	else
	{
		i = 0;
		if (n < 0)
			s[i++] = '-';
	}

	s[i++] = abs(n % 10) + '0';
	s[i] = '\0';
}
