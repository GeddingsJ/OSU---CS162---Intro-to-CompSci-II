#ifndef CREATURE_H
#define CREATURE_H

#include<stdlib.h>

#include<iostream>

using namespace std;

class Creature{
	protected:
		int armor;
		int strength;
	public:
		virtual int attack() = 0;
		virtual int defend() = 0;
		virtual int condition(int attack, int defend) = 0;
		virtual int life(int strength) = 0;
		virtual void special(int condition);
};

#endif
