#include "sort_data.h"

using namespace std;

/*
 * test array
 * intuts - pArray: pointer to array
 * 	      - *sort(int *): pointer to member function with input as int pointer
 * sorts an array pArray using function *sort
 */
void sort_data::test(int *pArray, void (sort_data::*sort)(int *) ) {
	print_array(pArray);
	(this->*sort)(pArray);
	print_array(pArray);
	cout << endl;
}

/*
 * test all
 * inputs - none
 * tests all variations of sorting
 */
void sort_data::test_all() {
	
	//pointer to sort_data function
	typedef void (sort_data::*pFunc) (int *);  

	//list of sort functions
	pFunc funcList[] = { &sort_data::selection_sort, &sort_data::insertion_sort,
						 &sort_data::q_sort};
	//sort type names
	char* type[] = {"Selectoin Sort", "Insertion Sort", "Quik Sort"};

	//number of functions to iterate
	int funcNum  = sizeof funcList / sizeof pFunc;

	for (int i = 0; i < 3; i++) {
		set_arrays();
		cout << type[i] << endl
			 <<	"--------------------------\n";
		cout << "Increasing\n";
		test(pInc,funcList[i]);
		cout << "Decreasing\n";
		test(pDec,funcList[i]);
		cout << "Random\n";
		test(pRnd,funcList[i]);
	}
	del_arrays(); //free memory
}

/*
 * set_arrays
 * inputs - none
 * dynamically sets increasing, decreasing and, random arrays
 */
void sort_data::set_arrays() {
	pInc = new int[SIZE];
	pDec = new int[SIZE];
	pRnd = new int[SIZE];

	array_increasing(pInc);
	array_decreasing(pDec);
	array_random(pRnd);
}

/* 
 * del_arrays
 * inputs - none
 * deallocates array memory
 */
void sort_data::del_arrays() {
	delete [] pInc;
	delete [] pDec;
	delete [] pRnd;
}

/*
 * array_increasing
 * imputs - pointer to array
 * defines an array if increasing values
 */
void sort_data::array_increasing(int *A) {
	for (int i = 0;  i < SIZE; i++) {
		A[i] = i+1;
	}
}

/*
 * array_increasing
 * imputs - pointer to array
 * defines an array if decreasing values
 */
void sort_data::array_decreasing(int *A) {
	int max = SIZE;
	for (int i = 0;  i < SIZE; i++) {
		A[i] = max - i;
	}
}

/*
 * array_increasing
 * imputs - pointer to array
 * defines an array if random values
 */
void sort_data:: array_random(int *A) {
	for (int i = 0;  i < SIZE; i++) {
		A[i] = rand() % 100;
	}
}

/*
 * print_array
 * imputs - pointer to array
 * prints all elements in an array
 */
void sort_data::print_array(int *A) {
	for (int i = 0; i < SIZE; i++) {
		printf("%d",A[i]);
		if(i != SIZE-1)
			printf(",");
	}
	printf("\n");
}




