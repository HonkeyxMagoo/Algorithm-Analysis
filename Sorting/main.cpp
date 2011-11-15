#include <stdio.h>
#include "sort.h"

#define INCREASING 0
#define DECREASING 1
#define RANDOM 2

void test(int);

int main() {

	printf("SELECTION SORT\n");
	test(INCREASING);
	test(DECREASING);
	test(RANDOM);
	
	return 0;
}

void test(int T) {
	char *type;

	switch(T) {
		case 0: array_increasing();
				type = "Increasing";
				break;
		case 1: array_decreasing();
				type = "Decreasing";
				break;
		case 2: array_random();
				type = "Random";
				break;
	}

	//print_array();
	
	selection_sort(A);
	
	//print_array();



	//printf("Runtime for %s was %u\n\n", type);
}