/*prog name: car.cpp
 * author: jacob geddings
 * date 1/29/2016
 * desc car child
 * input n/a
 * output data for array
 */

#include "car.h"

#include<iostream>
#include<string>

using namespace std;

Car::Car() : Vehicle(){
	//special traits of car
}

/*func: validCar
 * desc: check for correct input
 * para: integer
 * prec: called from checkCar
 * postc: clear an input
 */
int Car::validCar(int x){
	int check = 0;	

	while(check == 0){
		if(cin.fail() || x < 1){
			cin.clear();
			cin.ignore();
			cout << "Invalid Entry, try again. " << endl;
			cin >> x;
		}else{
			check = 1;
		}
	}

	return x;
}

/*func: checkCar
 * desc: inputs all variables for a single car
 * para: none
 * prec: call from main
 * postc: send to list
 */
Car Car::checkCar(){
	Car car;

	int user = 0;
	string userInput;

	cout << "Enter lot #: " << endl;
	cin >> user;
	car.lot = car.validCar(user);
	user = 0;
	
	cout << "Enter Make: " << endl;
	cin >> userInput;
	car.make = userInput;
	//user = 0;

	cout << "Enter Model: " << endl;
	cin >> userInput;
	car.model = userInput;
	//user = 0;

	cout << "Enter Color: " << endl;
	cin >> userInput;
	car.color = userInput;
	//user = 0;

	cout << "Enter miles: " << endl;
	cin >> user;
	car.mile = car.validCar(user);
	user = 0;

	return car;
}
