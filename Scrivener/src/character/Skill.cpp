/*
 * Skill.cpp
 *
 *  Created on: Nov 26, 2016
 *      Author: jinieren
 */

#include"Skill.h"

#include<string>

using namespace Scrivener;

Skill::Skill(const std::string& new_name_, const skill_id_t new_id_, const bool new_armor_penalty_,
		const bool new_trained_only_) :
		name_(new_name_), id_(new_id_), armor_penalty_(new_armor_penalty_), trained_only_(
				new_trained_only_){
}

std::string Skill::getSkillName(){
	return name_;
}

skill_id_t Skill::getSkillId(){
	return id_;
}
