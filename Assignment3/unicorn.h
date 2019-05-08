#ifndef UNICORN_H
#define UNICORN_H

#include "creature.h"

class Unicorn : public Creature {
	protected:
		int mirror;	
	public:
		Unicorn();
		int attack();
		int defend();
		int condition(int attack, int defend);
		int life(int damage);
		void special(int choice);
};

#endif
