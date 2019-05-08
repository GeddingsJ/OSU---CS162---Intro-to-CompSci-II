#include <iostream>
using namepspace std;

int main(){
	#ifdef DEBUG
		cout << "Error" << endl;
	#else
		cout << "Clear" << endl;
	#endif
}
