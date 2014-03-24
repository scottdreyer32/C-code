/*
 * hw2115.cpp
 *
 *  Created on: Sep 29, 2013
 *      Author: Scott
 */

#include <vector>
using namespace std;


int arraySearch(const vector<int> & a, const int & x){
	int low=0, high=a.size()-1;

	while(low<=high){
		int mid = (low + high)/2;

		if(a[mid]< mid){
			low = mid +1;
		}else if(a[mid]>mid){
			high = mid -1;
		}else
			return mid;
	}
	return -1;
}


