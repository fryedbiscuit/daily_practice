#include <stdio.h>

int main() {
	FILE* input_file = fopen("input.txt","r");
	char buffer[BUFSIZ];
	long total_read = 0;
	long nread = 0;
	long floor = 0;
	long basement_entry = 0;

	while((nread = fread(buffer,sizeof(char),BUFSIZ,input_file))) {
		for (int i = 0;i < nread; i++){
			if (buffer[i] == '(') {
				floor += 1;
			} else if (buffer[i] == ')') {
				floor -= 1;
			}

			if ((floor == -1) && (basement_entry == 0)) {
				basement_entry = total_read + i + 1;
			}
		}
		total_read += nread;
	}

	printf("Santa should go to floor %ld!\nHe entered the basement on position %ld\n", floor, basement_entry);
}
