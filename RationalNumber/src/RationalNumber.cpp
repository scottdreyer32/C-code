//============================================================================
// Name        : RationalNumber.cpp
// Author      : Scott Dreyer
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "RationalNumber.h"
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
using namespace std;

#include <utility>
#include "RationalNumber.h"

RationalNumber::RationalNumber()
{
    numerator = 0;
    denominator = 1;
}

RationalNumber::RationalNumber(int numer, int denom) {
    if (denom == 0)
        denom = 1;
    if (denom < 0) {
        numer *= -1;
        denom *= -1;
    }
    numerator = numer;
    denominator = denom;

    reduce();
}

RationalNumber::RationalNumber(const RationalNumber& r)
{
    numerator = r.numerator;
    denominator = r.denominator;
}

RationalNumber::RationalNumber(RationalNumber&& r)
{
    numerator = r.numerator;
    denominator = r.denominator;
}

RationalNumber& RationalNumber::operator= (const RationalNumber& r)
{
    numerator = r.numerator;
    denominator = r.denominator;
//    RationalNumber tmp{r};
//    std::swap(tmp,*this);
    return *this;
}

RationalNumber& RationalNumber::operator= (RationalNumber&& r)
{
    numerator = r.numerator;
    denominator = r.denominator;
    return *this;
}

int RationalNumber::getNumerator() const
{
    return numerator;
}

int RationalNumber::getDenominator() const
{
    return denominator;
}

RationalNumber RationalNumber::reciprocal() const
{
    return RationalNumber(denominator, numerator);
}

RationalNumber RationalNumber::add (const RationalNumber& op2) const
{
    int commonDenom = denominator * op2.denominator;
    int num1 = numerator * op2.denominator;
    int num2 = op2.numerator * denominator;
    int sum = num1 + num2;
    return RationalNumber(sum, commonDenom);
}

RationalNumber RationalNumber::subtract (const RationalNumber& op2) const
{
    int commonDenom = denominator * op2.denominator;
    int num1 = numerator * op2.denominator;
    int num2 = op2.numerator * denominator;
    int diff = num1 - num2;
    return RationalNumber(diff, commonDenom);
}

RationalNumber RationalNumber::multiply (const RationalNumber& op2) const
{
    return RationalNumber{numerator * op2.numerator,
        denominator * op2.denominator};
}

RationalNumber RationalNumber::divide (const RationalNumber& op2) const
{
    return multiply(op2.reciprocal());
}

void RationalNumber::reduce()
{
    if (numerator != 0) {
        int common = gcd(abs(numerator), denominator);
        numerator /= common;
        denominator /= common;
    }
}

int RationalNumber::gcd (int num1, int num2) const
{
    while (num1 != num2)
        if (num1 > num2)
            num1 -= num2;
        else
            num2 -= num1;
    return num1;
}

bool RationalNumber::isLike (const RationalNumber& r) const
{
    return numerator == r.numerator && denominator == r.denominator;
}

ostream& operator<< (ostream& s, const RationalNumber& r)
{
    s << r.getNumerator() << "/" << r.getDenominator();
    return s;
}











 /* namespace std */
