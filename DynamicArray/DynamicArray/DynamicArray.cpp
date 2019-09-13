
#include "pch.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void set_all_elem(int * & d_arr, int value, int length);

int main(int argc, char * argv[])
{
	// pointer for dynamically allocating array
	int * dynamic_array;

    // Enforce proper usage of program.
	if (argc != 2) {
		cout << "Usage: " << argv[0] << " <num elements>\n";
		return 1;
	}

	// dynamically allocate array based off of input.
	int num_elements = atoi(argv[1]);
	dynamic_array = new int[num_elements];

	// set the elements
	set_all_elem(dynamic_array, 13, num_elements);

	// display all array contents.
	cout << "Printing a dynamically allocated array "
		 << "with " << argv[1] << " elements.\n";

	for (int i = 0; i < num_elements; i++) {
		cout << "index[" << i << "]: " << dynamic_array[i] << "\n";
	}
	cout << endl;

	// deallocate memory
	delete[] dynamic_array;

	return 0;
}

void set_all_elem(int * & d_arr, int value, int length) {
	d_arr[0] = -1; // marks the beginning
	for (int i = 1; i < length - 1; i++) {
		d_arr[i] = value;
	}
	d_arr[length - 1] = -10; // marks the end;
}
