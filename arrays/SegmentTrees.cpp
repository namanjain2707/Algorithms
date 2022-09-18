#include<bits/stdc++.h>
using namespace std;

#define BASE_VALUE 0 //Will be INT_MAX in case if min in range is required.

/*
	Important Notes :
	1) The root node of the segment tree is 1 in our implementation.
	2) The array is 0 indexed.
	3) node holds the answer for 'st' to 'en'. 2*node holds the answer for 'st' to 'mid'. 2*node+1 holds the answer for 'mid+1' to 'en'.
	4) For an array of size 'n', the maximum size of the segment tree would 2*(2^(ceil(log2(n))))-1.
	5) We can approximate it to 4*n for general case and would be 2*n in case where n is power of 2.
*/


int applyFunction(int a, int b){
	int val = a+b;	//Will be min(a, b) if min in range is required.
	return val;
}

/*
	O(n)
*/
void build(int node, int st, int en, int tree[], int arr[]){
	if(st == en){
		tree[node] = arr[st];
	}else{
		int mid = (st+en)/2;
		build(2*node, st, mid, tree, arr);
		build(2*node+1, mid+1, en, tree, arr);

		tree[node] = applyFunction(tree[2*node], tree[2*node+1]);
	}
}

/*
	Updates the value at index 'ind' to 'val'
	O(logn)
*/
void update(int node, int st, int en, int ind, int val, int tree[], int arr[]){
	//If st == en == ind obviously
	if(st == en){
		arr[ind] = val;
		tree[node] = val;
	}else{
		int mid = (st+en)/2;

		if(ind <= mid){
			update(2*node, st, mid, ind, val, tree, arr);
		}else{
			update(2*node+1, mid+1, en, ind, val, tree, arr);
		}

		tree[node] = applyFunction(tree[2*node], tree[2*node+1]);
	}
}

/*
	Gets the answer for the range 'l' to 'r'.
	O(logn)
	Conditions to check:
		1) Range represented by a node is completely inside the queried range
		2) Range represented by a node is completely outside the queried range
		3) Range represented by a node is partially inside and partially outside the queried range
*/
int get(int node, int st, int en, int l, int r, int tree[], int arr[]){
	if(l>en || r<st) return BASE_VALUE;
	else if(l<=st && r>=en) return tree[node];
	else{
		int mid = (st+en)/2;
		return applyFunction(get(2*node, st, mid, l, r, tree, arr), get(2*node+1, mid+1, en, l, r, tree, arr));
	}
}

int main(){
	return 0;
}