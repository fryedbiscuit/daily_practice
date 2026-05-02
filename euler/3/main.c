/* What is the largest prime factor of 600851475143 */
/* simple brute force. tries all numbers, but clears out all the multiples*/
#include <stdio.h>
int main() {
	long number = 600851475143;
	long divisor = 1;

	while (number > 1) {
		divisor++;

		while (number % divisor == 0) {
			number /= divisor;
		}
	}

	printf("largest factor is %ld\n", divisor);
}
