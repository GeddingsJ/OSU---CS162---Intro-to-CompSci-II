#include <iostream>

using namespace std;

struct Node{
	Node *next;
	char value;
};

class Stack{
	protected:
		Node *top;
		int count;
	public:
		Stack(){
			top = NULL;
			count = 0;
		}
		// push
		void add(char value);
		// pop
		char remove();
};

void Stack::add(char newValue){
	Node *temp = new Node();
	temp -> value = newValue;
	temp -> next = top;
	top = temp;
	count++;
}

char Stack::remove(){
	if(top == NULL){
		cout << "Stack is empty" << endl;
	}else{
		char removed = top -> value;

		Node *temp = top -> next;
		delete top;
		top = temp;

		count--;
	
		return removed;
	}		
}

void menu(){
	cout << "Stack-like Behavior" << endl;
	cout << "[1] Add" << endl;
	cout << "[2] Remove" << endl;
	cout << "[3] End" << endl;
}

int main(){
	Stack *head = NULL;
	head = new Stack;
	
	char value;
	char removed;
	int choice;
	bool quit = false;

	while(quit == false){
		menu();
		cin >> choice;
		
		switch(choice){
			case 1:
				cout << "Enter a value: ";
				cin >> value;
				head -> add(value);
				break;
			case 2:
				removed = head -> remove();
				cout << "Removed: " << removed << endl;
				break;
			case 3:
				quit = true;
				break;
		}
	}
		
	return 0;
}
