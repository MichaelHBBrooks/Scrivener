/*
 * CharacterManager.cpp
 *
 *  Created on: Dec 31, 2016
 *      Author: jinieren
 */

#include"CharacterManager.h"

#include<fstream>
#include<iterator>
#include<iostream>
#include<map>
#include<regex>
#include<string>

#include"character/Attribute.h"
#include"character/Race.h"
#include"character/Skill.h"
#include"json/json.h"

using namespace Scrivener;

CharacterManager::CharacterManager(const char* new_config_path_) :
		path_to_config_file_(new_config_path_){
	std::string line;
	std::regex key_value_pair("^\\s*([^#][a-zA-Z0-9]+)\\s*=\\s*(.+)");
	std::smatch match;
	std::ifstream my_file(path_to_config_file_);
	std::map<std::string, std::string> params;

	if(my_file.is_open()){
		while(getline(my_file, line)){
			if(std::regex_search(line, match, key_value_pair)){
				params.insert(std::make_pair<std::string, std::string>(match[1], match[2]));
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
			loadRaces(races_path);
		}
		if(params.find("itemsPath") != params.end()){
			items_path = params.find("itemsPath")->second;
		}
	}
}

CharacterManager::~CharacterManager(){
	for(std::vector<Skill*>::iterator skillPtr = skills_.begin(); skillPtr != skills_.end();
			++skillPtr){
		delete *skillPtr;
	}
	for(std::vector<Race*>::iterator racePtr = races_.begin(); racePtr != races_.end();
			++racePtr){
		delete *racePtr;
	}
}

void CharacterManager::loadSkills(const std::string& skills_path){
	std::ifstream skills_file(skills_path, std::ifstream::binary);
	Json::Value json_root;
	Json::Reader json_reader;
	bool parsing_successful = json_reader.parse(skills_file, json_root, false);
	if(!parsing_successful){
		std::cout << json_reader.getFormattedErrorMessages() << std::endl;
	}
	//std::cout << json_root;
	if(json_root.size() > 0){
		Json::Value json_skill_list = json_root["skills"]["skill"];
		Json::Value json_skill;
		std::string skill_name;
		skill_id_t skill_id;
		bool skill_armor;
		bool skill_trained;
		std::string attribute;
		Attribute skill_attribute_modifier;

		for(Json::ValueIterator itr = json_skill_list.begin(); itr != json_skill_list.end(); itr++){
			json_skill = *itr;
			skill_name = json_skill["name"].asString();
			skill_id = json_skill["id"].asInt();
			skill_armor = json_skill["armorPenalty"].asBool();
			skill_trained = json_skill["trainedOnly"].asBool();
			attribute = json_skill["attribute"].asString();
			if(attribute == "strength"){
				skill_attribute_modifier = Attribute::strength;
			}else if(attribute == "dexterity"){
				skill_attribute_modifier = Attribute::dexterity;
			}else if(attribute == "constitution"){
				skill_attribute_modifier = Attribute::constitution;
			}else if(attribute == "intelligence"){
				skill_attribute_modifier = Attribute::intelligence;
			}else if(attribute == "wisdom"){
				skill_attribute_modifier = Attribute::wisdom;
			}else if(attribute == "charisma"){
				skill_attribute_modifier = Attribute::charisma;
			}else{
				skill_attribute_modifier = static_cast<Attribute>(-1);
			}

			skills_.push_back(
					new Skill(skill_name, skill_id, skill_armor, skill_trained,
							skill_attribute_modifier));

//			std::cout << '\t' << skills_.back()->getName() << '\t' << skills_.back()->getId() << '\t' << attribute << ":";
//			if(skills_.back()->getAttributeModifier() == Attribute::strength){
//				std::cout << "strength";
//			}else if(skills_.back()->getAttributeModifier() == Attribute::dexterity){
//				std::cout << "dexterity";
//			}else if(skills_.back()->getAttributeModifier() == Attribute::constitution){
//				std::cout << "constitution";
//			}else if(skills_.back()->getAttributeModifier() == Attribute::intelligence){
//				std::cout << "intelligence";
//			}else if(skills_.back()->getAttributeModifier() == Attribute::wisdom){
//				std::cout << "wisdom";
//			}else if(skills_.back()->getAttributeModifier() == Attribute::charisma){
//				std::cout << "charisma";
//			}else if(static_cast<int>(skills_.back()->getAttributeModifier()) == -1){
//				std::cout << "none";
//			}else{
//				std::cout << "undefined";
//			}
//			std::cout << std::endl;
		}
	}
}

void CharacterManager::loadRaces(const std::string& races_path){
	std::ifstream races_file(races_path, std::ifstream::binary);
	Json::Value json_root;
	Json::Reader json_reader;
	bool parsing_successful = json_reader.parse(races_file, json_root, false);
	if(!parsing_successful){
		std::cout << json_reader.getFormattedErrorMessages() << std::endl;
	}
	if(json_root.size() > 0){
		Json::Value json_race_list = json_root["races"]["race"];
		Json::Value json_race;
		Json::Value json_aging_effects;
		Json::Value json_age;
		std::string json_race_size;  //This will be converted to enum.
		int x = 0;

		std::string race_name;
		race_id_t race_id;
		std::string race_shape;
		Size race_size;
		int race_land_speed;

		for(Json::ValueIterator itr = json_race_list.begin(); itr != json_race_list.end(); itr++){
			json_race = *itr;
			json_race_size = json_race["size"].asString();

			race_name = json_race["name"].asString();
			race_id = json_race["id"].asInt();
			race_shape = json_race["shape"].asString();
			race_land_speed = json_race["baseLandSpeed"].asInt();

			race_size = sizeStringToEnum(json_race_size);

			json_aging_effects = json_race["agingEffects"];
			if(json_aging_effects.size() > 0){
				for(Json::ValueIterator itr_aging_effects = json_aging_effects.begin();
						itr_aging_effects != json_aging_effects.end(); itr_aging_effects++){
					json_age = *itr_aging_effects;
					std::cout << "Age "<< x++ << ": " << json_age << std::endl;
				}
			}

			races_.push_back(new Race(race_name,
					race_id,
					race_shape,
					race_size,
					race_land_speed));

//			std::cout << '\t' << races_.back()->getName() << '\t' << races_.back()->getId() << '\t' << attribute << ":";
//			if(races_.back()->getAttributeModifier() == Attribute::strength){
//				std::cout << "strength";
//			}else if(races_.back()->getAttributeModifier() == Attribute::dexterity){
//				std::cout << "dexterity";
//			}else if(races_.back()->getAttributeModifier() == Attribute::constitution){
//				std::cout << "constitution";
//			}else if(races_.back()->getAttributeModifier() == Attribute::intelligence){
//				std::cout << "intelligence";
//			}else if(races_.back()->getAttributeModifier() == Attribute::wisdom){
//				std::cout << "wisdom";
//			}else if(races_.back()->getAttributeModifier() == Attribute::charisma){
//				std::cout << "charisma";
//			}else if(static_cast<int>(races_.back()->getAttributeModifier()) == -1){
//				std::cout << "none";
//			}else{
//				std::cout << "undefined";
//			}
//			std::cout << std::endl;
		}
		for(std::vector<Race*>::iterator itr = races_.begin(); itr != races_.end(); ++itr){
			std::cout << (*itr)->getName() << std::endl;
		}
	}
}

Size CharacterManager::sizeStringToEnum(const std::string& value_){
	if(value_ == "fine"){
		return Size::fine;
	}else if(value_ == "diminutive"){
		return Size::diminutive;
	}else if(value_ == "tiny"){
		return Size::tiny;
	}else if(value_ == "small"){
		return Size::small;
	}else if(value_ == "medium"){
		return Size::medium;
	}else if(value_ == "large"){
		return Size::large;
	}else if(value_ == "huge"){
		return Size::huge;
	}else if(value_ == "gargantuan"){
		return Size::gargantuan;
	}else if(value_ == "colossal"){
		return Size::colossal;
	}else if(value_ == "colossalPlus"){
		return Size::colossalPlus;
	}
	return static_cast<Size>(-1);
}

Attribute AttributeStringToEnum(const std::string& value_){
	if(value_ == "strength"){
		return Attribute::strength;
	}else if(value_ == "dexterity"){
		return Attribute::dexterity;
	}else if(value_ == "constitution"){
		return Attribute::constitution;
	}else if(value_ == "intelligence"){
		return Attribute::intelligence;
	}else if(value_ == "wisdom"){
		return Attribute::wisdom;
	}else if(value_ == "charisma"){
		return Attribute::charisma;
	}
	return static_cast<Attribute>(-1);
}

Alignment_axis1 Alignment_axis1StringToEnum(const std::string& value_){
	if(value_ == "lawful"){
		return Alignment_axis1::lawful;
	}else if(value_ == "neutral"){
		return Alignment_axis1::neutral;
	}else if(value_ == "chaotic"){
		return Alignment_axis1::chaotic;
	}
	return static_cast<Alignment_axis1>(-1);
}

Alignment_axis2 Alignment_axis2StringToEnum(const std::string& value_){
	if(value_ == "good"){
		return Alignment_axis2::good;
	}else if(value_ == "neutral"){
		return Alignment_axis2::neutral;
	}else if(value_ == "evil"){
		return Alignment_axis2::evil;
	}
	return static_cast<Alignment_axis2>(-1);
}
