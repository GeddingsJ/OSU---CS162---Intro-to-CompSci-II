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

void Floor :: setFloor(int c, int r, char** t , Actor** ros){
	col = c;
	row = r;
	tiles = t;
	roster = ros;
}

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
