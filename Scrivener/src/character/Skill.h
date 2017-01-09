/*
 * Skill.h
 *
 *  Created on: Nov 26, 2016
 *      Author: jinieren
 */

#ifndef SRC_SKILL_H_
#define SRC_SKILL_H_

#include<string>

namespace Scrivener{

typedef unsigned int skill_id_t;

class Skill{
//	struct synergyBonus {
//		int bonusValue;
//		Skill* synergySkill;
//		std::string synergyCircumstance;
//	};
public:
	/**
	 * A new skill is assigned a name and id.
	 * @param new_name_
	 * @param new_id_
	 */
	Skill(const std::string& new_name_, const skill_id_t new_id_, const bool new_armor_penalty_,
			const bool new_trained_only_);

	/**
	 * Returns the skill name.
	 * @return
	 */
	std::string getSkillName();

	/**
	 * Returns the skill id.
	 * @return
	 */
	skill_id_t getSkillId();

private:
	const std::string name_;
	const skill_id_t id_;
	const bool armor_penalty_;
	const bool trained_only_;
};

} //  namespace Scrivener

#endif /* SRC_SKILL_H_ */
