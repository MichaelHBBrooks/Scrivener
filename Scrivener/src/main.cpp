/**
 * @author	Michael.H.B.Brooks@gmail.com
 * @brief	The main entry point for the Scrivener program.
 *
 * The goal of this project is to create a modify my old 3.5 D&D character
 * named "Jinieren". He was a level 21 rogue with epic level gear, lycanthropy,
 * and shadow dancer abilities. There were a lot of things to keep track of. The
 * most debilitating thing that could occur to any game session would be
 * figuring out if I could dodge something while in an anti-magic field.
 *
 * This program was designed to help answer that question.
 */

#include "Attribute.h"
#include "CharacterSheet.h"
#include <iostream>
#include <string>

using namespace std;

void printStats(CharacterSheet);

/**
 *
 * @param argc The number of arguments passed in.
 * @param argv A list of values passed in as arguments.
 * @return
 */
int main(int argc, char* argv[]){
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

/**
 * A function that prints the stats for a character.
 * @param character The character whose stats will be printed.
 */
void printStats(CharacterSheet character){
	try{
		cout << "Name: " << endl
				<< "Str: " << character.getAttribute("strength").getValue() << endl
				<< "Dex: " << character.getAttribute("dexterity").getValue() << endl
				<< "Con: " << character.getAttribute("constitution").getValue() << endl
				<< "Int: " << character.getAttribute("intelligence").getValue() << endl
				<< "Wis: " << character.getAttribute("wisdom").getValue() << endl
				<< "Cha: " << character.getAttribute("charisma").getValue() << endl;
	}catch(...){
		cout << "Bad attribute!" << endl;
	}
}
