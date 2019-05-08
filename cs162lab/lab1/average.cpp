
#include <iostream>
using namespace std;

double avg (int size, int array[]) {

	double average = 0;
	int summation = 0;

	for (int i = 0; i < size; i++) {
		summation += array[i];
	}
	
	average = summation / size;
	
	return average;
}
