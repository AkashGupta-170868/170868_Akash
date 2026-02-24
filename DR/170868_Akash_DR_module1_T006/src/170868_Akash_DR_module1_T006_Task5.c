/*
 * Descriptions:this function is about that prints the value of tempreture in a reverse order
 * Author : Akash Gupta
 * Created at : 09-02-2026
 * Modified at : 10-02-2026
 */




#include <stdio.h>
void reverse_order()
{
 int fahr;
 for (fahr = 300; fahr >= 0; fahr = fahr - 20)
 printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));

}
