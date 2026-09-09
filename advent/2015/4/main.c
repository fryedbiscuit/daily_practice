#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "lib/md5.h"
#include "lib/md5.c"

void hash_as_hex(uint8_t* hash, char* buffer){
	char piece[6];
    for(int i = 0; i < 16; ++i){
        snprintf(piece,6,"%02x", hash[i]);
		strcat(buffer,piece);
    }

}

int main(){
	// char* input= "abcdef"; // Test
	// uint64_t num = 609043;
	char* input= "yzbqklnj";
	uint64_t num = 0;

	while(1){
		char buffer[100] = {0};
		uint8_t hash[16] = {0};
		char hex[33] = {0};

		snprintf(buffer,100,"%s%ld",input,num);
		md5String(buffer, hash);
		hash_as_hex(hash, hex);

		bool has_zeroes = true;

		for(int i = 0;i < 6; i++){
			if(hex[i] != '0'){
				has_zeroes = false;
				break;
			}

		};

		if(has_zeroes){
				printf("result: %ld\n", num);
				return 0;
		}

		num++;	
	}
}
