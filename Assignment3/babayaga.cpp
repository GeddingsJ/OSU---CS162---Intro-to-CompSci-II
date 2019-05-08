/*Filename: babayaga.cpp
*Author: Jacob Geddings
*Date: 2/12/2016
*Desc: Child monster class
*Input: n/a
*Output: Respective creature
*/
#include "babayaga.h"

/*Func: Babayaga()
*Desc: Constructor
*Para: null
*Pre: n/a
*Post: fills armor and strength variable
*/
Babayaga :: Babayaga() : Creature(){
	armor = 3;
	strength = 12;
	specialBonus = 0;
}

/*Func: attack
*Desc: carries out attack rolls
*Para: n/a
*Pre: n/a
*Post: returns cumalative damage
*/
int Babayaga :: attack(){
	int attack = 0;

	for(int i = 0; i < 1; ++i){
		int temp;
		
		temp = rand() % 6 + 1;	

		attack += temp;
		//cout << attack << endl;
	}
	
	//attack += specialBonus;
	//attack = 10;
	return attack;
}

/*Func: defend
*Desc: carries out defense rolls
*Para: n/a
*Pre: n/a
*Post: returns cumalative defense
*/
int Babayaga :: defend(){
	int defend = 0;

	for(int i = 0; i < 1; ++i){
		int temp;

		temp = rand() % 10 + 1;

		defend += temp;
	}
	//cout << "Defense: " << defend << endl;
	return defend;
}

/*func: condition
*desc: attack clearance
*para: attack and defend
*pre: n/a
*post: returns damage sustained
*/
int Babayaga :: condition(int attack, int defend){
	int damage = 0;

	attack -= defend;	

	if(attack > defend){
		attack -= defend;
		cout << "Baba Yaga takes " << attack << " damage!" << endl;
		damage = attack;		
	}else{
		cout << "Baba Yaga isn't hurt!" << endl;
	}

	return damage;
}

/*func: life
*desc: checks for death
*para: n/a
*pre: n/a
*post: returns if dead
*/
int Babayaga :: life(int damage){
	int status = 0;
	strength += specialBonus;
	strength -= damage;
	
	//cout << "Health: " << strength << endl;

	if(strength < 1){
		cout << "Baba Yaga has been defeated!" << endl;
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
void Babayaga :: special(int condition){
	specialBonus = condition;
	cout << "Baba Yaga gains " << specialBonus << " strength!" << endl;
}
