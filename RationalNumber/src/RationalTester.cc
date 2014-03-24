/*
 * RationalTester.cc
 *
 *  Created on: Sep 14, 2013
 *      Author: Scott
 */


#include "RationalNumber.h"
#include <iostream>
using namespace std;

int main(){
	RationalNumber r1 = RationalNumber(6,8);
	RationalNumber r2 = RationalNumber(1,3);


	cout << "First rational number: " << r1<< endl;
	cout << "Second rational number: " << r2 << endl;

	if(r1.isLike(r2)){
		cout << "r1 and r2 are equal." << endl;
	}else
		cout << "r1 and r2 are NOT equal." << endl;

	RationalNumber r3 = r1.reciprocal();
	cout << "The reciprocal of r1 is: " << r3 << endl;

	RationalNumber r4 = r1 + r2;
	RationalNumber r5 = r1 - r2;
	RationalNumber r6 = r1 * r2;
	RationalNumber r7 = r1 / r2;

	cout << "r1 + r2: " << r4 << endl;
	cout << "r1 - r2: " << r5 << endl;
	cout << "r1 * r2: " << r6 << endl;
	cout << "r1 / r2: " << r7<< endl;

	return 0;

}


