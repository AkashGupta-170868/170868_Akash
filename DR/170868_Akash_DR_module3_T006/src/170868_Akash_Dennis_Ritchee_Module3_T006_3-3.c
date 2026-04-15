/*description :Create a function expand(shorthand_string , expanded_string) which will take shorthand notation as an one argument and it will store the result (expanded string) on the second-string argument.
 *Author : Akash Gupta
 *Created At: 25-02-2026
 *Modified At: 25-02-2026
*/

#include <stdio.h>

void expand(char s1[], char s2[])
{
    int i = 0;   // index string1
    int j = 0;   // index string2
    int k;

    while (s1[i] != '\0')
    {
        // check if current character is '-' and not first or last
        if (s1[i] == '-' && i > 0 && s1[i+1] != '\0')
        {
            char start = s1[i-1];     // previous character
            char end   = s1[i+1];     // next character

            if (start < end)
            {
                for (k = start + 1; k <= end; k++)
                {
                    s2[j++] = k;
                }
                i += 2; 
                continue;
            }else {

        }

        s2[j++] = s1[i++];
    }

    s2[j] = '\0'; 

}}

int expand_t()
{
    char input[100], output[500];

    printf("Enter shorthand string: ");
    scanf("%s", input);

    expand(input, output);

    printf("Expanded string: %s\n", output);

    return 0;
}
