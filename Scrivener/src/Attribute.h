/*
 * Attribute.h
 *
 *  Created on: Oct 16, 2016
 *      Author: jinieren
 */

#ifndef SRC_ATTRIBUTE_H_
#define SRC_ATTRIBUTE_H_

class Attribute {
	short value;
public:
	Attribute();
	Attribute(short);

	void setValue(short);
	short getValue();

};

#endif /* SRC_ATTRIBUTE_H_ */
