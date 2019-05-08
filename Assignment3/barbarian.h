#ifndef BARBARIAN_H
#define BARBARIAN_H

#include "creature.h"

class Barbarian : public Creature{
	protected:
	
	public:
		Barbarian();
		int attack();
		int defend();
		int condition(int attack, int defend);
		int life(int strength);
};

#endif
