#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAYSIZ 10000

typedef struct { int x; int y; } House;

void visit(int x, int y, House* arr[], int* count) {
	for (int i = 0; i < *count; i++) {
		if(arr[i]->x == x && arr[i]->y == y) {
			return;
		}
	}

	arr[*count] = malloc(sizeof(House));
	*arr[*count] = (House){x,y};

	*count = *count + 1;
};

int main(void) {
	FILE* input = fopen("input.txt", "r");

	House* houses[ARRAYSIZ] = {0};
	int count = 0;

	int x = 0;
	int y = 0;
	int rx = 0;
	int ry = 0;

	int c;

	bool is_santa = true;

	visit(x,y,houses,&count);
	while ((c = fgetc(input)) != EOF) {
		if (is_santa) {
			switch (c) {
				case '^':
					y--;
					break;
				case 'v':
					y++;
					break;
			case '<':
					x--;
					break;
				case '>':
					x++;
					break;
			}
			visit(x,y,houses,&count);
		} else {
			switch (c) {
				case '^':
					ry--;
					break;
				case 'v':
					ry++;
					break;
				case '<':
					rx--;
					break;
				case '>':
					rx++;
					break;
			}
			visit(rx,ry,houses,&count);
		}
		is_santa = !is_santa;
	}

	printf("Santa has visited %d houses\n", count);
}
