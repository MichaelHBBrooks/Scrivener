/*
 * Skill.h
 *
 *  Created on: Nov 26, 2016
 *      Author: jinieren
 */

#ifndef SRC_SKILL_H_
#define SRC_SKILL_H_

#include <string>

class Skill {
	std::string name;
	int value;

//	struct synergyBonus {
//		int bonusValue;
//		Skill* synergySkill;
//		std::string synergyCircumstance;
//	};
public:
	Skill();
	Skill(std::string&,int);
	Skill(std::string&);

	void setSkillValue(int);
	int getSkillValue();

	void setSkillName(std::string);
	std::string getSkillName();
};

#endif /* SRC_SKILL_H_ */
