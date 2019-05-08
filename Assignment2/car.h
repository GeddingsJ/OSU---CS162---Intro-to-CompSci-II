#ifndef CAR_H
#define CAR_H

#include"vehicle.h"

#include<iostream>
#include<string>

using namespace std;

class Car : public Vehicle{
	protected:
		//car specific traits
	public:
		Car();
		int validCar(int x);
		Car checkCar();
	
};

#endif
