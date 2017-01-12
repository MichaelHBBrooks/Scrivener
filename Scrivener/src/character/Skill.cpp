/*
 * Skill.cpp
 *
 *  Created on: Nov 26, 2016
 *      Author: jinieren
 */

#include"Skill.h"

#include<string>

#include"Attribute.h"

using namespace Scrivener;

Skill::Skill(const std::string& new_name_, const skill_id_t new_id_, const bool new_armor_penalty_,
		const bool new_trained_only_, const Attribute new_attribute_modifier_) :
		name_(new_name_), id_(new_id_), armor_penalty_(new_armor_penalty_), trained_only_(
				new_trained_only_), attribute_modifier_(new_attribute_modifier_){
}

std::string Skill::getName(){
	return name_;
}

skill_id_t Skill::getId(){
	return id_;
}

bool Skill::isArmorPenalized(){
	return armor_penalty_;
}

bool Skill::isTrainedOnly(){
	return trained_only_;
}

Attribute Skill::getAttributeModifier(){
	return attribute_modifier_;
}
