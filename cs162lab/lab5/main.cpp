#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

class Encryption{
	protected:
		ifstream inFile;
		ofstream outFile;
		int key;
		//char transCh;
	public:

		void setKey(int k);	

		Encryption(char *inFileName, char *outFileName);
		~Encryption();
		//pure virtual function
		virtual char transform(char ch) /*const*/ = 0;

		//Do the actual work
		void encrypt();
};

void Encryption::setKey(int k){
	key = k;
}

Encryption::Encryption(char *inFileName, char *outFileName){
	inFile.open(inFileName);
	outFile.open(outFileName);
	if(!inFile){
		cout << "The file " << inFileName
			<< " cannot be opened.";
		exit(1);
	}
	if(!outFile){
		cout << "The file " << outFileName
			<< " cannot be opened.";
		exit(1);
	}	
}

Encryption::~Encryption(){
	inFile.close();
	outFile.close();
}

void Encryption::encrypt(){
	char ch;
	char transCh;
	inFile.get(ch);

	cout << "Encryption key set to: " << key << endl;

	while(!inFile.fail()){
		transCh = transform(ch);
		outFile.put(transCh);
		inFile.get(ch);
	}
}

class SimpleEncryption : public Encryption{
	public:
		char transform(char ch) /*const*/{
			return ch + key;
		}
		SimpleEncryption(char *inFileName, char *outFileName)
		: Encryption(inFileName, outFileName){
				
		}
};
/*
class SimpleDecryption : public Encryption{
	public:
		char transform(char ch) const{
			return ch - key;
		}
		SimpleDecryption(char *inFileName, char *outFileName)
		: Encryption(inFileName, outFileName){
		}
};
*/
class TransformEncryption : public SimpleEncryption{
	public:
		char transform(char ch) /*const*/{
			return ch - key;
		}
		TransformEncryption(char *inFileName, char *outFileName)
		: SimpleEncryption(inFileName, outFileName){
		}
};

int main(){
	char inFileName[80], outFileName[80]/*, transFileName[80]*/;
	int key;
	cout << "Enter name of file to encrypt: ";
	cin >> inFileName;
	cout << "Enter name of file to receive "
		<< "the encrypted text: ";
	cin >> outFileName;
	
	//cout << "Enter name of transFileName: " << endl;
	//cin >> transFileName;

	cout << "Enter encryption key: ";
	cin >> key;

	SimpleEncryption obfuscate(inFileName, outFileName);
	//SimpleDecryption fix(inFileName, outFileName);
	TransformEncryption tE(outFileName, outFileName);

	obfuscate.setKey(key);		
	obfuscate.encrypt();
	//fix.encrypt();
	
	//cout << "Enter transFileName: " << endl;
	//cin >> transFileName;

	tE.setKey(key);
	tE.encrypt();

	return 0;
}
