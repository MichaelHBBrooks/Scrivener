/*
 * Attribute.h
 *
 *  Created on: Oct 16, 2016
 *      Author: jinieren
 */

#ifndef SRC_ATTRIBUTE_H_
#define SRC_ATTRIBUTE_H_

#include <string>

class Attribute {
	int value;
	std::string name;
	std::string abbreviation;

public:
	Attribute();
	Attribute(int);

	void setValue(int);
	int getValue();

	void setName(std::string);
	std::string getName();

	void setAbbreviation(std::string);
	std::string getAbbreviation();

	int getAttributeModifier();
};

#endif /* SRC_ATTRIBUTE_H_ */
