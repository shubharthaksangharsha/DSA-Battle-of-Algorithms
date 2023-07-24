//Author - Shubharthak Sangharasha
/*
    Description: Get the maximum sum of subsequence of the array
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

//Using Recursion 
int solve(int i, vector<int>&arr){
	//base case
	if (i == 0){
		return arr[i];
	}
	if (i < 0){
		return 0;
	}

	int pick = solve(i -2, arr) + arr[i];
	int not_pick = solve(i -1, arr);
	return max(not_pick, pick);

}

//Using DP Tabulation Bottom up approach
int solve3(int ind, vector<int>&arr, vector<int>&dp){
	dp[0] = arr[0]; 
	for(int i = 1; i < arr.size(); i++){
		int take = arr[i];
		if (i > 1){
			take += dp[i-2];
		}
		int not_take = dp[i - 1]; 
		dp[i] = max(take, not_take);
	}
	print(dp); 
	return dp[ind];
}

//Using DP Memoization Top Down Approach
int solve2(int i, vector<int>&arr, vector<int>&dp){
	//base case 
	if(i == 0){
		return arr[i];
	}
	if(i < 0){
		return 0;
	}
	if (dp[i] != -1){
		return dp[i];
	}
	int pick = solve2(i-2, arr, dp) + arr[i];
	int not_pick = solve2(i - 1, arr, dp);
	return dp[i] = max(not_pick, pick);
}
//Space Optimized DP Bottom Up Tabulation 
int solve4(int i,vector<int>&arr){
	int prev1 = arr[0]; 
	int prev2 = 0; 
	for(int i = 1; i < arr.size(); i++){
		int take = arr[i]; 
		if (i > 1){
			take += prev2;
		}
		int not_take = prev1;  
		int result = max(take, not_take);
		prev2 = prev1; 
		prev1 = result;
	}
	return prev1;
}
int maxNonAdjacentSum(vector<int>&arr){
	vector<int>dp(arr.size(), -1);
	return solve4(arr.size() - 1, arr);
	return solve3(arr.size()-1, arr, dp);
	// return solve2(arr.size()-1, arr, dp);

}
int main(){
	int n; cin >> n;
	vector<int>arr(n); 
	input(arr); 
	// print(arr);
	cout << maxNonAdjacentSum(arr);
    return 0; 
}