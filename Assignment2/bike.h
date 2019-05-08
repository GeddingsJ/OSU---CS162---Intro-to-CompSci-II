#ifndef BIKE_H
#define BIKE_H

#include "vehicle.h"

#include<iostream>
#include<string>

using namespace std;

class Bike : public Vehicle{
	protected:
		//unique bike traits
	public:
		Bike();
		int validBike(int x);
		Bike checkBike();
		
};

#endif
