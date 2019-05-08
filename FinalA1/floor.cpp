/*Prog: floor.cpp
author: Jacob Geddings
date: 3/13/2016
desc: primarily just the display of the board
input: n/a
output: getRow, getCol, getTiles
*/

#include "floor.h"

Floor :: Floor(){
	int row = 0;
	int col = 0;
}

int Floor :: getRow(){
	return row;
}

int Floor :: getCol(){
	return col;
}

char** Floor :: getTiles(){
	return tiles;
}

/*func: setFloor
desc: assigns the necessary variables for display
para: two ints, a char** and a class**
precon: must have para
postcon: sets correct map values
*/
void Floor :: setFloor(int c, int r, char** t , Actor** ros){
	col = c;
	row = r;
	tiles = t;
	roster = ros;
}

/*func: display
desc: show the map in it's current phase/turn
para: n/a
precon: map must be filled via setFloor
postcon: cout the map for player use
*/
void Floor :: display(){

	int pC = roster[0] -> getCol();
	int pR = roster [0] -> getRow();

	int sC = roster[1] -> getCol();
	int sR = roster[1] -> getRow();

	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			if(i == pC && j == pR){
				cout << 'P';
			}else if( i == sC && j == sR){
				cout << 'S';
			}else{
				cout << tiles[i][j];
			}
		}
		cout << endl;
	}
}
