#ifndef "list_h"
#define "list_h"

#include<iostream>
#include<string>

using namespace std;

class List{
	private:
		string lname;
		double lunit;
		int lbuy;
		double lprice;
	public:
		void setList(string n, double u, int b, double p);
		void storeArray(string n, double u, int b, double p);
};


#endif
