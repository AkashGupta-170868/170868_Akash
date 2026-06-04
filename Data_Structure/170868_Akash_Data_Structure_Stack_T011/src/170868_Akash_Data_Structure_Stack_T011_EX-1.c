#include <stdio.h>
#include <stdint.h>

#define STACKSIZE 50

char Stack[STACKSIZE];
int16_t top = -1;

static void push(char ch);
static char pop(void);
static int16_t isMatching(char open, char close);

/*
 * Function Name: BracketMatching()
 * Function Description: This function matches brackets and verifies proper order using stack.
 * Author: Akash Gupta
 * Created: 18 May, 2026
 */
void BracketMatching() {
	char exp[100];
	int16_t indx;

	top = -1;

	printf("Enter expression: ");
	scanf(" %99[^\n]", exp);

	for(indx = 0; exp[indx] != '\0'; indx++) {

		char ch = exp[indx];

		if(ch == '(' || ch == '{' || ch == '[') {
			push(ch);
		}

		else if(ch == ')' || ch == '}' || ch == ']') {

			if(top == -1) {
				printf("Not Balanced\n");
				return;
			}

			char open = pop();

			if(!isMatching(open, ch)) {
				printf("Not Balanced\n");
				return;
			}
		}
	}

	if(top == -1)
		printf("Balanced\n");
	else
		printf("Not Balanced\n");
}

/*
 * Function Name: push()
 * Function Description: Push element into stack
 * Author: Akash Gupta
 * Created: 18 May, 2026
 */
static void push(char ch) {
	Stack[++top] = ch;
}

/*
 * Function Name: pop()
 * Function Description: Pop element from stack
 * Author: Akash Gupta
 * Created: 18 May, 2026
 */
static char pop(void) {
	return Stack[top--];
}

/*
 * Function Name: isMatching()
 * Function Description: Match the appropriate bracket pair.
 * Author: Akash Gupta
 * Created: 18 May, 2026
 */
static int16_t isMatching(char open, char close) {
	return (open == '(' && close == ')') ||
		(open == '{' && close == '}') ||
		(open == '[' && close == ']');
}
