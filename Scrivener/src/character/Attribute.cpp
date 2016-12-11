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

/**
 * Create a new attribute with a predefined value.
 * @param newAttribute
 */
Attribute::Attribute(int newAttribute){
	value = newAttribute;
}


/**
 * Set the value of the attribute.
 * @param newAttribute
 */
void Attribute::setValue(int newAttribute){
	value = newAttribute;
}

/**
 * Return the value of the attribute.
 * @return
 */
int Attribute::getValue(){
	return value;
}


/**
 * Set the name of the attribute.
 * @param newName
 */
void Attribute::setName(std::string newName){
	name = newName;
}

/**
 * Return the value of the attribute.
 * @return
 */
std::string Attribute::getName(){
	return name;
}


/**
 * Set the abbreviated name of the attribute.
 * @param newAbbreviation
 */
void Attribute::setAbbreviation(std::string newAbbreviation){
	abbreviation = newAbbreviation;
}

/**
 * Return the abbreviated attribute name.
 * @return
 */
std::string Attribute::getAbbreviation(){
	return abbreviation;
}

int Attribute::getAttributeModifier(){
//	return value>0 ? (value - 10) / 2 : (value-11) / 2;
	return value%2 == 0 ? (value-10)/2 : (value-11) / 2;
}
