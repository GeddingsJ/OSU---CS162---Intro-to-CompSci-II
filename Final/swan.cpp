#include "swan.h"

void Swan :: setPos(int c, int r){
	col = c;
	row = r;
}

int Swan :: getRow(){
	return row;
}

int Swan :: getCol(){
	return col;
}

void Swan :: move(int c, int r, char** m){
	int dice;

	dice = rand() % 4 + 1;		
	
	if(dice == 1){
		if(m[col - 1][row] == ' '){
			setPos(col - 1, row);
		}
	}else if(dice == 2){
		if(m[col][row - 1] == ' '){
			setPos(col, row - 1);
		}
	}else if(dice == 3){
		if(m[col + 1][row] == ' '){
			setPos(col + 1, row);
		}
	}else if(dice == 4){
		if(m[col][row + 1] == ' '){
			setPos(col, row + 1);
		}
	}


}
