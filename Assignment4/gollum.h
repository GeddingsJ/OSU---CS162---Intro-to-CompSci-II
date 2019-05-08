#ifndef GOLLUM_H
#define GOLLUM_H

#include "creature.h"

class Gollum : public Creature {
	protected:
		int ID;
	public:
		Gollum();
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
