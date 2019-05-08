/*Filename: barbarian.cpp
*Author: Jacob Geddings
*Date: 2/12/2016
*Desc: Child monster class
*Input: n/a
*Output: Respective creature
*/
#include "barbarian.h"

/*Func: Barbarian()
*Desc: Constructor
*Para: null
*Pre: n/a
*Post: fills armor and strength variable
*/
Barbarian :: Barbarian() : Creature(){
	armor = 0;
	strength = 12;
	ID = 1;
	name = "Barbarian";	
}

/*Func: attack
*Desc: carries out attack rolls
*Para: n/a
*Pre: n/a
*Post: returns cumalative damage
*/
int Barbarian :: attack(){
	int attack = 0;

	for(int i = 0; i < 2; ++i){
		int temp = 0;
		
		temp = rand() % 6 + 1;
	
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
int Barbarian :: defend(){
	int defend = 0;

	for(int i = 0; i < 2; ++i){
		int temp = 0;

		temp = rand() % 6 + 1;

		defend += temp;

		//cout << defend << endl;
	}	
		
	return defend;
}

/*func: condition
*desc: attack clearance
*para: attack and defend
*pre: n/a
*post: returns damage sustained
*/
int Barbarian :: condition(int attack, int defend){
	
	int damage = 0;
	
	attack -= armor;

	if(attack > defend){
		attack -= defend;
		cout << "Barbarian takes " << attack << " damage!" << endl;
		damage = attack;
	}else{
		cout << "Barbarian sustains no damage!" << endl;
	}

	return damage;
}

/*func: life
*desc: checks for death
*para: n/a
*pre: n/a
*post: returns if dead
*/

int Barbarian :: life(int damage){
	int status = 0;
	
	strength -= damage;

	if (strength < 1){
		cout << "Barbarian has fallen!" << endl;
		status = 1;
	}

	return status;
}
