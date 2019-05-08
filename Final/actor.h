#ifndef ACTOR_H
#define ACTOR_H

/*#include "game.h"
#include "swan.h"
#include "player.h"
#include "floor.h"*/


class Actor{
	protected:
		int row, col;
		char symbol;
	public:
		virtual void setPos(int c, int r) = 0;
		virtual void move(int c, int r, char** m) = 0;
		virtual int getRow() = 0;
		virtual int getCol() = 0;
		virtual int getTimer();
		virtual void setTimer(int t);


};

#endif
