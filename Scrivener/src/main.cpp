/*
 * main.cpp
 *
 *  Created on: Oct 16, 2016
 *      Author: jinieren
 */

#include "Attribute.h"
#include "CharacterSheet.h"
#include <iostream>
#include <string>

using namespace std;

//int main(int argc, char* argv[])

int main(){
	Attribute str (10);
	cout << "Strength = " << str.getValue() << endl;

	CharacterSheet bob;
	Attribute str2 = bob.getStr();
	cout << "Strength: " << str2.getValue() << endl;
	str2.setValue(11);
	cout << "Strength: " << str2.getValue() << endl;
	cout << "Strength: " << bob.getStr().getValue() << endl;

	cout << "--------------------------" << endl;
	Attribute *StrPtr = bob.getStrPtr();
	cout << "Strength: " << StrPtr->getValue() << endl;


	return 0;
}
