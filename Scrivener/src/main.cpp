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

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

//#include "character/Attribute.h"
//#include "character/Skill.h"
//#include "character/CharacterSheet.h"
//#include "json/reader.h"
//#include "json/writer.h"
//#include "json/elements.h"
#include "CharacterManager.h"

using namespace std;

//void loadData();
//void loadStandardSkills();
//void printStats(CharacterSheet);
//void cleanup();

vector<Skill*> standardSkills;

/**
 *
 * @param argc The number of arguments passed in.
 * @param argv A list of values passed in as arguments.
 * @return
 */
int main(int argc, char* argv[]){
//	loadData();
//	Attribute str (10);
//	cout << "Strength = " << str.getValue() << endl;
//
//	CharacterSheet bob;
//	Attribute str2 = bob.getStr();
//	cout << "Strength: " << str2.getValue() << endl;
//	str2.setValue(11);
//	cout << "Strength: " << str2.getValue() << endl;
//	cout << "Strength: " << bob.getStr().getValue() << endl;
//
//	cout << "--------------------------" << endl;
//	Attribute *StrPtr = bob.getStrPtr();
//	cout << "Strength: " << StrPtr->getValue() << endl;
//
//	cout << "--------------------------" << endl;
//	bob.rollStats("random");
//	cout << "Strength (random): " << bob.getStr().getValue() << endl;
//	bob.rollStats("4d6 drop lowest");
//	cout << "Strength (4d6 drop lowest): " << bob.getStr().getValue() << endl;
//
//	printStats(bob);
//
//	cleanup();
//	char asdf[20] = "something";
//	CharacterManager cm(asdf);
	CharacterManager cm2("settings.ini");

	cout << "Number of arguments: " << argc << endl;
	for (int i = 0; i < argc; ++i) {
		cout << argv[i] << endl;
	}

	return 0;
}

/**
 * Load all data.
 * Various global variables will be defined by functions called through here.
 */
//void loadData(){
//	loadStandardSkills();
//	//loadStandardItems();
//	//loadStandardRaces();
//	//loadStandardClasses();
//	//loadPlayerData();
//}

/**
 * Loads all known skills.
 * For now, this is hard coded. The skillNames vector will be replaced by either a JSON or XML file.
 * Data will be loaded into a global skills variable afterward however.
 */
//void loadStandardSkills(){
//	vector<string> skillNames;
//	skillNames.push_back("Appraise");
//	skillNames.push_back("Balance");
//	skillNames.push_back("Bluff");
//	skillNames.push_back("Climb");
//	skillNames.push_back("Concentration");
//	skillNames.push_back("Craft");
//	skillNames.push_back("Decipher Script");
//	skillNames.push_back("Diplomacy");
//	skillNames.push_back("Disable Device");
//	skillNames.push_back("Disguise");
//	skillNames.push_back("Escape Artist");
//	skillNames.push_back("Forgery");
//	skillNames.push_back("Gather Information");
//	skillNames.push_back("Handle Animal");
//	skillNames.push_back("Heal");
//	skillNames.push_back("Hide");
//	skillNames.push_back("Intimidate");
//	skillNames.push_back("Jump");
//	skillNames.push_back("Knowledge");
//	skillNames.push_back("Listen");
//	skillNames.push_back("Move Silently");
//	skillNames.push_back("Open Lock");
//	skillNames.push_back("Perform");
//	skillNames.push_back("Profession");
//	skillNames.push_back("Ride");
//	skillNames.push_back("Search");
//	skillNames.push_back("Sense Motive");
//	skillNames.push_back("Sleight Of Hand");
//	skillNames.push_back("Speak Language");
//	skillNames.push_back("Spellcraft");
//	skillNames.push_back("Spot");
//	skillNames.push_back("Survival");
//	skillNames.push_back("Swim");
//	skillNames.push_back("Tumble");
//	skillNames.push_back("Use Magic Device");
//	skillNames.push_back("Use Rope");
//
//	Skill* someSkill;
//	for(vector<string>::iterator x = skillNames.begin(); x != skillNames.end(); ++x){
//		someSkill = new Skill(*x);
//		//standardSkills.push_back
//		standardSkills.push_back(someSkill);
//	}
//}

/**
 * A function that prints the stats for a character.
 * @param character The character whose stats will be printed.
 */
//void printStats(CharacterSheet character){
//	Attribute str = character.getAttribute("strength");
//	Attribute dex = character.getAttribute("dexterity");
//	Attribute con = character.getAttribute("constitution");
//	Attribute inte = character.getAttribute("intelligence");
//	Attribute wis = character.getAttribute("wisdom");
//	Attribute cha = character.getAttribute("charisma");
//
//	try{
//		cout << "Name: " << endl
//				<< "Str: " << str.getValue() << " (" << str.getAttributeModifier() << ')' << endl
//				<< "Dex: " << dex.getValue() << " (" << dex.getAttributeModifier() << ')' << endl
//				<< "Con: " << con.getValue() << " (" << con.getAttributeModifier() << ')' << endl
//				<< "Int: " << inte.getValue() << " (" << inte.getAttributeModifier() << ')' << endl
//				<< "Wis: " << wis.getValue() << " (" << wis.getAttributeModifier() << ')' << endl
//				<< "Cha: " << cha.getValue() << " (" << cha.getAttributeModifier() << ')' << endl;
//	}catch(...){
//		cout << "Bad attribute!" << endl;
//	}
//}

//void cleanup(){
//	for(vector<Skill*>::iterator skillPtr = standardSkills.begin(); skillPtr != standardSkills.end(); ++skillPtr){
//		delete *skillPtr;
//	}
//}
