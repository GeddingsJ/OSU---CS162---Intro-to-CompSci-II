#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>

using namespace std;

int main(int argc, char** argv){
	/*
	if(argc != 2){
		cout << "Error: " << argv[0] << " <ONID>" << endl;
	}*/
	
	string date = "_2March2016";
	string fileName, input;
	
	fileName = argv[1] + date;
		
	ofstream outStream(fileName.c_str());

	if(outStream.fail()){
		cout << "Logger file failed to open." << endl;
		exit(1);
	}
	
	cout << "Text to add to file (enter '--' on last line to stop)" << endl;
	while(input != "--"){
		getline(cin, input);	
		outStream << input << endl;
	}
	outStream.close();

	return 0;
}
