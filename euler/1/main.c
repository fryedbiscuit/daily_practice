/* What is the sum of all the multiples of 3 or 5 below 1000 */
#include <stdio.h>


int main() {
	int sum = 0;
	for (int n = 0; n < 1000; n++) {
		if ((n % 3 == 0) | ( n % 5 == 0)) {
			sum += n;
		}
	}

	printf("%d\n", sum);
}
