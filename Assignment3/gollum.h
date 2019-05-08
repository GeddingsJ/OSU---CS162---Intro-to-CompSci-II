#ifndef GOLLUM_H
#define GOLLUM_H

#include "creature.h"

class Gollum : public Creature {
	protected:

	public:
		Gollum();
		int attack();
		int defend();
		int condition(int attack, int defend);
		int life(int strength);
};

#endif
