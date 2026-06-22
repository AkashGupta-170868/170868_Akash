/*description : strindex which returns rightmost occurrence 
author:Akash Gupta
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>

int32_t mstrindex(char s[], char t[])
{
	int32_t idx, chk, pat, result;

	result = -1;

	for(idx = 0; s[idx] != '\0'; idx++)
	{
		for(chk = idx, pat = 0; t[pat] != '\0' && s[chk] == t[pat]; chk++, pat++)
			;

		if(pat > 0 && t[pat] == '\0')
			result = idx + 1;
	}

	return result;
}

/*i → idx (current index)
  j → chk (checking position)
  k → pat (pattern index)*/

/*description : take input from the user.
author:Akash Gupta
 */
int mstrindex_main(void)
{
	char line[100];
	char pattern[100];
	int32_t found;

	printf("Enter String: ");
	fgets(line, sizeof(line), stdin);

	printf("Enter Match String: ");
	fgets(pattern, sizeof(pattern), stdin);

	line[strcspn(line, "\n")] = '\0';
	pattern[strcspn(pattern, "\n")] = '\0';

	found = mstrindex(line, pattern);

	if(found != -1)
		printf("String \"%s\" found in \"%s\" at position %d\n", pattern, line, found);
	else
		printf("Match not found\n");

	return 0;
}
