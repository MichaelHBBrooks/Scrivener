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
	enum alignment1 { alignment1_lawful, alignment1_neutral, alignment1_chaotic };
	enum alignment2 { alignment2_good, alignment2_neutral, alignment2_evil };
	float baseWeight;

	/**
	 * Size is derived from race and spell effects.
	 */
	enum size { size_fine,
				size_diminutive,
				size_tiny,
				size_small,
				size_medium,
				size_large,
				size_huge,
				size_gargantuan,
				size_colossal,
				size_colossalPlus };

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
	int getFortitudeSave();
	int getReflexSave();
	int getWillSave();
	void rollStats(std::string);
};

#endif /* SRC_CHARACTERSHEET_H_ */
