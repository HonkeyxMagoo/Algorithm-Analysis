#include <iostream>
#include "sort_data.h"

using namespace std;

int main() {
	
	int x;
	cout << "This program tests various sorting algorithms and displas there runtime\n"
		 << "Please enter the size of the arrays you would like to test:";
	
	cin >>x;
	cout << "Running tests on input size " << x << endl << endl;

	sort_data test;
	test.set_size(x);
	test.test_all();
	
	
	system("pause");
	return 0;

}


