/*
 * CharacterManager.cpp
 *
 *  Created on: Dec 31, 2016
 *      Author: jinieren
 */

#include "CharacterManager.h"

#include <fstream>
#include <iterator>
#include <iostream>
#include <map>
#include <regex>
#include <string>

#include "character/Race.h"
#include "character/Skill.h"
#include "json/json.h"

CharacterManager::CharacterManager(const char* config_path_) : path_to_config_file_(config_path_){
	std::string line;
	std::regex key_value_pair("^\\s*([^#][a-zA-Z0-9]+)\\s*=\\s*(.+)");
	std::smatch match;
	std::ifstream my_file(config_path_);
	std::map<std::string,std::string> params;

	if(my_file.is_open()){
		while(getline(my_file,line)){
			if(std::regex_search(line, match, key_value_pair)){
//				std::cout << "Matches for '" << line << "'\n";
//				for (size_t i = 0; i < match.size(); ++i){
//					std::cout << i << " = '" << match[i] << "'\n";
//				}
				params.insert(std::make_pair<std::string,std::string>(match[1],match[2]));
			}
		}
		//	std::map<std::string, std::string>::iterator it = params.begin();
		//	while(it != params.end()){
		//		std::cout <<it->first<<" :: "<<it->second<<std::endl;
		//		it++;
		//	}
		//	if(params.find("racesPath") != params.end()){
		//		std::cout << "racesPath has been found." << std::endl;
		//	}else{
		//		std::cout << "racesPath not found.\n";
		//	}
		std::string skills_path;
		std::string races_path;
		std::string items_path;
		if(params.find("skillsPath") != params.end()){
			skills_path = params.find("skillsPath")->second;
			loadSkills(skills_path);
		}
		if(params.find("racesPath") != params.end()){
			races_path = params.find("racesPath")->second;
		}
		if(params.find("itemsPath") != params.end()){
			items_path = params.find("itemsPath")->second;
		}
	}
}
CharacterManager::~CharacterManager(){

}

void CharacterManager::loadSkills(const std::string& skills_path){
	std::ifstream skills_file (skills_path, std::ifstream::binary);
	Json::Value root;
	Json::Reader reader;
	bool parsing_successful = reader.parse(skills_file, root, false);
	if (!parsing_successful){
		std::cout << reader.getFormattedErrorMessages() << std::endl;
	}
	//std::cout << root;
	if(root.size() > 0){
		Json::Value skill_list = root["skills"]["skill"];
		Json::Value skill;
		std::cout << "skills found: " << std::endl;
//		std::cout << "  " << skill[0] << std:: endl;
//		std::cout << "  " << skill[1] << std:: endl;
		for(Json::ValueIterator itr = skill_list.begin(); itr != skill_list.end(); itr++){
			skill = *itr;
			std::cout << "   " << skill["name"].asString() << std::endl;
		}
	}
}
