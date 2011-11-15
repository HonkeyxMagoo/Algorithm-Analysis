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
template<class T>
bool is_sorted_b(T input[]) {
bool sorted = true;

for ( int z = 0; z < SIZE-1; z++ ) {
if (input[z] > input[z+1]) {
sorted = false;
return sorted;
}
}

return sorted;
}


template <class t> inline
void selection_sort(t* A) {
	if (is_sorted_b(A))
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


#endif