/*
 * CharacterSheet.cpp
 *
 *  Created on: Oct 23, 2016
 *      Author: jinieren
 */

#include "CharacterSheet.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include "Attribute.h"

using namespace Scrivener;

int rollD6();
int Roll4D6DropLowest();

/**
 * A constructor for character sheets.
 */
CharacterSheet::CharacterSheet() {
//	strength = 0;
//	dexterity = 0;
//	constitution = 0;
//	intelligence = 0;
//	wisdom = 0;
//	charisma = 0;
}

/**
 * Print character's basic attribute.
 * @return The character's strength attribute.
 */
//Attribute CharacterSheet::getStr(){
//	return baseStrength;
//}

/**
 * Return a pointer to a basic attribute for a character.
 * @return A pointer to the character's strength attribute.
 */
//Attribute *CharacterSheet::getStrPtr(){
//	return &baseStrength;
//}

/**
 * Assign values to the basic attributes of a character.
 * Currently supported methods are:
 *   - "random"
 *   - "4d6 drop lowest"
 *   - "average"
 * @param method The method in which the dice will be rolled.
 */
//void CharacterSheet::rollStats(std::string method){
//	if(method == "random"){
//		std::srand(std::time(0));
//		baseStrength.setValue(std::rand()%18+1);
//	}else if(method == "4d6 drop lowest"){
//		std::srand(std::time(0));
//		baseStrength.setValue(Roll4D6DropLowest());
//		baseDexterity.setValue(Roll4D6DropLowest());
//		baseConstitution.setValue(Roll4D6DropLowest());
//		baseIntelligence.setValue(Roll4D6DropLowest());
//		baseWisdom.setValue(Roll4D6DropLowest());
//		baseCharisma.setValue(Roll4D6DropLowest());
//	}else if(method == "average"){
//		baseStrength.setValue(10);
//		baseDexterity.setValue(10);
//		baseConstitution.setValue(10);
//		baseIntelligence.setValue(10);
//		baseWisdom.setValue(10);
//		baseCharisma.setValue(10);
//	}
//}

/**
 * Randomly generate a number between 1-6.
 */
int rollD6(){
	return std::rand()%6+1;
}

/**
 * Randomly roll four 6-sided dice and drop the lowest value.
 */
int Roll4D6DropLowest(){
	int roll;
	int lowest;
	int sum;

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

/**
 * Return an attribute's value.
 * @param attr The name of an attribute.
 * @return The value of a character's attribute.
 */
//Attribute CharacterSheet::getAttribute(std::string attr){
//		if(attr == "strength" || attr == "str"){
//			return baseStrength;
//		}else if(attr == "dexterity" || attr == "dex"){
//			return baseDexterity;
//		}else if(attr == "constitution" || attr == "con"){
//			return baseConstitution;
//		}else if(attr == "intelligence" || attr == "int"){
//			return baseIntelligence;
//		}else if(attr == "wisdom" || attr == "wis"){
//			return baseWisdom;
//		}else if(attr == "charisma" || attr == "cha"){
//			return baseCharisma;
//		}
//		throw "Undefined Attribute";
//}

/**
 * Return the character's Fortitude save.
 * @return
 */
//int CharacterSheet::getFortitudeSave(){
//	return baseConstitution.getAttributeModifier();
//}

/**
 * Return the character's Reflex save.
 * @return
 */
//int CharacterSheet::getReflexSave(){
//	return baseDexterity.getAttributeModifier();
//}

/**
 * Return the character's Will save.
 * @return
 */
//int CharacterSheet::getWillSave(){
//	return baseWisdom.getAttributeModifier();
//}
