#ifndef SORT_H
#define SORT_H
#include "sort_data.h"

template <class t> inline 
void swap(t* A, int x, int y) {
	t temp;
	temp = A[x];
	A[x] = A[y];
	A[y] = temp;
}


template<class t>
bool sorted_ascending(t A[]) {
	for ( int i = 0; i < SIZE-1; i++ ) {
		if (A[i] > A[i+1]) 
			return false;
	}
	return true;
}


template <class t> inline
void selection_sort(t A[]) {
	if (sorted_ascending(A))
		return;

	size_t min;

	for (int i = 0; i < SIZE; i ++) {
		min = i;
		for (int j = i+1; j < SIZE; j++) {	
				if (A[j] < A[min])
					min = j;
		}

		if (min != i) 
			swap(A, i, min);
	}
}


template <class t>
void insertion_sort(t A[]) {
	for (int j = 1; j < SIZE; j ++) {
		t x = A[j];
		int i = j - 1;
		while ( i >= 0 && A[i] > x ) {
			A[i+1] = A[i];
			i--;
		}

		A[i+1] = x;
	}
}

#endif