#ifndef BLUEMEN_H
#define BLUEMEN_H

#include "creature.h"

class Bluemen : public Creature {
	protected:
		int ID;
	public:
		Bluemen();
		int getID(){
			return ID;
		}
		string getName(){
			return name;
		}
		int attack();
		int defend();
		int condition(int attack, int defend);
		int life(int damage);
};

#endif
