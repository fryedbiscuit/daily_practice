/* Find the largest palindrome made from the product of two-digit numbers. */
#include <stdio.h>
typedef char bool;

bool is_palindrome(unsigned long number){
	char digits[20];
	char n_digits = 0;
	char is_palindrome = 1;

	while (number > 0) {
		digits[n_digits] = number % 10;
		number /= 10;
		n_digits++;
	}

	for (int i = 0;i < n_digits; i ++) {
		if (digits[i] != digits[n_digits - i - 1]) {
			is_palindrome = 0;
			break;
		}
	}

	return is_palindrome;
}

int main () {
	long limit = 999;
	long largest_palindrome = 0;
	long product;

	for (long n1 = 100; n1 <= limit; n1++){
		for(long n2 = 100; n2 <= limit; n2++) {
			product = n1 * n2;
			if (is_palindrome(product) && product > largest_palindrome) {
				largest_palindrome = product;
			}
		}
	}
	printf("%ld\n", largest_palindrome);
}
