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
public:
	/**
	 *
	 * @param
	 */
	CharacterManager(const char* configPath_);
	~CharacterManager();
private:
	const char* path_to_config_file_;

	//SRD = System Reference Document
	std::vector<Skill*> skills_;
	std::vector<Race*> races_;

	void loadSkills(const std::string& skills_path_);
	void loadRaces();
};

#endif /* SRC_CHARACTERMANAGER_H_ */
