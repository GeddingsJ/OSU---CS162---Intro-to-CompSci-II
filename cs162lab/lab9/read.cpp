#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>

using namespace std;

int main(int argc, char** argv){
	string fileName, name, next;
	
	name = argv[1];
	char underscore = '_';
	string date;	

	cout << "Enter date: " << endl;
	getline(cin, date);
	fileName = name + underscore + date;
	

	ifstream inStream(fileName.c_str());
	
	if(inStream.fail()){
		cout << "Input file failed. " << endl;
		exit(1);
	}
	
	while(inStream >> next){
		
		cout << next << " " << endl;
	}

	inStream.close();

	return 0;
}
