/*
 * CharacterManager.cpp
 *
 *  Created on: Dec 31, 2016
 *      Author: jinieren
 */

#include "CharacterManager.h"

#include <string>
#include <vector>

#include "character/Race.h"
#include "character/Skill.h"

CharacterManager::CharacterManager(const char* configPath_) : pathToConfigFile_(configPath_){
}
CharacterManager::~CharacterManager(){

}

