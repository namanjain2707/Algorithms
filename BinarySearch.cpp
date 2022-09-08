#include<bits/stdc++.h>
using namespace std;

/*
	lower_bound() -> Gives the first number in the sorted array which is greater than or equal to p.
	upper_bound() -> Gives the first number in the sorted array which is strictly greater than p.
	Binary Search as a solution must strike as a possible solution in any of the following cases:

	1) min-max problems -> Given an array, find the largest number smaller than the number p.
	2) Monotonously increasing or decreasing functions -> 

	Problem Links : 
*/

/*
	Simple Binary Search on a sorted vector from 'st' to 'en' for a value 'val'.
	In case of duplicate numbers in vector, it might return any match.
*/
int search(vector<int> vec, int st, int en, int val){
	while(st<=en){
		int mid=(st+en)/2;
		if(vec[mid] > val){
			en = mid-1;
		}else if(vec[mid] < val){
			st = mid+1;
		}else return mid;
	}
	return -1;
}

int searchFirstValue(vector<int> vec, int st, int en, int val){
	while(st<=en){
		int mid=(st+en)/2;
		if(vec[mid] > val){
			en = mid-1;
		}else if(vec[mid] < val){
			st = mid+1;
		}else{
			if(mid == st || vec[mid-1] < val) return mid;
			else en = mid-1;
		}
	}
	return -1;
}

int searchLastValue(vector<int> vec, int st, int en, int val){
	while(st<=en){
		int mid=(st+en)/2;
		if(vec[mid] > val){
			en = mid-1;
		}else if(vec[mid] < val){
			st = mid+1;
		}else{
			if(mid == en || vec[mid+1] > val) return mid;
			else st = mid+1;
		}
	}
	return -1;
}

int lower_bound(vector<int> vec, int st, int en, int val){
	while(st<=en){
		int mid=(st+en)/2;
		if(vec[mid] >= val){
			if(st == mid || vec[mid-1] < val) return mid;
			else en = mid-1;
		}else if(vec[mid] < val){
			st = mid+1;
		}
	}

	return -1;
}

int upper_bound(vector<int> vec, int st, int en, int val){
	while(st<=en){
		int mid=(st+en)/2;
		if(vec[mid] > val){
			if(st == mid || vec[mid-1] <= val) return mid;
			else en = mid-1;
		}else if(vec[mid] <= val){
			st = mid+1;
		}
	}

	return -1;
}

int largestNumberSmallerThanVal(vector<int> vec, int st, int en, int val){
	return lower_bound(vec, st, en, val)-1;
}

int smallestNumberLargerThanVal(vector<int> vec, int st, int en, int val){
	return upper_bound(vec, st, en, val);
}


int main(){
	vector<int> vec;
	for(int i=1;i<10;i++){
		for(int j=0;j<i;j++) vec.push_back(i);
	}

	cout<<vec[smallestNumberLargerThanVal(vec, 0, vec.size()-1, 8)]<<endl;
	return 0;
}