/*description :Functions like isupper can be implemented to save space or to save time. Explore both possibilities. 
Author:Akash Gupta
created At:24-04-2026
modified at: 24-04-2026
 */

#include <stdio.h>
#include <time.h>
#include <ctype.h>
#define MAX 256

/*description :isupper_01(); function that search if the char a capital or not ? and it time complexicity is o(1).
Author:Akash Gupta
created At:20-04-2026
modified at: 20-04-2026
 */
int isupper_O1(char c) {
	return (c >= 'A' && c <= 'Z');
}

char uppercase_list[] = {
	'A','B','C','D','E','F','G','H','I','J',
	'K','L','M','N','O','P','Q','R','S','T',
	'U','V','W','X','Y','Z'
};
/*description :isupper_0n(); function that search if the char a capital or not ? and it time complexicity is o(n).
Author:Akash Gupta
created At:20-04-2026
modified at: 20-04-2026
 */
int isupper_On(char c) {
	for (int i = 0; i < 26; i++) {
		if (uppercase_list[i] == c) {
			return 1;
		}
	}

	return 0;

}

/*description :time_space_main(); function that handle the interation and display the time taken by the both function.
Author:Akash Gupta
created At:24-04-2026
modified at: 24-04-2026
 */
int time_space_main() {
	long iterations;
	char test_char = 'G';
	clock_t start, end;
	double time_O1, time_On;
	volatile int result;

	printf("Enter number of iterations: ");
	scanf("%ld", &iterations);

	if (iterations <= 0) {
		printf("Invalid input\n");
		return 1;
	}
	start = clock();
	for (long i = 0; i < iterations; i++) {
		result = isupper_O1(test_char);
	}
	end = clock();
	time_O1 = (double)(end - start) / CLOCKS_PER_SEC;

	start = clock();
	for (long i = 0; i < iterations; i++) {
		result = isupper_On(test_char);
	}
	end = clock();
	time_On = (double)(end - start) / CLOCKS_PER_SEC;

	printf("\nO(1) time: %f seconds\n", time_O1);
	printf("O(n) time: %f seconds\n", time_On);

	return 0;
}





