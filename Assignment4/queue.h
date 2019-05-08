#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "creature.h"
using namespace std;

struct Node{
	Creature* value;
	Node *next;
	Node *previous;
};

class Queue{
	public:
		Node *back;
		Node *front;
	
		Queue();
		void addQ(Creature* value);
		Creature* removeQ();	
};

#endif
