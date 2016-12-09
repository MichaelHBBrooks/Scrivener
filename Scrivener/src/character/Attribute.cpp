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

Attribute::Attribute(int newAttribute){
	value = newAttribute;
}


void Attribute::setValue(int newAttribute){
	value = newAttribute;
}

int Attribute::getValue(){
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

int Attribute::getAttributeModifier(){
//	return value>0 ? (value - 10) / 2 : (value-11) / 2;
	return value%2 == 0 ? (value-10)/2 : (value-11) / 2;
}
