/*
 * attribute.cpp
 *
 *  Created on: Oct 16, 2016
 *      Author: jinieren
 */

#include "Attribute.h"

Attribute::Attribute(short newAttribute){
	value = newAttribute;
}

void Attribute::setAttribute(short newAttribute){
	value = newAttribute;
}

short Attribute::getAttribute(){
	return value;
}
