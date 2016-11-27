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
	short value;
public:
	Skill();
	Skill(std::string,short);

	void setSkillValue(short);
	short getSkillValue();

	void setSkillName(std::string);
	std::string getSkillName();
};

#endif /* SRC_SKILL_H_ */
