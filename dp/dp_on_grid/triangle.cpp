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

int f(int const i, int const j, int const n, vector<vector<int>>&arr){
	//base case 
	if (i == n - 1){
		return arr[i][j];
	}
	int down = arr[i][j] + f(i + 1, j, n, arr);
	int diagnal = arr[i][j]+ f(i + 1, j + 1, n, arr);
	return min(down, diagnal);
}

//DP Memoization using Top Down Approach 
int f2(int const i, int const j, int const n, vector<vector<int>>&arr,vector<vector<int>>&dp){
	//base case 
	if (i == n - 1){
		return arr[i][j];
	}
	if(dp[i][j] != -1){
		return dp[i][j];
	}
	int down = arr[i][j] + f(i + 1, j, n, arr);
	int diagnal = arr[i][j]+ f(i + 1, j + 1, n, arr);
	return dp[i][j] = min(down, diagnal);
}

//Tabulation for DP using Bottom up approach 
int f3(int const n, vector<vector<int>>&arr){
	//initializing the dp 
	vector<vector<int>>dp(n, vector<int>(n, -1));
	//filling the last row 
	for(int j = 0; j < n; j++){
		dp[n - 1][j] = arr[n-1][j];
	}
	for(int i = n -2; i >= 0; i--){
		for(int j = i; j >= 0; j--){
			int d= arr[i][j] + arr[i +1][j]; 
			int dg = arr[i][j] + arr[i + 1][j+1];
			dp[i][j] = min(d, dg);
		}
	}
	return dp[0][0];	
}

//Tabulation for DP using Bottom up approach 
int f4(int const n, vector<vector<int>>&arr){
	//initializing the dp 
	vector<int>front(n, 0), cur(n, 0); 
	//filling the last row 
	for(int j = 0; j < n; j++){
		front[j] = arr[n-1][j];
	}
	for(int i = n -2; i >= 0; i--){
		for(int j = i; j >= 0; j--){
			int d= arr[i][j] + front[j]; 
			int dg = arr[i][j] + front[j+1];
			cur[j] = min(d, dg);
		}
		front = cur;
	}
	return front[0];	
}

int solve(int const m, int const n, vector<vector<int>>&arr){
	vector<vector<int>>dp(m, vector<int>(n, -1));
	return f4(m, arr);
	// return f3(m, arr);
	// return f2(0, 0, m, arr, dp);
	// return f(0, 0, m, arr);
}

int main(){
 	int m, n;
 	cin >> m >> n; 
 	vector<vector<int> >arr(m, vector<int>(n));
 	input(arr);
 	// print(arr);
 	cout << solve(m, n, arr) << endl;;
    return 0; 
}