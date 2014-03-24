//============================================================================
// Name        : Rectangle.cpp
// Author      : Scott Dreyer
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Rectangle.h"
#include<vector>
using namespace std;

Rectangle::Rectangle(int length, int width) {
   recLength = length;
   recWidth = width;

}

int Rectangle::length()const{
	return recLength;
}

int Rectangle::width()const{
	return recWidth;
}

int Rectangle::area()const{
	return length() * width();
}

int Rectangle::perimeter()const{
	return (length()+width()) * 2;
}

string Rectangle::toString(Rectangle re){
    string result = "";
    result += re.length() + "," + re.width();
    return result;
}

ostream& operator<< (ostream& os, const Rectangle& rec)
{
	os<< rec.width() << "," << rec.length();
	return os;
}





