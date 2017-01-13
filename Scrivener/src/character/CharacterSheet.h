/*
 * CharacterSheet.h
 *
 *  Created on: Oct 23, 2016
 *      Author: jinieren
 */

#ifndef SRC_CHARACTERSHEET_H_
#define SRC_CHARACTERSHEET_H_

#include<string>

#include"Attribute.h"
#include"Skill.h"

namespace Scrivener{

class CharacterSheet{
	std::string character_name;
	std::string player_name;
	signed int experience;
	float base_weight;
	Alignment_axis1 base_alignment1;
	Alignment_axis2 base_alignment2;
	attribute_value_t base_abilities[6];
	Skill base_skilles[];

public:
	CharacterSheet();
//	Attribute getStr();
//	Attribute *getStrPtr();

	attribute_value_t getAttribute(Attribute someAttribute);
	int getFortitudeSave();
	int getReflexSave();
	int getWillSave();
	void rollStats(std::string method);
};

}

#endif /* SRC_CHARACTERSHEET_H_ */
