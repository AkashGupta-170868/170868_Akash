/*
 * Descriptions:Write a loop equivalent to the for loop above without using && or ||.
 * Author : Akash Gupta
 * Created at : 09-02-2026
 * Modified at : 10-02-2026
 */
#include <stdio.h>
#include <stdint.h>
int16_t loop_eq(){
	int8_t idx =0 ;
	int16_t limit = 100;
	int8_t charcter;
	char str[limit];

	while (1) {
		if ( idx >= limit -1 ) {
			break;
		}
		charcter = getchar() ;
		if ( charcter == EOF){
			break;
		}
		if ( charcter == '\n') {
			break;
		}
		str[idx] = charcter;
		idx++;
	}
	str[idx] = '\0';

	printf("%s\n", str);

	return 0;
}
