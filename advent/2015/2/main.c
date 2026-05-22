#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
long max3(long a, long b, long c) {
	long max = a;
	if (b > max) max = b;
	if (c > max) max = c;
	return max;
}

long min3(long a, long b, long c) {
	// return the smallest of the arguments
	long min = a;
	if (b < min) min = b;
	if (c < min) min = c;
	return min;
}

long get_ribbon_length(long l, long w, long h) {
	long wrap_lenght = (l + w + h - max3(l,w,h)) * 2;
	long bow_lenght = l * w * h;
	return wrap_lenght + bow_lenght;
}

int main() {
	// FILE* input = fopen("example.txt", "r");
	FILE* input = fopen("input.txt", "r");
	
	char* line_buffer = malloc(100);
	int nread = 0;
	size_t llenght = 0;

	long l,w,h;
	long total_area = 0;
	long ribbon_length = 0;

	while ((getline(&line_buffer,&llenght,input)) != -1) {
		sscanf(line_buffer,"%ldx%ldx%ld", &l,&w,&h);
		total_area += (2 * l * w) + (2 * w * h) + (2 * h * l) + min3(l*w, w*h, l*h);
		ribbon_length += get_ribbon_length(l,w,h);
	}

	printf("They should order %ld feet. Plus %ld feet of ribbon.\n", total_area, ribbon_length);
}
