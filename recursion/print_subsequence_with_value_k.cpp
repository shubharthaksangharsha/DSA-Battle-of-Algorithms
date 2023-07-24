
//Author - Shubharthak Sangharasha
/*
    Description: 
*/


#include<bits/stdc++.h> 
using namespace std; 
int const N = 10e6;

void f(int i, vector<int>&arr, vector<int>array, int sum, int k){
	if(i == array.size() ){
		if (sum == k){
			for(auto i: arr){
				cout << i << " ";
			}
			cout << endl;
		}
		return;
	}
	//add
	arr.push_back(array[i]);
	f(i+1, arr, array, sum + array[i], k);
	arr.pop_back();
	f(i+1, arr, array, sum, k);
}


int main(){
 	// int n; cin >> n;
 	vector<int>array = { 1, 2, 1};
 	vector<int>arr;
 	int k = 2; 
 	f(0, arr, array, 0, k);
  	return 0; 
}