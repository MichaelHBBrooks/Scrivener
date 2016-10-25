/*
 * CharacterSheet.cpp
 *
 *  Created on: Oct 23, 2016
 *      Author: jinieren
 */

#include "CharacterSheet.h"
#include "Attribute.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

CharacterSheet::CharacterSheet() {
//	strength = 0;
//	dexterity = 0;
//	constitution = 0;
//	intelligence = 0;
//	wisdom = 0;
//	charisma = 0;
}

Attribute CharacterSheet::getStr(){
	return baseStrength;
}

Attribute *CharacterSheet::getStrPtr(){
	return &baseStrength;
}

void CharacterSheet::rollStats(std::string method){
	if(method == "random"){
		std::srand(std::time(0));
		baseStrength.setValue(std::rand()%18+1);
	}else if(method == "4d6 drop lowest"){
		std::srand(std::time(0));
		int roll;
		int lowest;
		int sum;

		roll = lowest = sum = std::rand()%6+1;

		roll = std::rand()%6+1;
		lowest = std::min(lowest,roll);
		sum += roll;

		roll = std::rand()%6+1;
		lowest = std::min(lowest,roll);
		sum += roll;

		roll = std::rand()%6+1;
		lowest = std::min(lowest,roll);
		sum += roll;

		sum -= lowest;
		baseStrength.setValue(sum);
	}
}
