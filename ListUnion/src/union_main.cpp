/*
 * hw34_main.cpp
 *
 *  Created on: Oct 7, 2013
 *      Author: Scott
 */

/*
 * Scott Dreyer
 */
#include <iostream>
#include <list>
#include <iterator>
#include <string>
#include "list_union.h"
#include "Rectangle.h"
#include "RationalNumber.h"

using namespace std;

int main() {
	/*--- begin replicate ---*/
	list<int> num1 { 5, 11, 20, 30, 45, 71 };
	list<int> num2 { -2, 10, 11, 20, 45, 74, 89 };
	list<int> nums = listUnion(num1, num2);
	/* nums should contain only 10 elements */

	/* Copy from the list to stdout (or print the elements) */
	// to print other classes replace <int> with <string>, <RationalNumber>, ....
	copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, ", "));
	cout << endl;
	/*--- end replicate ---*/

	list<string> string1 { "apple", "car", "compass", "dog", "elephant", "grape" };
	list<string> string2 { "berry", "candy", "compass", "dingo", "fox", "grape",
			"hollow" };
	list<string> strings = listUnion(string1, string2);
	/* nums should contain only 10 elements */

	/* Copy from the list to stdout (or print the elements) */
	// to print other classes replace <int> with <string>, <RationalNumber>, ....
	copy(strings.begin(), strings.end(), ostream_iterator<string>(cout, ", "));
	cout << endl;
	/*--- end replicate ---*/

	list<RationalNumber> rat1 { RationalNumber(1, 32), RationalNumber(3, 32),RationalNumber(5, 32),
		RationalNumber(7, 32), RationalNumber(9, 32),RationalNumber(11, 32)};
	list<RationalNumber> rat2 { RationalNumber(1, 16), RationalNumber(1, 8),
			RationalNumber(3, 16), RationalNumber(2, 8), RationalNumber(5, 16),
			RationalNumber(3, 8), RationalNumber(7, 16) };
	list<RationalNumber> rats = listUnion(rat1, rat2);
	/* nums should contain only 10 elements */

	/* Copy from the list to stdout (or print the elements) */
	// to print other classes replace <int> with <string>, <RationalNumber>, ....
	copy(rats.begin(), rats.end(),
			ostream_iterator<RationalNumber>(cout, ", "));
	cout << endl;

	list<Rectangle> rec1 { Rectangle(1, 32), Rectangle(3, 32),
		Rectangle(5, 32), Rectangle(7, 32), Rectangle(9, 32),
		Rectangle(11, 32) };
	list<Rectangle> rec2 { Rectangle(1, 16), Rectangle(1, 8),
		Rectangle(3, 16), Rectangle(2, 8), Rectangle(5, 16),
		Rectangle(3, 8), Rectangle(7, 16) };
	list<Rectangle> recs = listUnion(rec1, rec2);
	/* nums should contain only 10 elements */

	/* Copy from the list to stdout (or print the elements) */
	// to print other classes replace <int> with <string>, <RationalNumber>, ....
	copy(recs.begin(), recs.end(),
			ostream_iterator<Rectangle>(cout, ", "));
	cout << endl;
}

