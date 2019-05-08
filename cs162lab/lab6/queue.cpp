#include <iostream>

using namespace std;

struct Node{
	char value;
	Node *next;
	Node *previous;
};

class Queue{
	protected:
		Node *back;
		Node *front;
	public:
		Queue();
		void addQ(char value);
		char removeQ();
};

Queue::Queue(){
	back = NULL;
	front = NULL;
}

void Queue::addQ(char newValue){

	Node *tempAdd = new Node;
	
	tempAdd -> value = newValue;
	tempAdd -> next = NULL;

	if(front == NULL){
		front = tempAdd;
	}else{
		back -> next = tempAdd;
	}
	
	back = tempAdd;
	
}

char Queue::removeQ(){
	if(front == NULL){
		cout << "Empty" << endl;
	}else{
		char removed = front -> value;

		Node *temp = front -> next;
		delete front;
		front = temp;

		return removed;
	}
}

void menu(){
	cout << "[1] Add" << endl;
	cout << "[2] Remove" << endl;
	cout << "[3] End " << endl;
}

int main(){
	Queue *start = NULL;
	start = new Queue;

	char value;
	char removed;
	int choice;
	bool quit = false;

	while(quit == false){
		menu();
		cin >> choice;

		switch (choice){
			case 1:
				cout << "Enter add value: ";
				cin >> value;
				start -> addQ(value);
				break;
			case 2:
				removed = start -> removeQ();
				cout << "Removed " << removed << endl;
				break;
			case 3: 
				quit = true;
				break;
		}
	}
	return 0;
}
