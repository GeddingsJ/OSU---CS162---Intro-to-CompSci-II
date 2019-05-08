/*Prog Name: Main.cpp
 *Authot: Jacob Geddings
 *Date: 1/29/2016
 *Desc: stores main for sales
 * I/O: Takes in vehicle, list, car, and bike
 */ 

#include "vehicle.h"
#include "list.h"
#include "car.h"
#include "bike.h"

#include<iostream>
#include<string>

using namespace std;
/*Func: menu
 *Desc: Display generic menu for user
 *Para: None
 *PreC: main had to start
 *PostC: cout display of menu nav
 */
void menu(){
	cout << "Assignment 2 MENU" << endl;
	cout << "[1] Add CAR" << endl;
	cout << "[2] Add BIKE" << endl;
	cout << "[3] SEARCH" << endl;
	cout << "[4] Display ALL" << endl;
	cout << "[5] Add MILEAGE" << endl;
	cout << "[6] PURCHASE" << endl;
	cout << "[7] CLOSE" << endl;
}

/*Func: getInput
 *Desc: Error check for navigation of menu
 *Para: None
 *PreC: main calls it
 *PostC: Ensures allowed navigation
 */ 
int getInput(int SIZE){
	int input = 0;
	cin >> input;
	cin.clear();
	cin.ignore();

	while (input < 1 || input > SIZE){
		cout << "Invalid entry, try again" << endl;
		cin >> input;
		cin.clear();
		cin.ignore();
	}
	return input;
}

/*Func: main
 * Desc: Primary for program
 * Para: None
 * PreC: None
 * PostC: Complete program
 */
int main(){
	List list;
	Car car;
	Bike bike;

	const int SIZE = 7;
	int input = 0;
	int userSearch;

	while(input != 7){
		menu();
		input = getInput(SIZE);

		switch(input){
			case 1:
				//add car
				car = car.checkCar();				
				list.inputCar(list, car);
				list.displayCar();
				break;
			case 2:
				//add bike
				bike = bike.checkBike();
				list.inputBike(list, bike);
				list.displayBike();
				break;
			case 3:
				//search
				cout << "Search car[1] or bike[2]: " << endl;
				cin >> userSearch;
				if(userSearch == 1){
					list.searchFind();
				}else if(userSearch == 2){
					list.searchFindBike();
				}
				break;
			case 4:
				//display all
				list.displayCar();
				list.displayBike();
				break;
			case 5:
				//add mileage
				list.addMiles();
				break;
			case 6:
				//purchase
				break;
			case 7:
				input = 7;
				break;
		}	
	}
	return 0;
}
