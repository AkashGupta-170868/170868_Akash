#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAXLINE 1000
#define MAXVAL 100
#define NUMBER '0'
#define VARIABLE '1'

int sp = 0;
double val[MAXVAL];

double variables[26];
double last = 0.0;

// Stack functions
void push(double f) {
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("Error: stack full\n");
}

double pop(void) {
	if (sp > 0)
		return val[--sp];
	else {
		printf("Error: stack empty\n");
		return 0.0;
	}
}

// Parse next token from line
int getop(char *line, int *index, char s[]) {
	int i = 0;

	// Skip spaces
	while (line[*index] == ' ' || line[*index] == '\t')
		(*index)++;

	char c = line[*index];

	if (c == '\0' || c == '\n')
		return EOF;

	s[i++] = c;
	s[i] = '\0';
	(*index)++;

	// Variable
	if (islower(c)) {
		return VARIABLE;
	}

	// Not number or '-' → operator
	if (!isdigit(c) && c != '.' && c != '-')
		return c;

	// Handle negative numbers
	if (c == '-') {
		char next = line[*index];
		if (!isdigit(next) && next != '.') {
			return '-';
		}
		s[i++] = next;
		(*index)++;
		c = next;
	}

	// Integer part
	while (isdigit(line[*index])) {
		s[i++] = line[*index];
		(*index)++;
	}

	// Fraction part
	if (line[*index] == '.') {
		s[i++] = line[*index];
		(*index)++;
		while (isdigit(line[*index])) {
			s[i++] = line[*index];
			(*index)++;
		}
	}

	s[i] = '\0';
	return NUMBER;
}

int test_410() {
	char line[MAXLINE];
	char s[100];
	int type, index, var = -1;
	double op2;

	printf("Enter RPN expressions:\n");

	while (fgets(line, MAXLINE, stdin) != NULL) {
		index = 0;

		while ((type = getop(line, &index, s)) != EOF) {

			switch (type) {

				case NUMBER:
					push(atof(s));
					break;

				case VARIABLE:
					var = s[0] - 'a';
					push(variables[var]);
					break;

				case '=':
					if (var >= 0)
						variables[var] = pop();
					else
						printf("Error: no variable\n");
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
						printf("Error: zero divisor\n");
					break;

				case '%': {
						  int op2i = (int)pop();
						  int op1i = (int)pop();
						  if (op2i != 0)
							  push(op1i % op2i);
						  else
							  printf("Error: zero divisor\n");
						  break;
					  }

				case 'v':
					  push(last);
					  break;

				default:
					  printf("Error: unknown command %s\n", s);
					  break;
			}
		}

		// Print result after full line
		if (sp > 0) {
			last = pop();
			printf("Result: %.8g\n", last);
		}
	}

	return 0;
}

