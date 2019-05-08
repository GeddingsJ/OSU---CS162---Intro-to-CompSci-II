#include<iostream>
#include<string>
#include<math.h>
#include<cctype>
#include<cstring>
using namespace std;

void validString(string check){
	int digit = 1;
	char special = 'a';

	char* array = new char [check.length() + 1];
	strcpy(array, check.c_str());

	for(int i = 0; i < 10; ++i){
		if(isdigit(array[i])){
			throw digit;
		}
	}
	
	for(int j = 0; j < 10; ++j){
		if(ispunct(array[j])){
			throw special;
		}
	}
}

int main(){
	int first = 0, second = 0;
	string one, two, three;
	int check = 0;

	cout << "Enter first integer: " << endl;
	try{
		cin >> first;
		if(cin.fail()){
			throw first;
		}
	}

	catch(int first){
		cout << "Bad entry" << endl;
	}

	cout << "Enter second integer: " << endl;
	try{
		cin >> second;
		if(cin.fail()){
			throw second;
		}
	}

	catch(int second){
		cout << "Bad entry. " << endl;
	}

	cout << "total = " << pow(first, second) << endl << endl;

	cin.ignore(10000, '\n');

	cout << "Enter first string: " << endl;
	try{ 
		getline(cin, one);
		validString(one);
	//	cin.clear();
	//}
	/*catch(int one){
		cout << "No integers" << endl;
	}	
	catch(char one){
		cout << "No special characters" << endl;
	}*/

	cout << "Enter second string: " << endl;
	//try{
		getline(cin, two);
		validString(two);
	}
	catch(int digit){
		cout << "No integer " << endl;
	}	
	catch(char special){
		cout << "No special character" << endl;

	}
	three = one + two;
	cout << three << endl;
}
