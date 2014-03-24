/*main.cpp
 *
 *  Created on: Oct 8, 2013
 *      Author: Scott
 */
/*
 * Scott Dreyer
 */
#include <algorithm>
#include <iostream>
#include <iterator>
#include "list.hpp"
using gvsu::list;
using namespace std;

int main()
{
    list<float> famous_numbers {3.14159, 2.71828, 0.57721, 6.02214};

    for (auto p = famous_numbers.begin();
              p != famous_numbers.end();
              ++p)
    {
        cout << *p << endl;
    }
    /* the following should output 6.02214 */
    cout << famous_numbers[-1] << endl;
    /* the following should output 0.57721 */
    cout << famous_numbers[2] << endl;
    /* the following should print in reverse order */
    for (auto p = famous_numbers.rbegin();
              p != famous_numbers.rend();
              --p)
    {
        cout << *p << endl;
    }

}
