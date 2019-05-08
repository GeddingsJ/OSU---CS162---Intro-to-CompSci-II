#include<iostream>
#include<string>

#include"item.h"
//#include"list.h"

using namespace std;

Item::Item(){
	item = "item";
	unit = 1.0;
	buy = 1;
	price = 1.0;	
}

void Item::setItem(string i, double u, int b, double p){
	item = i;
	unit = u;
	buy = b;
	price = p;
}

void Item::showItem(){
	cout << item << endl;
	cout << unit << endl;
	cout << buy << endl;
	cout << price << endl;
}

double Item::getExtendedPrice(int buy, double price){
	double total = 0;
	total = buy * price;

	return total;
}
