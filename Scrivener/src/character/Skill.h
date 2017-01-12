/*
 * Skill.h
 *
 *  Created on: Nov 26, 2016
 *      Author: jinieren
 */

#ifndef SRC_SKILL_H_
#define SRC_SKILL_H_

#include<string>

#include"Attribute.h"

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
			const bool new_trained_only_, const Attribute new_attribute_modifier_);

	/**
	 * Returns the skill name.
	 * @return The skill name.
	 */
	std::string getName();

	/**
	 * Returns the skill id.
	 * @return The skill id.
	 */
	skill_id_t getId();

	/**
	 * Returns the Armor Penalty boolean.
	 * @return True if armor affects skill rolls. False otherwise.
	 */
	bool isArmorPenalized();

	/**
	 * Returns the Trained Only boolean.
	 * @return True if skill must be trained. False otherwise.
	 */
	bool isTrainedOnly();

	/**
	 * Returns the skill's attribute modifier.
	 * @return The skill's attribute modifier.
	 */
	Attribute getAttributeModifier();

private:
	const std::string name_;
	const skill_id_t id_;
	const bool armor_penalty_;
	const bool trained_only_;
	const Attribute attribute_modifier_;
};

} //  namespace Scrivener

#endif /* SRC_SKILL_H_ */
