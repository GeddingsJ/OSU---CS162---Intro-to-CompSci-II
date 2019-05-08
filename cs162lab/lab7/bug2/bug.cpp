#include <iostream>
using namespace std;

int main(){
	#ifdef DEBUG
		cout << "Error" << endl;
	#else 
		cout << "Clear" << endl;
	#endif

}
