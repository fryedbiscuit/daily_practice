// a² + b² == c² with a < b < c
#include <stdio.h>
#include <stdlib.h>

int main() {
	for (unsigned long a = 1;a <= 1000;a++) {
		for (unsigned long b = 1;b <= 1000;b++) {
			for (unsigned long c = 1000;c > 0;c--) {
				if (a < b && b < c) {
					if ((a * a) + (b * b) == (c * c)) {
						if (a + b + c == 1000) {
							printf("%ld\n", a * b * c);
							exit(0);
						}
					}
				} else {
					break;
				}
			}
		}
	}
	exit(1);
}
