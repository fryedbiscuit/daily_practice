/* What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20? */
#include <stdio.h>
#include <stdbool.h>

long find_number() {
	bool is_divisible = true;

	// loop over all positives over 20
	for (long number = 20;;number += 20) {

		// Test if the number is divisible
		is_divisible = true;
		for (long n = 20; n > 2 && is_divisible; n--) { 
			// If not divisible set to false
			if (number % n) is_divisible = false;
		}

		// If still divisible return else go to next number
		if(is_divisible) return number;
	}
}

int main() {
	printf("%ld\n",find_number());
}
