#ifndef BARBARIAN_H
#define BARBARIAN_H

#include "creature.h"

class Barbarian : public Creature{
	protected:
		int ID;	
	public:
		Barbarian();
		int getID(){
			return ID;	
		}
		string getName(){
			return name;
		}
		int attack();
		int defend();
		int condition(int attack, int defend);
		int life(int strength);
};

#endif
