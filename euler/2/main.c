/* What is the sum of all the even fibonacci numbers below four million*/
#include <stdio.h>
int main() {
	long limit = 4000000;

	long a = 1;
	long b = 2;
	long c = 0;

	long sum = 2;

	while(1) {
		c = a + b;
		if (c > limit) break;
		if (c % 2 == 0) sum += c;

		a = b;
		b = c;
	}

	printf("%ld\n",sum);
}
