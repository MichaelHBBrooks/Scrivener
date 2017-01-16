/*
 * Attribute.h
 *
 *  Created on: Oct 16, 2016
 *      Author: jinieren
 */

#ifndef SRC_ATTRIBUTE_H_
#define SRC_ATTRIBUTE_H_

#include<map>
#include<string>

namespace Scrivener {

typedef int attribute_value_t;

/**
 * The building blocks of a character.
 */
enum class Attribute{
	strength, dexterity, constitution, intelligence, wisdom, charisma
};

/**
 * Size is derived from race and spell effects.
 */
enum class Size{
	fine, diminutive, tiny, small, medium, large, huge, gargantuan, colossal, colossalPlus
};

enum class Alignment_axis1{
	lawful, neutral, chaotic
};

enum class Alignment_axis2{
	good, neutral, evil
};

}  //namespace Scrivener
#endif /* SRC_ATTRIBUTE_H_ */
