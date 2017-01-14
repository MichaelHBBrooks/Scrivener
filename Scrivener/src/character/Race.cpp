/*
 * Race.cpp
 *
 *  Created on: Nov 28, 2016
 *      Author: jinieren
 */

#include"Race.h"

#include<string>

#include"Attribute.h"

using namespace Scrivener;
using namespace std;

Race::Race(const std::string new_name_,
		const race_id_t new_id_,
		const std::string new_shape_,
		const Size new_size_,
		const int new_land_speed_) :
				name_(new_name_),
				id_(new_id_),
				shape_(new_shape_),
				size_(new_size_),
				land_speed_(new_land_speed_){

}

//Race::Race(const std::string new_name_,
//		const race_id_t new_id_,
//		const std::string new_shape_,
//		const Size new_size_,
//		const int new_land_speed_,
//		const std::vector<std::string> new_bonus_languages_) :
//				name_(new_name_),
//				id_(new_id_),
//				shape_(new_shape_),
//				size_(new_size_),
//				land_speed_(new_land_speed_),
//				bonus_languages_(new_bonus_languages_){
//
//}

#include <string>
