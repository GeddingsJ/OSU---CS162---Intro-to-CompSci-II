#ifndef BABAYAGA_H
#define BABAYAGA_H

#include "creature.h"

class Babayaga : public Creature{
	protected:
		int specialBonus;
		int ID;
	public:
		Babayaga();
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
		void special(int condition);
};

#endif
