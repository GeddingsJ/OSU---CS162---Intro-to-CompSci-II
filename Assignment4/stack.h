#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "creature.h"
using namespace std;

struct sNode{
	sNode *next;
	Creature* value;
};

class Stack{
	public:
		sNode *top;
		int count;
	
		Stack(){
			top = NULL;
			count = 0;
		}
		void add(Creature* value);
		Creature* remove();
};

#endif
