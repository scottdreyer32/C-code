/*
 * hw217.cpp
 *
 *  Created on: Sep 29, 2013
 *      Author: Scott
 */
#include<vector>
using namespace std;

int minSubSum(const vector<int> & a){
	int minSum = a[0];
	int thisSum = 0;
	for(int j = 0; j<a.size(); ++j){
		thisSum += a[j];

		if(thisSum<minSum){
			minSum = thisSum;
		}
	}

	return minSum;
}

int minSubSumPos(const vector<int> & a){
	int minSum = a[0];
	int thisSum = 0;
	for(int j = 0; j<a.size(); ++j){
		thisSum += a[j];

		if((thisSum<minSum)&&thisSum>0){
			minSum = thisSum;
		}
	}

	return minSum;
}



