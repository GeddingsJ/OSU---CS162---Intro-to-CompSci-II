#include "player.h"

void Player :: setPos(int c, int r){
	col = c;
	row = r;
}

int Player :: getRow(){
	return row;
}

int Player :: getCol(){
	return col;
}

int Player :: getTimer(){
	return timer;
}

void Player :: setTimer(int t){
	timer = t;
}

void Player :: move(int c, int r, char** m){	
	char input;
	int check = 0;

	while(check == 0){
		cout << "enter move" << endl;
		cin >> input;
		if(cin.fail()){
			cin.clear();
			cin.ignore();
			cout << "Bad entry try again." << endl;
		}/*else if(input != 'w' || input != 'a' || input != 's' || input != 'd' || input != 'q' || input != 'u' ||  input != 'e'){
			//cin.clear();
			//cin.ignore();
			cout << "Invalid character try again." << endl;
		}*/
		if( input == 'w'){
			//setPos(col - 1, row);
			if(m[col - 1][row] == ' ' || m[col - 1][row] == 'K' || m[col - 1][row] == 'A'){
				setPos(col - 1, row);
				if(m[col][row] == 'K'){
					if(keys < 4){
						keys++;
						m[col][row] = ' ';
					}
				}else if( m[col][row] == 'A'){
					if(apples < 3){
						apples++;
						m[col][row] = ' ';
					}
				}
			}else if(m[col - 1][row] == 'D' && keys > 0){
				m[col - 1][row] = ' ';
				setPos(col - 1, row);
				keys--;
			}
			check++;
		}else if( input == 'a'){
			if(m[col][row - 1] == ' ' || m[col][row - 1] == 'K' || m[col][row - 1] == 'A'){
				setPos(col, row - 1);
				if(m[col][row] == 'K'){
					if( keys < 4){
						keys++;
						m[col][row] = ' ';
					}
				}else if( m[col][row] == 'A'){
					if( apples < 3){
						apples++;
						m[col][row] = ' ';
					}
				}
			}else if(m[col][row - 1] == 'D' && keys > 0){
				m[col][row - 1] = ' ';
				setPos(col, row - 1);
				keys--;
			}	
			check++;
		}else if( input == 's'){
			if(m[col + 1][row] == ' ' || m[col + 1][row] == 'K' || m[col + 1][row] == 'A'){
				setPos(col + 1, row);
				if(m[col][row] == 'K'){
					if(keys < 4){
						keys++;
						m[col][row] = ' ';
					}
				}else if( m[col][row] == 'A'){
					if(apples < 3){
						apples++;
						m[col][row] = ' ';
					}
				}
			}else if(m[col + 1][row] == 'D' && keys > 0){
				m[col + 1][row] = ' ';
				setPos(col + 1, row);
				keys--;
			}
			check++;
		}else if( input == 'd'){
			if(m[col][row + 1] == ' ' || m[col][row + 1] == 'K' || m[col][row + 1] == 'A'){
				setPos(col, row + 1);
				if(m[col][row] == 'K'){
					if(keys < 4){
						keys++;
						m[col][row] = ' ';
					}
				}else if (m[col][row] == 'A'){
					if(apples < 3){
						apples++;
						m[col][row] = ' ';
					}
				}
			}else if(m[col][row + 1] == 'D' && keys > 0){
				m[col][row + 1] = ' ';
				setPos(col, row + 1);
				keys--;
			}
			check++;

		}else if( input == 'q'){
			exit(1);
		}else if(input == 'e' && apples > 0){
			timer += 15;
			cout << "Apple has been consumed." << endl;
			apples--;
		}else{
			cout << "Invalid character entry. " << endl;
		}
	}	
}
