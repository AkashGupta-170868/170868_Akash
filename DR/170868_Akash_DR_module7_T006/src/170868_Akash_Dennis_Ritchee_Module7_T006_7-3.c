/*Description :create your own printf function .
Author :Akash Gupta
Created at:21-04-2026
Modified at:21-04-2026
 */
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
void minprintf(char *fmt, ...);

int32_t printf_main() {
	int32_t intVal;
	float floatVal;
	double doubleVal;
	uint32_t uintVal;
	char ch;
	char strVal[100];
	int32_t baseNum;

	printf("Enter integer number: ");
	scanf("%d", &intVal);

	printf("Enter float number: ");
	scanf("%f", &floatVal);

	printf("Enter double number: ");
	scanf("%lf", &doubleVal);

	printf("Enter unsigned integer number: ");
	scanf("%u", &uintVal);

	printf("Enter character: ");
	scanf(" %c", &ch);

	printf("Enter string: ");
	scanf(" %[^\n]", strVal);

	printf("Enter integer (for hex and octal): ");
	scanf("%d", &baseNum);

	minprintf("\n--- OUTPUT ---\n");

	minprintf("Integer: %d\n", intVal);
	minprintf("Float: %f\n", floatVal);
	minprintf("Double: %f\n", doubleVal);
	minprintf("Unsigned: %u\n", uintVal);
	minprintf("Character: %c\n", ch);
	minprintf("String: %s\n", strVal);

	minprintf("Octal value: %o\n", baseNum);
	minprintf("Hex value: %x\n", baseNum);
	minprintf("Address of i: %p\n", &intVal);

	return 0;
}

/*Description : handle all the format specifier like d f p s u c o x.
  Function name : minprintf
Author :Akash Gupta
Created at:21-04-2026
Modified at:21-04-2026
 */
void minprintf(char *fmt, ...) {
	va_list ap;
	char *p, *sval;
	int ival;
	double dval;
	unsigned int uval;
	char cval;
	void *ptr;

	va_start(ap, fmt);

	for (p = fmt; *p; p++) {

		if (*p != '%') {
			putchar(*p);
			continue;
		}

		switch (*++p) {

			case 'd': 
				ival = va_arg(ap, int);
				printf("%d", ival);
				break;

			case 'f': 
				dval = va_arg(ap, double);
				printf("%f", dval);
				break;

			case 's':  
				sval = va_arg(ap, char *);
				while (*sval)
					putchar(*sval++);
				break;

			case 'u':   
				uval = va_arg(ap, unsigned int);
				printf("%u", uval);
				break;

			case 'c':  
				cval = (char) va_arg(ap, int);
				putchar(cval);
				break;

			case 'o':   
				ival = va_arg(ap, int);
				printf("%o", ival);
				break;

			case 'x':  
				ival = va_arg(ap, int);
				printf("%x", ival);
				break;

			case 'p':  
				ptr = va_arg(ap, void *);
				printf("%p", ptr);
				break;

			default:
				putchar(*p);
				break;
		}
	}

	va_end(ap);
}
