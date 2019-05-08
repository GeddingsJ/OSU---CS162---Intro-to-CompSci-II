/*Filename: main.cpp
*Author: Jacob Geddings
*Date: 2/12/2016
*Desc: Start and end of the program
*Input: n/a
*Output: Program
*/
//#include "creature.h"
#include "gollum.h"
#include "barbarian.h"
#include "babayaga.h"
#include "bluemen.h"
#include "unicorn.h"
#include "queue.h"
#include "stack.h"

#include <iostream>

using namespace std;

/*func: menu
*desc: display a menu for user
*para: n/a
*input: n/a
*output: void
*/
void menu(){
	//cout << "MONSTER BATTLE" << endl;
	cout << "---------------" << endl;
	cout << "[1] Gollum" << endl;
	cout << "[2] Barbarian" << endl;
	cout << "[3] Baba Yaga" << endl;
	cout << "[4] Blue Men" << endl;
	cout << "[5] Unicorn" << endl;
}

/*func: m
*desc: pointer array for assigning a monster to player choice
*para: integer
*input: integer
*output: pointer to monster for use
*/
Creature* m(int choice){
	Creature** list;
	
	choice -= 1;

	list = new Creature*[5];

	list[0] = new Gollum;
	list[1] = new Barbarian;
	list[2] = new Babayaga;
	list[3] = new Bluemen;
	list[4] = new Unicorn;

	return list[choice];
}

/*func: red
 * desc: assign red team roster
 * para: team size
 * input: integer
 * output: queue for red team
 */
Queue red(int teamsize){
	Creature* m1;
	Queue red;

	int choice;

	for(int i = 0; i < teamsize; i++){
		cout << "Red Team choose unit for " << i + 1 << " position" << endl;
		menu();
		cin >> choice;
		m1 = m(choice);
		red.addQ(m1);
	}
	return red;
}

/*func: blue
 * desc: assign blue team roster
 * para: team size
 * input: int
 * out: queue for blue team
 */
Queue blue(int teamsize){
	Creature* m2;
	Queue blue;

	int choice;

	for(int i = 0; i < teamsize; i++){
		cout << "Blue Team choose unit for " << i + 1 << " position" << endl;
		menu();
		cin >> choice;
		m2 = m(choice);
		blue.addQ(m2);
	}
	return blue;
}

/*func: fight
 * desc: tournament takes place here
 * para: both teams rosters
 * input: two queues
 * output: n/a
 */
void fight(Queue red, Queue blue){
	Creature* t1;
	Creature* t2;

	Stack pile;

	int attack, defend, strength, redID, blueID, redKill, blueKill, review;
	int round = 1;
	int turn = 0;
	int mend = 0;

	string topPile;
	
	while(red.front != NULL && blue.front != NULL){
		int check = 0;

		t1 = red.removeQ();
		redID = t1 -> getID();
	
		t2 = blue.removeQ();
		blueID = t2 -> getID();
	
		while(check == 0){
			if(turn == 0){

				//cout << "Red Team's Turn: " << endl;

				if(blueID == 4){
					t1 -> special(blueID);
				}
			
				attack = t1 -> attack();
				defend = t2 -> defend();
	
				//cout << "Blue - ";
				strength = t2 -> condition(attack, defend);
	
				if(blueID == 4){
					t1 -> special(blueID);
				}else{
					t1 -> special(strength);
				}
				
				check = t2 -> life(strength);

				if(check == 1){
					redKill = 1;
					pile.add(t2);
				}

				turn = 1;	
			}else{

				//cout << "Blue Team's Turn: " << endl;
				
				if(redID == 4){
					t2 -> special(redID);
				}
	
				attack = t2 -> attack();
				defend = t1 -> defend();
	
				//cout << "Red - ";
				strength = t1 -> condition(attack, defend);
			
				if(redID == 4){
					t2 -> special(redID);
				}else{
					t2 -> special(strength);
				}

				check = t1 -> life(strength);
				
				if(check == 1){
					blueKill = 1;
					pile.add(t1);
				}

				turn = 0;
			}
		}
	
		cout << "	" << "Round " << round++ << ": complete" << endl;
	
		if(blueKill == 1){
			mend = rand() % 6 + 1;
			cout << "	" << t2 -> getName() <<  " is healed for " << mend << " and sent to the back of the line!" << endl;
			t2 -> life(-mend);
			blue.addQ(t2);
		}else if(redKill == 1){
			mend = rand() % 6 + 1;
			cout << "	" << t1 -> getName() << " is healed for " << mend << " and sent to the back of the line!" << endl;
			t1 -> life(-mend);
			red.addQ(t1);
		
		}

		 if(red.front == NULL){
			cout << "Blue Team Wins!" << endl;
			cout << "1st Place: " << t2 -> getName() << " of Blue Team!" << endl;
			cout << "2nd Place: " << pile.top -> value -> getName() << " of Red Team!" << endl;

			topPile = pile.top -> value -> getName();
			pile.remove();

			if(blue.front -> value != NULL){
				cout << "3rd Place: " << blue.front -> value -> getName() << " of Blue Team!"<< endl;
			}else if( blue.front -> value == NULL){
				cout << "3rd Place: " << pile.top -> value -> getName() << " of Blue Team!" << endl;	
			}else{
				cout << "None left, 1st place gets two medals!" << endl;
			}
			
			turn = 2;

		}else if(blue.front == NULL){
			cout << "Red Team Wins!" << endl;
			cout << "1st Place: " << t1 -> getName() << " of Red Team!" << endl;
			cout << "2nd Place: " << pile.top -> value -> getName() << " of Blue Team!" << endl;

			topPile = pile.top -> value -> getName();
			pile.remove();

			if(red.front -> value != NULL){
				cout << "3rd Place: " << red.front -> value -> getName() << " of Red Team!" << endl;
			}else if(red.front -> value == NULL){
				cout << "3rd Place: " << pile.top -> value -> getName() << " of Red Team!"  << endl;
			}else{	
				cout << "None left, 1st place gets two medals!" << endl;
			}

			turn = 2;
		}
	}

	cout << "Do you want to review the pile? [1]yes or [2]no" << endl;
	cin >> review;
	if(review == 1){
		cout << topPile << endl;
		while(pile.top != NULL){
			cout << pile.top -> value -> getName() << endl;
			//cout << pile.remove() << endl;
			pile.remove();
		}
	}
}

int main(){
	
	srand(time(NULL));

	Queue team1;
	Queue team2;

	int size = 0;

	cout << "Enter Team Size: " << endl;
	cin >> size;

	team1 = red(size);
	team2 = blue(size);

	fight(team1, team2);

/*
	int attack, defend, strength, choice, choice2;
	int check = 0;
	int turn = 0;	

	cin >> choice;
	m1 = m(choice);

	cout << "Choose another: " << endl;
	
	cin >> choice2;
	m2 = m(choice2);
	
	while(check == 0){
		if(turn == 0){
			
			if(choice2 == 5){
				m1 -> special(choice2);
			}

			attack = m1 -> attack();
			defend = m2 -> defend();
			
			cout << "1 - ";
			strength = m2 -> condition(attack, defend);
			
			if(choice2 == 5){
				m1 -> special(choice2);
			}else{
				m1 -> special(strength);
			}

			check = m2 -> life(strength);
			turn = 1;
		}else{

			if(choice == 5){
				m2 -> special(choice);
			}

			attack = m2 -> attack();
			defend = m1 -> defend();
			
			cout << "2 - ";
			strength = m1 -> condition(attack, defend);
			
			if(choice == 5){
				m2 -> special(choice);
			}else{
				m2 -> special(strength);
			}

			check = m1 -> life(strength);	
			turn = 0;		
		}
	}

	int check = 0;

	while(check == 0){
		attack = n1 -> attack();
		defend = n2 -> defend();

		strength = n2 -> condition(attack, defend);

		check = n2 -> life(strength);

		
	}
*/
	return 0;
}
