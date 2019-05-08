
#include <iostream>
using namespace std;

double sum (int size, int array[]) {

	double summation = 0;

	for (int i = 0; i < size; i++) {
		summation += array[i];
	}

	return summation;
}
