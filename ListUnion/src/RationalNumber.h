/*
 * RationalNumber.h
 *
 *  Created on: Oct 8, 2013
 *      Author: Scott
 */

#ifndef RATIONALNUMBER_H_
#define RATIONALNUMBER_H_

#include <iostream>
#include <string>
using namespace std;

class RationalNumber {
public:
	RationalNumber();
	RationalNumber(int numer, int denom);
	RationalNumber(const RationalNumber&);
	RationalNumber(RationalNumber&&);
	RationalNumber& operator=(const RationalNumber&);
	RationalNumber& operator=(RationalNumber&&);

	int getNumerator() const;
	int getDenominator() const;
	RationalNumber reciprocal() const;
	RationalNumber add(const RationalNumber&) const;
	RationalNumber subtract(const RationalNumber&) const;
	RationalNumber multiply(const RationalNumber&) const;
	RationalNumber divide(const RationalNumber&) const;

	RationalNumber operator+(const RationalNumber& op2) const {
		return this->add(op2);
	}
	RationalNumber operator-(const RationalNumber& op2) const {
		return this->subtract(op2);
	}
	RationalNumber operator*(const RationalNumber& op2) const {
		return this->multiply(op2);
	}
	RationalNumber operator/(const RationalNumber& op2) const {
		return this->divide(op2);
	}
	bool operator<(const RationalNumber& op2) const {
		int num1 = numerator * op2.denominator;
		int num2 = op2.numerator * denominator;
		return num1 < num2;

	}

	bool operator==(const RationalNumber& op2) const {
		int num1 = numerator * op2.denominator;
		int num2 = op2.numerator * denominator;
		return num1 == num2;

	}

	bool isLike(const RationalNumber&) const;
	friend ostream& operator<<(ostream&, const RationalNumber&);
private:
	void reduce();
	int gcd(int, int) const;
	int numerator, denominator;
};

#endif /* RATIONALNUMBER_H_ */
