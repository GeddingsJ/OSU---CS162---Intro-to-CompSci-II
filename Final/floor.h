#ifndef FLOOR_H
#define FLOOR_H

#include "actor.h"
#include "swan.h"
#include "player.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Floor{
	protected:
		char** tiles;
		int col, row;
		Actor** roster;
	public:
		Floor();
		void display();
		void setFloor(int c, int r, char** t, Actor** ros);
		int getRow();
		int getCol();
		char** getTiles();
		
};

#endif

