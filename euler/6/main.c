/* Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum. */

#include <stdio.h>

int main() {
	int sum_of_squares = 0;
	int square_of_sums = 0;

	for (int n = 1;n <= 100;n++) {
		sum_of_squares += n * n;
		square_of_sums += n;
	}
	square_of_sums *= square_of_sums;

	printf("%d\n", square_of_sums - sum_of_squares);
}
