#ifndef item_h
#define item_h

#include<iostream>
//#include<string>

using namespace std;

class Item{
	private:
		string item;
		double unit;
		int buy;
		double price;
	public:
		Item();
		void setItem(string i, double u, int b, double p);
		void showItem();
		double getExtendedPrice(int buy, double price);
		
};

#endif
