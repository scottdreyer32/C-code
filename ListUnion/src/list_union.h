/*
 * list_union.h
 *
 *  Created on: Oct 7, 2013
 *      Author: Scott
 */

/*
 * Scott Dreyer
 */
#ifndef CS263_LIST_UNI_H
#define CS263_LIST_UNI_H
#include <list>
#include<iterator>
using std::list;

/* TEMPLATE FUNCTION FOR UNION OF 2 LISTS */
template<typename T>
list<T> listUnion(const list<T>& one, const list<T>& two) {
	list<T> result;

	auto iterOne = one.begin();
	auto iterTwo = two.begin();

	while (iterOne!=one.end() || iterTwo!=two.end()) {

		if (*iterOne < *iterTwo ) {
			if(iterOne!=one.end()){
				result.push_back(*iterOne);
				iterOne++;
			}else{
				result.push_back(*iterTwo);
				iterTwo++;
			}

		} else if (*iterTwo < *iterOne) {
			if(iterTwo!=two.end()){
				result.push_back(*iterTwo);
				iterTwo++;
			}else{
				result.push_back(*iterOne);
				iterOne++;
			}

		} else{
			result.push_back(*iterOne);
			iterOne++;
			iterTwo++;
		}
	}

	return result;

}

#endif
