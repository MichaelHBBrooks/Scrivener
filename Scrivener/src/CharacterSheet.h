/*
 * CharacterSheet.h
 *
 *  Created on: Oct 23, 2016
 *      Author: jinieren
 */

#ifndef SRC_CHARACTERSHEET_H_
#define SRC_CHARACTERSHEET_H_

#include "Attribute.h"
#include <string>

class CharacterSheet {
	Attribute strength;
	Attribute dexterity;
	Attribute constitution;
	Attribute intelligence;
	Attribute wisdom;
	Attribute charisma;
public:
	CharacterSheet();
	Attribute getAttribute(std::string);
	Attribute getStr();
	Attribute *getStrPtr();
};

#endif /* SRC_CHARACTERSHEET_H_ */
