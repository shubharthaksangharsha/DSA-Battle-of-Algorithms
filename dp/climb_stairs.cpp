
//Author - Shubharthak Sangharasha
/*
    Description: Count the distinct ways to stair up till n 
*/


/*
Steps to solve DP problem 
Step1: Try to represent the problem in terms of index 
Step2: Do all possible stuffs on that index according to the problem statement 
Step3: Sum up all stuffs -> if questions says: Count 
	   Minimum of all stuffs: if question says: Find minimum 

*/

#include<bits/stdc++.h>
using namespace std;
//Top Down Recursion
/*int f(int i){
	//base case 
	if(i == 0 || i == 1){
		return 1; 
	}
	return f(i - 1) + (i - 2); 

}*/
//Top Down DP Recursion 
int f(int const i, vector<int>&dp){
	//base case 
	if(i == 0 || i == 1){
		return 1; 
	}
	if(dp[i] != -1){
		return dp[i];
	}
	return dp[i] = f(i - 1, dp) + f(i - 2, dp); 
}

//Bottom up Recursion 
int f2(int const n, vector<int>&dp){
	dp[0] = 1; dp[1] = 1;

	for(int i = 2; i <= n; i++){
		dp[i] = dp[i-1] + dp[i - 2];
	}
	return dp[n];
}

//Space Optimized Sol 

int f3(int const n){
	int prev = 1; 
	int prev2 = 1; 
	for(int i = 2; i <= n; i++){
		int res = prev + prev2; 
		prev2 = prev; 
		prev = res; 
	}
	return prev;
}

int main(){
 	int n; cin >> n;
	vector<int>dp(n+1, -1);
	cout << f3(n);
	
  	return 0; 
}