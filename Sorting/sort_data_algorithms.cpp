#include "sort_data.h"


void sort_data::swap(int* A, int x, int y) {
	int temp;
	temp = A[x];
	A[x] = A[y];
	A[y] = temp;
}


bool sort_data::sorted_ascending(int *A) {
	for ( int i = 0; i < SIZE; i++ ) {
		if (A[i] > A[i+1]) 
			return false;
	}
	return true;
}


void sort_data::selection_sort(int *A) {
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



 void sort_data::insertion_sort(int *A) {
	for (int j = 1; j < SIZE; j ++) {
		int x = A[j];
		int i = j - 1;
		while ( i >= 0 && A[i] > x ) {
			A[i+1] = A[i];
			i--;
		}

		A[i+1] = x;
	}
}

 int sort_data::partition(int *A, int l, int r, int p) {
	int pVal = A[p];
	int sIndex = l - 1;
	for (int i = l; i < r; i++) {
		if (A[i] < pVal) {
			sIndex += 1;
			swap(A, i, sIndex);
		}
	}
	swap(A, sIndex+1, r);
	return sIndex+1;
}

void sort_data::q_sort(int *A) {
	int l = 0;
	int r = SIZE-1;
	quiksort(A, l, r);
}

void sort_data::quiksort(int *A, int l, int r) {
	if (l < r) {
		int p = r;
		int pNew = partition(A, l, r, p);
		quiksort(A, l, pNew-1);
		quiksort(A, pNew+1, r);
	}
}
