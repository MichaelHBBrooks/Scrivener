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

void printStats(CharacterSheet);

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

	cout << "--------------------------" << endl;
	bob.rollStats("random");
	cout << "Strength (random): " << bob.getStr().getValue() << endl;
	bob.rollStats("4d6 drop lowest");
	cout << "Strength (4d6 drop lowest): " << bob.getStr().getValue() << endl;

	printStats(bob);

	return 0;
}

void printStats(CharacterSheet character){
	try{
		cout << "Name: " << endl
				<< "Strength: " << character.getAttribute("strength").getValue() << endl
				<< "Dexterity: " << character.getAttribute("dexterity").getValue() << endl
				<< "Constition" << character.getAttribute("constitution").getValue() << endl;
	}catch(...){
		cout << "Bad attribute!" << endl;
	}
}
