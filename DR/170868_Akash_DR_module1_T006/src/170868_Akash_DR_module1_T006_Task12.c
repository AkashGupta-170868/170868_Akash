/*
 * Descriptions:this function is about that prints every word at new line
 * Author : Akash Gupta
 * Created at : 10-02-2026
 * Modified at : 10-02-2026
 */

#include <stdio.h>
#include <stdint.h> 
 int newline(){
     int8_t c;
     
  while ((c = getchar()) != EOF) {
 if(c == ' '|| c == '\t' || c == '\n'){
     printf("\n");
 }else
 putchar(c);
 }
return 0;
 }

