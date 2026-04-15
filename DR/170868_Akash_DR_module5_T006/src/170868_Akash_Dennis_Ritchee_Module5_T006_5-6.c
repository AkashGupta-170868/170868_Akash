/*
 * Descriptions:  Rewrite appropriate programs from earlier chapters and exercises with pointers
 instead of array indexing. 1.getline 2.atoi 3.itoa 4.reverse 5.strindex 6.gettop
 * Author : Akash Gupta
 * Created at : 30-03-2026
 * Modified at : 30-03-2026
 */
#include <stdio.h>
#include <stdint.h>
#include <ctype.h>
#include <stdlib.h>

#define NUM '0'
#define SIZE 100
#define MAXOP 100

int32_t getch(void);
void ungetch(int32_t);

/* function name : my_getline();
 * Descriptions: get the line input by user till Eof and \n
 * Author : Akash Gupta
 * Created at : 31-03-2026*/
int32_t my_getline(char *buf, int32_t lim)
{
	int32_t ch;
	char *start = buf;

	while (lim > 1 && (ch = getchar()) != EOF && ch != '\n') {
		*buf++ = ch;
		lim--;
	}

	if (ch == '\n')
		*buf++ = ch;

	*buf = '\0';

	return buf - start;
}

/* function name : my_atoi();
 * Descriptions: converts assic value to an integer
 * Author : Akash Gupta
 * Created at : 31-03-2026*/
int32_t my_atoi(char *str)
{
	int32_t num = 0;
	int sign = 1;

	if (*str == '-') {
		sign = -1;
		str++;
	} else if (*str == '+') {
		str++;
	}

	// Convert digits
	while (*str >= '0' && *str <= '9') {
		num = 10 * num + (*str - '0');
		str++;
	}

	return sign * num;
}

/* function name : reverse();
 * Descriptions: reverse the string
 * Author : Akash Gupta
 * Created at : 31-03-2026*/
void reverse(char *str)
{
	char *end = str;
	char tmp;

	while (*end)
		end++;

	end--;

	while (str < end) {
		tmp = *str;
		*str++ = *end;
		*end-- = tmp;
	}
}

/* function name : itoa();
 * Descriptions: converts integer to asiic
 * Author : Akash Gupta
 * Created at : 31-03-2026*/
void my_itoa(int32_t num, char *buf)
{
	int32_t sign = num;
	char *start = buf;

	if (num < 0)
		num = -num;

	do {
		*buf++ = (num % 10) + '0';
	} while ((num /= 10) > 0);

	if (sign < 0)
		*buf++ = '-';

	*buf = '\0';

	reverse(start);
}

/* strindex */
/* function name : strindex();
 * Descriptions: return the position of matched string from the substring to string
 * Author : Akash Gupta
 * Created at : 31-03-2026*/
int32_t my_strindex(char *str, char *sub)
{
	char *p, *q;
	char *start = str;
	int32_t pos = -1;

	while (*str) {
		p = str;
		q = sub;

		// Compare case-insensitive
		while (*q && tolower(*p) == tolower(*q)) {
			p++;
			q++;
		}

		// Match found
		if (*q == '\0') {
			pos = (str - start) + 1; // 1-based index
		}

		str++;
	}

	return pos;
}

/* function name : getop();
 * Descriptions:return the number inputed by the user
 * Author : Akash Gupta
 * Created at : 31-03-2026*/
int32_t my_getop(char *buf)
{
	int32_t ch;

	while ((*buf = ch = getch()) == ' ' || ch == '\t')
		;

	*(buf + 1) = '\0';

	if (!isdigit(ch) && ch != '.')
		return ch;

	if (isdigit(ch)) {
		while (isdigit(*++buf = ch = getch()))
			;
	}

	if (ch == '.') {
		while (isdigit(*++buf = ch = getch()))
			;
	}

	*buf = '\0';

	if (ch != EOF)
		ungetch(ch);

	return NUM;
}
#define MAXVAL 100

int sp = 0;            // stack pointer
double val[MAXVAL];    // stack

/* function name : push();
 * Descriptions: push the element into stack
 * Author : Akash Gupta
 * Created at : 31-03-2026*/
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("Error: stack full\n");
}

/* function name : pop();
 * Descriptions: pop the element from the stack
 * Author : Akash Gupta
 * Created at : 31-03-2026*/
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("Error: stack empty\n");
		return 0.0;
	}
}

/* function name : func_test();
 * Descriptions: display all the function at one place and run that accordingly
 * Author : Akash Gupta
 * Created at : 31-03-2026*/
int func_test()
{
	int choice;
	char str1[SIZE], str2[SIZE];
	int32_t num, result;

	do {
		printf("\n===== MENU =====\n");
		printf("1. getline\n");
		printf("2. atoi\n");
		printf("3. itoa\n");
		printf("4. reverse\n");
		printf("5. strindex\n");
		printf("6. getop RPN calculator\n");
		printf("0. Exit\n");
		printf("Enter choice: ");
		scanf("%d", &choice);
		getchar(); // clear newline

		switch (choice) {

			case 1:
				printf("Enter a line: ");
				result = my_getline(str1, SIZE);
				printf("Line: %s", str1);
				printf("Length: %d\n", result);
				break;

			case 2:
				printf("Enter numeric string: ");
				my_getline(str1, SIZE);
				if (result = my_atoi(str1)){
					printf("Integer: %d\n", result);}
				else printf("Enter the valid number"); 
				break;

			case 3:
				printf("Enter integer: ");
				if (scanf("%d", &num) != 1){
					printf("Enter the valid input");
					while (getchar() != '\n');
					break;
				}
				getchar();
				my_itoa(num, str1);
				printf("String: %s\n", str1);
				break;

			case 4:
				printf("Enter string: ");
				my_getline(str1, SIZE);
				reverse(str1);
				printf("Reversed: %s\n", str1);
				break;
			case 5:
				{
					printf("Enter main string: ");
					my_getline(str1, SIZE);

					printf("Enter substring: ");
					my_getline(str2, SIZE);

					result = my_strindex(str1, str2);

					if (result != -1)
						printf("String %s found in %s at position %d\n", str2, str1, result);
					else
						printf("Substring not found\n");

					break;
				}
			case 6:
				{
					int type;
					double op2;
					char s[MAXOP];

					printf("Enter RPN expression (press Enter for result, 'q' to quit):\n");

					while (1) {
						type = my_getop(s);

						// Exit condition
						if (type == 'q')
							break;

						switch (type) {

							case NUM:
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
									printf("Error: division by zero\n");
								break;

							case '\n':
								printf("Result: %.2f\n", pop());
								break;

							default:
								printf("Error: unknown command %s\n", s);
								break;
						}
					}

					break;
				}

			case 0:
				printf("Exiting...\n");
				break;

			default:
				printf("Invalid choice!\n");
		}

	} while (choice != 0);

	return 0;
}
