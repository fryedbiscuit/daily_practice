#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
long min(long a, long b, long c) {
	// return the smallest of the arguments
	long min = a;
	if (b < min) min = b;
	if (c < min) min = c;
	return min;
}

int main() {
	// FILE* input = fopen("example.txt", "r");
	FILE* input = fopen("input.txt", "r");
	
	char* line_buffer = malloc(100);
	int nread = 0;
	size_t llenght = 0;

	long l,w,h;
	long a,b,c;
	long result = 0;

	while ((getline(&line_buffer,&llenght,input)) != -1) {
		sscanf(line_buffer,"%ldx%ldx%ld", &l,&w,&h);
		result += (2 * l * w) + (2 * w * h) + (2 * h * l) + min(l*w, w*h, l*h);
	}

	printf("They should order %ld feet.\n", result);
}
