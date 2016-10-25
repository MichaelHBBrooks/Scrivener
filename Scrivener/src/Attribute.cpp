/*
 * attribute.cpp
 *
 *  Created on: Oct 16, 2016
 *      Author: jinieren
 */

#include "Attribute.h"

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
