#ifndef BLUEMEN_H
#define BLUEMEN_H

#include "creature.h"

class Bluemen : public Creature {
	protected:

	public:
		Bluemen();
		int attack();
		int defend();
		int condition(int attack, int defend);
		int life(int damage);
};

#endif
