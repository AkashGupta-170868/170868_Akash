/*
* This program prints a histogram of the frequencies of different characters in its input.
* Author: Akash Gupta
* Created: 12 February 2026
*/
#include <stdio.h>
#include <stdint.h>
 
/*
* Function Name: printFreqHistogram()
* Function Description: This function prints histogram of the frequencies of different characters in its input.
* Author: Akash Gupta
* Created: 12 February 2026
*/
 
void printFreqHistogram() {
	int8_t c;
	uint16_t freqArr[256] = {0};
	uint16_t i, j;
	printf("Enter the text and press ctrl + D for the output: ");
	/* Clear leftover input */
        while ((c = getchar()) != '\n' && c != EOF);
 
	while ((c = getchar()) != EOF) {
		if (c >= 0 && c < 256) {
			freqArr[(uint8_t)c]++;
        	}
    	}
    	printf("\nHistogram of character frequencies:\n");
 
    	for (i = 0; i < 256; i++) {
        	if (freqArr[i] > 0) {
			if(i == '\n'){
				printf("\\n: ");
			}else if(i == '\t'){
				printf("\\t: ");
			}else if(i == ' '){
				printf("\\s: ");
			}else if(i == '\r'){
				printf("\\r: ");
			}else{
            			printf("%c : ", (char)i);
			}
			for (j = 0; j < freqArr[i]; j++) {
                		printf("*");
           		}
			printf("\n");
    		}
	}
}
