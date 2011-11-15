#ifndef SORT_DATA_H
#define SORT_DATA_H
#include <iostream>

#define SIZE 10000
int A[SIZE];

void array_increasing() {
	for (int i = 0;  i < SIZE; i++) {
		A[i] = i+1;
	}
}

int max = SIZE;
void array_decreasing() {
	for (int i = 0;  i < SIZE; i++) {
		A[i] = max - i;
	}
}

void array_random() {
	for (int i = 0;  i < SIZE; i++) {
		A[i] = rand() % 100;
	}
}

void print_array() {
	for (int i = 0; i < SIZE; i++) {
		printf("%d",A[i]);
		if(i != SIZE-1)
			printf(",");
	}
	printf("\n");
}


#endif