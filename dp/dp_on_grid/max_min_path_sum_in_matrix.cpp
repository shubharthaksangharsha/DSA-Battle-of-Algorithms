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

//Normal Recursion 
int f(int const i, int const j, int const n, const vector<vector<int>>&arr){
	//out of bound case 
	if(j < 0 || j >= n){
		return -1e7;
	}
	//base case 
	if(i == n - 1){
		return arr[i][j];
	}

	int down = arr[i][j] + f(i+1, j, n, arr);
	int leftdg = arr[i][j] + f(i +1, j-1, n, arr);
	int rightdg = arr[i][j] + f(i +1, j + 1, n, arr);
	return max(down, max(leftdg, rightdg));
}
//DP Recursion using Top down approach 
int f2(int const i, int const j, int const n, const vector<vector<int>>&arr, vector<vector<int>>&dp){
	//out of bound case 
	if(j < 0 || j >= n){
		return -1e7;
	}
	//base case 
	if(i == n - 1){
		return arr[i][j];
	}
	if(dp[i][j] != -1){
		return dp[i][j];
	}
	int down = arr[i][j] + f2(i+1, j, n, arr, dp );
	int leftdg = arr[i][j] + f2(i +1, j-1, n, arr, dp );
	int rightdg = arr[i][j] + f2(i +1, j + 1, n, arr, dp);
	return dp[i][j] = max(down, max(leftdg, rightdg));
}

//DP Tabulation using Bottom up approach 
int f3(int const i, int const j , int const n, const vector<vector<int>>&arr, vector<vector<int>>&dp){
	
}
int solve(vector<vector<int>>&arr, int const n){
	int maxi = INT_MIN;
	vector<vector<int>>dp(n, vector<int>(n, -1));
	for(int j = 0; j < n; j++){
		// maxi = max(maxi, f(0, j, n, arr));
		maxi = max(maxi, f2(0, j, n, arr, dp));
		
	}
	return maxi;
}

int main(){
 	int m, n;
 	cin >> m >> n; 
 	vector<vector<int> >arr(m, vector<int>(n));
 	input(arr);
 	// print(arr);
 	cout << solve(arr, n);
    return 0; 
}