#ifndef BABAYAGA_H
#define BABAYAGA_H

#include "creature.h"

class Babayaga : public Creature{
	protected:
		int specialBonus;
	public:
		Babayaga();
		int attack();
		int defend();
		int condition(int attack, int defend);
		int life(int strength);
		void special(int condition);
};

#endif
