#ifndef PLAYER_H
#define PLAYER_H

#include "actor.h"

#include <iostream>
#include <stdlib.h>

using namespace std;

class Player : public Actor{
	protected:
		int apples, keys, timer;
	public:
		void setPos(int c, int r); 
		void move(int c, int r, char** m);
		int getRow();
		int getCol();
		int getTimer();
		void setTimer(int t);
	
};

#endif
