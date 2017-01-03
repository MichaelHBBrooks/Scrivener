/*
 * CharacterManager.h
 *
 *  Created on: Dec 31, 2016
 *      Author: jinieren
 */

#ifndef SRC_CHARACTERMANAGER_H_
#define SRC_CHARACTERMANAGER_H_

#include <string>
#include <vector>

#include "character/Race.h"
#include "character/Skill.h"

class CharacterManager{
	const char* pathToConfigFile_;

	//SRD = System Reference Document
	std::vector<Skill*> standardSkills_;
	std::vector<Race*> standardRaces_;

	void loadSkills();
	void loadRaces();
public:
	/**
	 *
	 * @param
	 */
	CharacterManager(const char* configPath_);
	~CharacterManager();
};

#endif /* SRC_CHARACTERMANAGER_H_ */
