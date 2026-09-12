#include <stdio.h>
#include <stdlib.h>

int main(){
	char* buffer = malloc(100);
	fgets(buffer, 100, stdin);
	long n = atol(buffer);

	while(n != 1){
		printf("%ld ",n);
		if(n % 2){
			n = (n * 3) + 1;
		} else {
			n = n / 2;
		}
	}
	printf("%ld\n",n);
}
