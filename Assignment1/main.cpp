/****
 *Name: Jacob Geddings
 *Class: CS 162 - 001
 *Assignment: Tic Tac Toe
 *Desc: Enable one or two players to play a game of tic tac toe on a grid ranging from 2x2 to 5x5 -- allow repeats
 ****/
#include<iostream>
#include<math.h>
#include<cstdlib>
using namespace std;

class Game {
	public:

	/*
 	*Function: validCheck
 	*Description: Ensure submitted data fits within selected data type
	*Parameters: Accepts single integer
	*PreCon: Variable must be initialized
	*PostCon: Variable will have correct data	
  	*/
	int validCheck(int x){ //Ensure correct data type entry
		int check = 0;

		while (check == 0){
			if(cin.fail()){
				cin.clear();
				cin.ignore();
				cout << "Invalid entry" << endl;
				cin >> x;
			}else{
				check = 1;
			}
		}
		return x;
	}

	/*
 	*Function: validMove
 	*Description: Ensure user will not overstep boundaries
 	*Parameters: Accepts 3 integers, grid with x and y coords
 	*PreCon: Grid must be made, coordinates must be requested
	*PostCon: Coordinates will correctly operate within grid bounds
 	*/
	void validMove(int grid, int x, int y){ //No overstepping map bounds
		int check = 0;
		while(check == 0){
			if(x > grid || y > grid){
				cout << "Invalid coordinate -- try again: " << endl;
				cin >> x;
				x = validCheck(x);
				cin >> y;
				y = validCheck(y);
			}else{
				check = 1;
			}
		}
			
	}
	/*
 	*Function: validBoard
 	*Description: Ensure initial board generation complies with requirements
 	*Parameters: Single integer, determines XxY of grid
 	*PreCon: User must indicate a desired board size
	*PostCon: Will ensure board size complies with assignment
 	*/ 
	int validBoard(int x){ //Correct map constraints
		int check = 0;

		while (check == 0){
			if (x > 1 && x < 6){
				check = 1;
			}else{
				cout << "Invalid grid size (2 = 2x2  and 5 = 5x5)" << endl;
				cin >> x;
				x = validCheck(x);
			}
		}
		return x;
	}
	/*
 	*Function: setPlayer
 	*Description: Checks how many players will be participating
 	*Paraents: Single integer, player count
 	*PreCon: Request of how many will play
 	*PostCon: Ensure player count complies with assignment
 	*/ 
	int setPlayer(int x){ //Accepting player count
		int check = 0;		

		while (check == 0){
			if(cin.fail()){
				cin.clear();
				cin.ignore();
				cin >> x;
			}
			if (x == 2){
				cout << "Player 1 and Player 2 confirmed" << endl;
				check = 1;
			}else if (x == 1){
				cout << "Player 1 confirmed" << endl;
				check = 1;
			}else{
				cout << "Invalid entry: bad player count -- try again." << endl;
				check = 0;
				cin >> x;
			}
		}
		return x;
	}
	/*
 	*Function: setBoard
 	*Description: Construct board based on accepted grid parameters
 	*Parameter: Accepts single integer, determines height and width
 	*PreCon: An accepted grid must be entered
 	*PostCon: A board filled with asterisks is generated
 	*/ 
	char** setBoard(int x){ //Construct board
		
		char** board = new char*[x];
		for (int i = 0; i < x; ++i){
			board[i] = new char[x];
		
			for (int j = 0; j < x; ++j){
				board[i][j] = '*';
				cout << board[i][j];
			}
			cout << "\n";
		}
		return board;
	}
	/*
 	*Function: displayBoard
 	*Desc: What will display the midgame progress
 	*Para: Need integer for width/height and the board array
 	*PreCon: Dimensions of board and first creation of board
 	*PostCon: Display any midgame changes to board
 	*/ 
	void displayBoard(int x, char** board){ //Up to date display of board
		for (int i = 0; i < x; ++i){
			for (int j = 0; j < x; ++j){
				cout << board[i][j];
			}
		cout << "\n";
		}
	}
	
	/*
		for (int i = 0; i < x; ++i){
			delete [] board[i];
		}
		
		while(valid == 0){
			int a = 0;
			int b = 0;
		
			cout << "Player 1 enter x coord: " << endl;
			cin >> a;

			cout << "Player 1 enter y coord: " << endl;
			cin >> b;
			
			board[a][b] = 'x';
			
			for (int i = 0; i < x; ++i){
				for (int j = 0; j < x; ++j){
					board[i][j] = '*';
					board[a][b] = 'x';
					cout << board[i][j];
				}
				cout << "\n";
			}

			valid = 1;
		}





	
		//for (int i = 0; i < x; ++i){
		//	delete [] board[i];
		//}

		//	board[1][1] = 'x';

		//delete [] board;
		//board[1][1] = 'x';
		//	cout << board[1][1] << endl;
	}
	*/
	/*
 	*Func: twoPlayer
 	*Desc: Game for two players 
 	*Para: Needs integer and array
 	*PreCon: Needs grid and board array
 	*PostCon: Completed two player game
 	*/ 
	void twoPlayer(int x, char** board){ //two player game
		int turn = 0; //Tracks turns
		int check = 0;
		int draw = x * x; //Indicate total squares on map
		char playerOne;
		char playerTwo;
		
		cout << "Player 1 choose: 'x' or 'o' " << endl;
		cin >> playerOne;	

		while (check == 0){
			if (playerOne == 'x'){
				playerTwo = 'o';
				check = 1;
			}else if(playerOne == 'o'){
				playerTwo = 'x';
				check = 1;
			}else{
				cout << "Invalid entry try again " << endl;
				cin >> playerOne;
			}
		}
		
		for(int i = 0; i < draw; ++i){
			int z = 0;
			int y = 0;			
	
			if ((turn%2) == 0){
				cout << "Player One: Choose 'x' and 'y' coordinate. " << endl;
				cin >> z >> y;
				z = validCheck(z);
				y = validCheck(y);
				
				validMove(x, z, y);

				z = z - 1;
				y = y - 1;

				board[z][y] = playerOne;
				displayBoard(x, board);

				turn += 1;
			}else{
				cout << "Player Two: " << endl;
				cin >> z >> y;
				z = validCheck(z);
				y = validCheck(y);

				validMove(x, z, y);				

				z = z - 1;
				y = y - 1;

				board[z][y] = playerTwo;
				displayBoard(x, board);
			
				turn += 1;
			} 				
		}
		cout << "Game Over - Draw " << endl;
	}
	/*
 	*Func: onePlayer
 	*Desc: Single player game with bot
 	*Para: Single integer and single array
 	*PreCon: Grid dimensions and board array
 	*PostCon: Completed game for a single person
 	*/ 
	void onePlayer(int x, char** board){ //One player game
		int turn = 0;
		int check = 0;
		int draw = x * x;
		char playerOne;
		char playerTwo;
		
		cout << "Player 1 choose 'x' or 'o' " << endl;
		cin >> playerOne;

		while(check == 0){
			if(playerOne == 'x'){
				playerTwo = 'o';
				check = 1;
			}else if(playerOne == 'o'){
				playerTwo = 'x';
				check = 1;
			}else{
				cout << "Bad entry try again" << endl;
				cin >> playerOne;
			}
		}
		for(int i = 0; i < draw; ++i){
			int z = 0;
			int y = 0;

			if ((turn%2) == 0) {
				cout << "Player One: choose 'x' and 'y' coordinate." << endl;
				cin >> z >> y;
				z = validCheck(z);
				y = validCheck(y);
				validMove(x, z, y);

				z = z - 1;
				y = y - 1;

				board[z][y] = playerOne;
				displayBoard(x, board);

				turn += 1;
			}else{
				bot(x, board);
			}
		}

	}
	/*
 	*Func: bot
 	*Desc: Automated opponent
 	*Para: Single integer and array
 	*PreCon: Single player selected, dimensions and array passed
 	*PostCon: Will select movements on board
 	*/ 
	char** bot(int x, char** board) {
		int turn = 0;
		int draw = x * x;
		int check = 0;
		int z = 0;
		int y = 0;

		cout << "Bot's turn" << endl;
		while(check = 0){
			z = rand() % draw;
			y = rand() % draw;

			if (board[z][y] != '*') {
				check = 0;
			}else{
				check = 1;
				board[z][y] = 'O';
			}
		}

		board[z][y] = 'o';
		displayBoard(x, board);

		turn += 1;

		return board;
	}
};
/*
 *Func: mai
 *Desc: Starts program
 *Para: N/A
 *PreCon: N/A
 *PostCon: Completed program
 */ 
int main(){
	
	Game game;

	int player = 0;//Total player count
	int x = 0; //Size of map
	int coin = 1; //Replay control
	
	do{
		cout << "Tic-Tac-Toe : How many players (1 or 2)" << endl;
		cin >> player;
		player = game.validCheck(player);
		player = game.setPlayer(player);
		cout << "Insert grid size (2-5): " << endl;
		cin >> x;
		x = game.validCheck(x);
		x = game.validBoard(x);
	
		char** board = game.setBoard(x);
	
		if (player == 2){
			cout << "Correct input per player is (x y): " << endl;
			game.twoPlayer(x, board);
		}else if(player == 1){
			cout << "Correct input is (x y): " << endl;
			game.onePlayer(x, board);
		}
		
		cout << "Want to play another game? 1 for yes, 2 for no " << endl;
		cin >> coin;
		coin = game.validCheck(coin);
		coin = game.setPlayer(coin);

	}while(coin == 1);

	return 0;
}
