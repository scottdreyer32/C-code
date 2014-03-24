/*
 * find.cpp
 *
 *  Created on: Sep 29, 2013
 *      Author: Scott
 */
#include<vector>
using namespace std;


int findCadidate(vector<int> arr, int size){
	int majIndex = 0;
	int majCount = 1;

	for(unsigned int i=1;i<arr.size(); ++i){
		if(arr[majIndex]==arr[i]){
			majCount++;
		}else
			majCount--;

		if(majCount ==0){
			majIndex = i;
			majCount =1;
		}

	}
	return arr[majIndex];
}

int findCandidateBook(vector<int> arr){
	vector<int> array;
	int majIndex = 0;

	for(unsigned int i=0;i<arr.size()-2; ++i){
			if(arr[i]==arr[i+1]){
				array.push_back(arr[i]);
			}

			++i;
		}
	return majIndex;
}



