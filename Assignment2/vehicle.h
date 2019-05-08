#ifndef VEHICLE_H
#define VEHICLE_H

#include<iostream>
#include<string>

using namespace std;

class Vehicle{

	friend class List;

	protected:
		int lot, mile, mpg, price;
		string make, model, color;
	public:
		Vehicle();
		//miles here?
		
};

#endif
