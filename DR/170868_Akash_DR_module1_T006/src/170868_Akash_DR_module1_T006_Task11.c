/*
 * Descriptions:this function is about that counts the new word , charcter and new line and prints its value at the end
 * Author : Akash Gupta
 * Created at : 09-02-2026
 * Modified at : 10-02-2026
 */



#include <stdio.h>
 #define IN 1 /* inside a word */
 #define OUT 0 
 
 int word_count()
 {
 int c, nl, nw, nc, state;
 state = OUT;
 nl = nw = nc = 0;
 while ((c = getchar()) != EOF) {
 ++nc;
 if (c == '\n')
 ++nl;
 if (c == ' ' || c == '\n' || c == '\t')
 state = OUT;
 else if (state == OUT) {
 state = IN;
 ++nw;
 }
 }
 printf("%d %d %d\n", nl, nw, nc);
 }

