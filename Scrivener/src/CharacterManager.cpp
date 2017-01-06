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
		std::string skillsPath;
		std::string racesPath;
		std::string itemsPath;
		if(params.find("skillsPath") != params.end()){
			skillsPath = params.find("skillsPath")->second;
		}
		if(params.find("racesPath") != params.end()){
			racesPath = params.find("racesPath")->second;
		}
		if(params.find("itemsPath") != params.end()){
			itemsPath = params.find("itemsPath")->second;
		}
	}
}
CharacterManager::~CharacterManager(){

}

