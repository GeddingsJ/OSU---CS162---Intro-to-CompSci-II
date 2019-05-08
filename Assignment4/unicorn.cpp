/*Filename: unicorn.cpp
*Author: Jacob Geddings
*Date: 2/12/2016
*Desc: Child monster class
*Input: n/a
*Output: Respective creature
*/
#include "unicorn.h"

/*Func: Unicorn()
*Desc: Constructor
*Para: null
*Pre: n/a
*Post: fills armor and strength variable
*/
Unicorn :: Unicorn() : Creature(){
	armor = 3;
	strength = 18;
	mirror = 0;
	ID = 4;
	name = "Unicorn";	
}

/*Func: attack
*Desc: carries out attack rolls
*Para: n/a
*Pre: n/a
*Post: returns cumalative damage
*/
int Unicorn :: attack(){
	int attack = 0;
	//if(mirror > 0){
	//	cout << "Unicorn spots a rival!" << endl;
	//}
	if(strength < 18 || mirror > 0){
		for(int i = 0; i < 1; ++i){
			int temp;
			
			temp = rand() % 20 + 1;

			attack += temp;
		}
		for(int i = 0; i < 2; ++i){
			int temp;

			temp = rand() % 6 + 1;

			attack += temp;
		}
	}

	return attack;
}

/*Func: defend
*Desc: carries out defense rolls
*Para: n/a
*Pre: n/a
*Post: returns cumalative defense
*/
int Unicorn :: defend(){
	int defend = 0;

	for(int i = 0; i < 2; ++i){
		int temp;
	
		temp = rand() % 6 + 1;

		defend += temp;
	}
	return defend;
}

/*func: condition
*desc: attack clearance
*para: attack and defend
*pre: n/a
*post: returns damage sustained
*/
int Unicorn :: condition(int attack, int defend){
	int damage = 0;

	attack -= defend;

	if(attack > defend){
		attack -= defend;
		cout << "Unicorn is struck with " << attack << " damage!" << endl;
		damage = attack;
	}else{
		cout << "Unicorn proved too quick!" << endl;
	}
	return damage;
}

/*func: life
*desc: checks for death
*para: n/a
*pre: n/a
*post: returns if dead
*/

int Unicorn :: life(int damage){
	int status = 0;
	strength -= damage;

	if(strength < 1){
		cout << "Unicorn has been defeated!" << endl;
		status = 1;
	}
	return status;
}

/*func: special
*desc: carries out unique moveset
*para: integer
*pre: must be chosen through if/else
*post: void
*/
void Unicorn :: special(int choice){
	mirror = choice;
}
