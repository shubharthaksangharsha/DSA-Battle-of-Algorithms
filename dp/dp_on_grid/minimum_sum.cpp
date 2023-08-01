//Author - Shubharthak Sangharasha
/*
    Description: 
*/

#include<bits/stdc++.h> 
using namespace std; 


void input(vector<vector<int>>&arr){
	for(auto &i: arr){
		for(auto &j : i){
			cin >> j; 
		}
	}
}

void print(const vector<vector<int>>&arr){
	for(auto const i: arr){
		for(auto const j: i){
			cout << j << " ";
		}
		cout << endl;
	}
}

int f(int const i, int const j, const vector<vector<int>>&arr){
	//base case 
	if(i == 0 && j == 0){
		return arr[i][j]; 
	}
	if(i < 0 || j < 0){
		return 1e9;
	}
	int up = arr[i][j] + f(i -1, j, arr); 
	int left = arr[i][j] + f(i, j - 1, arr);
	return min(up, left); 
}
//DP using memoization using Top down approach 
int f2(int i, int j, const vector<vector<int>>&arr, vector<vector<int>>&dp){
	//base case 
	if (i == 0 && j == 0){
		return arr[i][j]; 
	}
	if (i < 0 || j < 0){
		return 1e9; 
	}
	if(dp[i][j] != -1){
		return dp[i][j];
	}
	int up = arr[i][j] + f2(i - 1, j, arr, dp);
	int left = arr[i][j] + f2(i, j - 1, arr, dp ); 
	return dp[i][j] = min(up, left); 
}

//DP using tabulation using bottom up approach 
int f3(int const m, int const n, const vector<vector<int>>&arr, vector<vector<int>>&dp){
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(i == 0 && j == 0){
				dp[i][j] = arr[i][j]; 
			} else{
				int up = arr[i][j]; int left = arr[i][j]; 
				if(i > 0){
					up += dp[i -1][j]; 
				} else{
					up += 1e9;
				}
				if(j > 0){
					left += dp[i][j - 1];
				} else{
					left += 1e9;
				}
				dp[i][j] = min(left, up); 
			}
		}
	}
	return dp[m -1][n-1];
}

//DP using space optimization tabulation 
int f4(int const m, int const n, vector<vector<int>>&arr){

	return 0;
}
int solvemaze(const vector<vector<int>>&arr, int const m, int const n){
	vector<vector<int>>dp(m, vector<int>(n, -1));
	return f3(m, n, arr, dp);
	// return f2(m-1, n-1, arr, dp);
	// return f(m -1, n- 1, arr);
}
int main(){
 	int m, n;
 	cin >> m >> n; 
 	vector<vector<int> >arr(m, vector<int>(n));
 	input(arr);
 	// print(arr);
 	cout << solvemaze(arr, m, n);
    return 0; 
}