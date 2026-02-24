/*
 * Descriptions:this function is about that counts the escape charcater and prints its value
 * Author : Akash Gupta
 * Created at : 09-02-2026
 * Modified at : 10-02-2026
 */


#include <stdio.h>
int print_escape()
{
   
 int  nl=0,t1=0,s1=0;
 char c;
 putchar(c);
 do {
 if (c == '\n'){
 ++nl;
 }
 if( c == '\t'){
 ++t1;
 }
 if ( c == ' '){
     ++s1;
 }
 }while ((c = getchar()) != EOF);
 
 printf(" new line count is:%d\n new tap count is :%d\n new spaces count is:%d\n", nl,t1,s1);
 return 0;

}
