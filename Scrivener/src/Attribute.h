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
	Attribute(short);

	void setAttribute(short);
	short getAttribute();

};

#endif /* SRC_ATTRIBUTE_H_ */
