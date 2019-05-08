#include "floor.h"
#include "game.h"
#include "actor.h"
#include "swan.h"
#include "player.h"

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv){
	
	int check = 0, r, c, t;
	char** tiles;

	Game game;
	Actor** roster;

	if(argc != 2){
		cout << "Incorrect Entry. " << endl;
		exit(1);
	}else if(argv[1] == "0"){
		cout << "Level doesn't exist" << endl;
		exit(1);
	}

	game.setFloor();
	tiles = game.floor.getTiles();
	r = game.floor.getRow();
	c = game.floor.getCol();
	
	while(check == 0){
		roster = game.getRoster();	
	
		for(int i = 0; i < 2; ++i){
			roster[i] -> move( c, r, tiles);
		}
		t = roster[0] -> getTimer();
		if(t > 0){
			t--;
			cout << "IMMUNITY FOR: " << t << " TURNS" << endl;
			roster[0] -> setTimer(t);
		}else{
			game.eject();
		}
		game.floor.display();	
	}
	
	return 0;
}


