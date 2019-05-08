#ifndef GAME_H
#define GAME_H

#include "floor.h"
#include "actor.h"
#include "swan.h"
#include "player.h"

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>

using namespace std;

class Game{
	protected:
		string floorName;
		int totalFloor;
		int currentFloor;
		int popTick;
		int row;
		int col;
		char** mapLevel;		
		Actor** roster;
	public:
		Floor floor;
		void setFloor();
		Actor** getRoster();
		void eject();
	
};

#endif







