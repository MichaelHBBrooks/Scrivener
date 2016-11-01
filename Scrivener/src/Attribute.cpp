/*
 * attribute.cpp
 *
 *  Created on: Oct 16, 2016
 *      Author: jinieren
 */

#include "Attribute.h"
#include <string>

Attribute::Attribute(){
	value = 10;
}

Attribute::Attribute(short newAttribute){
	value = newAttribute;
}


void Attribute::setValue(short newAttribute){
	value = newAttribute;
}

short Attribute::getValue(){
	return value;
}


void Attribute::setName(std::string newName){
	name = newName;
}

std::string Attribute::getName(){
	return name;
}


void Attribute::setAbbreviation(std::string newAbbreviation){
	abbreviation = newAbbreviation;
}

std::string Attribute::getAbbreviation(){
	return abbreviation;
}
