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

short rollD6();
short Roll4D6DropLowest();

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
		baseStrength.setValue(Roll4D6DropLowest());
		baseDexterity.setValue(Roll4D6DropLowest());
		baseConstitution.setValue(Roll4D6DropLowest());
		baseIntelligence.setValue(Roll4D6DropLowest());
		baseWisdom.setValue(Roll4D6DropLowest());
		baseCharisma.setValue(Roll4D6DropLowest());
	}else if(method == "average"){
		baseStrength.setValue(10);
		baseDexterity.setValue(10);
		baseConstitution.setValue(10);
		baseIntelligence.setValue(10);
		baseWisdom.setValue(10);
		baseCharisma.setValue(10);
	}
}

short rollD6(){
	std::srand(std::time(0));
	return std::rand()%6+1;
}

short Roll4D6DropLowest(){
	short roll;
	short lowest;
	short sum;

	roll = lowest = sum = rollD6();

	roll = rollD6();
	lowest = std::min(lowest,roll);
	sum += roll;

	roll = rollD6();
	lowest = std::min(lowest,roll);
	sum += roll;

	roll = rollD6();
	lowest = std::min(lowest,roll);
	sum += roll;

	sum -= lowest;

	return sum;
}

Attribute CharacterSheet::getAttribute(std::string attr){
		if(attr == "strength" || attr == "str"){
			return baseStrength;
		}else if(attr == "dexterity" || attr == "dex"){
			return baseDexterity;
		}
		throw "Undefined Attribute";
}
