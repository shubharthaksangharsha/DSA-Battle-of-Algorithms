//Author - Shubharthak Sangharasha
/*
    Description: 
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

//using normal recursion 
int f(int i, int target, vector<int>&arr){
	//base case 
	if(target == 0){
		return true;
	}
	if(i == 0){
		return arr[i] == target; 
	}
	bool not_take = f(i - 1, target, arr); 
	bool take = false; 
	if(arr[i] >= target){
		take = f(i - 1, arr[i] - target, arr);
	}
	return take | not_take;
}
//using DP memoization top down approach 
int f2(int i, int target, vector<int>&arr, vector<vector<int>>&dp){
	//base case 
	if(target == 0){
		return true;
	}
	if(i == 0){
		return arr[i] == target;
	}
	bool not_take = f2(i - 1, target, arr, dp); 
	bool take = false; 
	if(arr[i] >= target){
		take = f2(i - 1, arr[i] - target, arr, dp); 
	}
	return dp[i][target] = take | not_take;
}
//using DP tabulation bottom up approach 
int f3(int i, int k, vector<int>&arr){
	vector<vector<bool> >dp(vector<bool>(k, 0)); 
	for(int i = 0; i < arr.size(); i++){
		dp[i][k] = true; 
	}
	for(int i = 0; i < arr.size(); i++){
		for(int target = 1; target < k; target++){
			bool not_take = dp[i-1, target]; 
			bool take = false; 
			if(arr[i] >= target){
				take = dp[i-1, target]; 
			}
			dp[i][target] = take | not_take;
		}
	}
	return dp[i][k];
}
bool solve(vector<int>&arr, int const k, int const n){
	vector<vector<int>>dp(n, vector<int>(k+1, -1));
	return f3(n-1, k, arr);
	return f2(n -1, k, arr, dp);
	return f(n -1, k, arr);
}
int main(){
 	int n, k; cin >> n >> k; 
 	vector<int>arr(n); 
 	input(arr); 
 	// print(arr);
 	if (solve(arr, k, n)){
 		cout << "True";
 	} else{
 		cout << "False";
 	}
    return 0; 
}