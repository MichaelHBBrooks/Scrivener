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

CharacterSheet::CharacterSheet() {
	strength = 0;
	dexterity = 0;
	constitution = 0;
	intelligence = 0;
	wisdom = 0;
	charisma = 0;
}

Attribute CharacterSheet::getAttribute(std::string asdf) {
	return strength;
}

Attribute CharacterSheet::getStr(){
	return strength;
}

Attribute *CharacterSheet::getStrPtr(){
	return &strength;
}
