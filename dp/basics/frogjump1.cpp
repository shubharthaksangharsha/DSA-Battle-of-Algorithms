

//Author - Shubharthak Sangharasha
/*
    Description: 
*/

/*
Steps required 
1. Take index 
2. Do all stuffs on that index 
3. Take the minimum (all stuffs)
*/
#include<bits/stdc++.h> 
using namespace std; 
int const N = 10e6;

int min(int a, int b){
	return (a >= b) ? b : a; 
}

int f(const int i, const vector<int>&a){
	//base case 
	if(i == 0){
		return 0;
	}
	int left = f(i - 1, a) + abs(a[i] - a[i - 1]);
	int right = INT_MAX;
	if (i > 1){
		right = f(i - 2, a) + abs(a[i] - a[i - 2]);
	}
	return min(left, right);
}
//DP Recursion Memoization
int f2(const int i, const vector<int>&a, vector<int>&dp){
	//base case 
	if(i == 0){
		return 0;
	}
	if(dp[i] != -1){
		return dp[i];
	}
	int left = f2(i - 1, a, dp) + abs(a[i] - a[i - 1]);
	int right = INT_MAX;
	if (i > 1){
		right = f2(i - 2, a, dp) + abs(a[i] - a[i - 2]);
	}
	return dp[i] = min(left, right);
}

//DP Tabulation Bottom up 
int f3(const int n, const vector<int>&a, vector<int>&dp){
	dp[0] = 0; 
	for(int i = 1; i <= n; i++){
		int fst = dp[i - 1] + abs(a[i] - a[i-1]);
		int second = INT_MAX;
		if (i > 1){
			second = dp[i - 2] + abs(a[i] - a[i - 2]);
		}
		dp[i] = min(fst, second);
	}
	return dp[n];
}

//DP Optimized Space Tabulation 
int f4(const int n, const vector<int>&a){
	int prev1 = 0; int prev2 = 0; 
	for(int i = 1; i <= n; i++){
		int fst = prev1 + abs(a[i] - a[i-1]);
		int second = INT_MAX;
		if (i > 1){
			second = prev2 + abs(a[i] - a[i - 2]);
		}
		int res = min(fst, second);
		prev2 = prev1; 
		prev1 = res;
	}
	return prev1; 
}
int main(){
 	int n; cin >> n;
 	vector<int>dp(n+1, -1);
 	vector<int>a(n, 0);
 	for(int i = 0; i < a.size(); i++){
 		cin >> a[i];
 	}
 	cout << f4(n, a);
 	// cout << f(n, dp);	
  	return 0; 
}