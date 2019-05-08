/*prog name: bike.cpp
 * author: jacob geddings
 * date: 1/29/2016
 * desc: child to vehicle -- bike type
 * input: bike data
 * output: stored bike data
 */

#include "bike.h"

#include<iostream>
#include<string>

using namespace std;

Bike::Bike() : Vehicle(){
	//unique identifiers
}

/*func: validBike
 * desc: input check
 * para: integer
 * prec: request to input bike
 * postc: clear input
 */
int Bike::validBike(int x){
	int check = 0;

	while(check == 0){
		if(cin.fail() || x < 1){
			cin.clear();
			cin.ignore();
			cout << "Invalid Entry. " << endl;
			cin >> x;
		}else{
			check = 1;	
		}
	}
	return x;	
}

/*func: checkBike
 * desc: add all relevant bike data
 * para: none
 * prec: called from main
 * postc: fills out for array
 */
Bike Bike::checkBike(){
	Bike bike;
	
	int user = 0;
	string userInput;

	cout << "Enter lot #: " << endl;
	cin >> user;
	bike.lot = bike.validBike(user);

	cout << "Enter Make: " << endl;
	cin >> userInput;
	bike.make = userInput;
	
	cout << "Enter Model: " << endl;
	cin >> userInput;
	bike.model = userInput;

	cout << "Enter Color: " << endl;
	cin >> userInput;
	bike.color = userInput;

	cout << "Enter Miles: " << endl;
	cin >> user;
	bike.mile = bike.validBike(user);

	return bike;
}	
