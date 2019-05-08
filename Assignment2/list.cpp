/*Prog Name: list.cpp
 * Author: Jacob Geddings
 * Date: 1/29/2016
 * Desc: Primary workhorse -- mutates and displays most data through here
 * Input: Accepts data from vehicle and it's children as well as main
 * Output: Feedback from user requests/inputs
 */

#include "list.h"

#include<set>

/*Func: List
 * Desc: Default Constructor
 * Parameter: None
 * PreC: None
 * PostC: arrays constructed
 */
List::List(){
	size = 2;
	position = 0;
	positionBike = 0;
	array = new Vehicle[size];
	arrayBike = new Vehicle[size];
}

/*Func: inputCar
 * Desc: Fills array with child 'car' info
 * Para: Takes in list object and reference to car object
 * PreC: Car must be started
 * PostC: Fills array with data
 */
void List::inputCar(List list, const Vehicle& car){
	array[position] = car;
	position++;
}

/*Func: inputBike
 * Desc: Fills array with bike info
 * Para: List object and reference to bike object
 * PreC: Bike must be started
 * PostC: Fills array with bike data
 */
void List::inputBike(List list, const Vehicle& bike){
	arrayBike[positionBike] = bike;
	positionBike++;
}

/*func: displayCar
 * Desc: Display all elements of car array
 * Para: None
 * PreC: Vehicle default constructor at minimum must be operating
 * PostC: Output visual of all car data stored
 */
void List::displayCar(){
	for (int i = 0; i < size; ++i){
		cout << "Lot: " << array[i].lot << endl;
		cout << "Make: " << array[i].make << " Model: " << array[i].model << endl;
		cout << "Color: " << array[i].color << " Miles: " << array[i].mile << endl;
	}
	cout << "----------" << endl;
	//array[position] = carcycle;
	//position++;
}

/*func: displayBike
 * Desc: Display all elements of bike array
 * Para: None
 * PreC: Vehicle default constructor at minimum
 * PostC: Display all bike array data
 */
void List::displayBike(){
	for(int i = 0; i < size; ++i){
		cout << "Lot: " << arrayBike[i].lot << endl;
		cout << "Make: " << arrayBike[i].make << " Model: " << arrayBike[i].model << endl;
		cout << "Color: " << arrayBike[i].color << " Miles: " << arrayBike[i].mile << endl;
	
	}
	cout << "----------" << endl;
}

/*func: searchFind
 * desc: Search for requested lot num and output all associated data
 * Para: none
 * PreC: lot num must be filled 
 * PostC: Displays if a match exists
 */
void List::searchFind(){
	int typeSearch, searchRequest, check = 0;
	string search;
	/*
	cout << "Integer or String Variable Search? [1] or [2]" << endl;
	while(check == 0){
		cin >> typeSearch;
		if(cin.fail() || typeSearch > 2 || typeSearch < 1){
			cin.clear();
			cin.ignore();
			cin >> typeSearch;
		}else{
			check = 1;
		}
	}
	*/
	//if(typeSearch == 1){
		cout << "Input integer to search lot: " << endl;
		cin >> searchRequest;
	
		for(int i = 0; i < size; ++i){
			if(array[i].lot == searchRequest){
				cout << "MATCH FOUND:  " << endl;
				cout << "Lot number: " <<  array[i].lot << endl;
				cout << "Make: " << array[i].make << "Model: " <<  array[i].model << endl;
				cout << "Color: " <<  array[i].color << "Miles: " <<  array[i].mile << endl;
				cout << "----------" << endl;
				//displayCar();	
			}//else if(array[i].mile == searchRequest){
			//	cout << "Match found. " << endl;
				//displayCar();
			//}
		}
	/*}else if(typeSearch == 2){
		cout << "Input string to search by: " << endl;
		cin >> search;
		
		for(int i = 0; i < size; ++i){
			if(array[i].make == search || array[i].model == search || array[i].color == search){
				cout << "Match found. " << endl;
				//displayCar();
			}
		}	
	}*/
}

/*func: searchFindBike
 * desc: search for match of lot num in bike array
 * para: none
 * prec: lot num must have data
 * postc: output matching data 
 */
void List::searchFindBike(){
	int searchRequest = 0;

	cout << "Input integer to search lot: " << endl;
	cin >> searchRequest;

	for(int i = 0; i < size; ++i){
		if(arrayBike[i].lot == searchRequest){
			cout << "MATCH FOUND: " << endl;
			cout << "Lot Number: " << arrayBike[i].lot << endl;
			cout << "Make: " << arrayBike[i].make << "Model: " << arrayBike[i].model << endl;
			cout << "Color: " << arrayBike[i].color << "Miles: " << arrayBike[i].mile << endl;
			cout << "----------" << endl;
		}
	}
}

/*func: addMiles
 * desc: Enables additional mileage to be tacked on
 * para: none
 * prec: vehicle must exist first
 * postc: miles added to total
 */
void List::addMiles(){
	int lot, addMiles, choice;
	
	cout << "Car[1] or bike[2]" << endl;
	cin >> choice;
	if(choice == 1){
		cout << "Enter lot # " << endl;
		cin >> lot;
		cout << "Enter added miles: " << endl;
		cin >> addMiles;

		for(int i = 0; i < size; ++i){
			if(array[i].lot == lot){
				array[i].mile += addMiles;
				cout << "Lot: " << array[i].lot << endl;
				cout << "Miles: " << array[i].mile << endl;
				cout << "---------" << endl;
			}
		}
	}else if(choice == 2){
		cout << "Enter lot #: " << endl;
		cin >> lot;
		cout << "Enter added miles: " << endl;
		cin >> addMiles;

		for(int i = 0; i < size; ++i){
			if(arrayBike[i].lot == lot){
				arrayBike[i].mile =+ addMiles;
				cout << "Lot: " << arrayBike[i].lot << endl;
				cout << "Miles: " << arrayBike[i].mile << endl;
				cout << "----------" << endl;
			}
		}
	}
}
