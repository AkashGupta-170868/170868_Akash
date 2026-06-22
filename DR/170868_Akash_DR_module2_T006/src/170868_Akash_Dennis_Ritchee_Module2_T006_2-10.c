/*
 * Descriptions: Rewrite the function lower, which converts upper case letters to lower case, with a conditional expression instead of if-else. 
 * Author : Akash Gupta
 * Created at : 23-02-2026
 * Modified at : 23-02-2026
 */

#include<stdio.h>
#include<stdint.h>

int16_t lower(int16_t charcter);

int16_t lower_t(void)
{
	int16_t charcter;

	while((charcter=getchar())!=EOF)
	{
		putchar(lower(charcter));
	}
}

int16_t lower(int16_t charcter)
{
	return charcter>='A' && charcter<='Z'? charcter+'a'-'A':charcter;
}
