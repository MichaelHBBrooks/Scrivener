/*
 * Race.h
 *
 *  Created on: Nov 28, 2016
 *      Author: jinieren
 */

#ifndef SRC_RACE_H_
#define SRC_RACE_H_

#include <string>

class Race {
	std::string name;
	std::string type;
	//TODO: Figure out a way to make size a global definition.
	enum size { size_fine,
				size_diminutive,
				size_tiny,
				size_small,
				size_medium,
				size_large,
				size_huge,
				size_gargantuan,
				size_colossal,
				size_colossalPlus };
	int landSpeed;

	int maleBaseHeight;
	//dice maleHeightModifier; // "+2d4"
	int maleBaseWeight;
	int femaleBaseHeight;
	//dice femaleHeightModifier; // "+2d4"
	int femaleBaseWeight;

	int levelAdjustment;
};


#endif /* SRC_RACE_H_ */
