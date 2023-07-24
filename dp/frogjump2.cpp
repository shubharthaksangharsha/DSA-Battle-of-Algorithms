
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

int f(const int i, const vector<int>&a, int const k){
	//base case 
	if(i == 0){
		return 0;
	}
	int min_steps = INT_MAX;
	for(int j = 1; j <= k; j++){
		int steps = 0;
		if (i - k >= 0){
			 steps = f(i - k, a, k) + abs(a[i] - a[i - j]);
		}
			min_steps = min(min_steps, steps);
	}
	return min_steps;
}

//Memoization DP Top Down Approach
int f2(const int i, const vector<int>&a, int const k, vector<int>&dp){
	//base case 
	if(i == 0){
		return 0;
	}
	if (dp[i] != -1 ){
		return dp[i];
	}
	int min_steps = INT_MAX;
	for(int j = 1; j <= k; j++){
		int steps = 0;
		if (i - j >= 0){
			 steps = f2(i - j, a, k, dp) + abs(a[i] - a[i - j]);
		}
			dp[i] = min_steps = min(min_steps, steps);
	}
	return dp[i] = min_steps;
}

//Tabulation DP Bottom Up Approach
int f3(const int i, const vector<int>&a, int const k, vector<int>&dp){
	dp[0] = 0;
	for(int index = 1; index <= i; index++){
		int min_steps = INT_MAX;
		for(int j = 1; j <= k; j++){
			int steps = 0;
			if (index - j >= 0){
				steps = dp[index - j] + abs(a[index] - a[index - j]);
			}
				min_steps = min(min_steps, steps);
			}	
		dp[index] = min_steps;	
	}
	return dp[i];
}



int main(){
 	int n, k; cin >> n; cin >> k;
 	vector<int>dp(n+1, -1);
 	vector<int>a(n, 0);
 	for(int i = 0; i < a.size(); i++){
 		cin >> a[i];
 	}
 	cout << f3(n, a, k, dp);
  	return 0; 
}