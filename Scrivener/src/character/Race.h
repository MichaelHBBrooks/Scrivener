/*
 * Race.h
 *
 *  Created on: Nov 28, 2016
 *      Author: jinieren
 */

#ifndef SRC_RACE_H_
#define SRC_RACE_H_

#include<string>
#include<vector>

#include"Attribute.h"

namespace Scrivener{

typedef unsigned int race_id_t;

class Race{
public:
//	Race(const std::string new_name_,
//			const race_id_t new_id_,
//			const std::string new_shape_,
//			const Size new_size_,
//			const int new_land_speed_,
//			const std::vector<std::string> new_bonus_languages_);
	Race(const std::string new_name_,
			const race_id_t new_id_,
			const std::string new_shape_,
			const Size new_size_,
			const int new_land_speed_);
private:
	const std::string name_;
	const race_id_t id_;
	const std::string shape_;
	const Size size_;
	const int land_speed_;
//	const std::vector<std::string> bonus_languages_;
//	const std::vector<std::string> favored_classes_;
//
//	struct AgingEffect{
//		std::string name;
//		attribute_value_t attributes[6];
//	};
//	std::vector<std::string> starting_ages_;
//	const std::vector<std::string> aging_effects_;

//	int male_base_height_;
//	//dice maleHeightModifier_; // "+2d4"
//	int male_base_weight_;
//	int female_base_height_;
//	//dice femaleHeightModifier_; // "+2d4"
//	int female_base_weight_;
//
//	int level_adjustment_;
};

}

#endif /* SRC_RACE_H_ */
