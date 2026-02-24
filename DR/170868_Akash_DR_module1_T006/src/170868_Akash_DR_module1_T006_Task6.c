/*
 * Descriptions:this function is about that verify the getchar() != EOF 
 * Author : Akash Gupta
 * Created at : 09-02-2026
 * Modified at : 10-02-2026
 */




#include <stdio.h>
void is_eof()
{
	int c;
	c = getchar() ;
if  (c == EOF){
    printf("0");
}else {
    printf("1");
}

}
