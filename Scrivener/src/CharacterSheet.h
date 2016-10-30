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
	std::string characterName;
	std::string playerName;
	signed int experience;
//	enum class alignment1 { lawful, neutral, chaotic };
//	enum class alignment2 { good, neutral, evil };
	float baseWeight;

	//  Size is derived from race and spell effects. I just don't want to get rid of this yet.
	//enum class size { fine, diminutive, tiny, small, medium, large, huge, gargantuan, colossal, colossalPlus };

	Attribute baseStrength;
	Attribute baseDexterity;
	Attribute baseConstitution;
	Attribute baseIntelligence;
	Attribute baseWisdom;
	Attribute baseCharisma;
public:
	CharacterSheet();
	Attribute getStr();
	Attribute *getStrPtr();

	Attribute getAttribute(std::string stat);
	void rollStats(std::string);
};

#endif /* SRC_CHARACTERSHEET_H_ */
