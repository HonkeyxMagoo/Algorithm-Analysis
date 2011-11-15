#include <stdio.h>
#include <time.h>
#include <ctime>
#include "sort.h"

#define INCREASING 0
#define DECREASING 1
#define RANDOM 2

#define SELECTION 0
#define INSERTION 1


void test(int, int);

int main() {

	test(INCREASING, SELECTION);
	test(DECREASING, SELECTION);
	test(RANDOM, SELECTION);
	
	test(INCREASING, INSERTION);
	test(DECREASING, INSERTION);
	test(RANDOM, INSERTION);

	system("pause");
	return 0;
}

void test(int T, int S) {
	char *type;
	clock_t start, finish;
	double runtime;


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

	

	switch(S) {
		case 0:
			printf("Selection Sort\n");
			//print_array();
			start = clock();
			selection_sort(A);
			finish = clock();
			//print_array();
			break;
		case 1:
			printf("Insertion Sort\n");
			//print_array();
			start = clock();
			insertion_sort(A);
			finish = clock();
			//print_array();
			break;
	}

	runtime = (finish - start) / CLOCKS_PER_SEC;
	printf("Runtime for %s was %f\n\n", type, runtime);
}