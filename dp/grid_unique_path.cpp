	//Author - Shubharthak Sangharasha
	/*
	    Description: Unique Grid Path 
	*/

	#include<bits/stdc++.h> 
	using namespace std; 
	int const N = 10e6;

	void input(vector<vector<int>>&arr){
		for(auto &i: arr){
			for(auto &j: i){
				cin >> j;
			}
		}
	}

	void print(const vector<vector<int> >&arr){
		for(auto const i: arr){
			for(auto const j: i){
				cout << j << " ";
			}
			cout << endl;
		}
	}

	//Recursive Approach
	int solve(int i, int j, vector<vector<int> >&arr){
		//base case 
		if(i == 0 && j == 0){
			return 1;
		}
		if (i < 0 || j < 0){
			return 0;
		}
		int left = solve(i, j-1, arr);
		int right = solve(i - 1, j, arr);
		return left + right;
	}

	//DP Memoization Top Down Approach 
	int solve2(int i, int j, vector<vector<int> >&arr, vector<vector<int> >&dp){
		//base case 
		if(i == 0 && j == 0){
			return 1;
		}
		if (i < 0 || j < 0){
			return 0;
		}
		if(dp[i][j] != -1){
			return dp[i][j];
		}
		int left = solve2(i, j-1, arr, dp);
		int right = solve2(i - 1, j, arr, dp);
		return dp[i][j] = left + right;
	}

	//Tabulation DP Bottom Up approach 
	int solve3(int m, int n, vector<vector<int> >&arr, vector<vector<int> >&dp){
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){

				if(i == 0 && j == 0){
					dp[i][j] = 1; 
				} else{
					int up = 0; int left = 0;
					if (i > 0){
						up = dp[i -1][j]; 
					}
					if (j > 0){
						left = dp[i][j - 1];
					}
					dp[i][j] = up + left; 
				}
			}
		}
		return dp[m -1][n -1];
	}

	//Space Optimization of Tabulation DP 
	int solve4(int m, int n, vector<vector<int> >&arr){
		vector<int>prev(n, 0);
		for(int i = 0; i < m; i++){
			vector<int>curr(n, 0);
			for(int j = 0; j < n; j++){
				if(i == 0 && j == 0){
					curr[j] = 1; 
				} else{
					int up = 0; int left = 0; 
					if(i > 0){
						up = prev[j];
					}
					if (j > 0){
						left = curr[j - 1];
					}
					curr[j] = up + left;
				}
			}
			prev = curr;
		}
		return prev[n -1];
	}
	int maze(vector<vector<int> >&arr, int m, int n){
		vector<vector<int> >dp(m, vector<int>(n, -1));
		return solve4(m, n, arr);
		return solve3(m, n, arr, dp);
		return solve(m-1, n-1, arr);
		return solve2(m-1, n-1, arr, dp);
	}
	int main(){
		int m; int n; 
		cin >> m; cin >> n;
		vector<vector<int> >arr(m, vector<int>(n));
		input(arr);
		// print(arr);
		cout << maze(arr, m, n);
	    return 0; 
	}