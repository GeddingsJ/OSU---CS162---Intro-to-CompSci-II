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

#include <iostream>

using namespace std;

/*func: menu
*desc: display a menu for user
*para: n/a
*input: n/a
*output: void
*/
void menu(){
	cout << "MONSTER BATTLE" << endl;
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

int main(){
	
	srand(time(NULL));
	
	Creature* m1;
	Creature* m2;

	menu();
	
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
/*
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
