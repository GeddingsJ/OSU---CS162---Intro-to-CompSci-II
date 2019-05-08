/*filename: game.cpp
author: jacob geddings
date: 3/13/2016
desc: handles the placing of movable units
input: n/a
output: character positions for the floor
*/
#include "game.h"

/*func: setFloor
desc: carries out initial file reading for the map and places units
para: n/a
input: file to read
output: characters for floor to map
*/
void Game :: setFloor(){
	ostringstream temp;
	string floorName = "floor_";
	string f;
	int currentFloor = 1;
	int y = 0, x = 0;
	char square;	

	temp << floorName << currentFloor;
	f += temp.str();

	ifstream inStream; 
	inStream.open(f.c_str());
	if(inStream.fail()){
		cout << "File failed to open." << endl;
		exit(1);
	}

	inStream >> row >> col;
	
	char** mapTemp = new char*[col];
	for(int i = 0; i < col; i++){
		mapTemp[i] = new char[row];
	}

	while(inStream.get(square)){
		if(square != '\n'){
			mapTemp[y][x] = square;
			x++;
			if (x == col){
				y++;
				x = 0;
			}
		}
	}


	mapLevel = mapTemp;


	roster = new Actor*[999];
	roster[0] = new Player;	
	
	int z = 1;

	for(int i = 0; i < row; ++i){
		for(int j = 0; j < col; ++j){
			if(mapLevel[i][j] == 'E'){
				roster[0] -> setPos(i, j);
			}
			if(mapLevel[i][j] == 'S'){
				roster[z] = new Swan;
				roster[z] -> setPos(i, j);
				z++;
				mapLevel[i][j] = ' ';
			}
		}
	}
	
	floor.setFloor(col, row, mapLevel, roster);
	floor.display();

	inStream.close();

}

Actor** Game :: getRoster(){
	return roster;
}

/*func: eject
desc: handles throwing player back to start when in proximity to swan
para: n/a
precon: player and swan must exist
postcon: if player is snagged get pushed to start
*/
void Game :: eject(){
	int pC, pR, sC, sR, startR, startC;

	int check = 0;

	pC = roster[0] -> getCol();
	pR = roster[0] -> getRow();
	sC = roster[1] -> getCol();
	sR = roster[1] -> getRow();

	for(int i = 0; i < row; ++i){
		for(int j = 0; j < col; ++j){
			if(mapLevel[i][j] == 'E'){
				startC = i;
				startR = j;
			}
		}
	}

	if( pC == sC - 1 && pR == sR -1){
		check = 1;
	}else if(pC == sC -1 && pR == sR){
		check = 1;
	}else if(pC == sC - 1 && pR == sR + 1){
		check = 1;
	}else if(pC == sC && pR == sR - 1){
		check = 1;
	}else if(pC == sC && pR == sR + 1){
		check = 1;
	}else if(pC == sC + 1 && pR == sR - 1){
		check = 1;
	}else if(pC == sC + 1 && pR == sR){
		check = 1;
	}else if(pC == sC + 1 && pR == sR + 1){
		check = 1;
	}else{
		check = 0;
	}

	if(check == 1){
		roster[0] -> setPos(startC, startR);
		cout << "Placed at starting position." << endl;
	}
}
