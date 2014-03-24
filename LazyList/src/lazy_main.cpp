/*
 * */

#include "lazylist.hpp"

#include "RationalNumber.h"

using gvsu::lazylist;

int main()

{

	lazylist<RationalNumber> rats {
	RationalNumber { 2, 3 },RationalNumber { 5, 7 },
		RationalNumber { 40, 75 }
	};

}

