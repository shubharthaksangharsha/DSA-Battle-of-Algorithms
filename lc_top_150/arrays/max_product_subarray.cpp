//Author - Shubharthak Sangharasha
/*
    Description: Return maximum product subarray
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
int solve(vector<int>&arr){
	//Brute Force , TC: O(n^2), SC: o(1)
	// int ans = INT_MIN;
	// for(int i = 0; i < arr.size(); i++){
	// 	for(int j = 0; j < arr.size(); j++){
	// 		int product = 1;
	// 		for(int k = i; k < j; k++){
	// 			product *= arr[k];
	// 		}
	// 		ans = max(ans, product);
	// 	}
	// }
	// return ans;

	//N^2: As new element is added just multiply it and store the max of it 
	// int ans = INT_MIN; 
	// for(int i = 0; i < arr.size(); i++){
	// 	int product = 1;
	// 	for(int j = i; j < arr.size(); j++){
	// 		product *= arr[j];
	// 		ans = max(ans, product);
	// 	}
	// }
	// return ans;

	//O(N) Solution O(1) Space : Suffix Prefix Method 
	int suffix = 1, prefix = 1, ans = INT_MIN; 
	for(int i = 0; i < arr.size(); i++){
		if(suffix == 0) suffix = 1;
		if(prefix == 0) prefix = 1; 

		suffix *= arr[arr.size() - i - 1]; prefix *= arr[i];
		ans = max(ans, max(prefix, suffix));
	}
	return ans;
}
int main(){
 	int n; cin >> n; 
 	vector<int>arr(n); 
 	input(arr); 
 	cout << solve(arr);
 	// print(arr);
    return 0; 
}