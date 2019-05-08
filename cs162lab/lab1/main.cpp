
#include <iostream>
#include "average.h"
#include "summation.h"

using namespace std;

int main () {

	int size = 0, array[size];
	double average, summation;
	cout << "How many inputs?" << endl;
	cin >> size;
	cout << endl;

	for (int i = 0; i < size; i++) {
		cout << "Enter a number: " << endl;
		cin >> array[i];
		cout << endl;
	}

	average = avg (size, array);
	summation = sum (size, array);

	cout << "The average is: " << average << endl;
	cout << "The sum is: " << summation << endl;

	return 0;
}

