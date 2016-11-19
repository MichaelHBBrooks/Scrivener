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
	short value;
	std::string name;
	std::string abbreviation;

public:
	Attribute();
	Attribute(short);

	void setValue(short);
	short getValue();

	void setName(std::string);
	std::string getName();

	void setAbbreviation(std::string);
	std::string getAbbreviation();

	short getAttributeModifier();
};

#endif /* SRC_ATTRIBUTE_H_ */
