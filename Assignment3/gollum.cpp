/*Filename: gollum.cpp
*Author: Jacob Geddings
*Date: 2/12/2016
*Desc: Child monster class
*Input: n/a
*Output: Respective creature
*/
#include "gollum.h"

/*Func: Gollum()
*Desc: Constructor
*Para: null
*Pre: n/a
*Post: fills armor and strength variable
*/
Gollum :: Gollum() : Creature(){
	armor = 1;
	strength = 8;
}

/*Func: attack
*Desc: carries out attack rolls
*Para: n/a
*Pre: n/a
*Post: returns cumalative damage
*/
int Gollum :: attack(){
	int attack = 0;

	for (int i = 0; i < 1; ++i){
		int temp = 0;
		int randTemp = 0;

		randTemp = rand() % 100 + 1;
		
		if(randTemp > 0 && randTemp < 6){
			cout << "Gollum equips the ring!" << endl;
			for(int j = 0; j < 3; ++j){
				temp = rand() % 6 + 1;
				attack += temp;
			}
		}else{
			for(int j = 0; j < 1; ++j){
				temp = rand() % 6 + 1;
				attack += temp;
			}
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
int Gollum :: defend(){
	int defend = 0;

	for(int i = 0; i < 2; ++i){
		int temp;

		temp = rand() % 6 + 1;

		defend += temp;
	}
	//cout << "Defnse: " << defend << endl;
	return defend;
}

/*func: condition
*desc: attack clearance
*para: attack and defend
*pre: n/a
*post: returns damage sustained
*/
int Gollum :: condition(int attack, int defend){
	int damage = 0;

	attack -= defend;

	if(attack > defend){
		attack -= defend;
		cout << "Gollum was hit! " << attack << " damage taken!" << endl;
		damage = attack;
	}else{
		cout << "Gollum dodged the attack!" << endl;
	}
	return damage;
}

/*func: life
*desc: checks for death
*para: n/a
*pre: n/a
*post: returns if dead
*/

int Gollum :: life(int damage){
	int status = 0;

	strength -= damage;

	if(strength < 1){
		cout << "Gollum has been slain!" << endl;
		status = 1;
	}
	return status;
}
