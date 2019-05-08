#include<iostream>
#include<string>

#include "item.h"
//#include "list.h"

using namespace std;

int main(){
	Item item;	
	//List list;
	
	string i;
	double u;
	int b;
	double p;

	cout << "Insert item: item, unit, buy, price" << endl;
	cin >> i >> u >> b >> p;
	item.setItem(i, u, b, p);
	item.showItem();
	//cout << item.getExtendedPrice;	
	
	return 0;
}
