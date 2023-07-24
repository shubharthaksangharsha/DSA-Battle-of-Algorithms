#include<bits/stdc++.h> 
using namespace std; 
int const N = 10e6;
int h[N];

//dp recursion 
int dp[N];
int frog_jump_dp(int n){
	//base case 
	if(n == 0){
		return 0; 
	} 
	int cost = INT_MAX; 
	if(dp[n] != -1){
		return dp[n];
	}
	//way1 
	cost = min(cost, frog_jump_dp(n - 1) + abs(h[n] - h[n -1]));
	//way2 
	if(n > 1){
		cost = min(cost, frog_jump_dp(n - 2) + abs(h[n] - h[n -2]));
	}
	return dp[n] = cost; 
}
//normal recursion 
int frog_jump(int n){
	//base case 
	if (n == 0){
		return 0; 
	} 
	int cost = 0; 
	//way 1 
	cost = min(cost, frog_jump(n - 1) + abs(h[n] - h[n - 1])); 
	//way 2 
	if (n > 1){
		cost = min(cost, frog_jump(n - 2) + abs(h[n] - h[n - 2])); 
	}
	return cost; 
}
int main(){
	memset(dp , -1, sizeof(dp));
 	int n;
 	cin >> n; 
 	for(int i = 0; i < n; i++){
 		cin >> h[i]; 
 	}
 	cout << frog_jump_dp(n-1) << endl;
  	return 0; 
}