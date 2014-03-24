/*
 * hw115.cpp
 *
 *  Created on: Sep 29, 2013
 *      Author: Scott
 */
#include "Rectangle.h"
#include<vector>
using namespace std;


template<typename Object, typename Comparator>
const Object& findMax(const vector<Object>& arr, Comparator less){
		int maxIndex = 0;
			for(unsigned int i=0; i<arr.size(); ++i){
				if(less(arr[maxIndex], arr[i])){
					maxIndex=i;
				}
			}

			return arr[maxIndex];
	}

class RectangleAreaCompare
{
public:
	bool operator () (const Rectangle& left, const Rectangle& right){
		return left.area()<right.area();
	}
};

int main(){
	vector<Rectangle> arr = { Rectangle{3,4}, Rectangle {5,6}, Rectangle{4,5}};

	cout<<findMax(arr, RectangleAreaCompare())<<endl;
	//cout<<findMax(arr)<<endl;

}
