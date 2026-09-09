#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

int count_vowels(char* str) {
	char* vowels = "aeiou";
	int vowel_count = 0;
	int str_size = strlen(str);

	for(int i = 0; i < str_size;i++) {
		for (int j = 0;j < 5;j++){
			if(str[i] == vowels[j]) vowel_count++;
		}
	}

	return vowel_count;
}

bool has_double_char(char* str){
	int str_size = strlen(str);
	bool has_double = false;
	for(int i = 0;i < str_size;i++) {
		if(str[i] == str[i + 1]) {
			return true;
		}
	}
	return false;
}

bool has_bad_string(char* str) {
	char* bad_strings[] = {"ab", "cd","pq","xy"};	
	int str_size = strlen(str);

	for (int i = 0; i < str_size; i++){
		for(int j = 0;j < 4; j++) {
			if(str[i] == bad_strings[j][0]) {
				if(str[i + 1] == bad_strings[j][1]) {
					return true;
				}
			}
		}
	}

	return false;
}

int main() {
	FILE* input = fopen("input.txt", "r");
	char buffer[100];
	int good_strings = 0;
	
	while(fgets(buffer, 100, input) != NULL){
		bool has_bad = has_bad_string(buffer);
		bool has_double = has_double_char(buffer);
		bool enough_vowels = count_vowels(buffer) >= 3;
		if (!has_bad && has_double && enough_vowels) {
			good_strings++;
		}
	}

	printf("I've found %d strings!\n", good_strings);
}
