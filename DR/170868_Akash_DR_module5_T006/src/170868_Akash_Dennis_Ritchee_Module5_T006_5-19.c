/* Description :  Modify undcl so that it does not add redundant parentheses to declarations
   Author:Akash Gupta
   Modified At:10-04-2026
   Created At:10-04-2026
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
 
#define MAXTOKEN 100
 
enum { NAME, PARENS, BRACKETS };
 
extern char token[MAXTOKEN];
extern char out[1000];
 /*
function name : undcl();
description :allows the arugement inside the function. and converted syntax to english.
created at : 10-04-2026
*/
void undcl(){
        int16_t type;
        int16_t nextType;
        char temp[MAXTOKEN];
        while (gettoken() != EOF) {
                strcpy(out, token);
                while ((type = gettoken()) != '\n')
                        if (type == PARENS || type == BRACKETS)
                                strcat(out, token);
                        else if (type == '*') {
                                while((nextType = gettoken()) == '*'){
                                        sprintf(temp, "*%s", out);
                                        strcpy(out,temp);
                                }
                                if(nextType == PARENS || nextType == BRACKETS){
                                        sprintf(temp, "(*%s)", out);
                                        strcpy(out,temp);
                                        ungetch(nextType);
                                }
                                else{
                                        sprintf(temp, "*%s", out);
                                        strcpy(out,temp);
                                        ungetch(nextType);
                                }
                        }
                        else if (type == NAME) {
                                sprintf(temp, "%s %s", token, out);
                                strcpy(out, temp);
                        } else
                                printf("invalid input at %s\n", token);
        }
        printf("%s\n", out);
}
