/*
 * Skill.cpp
 *
 *  Created on: Nov 26, 2016
 *      Author: jinieren
 */

#include "Skill.h"
#include <string>

Skill::Skill(){
	value = 0;
}

Skill::Skill(std::string newName, short newValue){
	name = newName;
	value = newValue;
}

void Skill::setSkillValue(short newValue){
	value = newValue;
}
short Skill::getSkillValue(){
	return value;
}

void Skill::setSkillName(std::string newName){
	name = newName;
}
std::string Skill::getSkillName(){
	return name;
}
