#ifndef UNICORN_H
#define UNICORN_H

#include "creature.h"

class Unicorn : public Creature {
	protected:
		int mirror;
		int ID;	
	public:
		Unicorn();
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
		void special(int choice);
};

#endif
