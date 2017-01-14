/*
 * CharacterManager.h
 *
 *  Created on: Dec 31, 2016
 *      Author: jinieren
 */

#ifndef SRC_CHARACTERMANAGER_H_
#define SRC_CHARACTERMANAGER_H_

#include<string>
#include<vector>

#include"character/Race.h"
#include"character/Skill.h"

namespace Scrivener{

class CharacterManager{
public:
	/**
	 * Create a centralized location to manage all Character Sheet data.
	 * @param new_config_path_
	 */
	CharacterManager(const char* new_config_path_);

	/**
	 * Destroy everything we love before abandoning the digital ashes.
	 */
	~CharacterManager();
private:
	/**
	 * Load the skills file defined at location skills_path_.
	 * @param skills_path_
	 */
	void loadSkills(const std::string& skills_path_);

	/**
	 * Load the races file defined at location races_path_.
	 * @param races_path_
	 */
	void loadRaces(const std::string& races_path_);

	const char* path_to_config_file_;

	//SRD = System Reference Document
	std::vector<Skill*> skills_;
	std::vector<Race*> races_;
};

} //  namespace Scrivener

#endif /* SRC_CHARACTERMANAGER_H_ */
