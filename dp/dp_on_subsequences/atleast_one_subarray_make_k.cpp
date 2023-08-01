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
bool f(int i, int target, vector<int>&arr){
	//base case 
	if(target == 0){
		return true;
	}
	if(i == 0){
		return arr[i] == target; 
	}
	bool not_take = f(i - 1, target, arr); 
	bool take = false; 
	if(arr[i] <= target){
		take = f(i - 1, target - arr[i], arr);
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
	if(arr[i] <= target){
		take = f2(i - 1, target - arr[i], arr, dp); 
	}
	return dp[i][target] = take | not_take;
}
bool f3(int i, int target, vector<int>&arr, int n){
	vector<vector<bool> >dp(n, vector<bool>(target + 1, false));
	for(int i = 0; i < n; i++){
		dp[i][0] = true;
	}
	for(int t  = 1; t <= target; t++){
		dp[0][t]  = arr[0] == t;
	}

	for(int i = 1; i < n; i++){
		for(int t = 1; t<= target; t++){
			bool not_take = dp[i - 1][t];
			bool take = false; 
			if(arr[i] <= t){
				take = dp[i - 1][t - arr[i]];
			}
			dp[i][t] = take | not_take;			
		}
	}
	return dp[n - 1][target];
}
bool f4(int i, int target, vector<int>&arr, int n){
	vector<bool>prev(target + 1, false);
	prev[0] = true; 
	for(int t  = 1; t <= target; t++){
		prev[t]  = arr[0] == t;
	}

	for(int i = 1; i < n; i++){
		for(int t = target; t >= 1; t--){
			bool not_take = prev[t];
			bool take = false; 
			if(arr[i] <= t){
				take = prev[t - arr[i]];
			}
			prev[t] = take | not_take;			
		}
	}
	return prev[target];
}

bool solve(vector<int>&arr, int const k, int const n){
	vector<vector<int>>dp(n, vector<int>(k+1, -1));
	return f3(0, k, arr, n);
	// return f2(n -1, k, arr, dp);
	// return f(n -1, k, arr);
}
int main(){
 	int n, k; cin >> n >> k; 
 	vector<int>arr(n); 
 	input(arr); 
 	print(arr);
 	cout << n << " " << k << endl;
 	cout << "        " << endl;
 	if (solve(arr, k, n)){
 		cout << "True";
 	} else{
 		cout << "False";
 	}
    return 0; 
}