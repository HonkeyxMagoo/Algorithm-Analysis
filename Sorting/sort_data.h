#ifndef SORT_DATA_H
#define SORT_DATA_H
#include <iostream>
#include <time.h>

class sort_data {
	private:
		int SIZE;							
		int *pInc, *pDec, *pRnd;	
		void set_arrays();
		void del_arrays();
		void array_increasing(int *A);
		void array_decreasing(int *A);
		void array_random(int *A);
		bool sorted_ascending(int *A);
		void swap(int* A, int x, int y);	//swap array elements
		void selection_sort(int *A);
		void insertion_sort(int *A);
		int partition(int *A, int l, int r, int p);
		void quiksort(int *A, int l, int r);
		void q_sort(int *A);

	public:
		sort_data() { srand(time(0)); }
		void set_size(const int s) { SIZE = s;}
		void test(int *, void (sort_data::*sort)(int *) );
		void test_all();
		void print_array(int *);

};



#endif