/*
 * Rectangle.h
 *
 *  Created on: Sep 29, 2013
 *      Author: Scott
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#include<iostream>
#include <string>
using namespace std;

class Rectangle {
	friend ostream& operator<<(ostream&, const Rectangle&);

public:
	Rectangle();
	Rectangle(int length, int width);

	int width() const;
	int length() const;

	int area() const;
	int perimeter() const;
	string toString(Rectangle rec);
	bool operator<(const Rectangle& op2) const {
		return this->perimeter() < op2.perimeter();
	}
	bool operator==(const Rectangle& op2) const {
		return this->perimeter() == op2.perimeter();
	}

private:
	int recLength, recWidth;

};
#endif /* RECTANGLE_H_ */
