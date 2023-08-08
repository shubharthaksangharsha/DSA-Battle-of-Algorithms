//Author - Shubharthak Sangharasha
/*
    Description: Find the min of maximum wall can be done by the given amount of painters.
*/

#include<bits/stdc++.h> 
using namespace std; 
int const N = 10e6;

void input(vector<int>&arr){
	for(auto &i: arr){
		cin >> i; 
	}
}

void print(const vector<int>&arr){
	for(auto const i: arr){
		cout << i << " ";
	}
	cout << endl;
}
int solve(const vector<int>&arr, int const painters, int n){
	//linear search 
	
}
int main(){
 	int n; cin >> n; 
 	vector<int>arr(n); 
 	input(arr); 
 	int painters; cin >> painters; 
 	cout << solve(arr, painters, n);
 	// print(arr);
    return 0; 
}