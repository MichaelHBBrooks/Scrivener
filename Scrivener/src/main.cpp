/*
 * main.cpp
 *
 *  Created on: Oct 16, 2016
 *      Author: jinieren
 */

#include <iostream>
#include "Attribute.h"

using namespace std;

int main(){
	Attribute str (10);
	cout << "Strength = " << str.getAttribute() << endl;
}


