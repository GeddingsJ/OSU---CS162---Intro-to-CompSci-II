/*Filename: bluemen.cpp
*Author: Jacob Geddings
*Date: 2/12/2016
*Desc: Child monster class
*Input: n/a
*Output: Respective creature
*/
#include "bluemen.h"

/*Func: Bluemen()
*Desc: Constructor
*Para: null
*Pre: n/a
*Post: fills armor and strength variable
*/
Bluemen :: Bluemen() : Creature(){
	armor = 3;
	strength = 12;
}

/*Func: attack
*Desc: carries out attack rolls
*Para: n/a
*Pre: n/a
*Post: returns cumalative damage
*/
int Bluemen :: attack(){
	int attack = 0;

	for(int i = 0; i < 2; ++i){
		int temp;

		temp = rand() % 10 + 1;

		attack += temp;
	}
	return attack;
}

/*Func: defend
*Desc: carries out defense rolls
*Para: n/a
*Pre: n/a
*Post: returns cumalative defense
*/
int Bluemen :: defend(){
	int defend = 0;
	
	//cout << "Blue men have " << strength << " health remaining!" << endl;

	if(strength > 8){
		cout << "Three men standing!" << endl;
		for(int i = 0; i < 3; ++i){
			int temp;
	
			temp = rand() % 6 + 1;

			defend += temp;
		}
	}else if(strength < 8 && strength > 4){
		cout << "Two men standing!" << endl;
		for(int i = 0; i < 2; ++i){
			int temp;

			temp = rand() % 6 + 1;

			defend += temp;
		}
	}else{
		cout << "One man standing!" << endl;
		for(int i = 0; i < 1; ++i){
			int temp;

			temp = rand() % 6 + 1;

			defend += temp;
		}
	}
	return defend;
}

/*func: condition
*desc: attack clearance
*para: attack and defend
*pre: n/a
*post: returns damage sustained
*/
int Bluemen :: condition(int attack, int defend){
	int damage = 0;

	attack -= defend;

	if(attack > defend){
		attack -= defend;
		cout << "Blue Men are hurt! " << attack << " damage taken!" << endl;
		damage = attack;
	}else{
		cout << "The Blue Men are unharmed!" << endl;
	}
	return damage;
}

/*func: life
*desc: checks for death
*para: n/a
*pre: n/a
*post: returns if dead
*/

int Bluemen :: life(int damage){
	int status = 0;

	strength -= damage;

	if(strength < 1){
		cout << "The Blue Men are no more!" << endl;
		status = 1;
	}
	return status;
}
