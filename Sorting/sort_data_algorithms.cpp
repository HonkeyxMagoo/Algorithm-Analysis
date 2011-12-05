#include "sort_data.h"
#define MAX 100001

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

void sort_data::partition(int *A, int &i, int &j, int q) {
	int tmp;
	      while (i <= j) {
            while (A[i] < q)
                  i++;
            while (A[j] > q)
                  j--;
				  
            if (i <= j) {
                  tmp = A[i];
                  A[i] = A[j];
                  A[j] = tmp;
                  i++;
                  j--;
            }
      };
}

void sort_data::quickSort(int *A, int l, int r) {
      int i = l, j = r;
      int q = A[(l + r) / 2];
 
	partition(A, i, j, q);
	if (l < j)
        quickSort(A, l, j);
	if (i < r)
		quickSort(A, i, r);
}

void sort_data::q_sort(int *A) {
	int l = 0;
	quickSort(A, l, SIZE-1);
}


void sort_data::counting_sort(int *A) {
  
  int *temp = new int[SIZE];
 
  int *counter = new int[MAX + 1];
  for (int i = 0; i <= MAX; i++)
    counter[i] = 0;
  
  for (int j = 0; j < SIZE; j++)
    counter[A[j]] = counter[A[j]] + 1;

  for (int k = 1; k <= MAX; k++)
    counter[k] += counter[k - 1];

  for (int i = SIZE - 1; i >= 0; i--) {
    temp[counter[A[i]] - 1] = A[i];
    --counter[A[i]];
  }

  for (int i = 0; i < SIZE; i++)
    A[i] = temp[i];
  delete [] temp;
  delete [] counter;
}

int sort_data::getSmaller(int x, int y) {
	if(x < y)
		return x;
    
    else
		return y;   
}

void sort_data::merge(int *A, int l, int r, int pLeft, int pRight) {
	int length = r - l;
    int pivot = length/2;

	int *subarray = new int[SIZE];

    for(int i = 0; i < length; i++) {
		if(pLeft < l + pivot)
			if(pRight == r || getSmaller(A[pLeft], A[pRight]) == A[pLeft]) {
				subarray[i] = A[pLeft];
				pLeft++;
			}
			else{
				subarray[i] = A[pRight];
				pRight++;
			}
    }

    for(int i = l; i < r; i++) {
        A[i] = subarray[i - l];
    }

	delete [] subarray;
}

void sort_data::mergesort(int *A, int l, int r) {
    if(r == l + 1)
		return;
    else {
        int length = r - l;
        int pivot = length/2;
        int pLeft = l, pRight = l + pivot;

        mergesort(A, l, l + pivot);
        mergesort(A, l + pivot, r);

		merge(A, l, r, pLeft, pRight);
    }
}

void sort_data::m_sort(int *A) {
		mergesort(A, 0, SIZE);
}

int sort_data::parent(int i) {
	return i/2;
}
int sort_data::left(int i) {
	return 2*i;
}
int sort_data::right(int i) {
	return 2*i +1;
}

void sort_data::max_heapify(int *A, int i) {
	int max = 0;
	int l = left(i);
	int r = right(i);

	if (l <= heapSize && A[l] > A[i])
		max = l;
	else
		max = i;
	if (r <= heapSize && A[r] > A[max])
		max = r;
	if (max != i) {
		swap(A, i, max);
		max_heapify(A, max);
	}
}

void sort_data::build_max_heap(int * A) {
	heapSize = SIZE-1;

	for (int i = (SIZE-1)/2; i >= 0; i--) 
		max_heapify(A, i);
}

void sort_data::h_sort(int *A) {
	build_max_heap(A);

	for (int i = SIZE-1; i>=1; i--) {
		swap(A, 0, i);
		heapSize = heapSize-1;
		max_heapify(A, 0);
	}
}



