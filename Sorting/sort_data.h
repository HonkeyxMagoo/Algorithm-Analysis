#ifndef SORT_DATA_H
#define SORT_DATA_H
#include <iostream>
#include <time.h>

class sort_data {
	private:
		int SIZE;
		int heapSize;
		int parent(int i);
		int left(int i);
		int right(int i);
		int *pInc, *pDec, *pRnd;
		int getSmaller(int x, int y);
		void set_arrays();
		void del_arrays();
		void array_increasing(int *A);
		void array_decreasing(int *A);
		void array_random(int *A);
		bool sorted_ascending(int *A);
		void swap(int* A, int x, int y);	//swap array elements
		void selection_sort(int *A);
		void insertion_sort(int *A);
		void partition(int *A, int &i, int &j, int q);
		void quickSort(int *A, int l, int r);
		void merge(int *A, int l, int r, int pLeft, int pRight);
		void mergesort(int *A, int l, int r);
		void m_sort(int *A);
		void q_sort(int *A);
		void counting_sort(int *A);
		void h_sort(int *A);
		void build_max_heap(int *A);
		void max_heapify(int *A, int i);

	public:
		sort_data() { srand(time(0)); }
		void set_size(const int s) { SIZE = s;}
		void test(int *, void (sort_data::*sort)(int *) );
		void test_all();
		void print_array(int *);

};



#endif