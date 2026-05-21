#include <stdio.h>

int main() {
	FILE* input_file = fopen("input.txt","r");
	char buffer[BUFSIZ];
	long nread;
	long floor = 0;

	while((nread = fread(buffer,sizeof(char),BUFSIZ,input_file))) {
		for (int i = 0;i < nread; i++){
			if (buffer[i] == '(') {
				floor += 1;
			} else if (buffer[i] == ')') {
				floor -= 1;
			}
		}
	}

	printf("Santa should go to floor %ld!\n", floor);
}
