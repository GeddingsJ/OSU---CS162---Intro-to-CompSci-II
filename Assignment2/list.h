#ifndef LIST_H
#define LIST_H

#include "vehicle.h"
#include "car.h"
#include "bike.h"

#include<iostream>
#include<string>

using namespace std;

class List {
	protected:
		Vehicle *array;
		Vehicle *arrayBike;
		int size, position, positionBike;
		
	public:
		List();
		void inputCar(List, const Vehicle&);
		void inputBike(List, const Vehicle&);

		void displayCar();
		void displayBike();

		void searchFind();
		void searchFindBike();

		void addMiles();

};

#endif
