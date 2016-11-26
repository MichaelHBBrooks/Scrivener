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
#include "json/reader.h"
#include "json/writer.h"
#include "json/elements.h"

#include <sstream>
#include <iostream>
#include <string>

using namespace std;

void loadData();
void printStats(CharacterSheet);

/**
 *
 * @param argc The number of arguments passed in.
 * @param argv A list of values passed in as arguments.
 * @return
 */
int main(int argc, char* argv[]){
	loadData();
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
 * Load all data.
 * Various global variables will be defined by functions called through here.
 */
void loadData(){
	//loadStandardSkills();
	//loadStandardItems();
	//loadStandardRaces();
	//loadStandardClasses();
	//loadPlayerData();
}

/**
 * A function that prints the stats for a character.
 * @param character The character whose stats will be printed.
 */
void printStats(CharacterSheet character){
	Attribute str = character.getAttribute("strength");
	Attribute dex = character.getAttribute("dexterity");
	Attribute con = character.getAttribute("constitution");
	Attribute inte = character.getAttribute("intelligence");
	Attribute wis = character.getAttribute("wisdom");
	Attribute cha = character.getAttribute("charisma");

	//  Apparently I'm not using C++11. What am I using? More investigation will
	//  be needed.
	//string strMod = str.getAttributeModifier() > 0 ? "+"+str.getAttributeModifier() : str.getAttributeModifier();
	//string strMod = std::to_string(str.getAttributeModifier());

	try{
		cout << "Name: " << endl
				<< "Str: " << str.getValue() << " (" << str.getAttributeModifier() << ')' << endl
				<< "Dex: " << dex.getValue() << " (" << dex.getAttributeModifier() << ')' << endl
				<< "Con: " << con.getValue() << " (" << con.getAttributeModifier() << ')' << endl
				<< "Int: " << inte.getValue() << " (" << inte.getAttributeModifier() << ')' << endl
				<< "Wis: " << wis.getValue() << " (" << wis.getAttributeModifier() << ')' << endl
				<< "Cha: " << cha.getValue() << " (" << cha.getAttributeModifier() << ')' << endl;
	}catch(...){
		cout << "Bad attribute!" << endl;
	}
}
