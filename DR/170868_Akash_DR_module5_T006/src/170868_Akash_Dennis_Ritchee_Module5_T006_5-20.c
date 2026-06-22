#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS, ARGUMENTS };

int8_t isError = 0;
extern int16_t tokentype;
extern char token[MAXTOKEN];
extern char name[MAXTOKEN];
extern char datatype[MAXTOKEN];
extern char out[1000];

static char *Storage[] = {"auto","register","extern","static"};
static char *typequantifier[] = {"const","volatile","restrict"};
static char *typeofdata[] = {"int","float","char","double","long","void"};

int buf = EOF;
/* function name : read_char();
 * Descriptions: this function takes command line argument like de and threshold value 2 then convert tap to 2 space.
 * Author : Akash Gupta
 * Created at : 03-04-2026
 */
int read_char(void) {
	int c;
	if (buf != EOF) {
		c = buf;
		buf = EOF;
		return c;
	}
	return getchar();
}

void pushback_char(int c) {
	buf = c;
}

void error_recovery(void) {
	int c;
	while ((c = read_char()) != '\n' && c != EOF)
		;
}
/* function name : get_token();
 * Descriptions: this function takes command line argument like de and threshold value 2 then convert tap to 2 space.
 * Author : Akash Gupta
 * Created at : 03-04-2026
 */
int16_t get_token(void) {
	int ch;
	char *p = token;

	while (1) {
		ch = read_char();

		if (ch == ' ' || ch == '\t')
			continue;

		if (ch == '/') {
			int next = read_char();
			if (next == '/') {
				while ((ch = read_char()) != '\n' && ch != EOF)
					;
				return tokentype = '\n';
			} else {
				pushback_char(next);
				break;
			}
		}
		break;
	}

	if (ch == '(') {
		int next = read_char();

		if (next == ')') {
			strcpy(token, "()");
			return tokentype = PARENS;
		}

		if (next == '*' || next == '(') {
			pushback_char(next);
			return tokentype = '(';
		}

		int indx = 0;
		token[indx++] = '(';
		token[indx++] = next;

		while ((ch = read_char()) != ')' && ch != EOF && ch != '\n') {
			token[indx++] = ch;
		}

		if (ch != ')') {
			isError = 1;
			return tokentype = '\n';
		}

		token[indx++] = ')';
		token[indx] = '\0';

		return tokentype = ARGUMENTS;
	}

	else if (ch == '[') {
		for (*p++ = ch; (*p++ = read_char()) != ']'; ) {
			if (*(p-1) == '\n' || *(p-1) == EOF) {
				isError = 1;
				return tokentype = BRACKETS;
			}
		}
		*p = '\0';
		return tokentype = BRACKETS;
	}

	else if (isalpha(ch)) {
		*p++ = ch;
		while (isalnum(ch = read_char()))
			*p++ = ch;

		*p = '\0';
		pushback_char(ch);
		return tokentype = NAME;
	}

	else
		return tokentype = ch;
}

void parse_dcl(void);
void parse_dirdcl(void);

void parse_dirdcl(void) {
	if (isError)
		return;

	int type;

	if (tokentype == '(') {
		get_token();
		parse_dcl();

		if (tokentype != ')') {
			isError = 1;
			return;
		}
		get_token();
	}
	else if (tokentype == NAME) {
		strcpy(name, token);
		get_token();
	}
	else {
		isError = 1;
		return;
	}

	while (!isError && (tokentype == PARENS || tokentype == BRACKETS || tokentype == ARGUMENTS)) {
		type = tokentype;

		if (type == PARENS)
			strcat(out, " function returning");

		else if (type == ARGUMENTS) {
			strcat(out, " function taking ");
			strcat(out, token);
			strcat(out, " and returning");
		}
		else {
			strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");
		}

		get_token();
	}
}

void parse_dcl(void) {
	if (isError)
		return;

	int ns;

	for (ns = 0; tokentype == '*'; ns++)
		get_token();

	parse_dirdcl();

	if (isError)
		return;

	while (ns-- > 0)
		strcat(out, " pointer to");
}

void parse_declaration() {
	while (get_token() != EOF) {

		isError = 0;
		name[0] = '\0';
		out[0] = '\0';
		datatype[0] = '\0';

		if (tokentype == '\n')
			continue;

		while (tokentype == NAME) {

			int isType = 0;

			for (int i = 0; i < 6; i++)
				if (strcmp(token, typeofdata[i]) == 0)
					isType = 1;

			for (int i = 0; i < 3; i++)
				if (strcmp(token, typequantifier[i]) == 0)
					isType = 1;

			for (int i = 0; i < 4; i++)
				if (strcmp(token, Storage[i]) == 0)
					isType = 1;

			if (!isType)
				break;

			strcat(datatype, token);
			strcat(datatype, " ");

			get_token();
		}

		parse_dcl();

		if (isError) {
			error_recovery();
			continue;
		}

		if (tokentype != '\n') {
			isError = 1;
			error_recovery();
			continue;
		}

		printf("%s: %s %s\n", name, out, datatype);
	}
}
