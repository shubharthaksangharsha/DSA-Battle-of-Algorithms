//Author - Shubharthak Sangharasha
/*
    Description: Assign signs to array and tell how many ways we can form target
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
int f(int i, int target, vector<int>&arr, int n){
	
}
int solve(vector<int>&arr, int target, int n){
	return f(n - 1, target, arr, n);
}
int main(){
 	int n; cin >> n; 
 	vector<int>arr(n); 
 	input(arr); 
 	int target; cin >> target;
 	cout << solve(arr, target, n);
    return 0; 
}