/*
 * Skill.cpp
 *
 *  Created on: Nov 26, 2016
 *      Author: jinieren
 */

#include "Skill.h"
#include <string>

/**
 * Sets a skill value to 0, but assigns no name.
 */
Skill::Skill(){
	value = 0;
}

/**
 * A new skill is assigned a name and value.
 * @param newName
 * @param newValue
 */
Skill::Skill(std::string& newName, int newValue){
	name = newName;
	value = newValue;
}

/**
 * A new skill is assigned a name while the value defaults to 0.
 * @param newName
 */
Skill::Skill(std::string& newName){
	name = newName;
	value = 0;
}

/**
 * Sets the skill value to newValue.
 * @param newValue
 */
void Skill::setSkillValue(int newValue){
	value = newValue;
}

/**
 * Returns the skill value.
 * @return
 */
int Skill::getSkillValue(){
	return value;
}

/**
 * Sets the skill name to newName.
 * @param newName
 */
void Skill::setSkillName(std::string newName){
	name = newName;
}

/**
 * Returns the skill name.
 * @return
 */
std::string Skill::getSkillName(){
	return name;
}
