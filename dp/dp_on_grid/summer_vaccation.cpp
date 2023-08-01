#include<bits/stdc++.h> 
using namespace std; 
int const N = 10e6;
int a[N];
int b[N];
int c[N];
//dp recursion 
int dp[N];
int summer_vaccation(int n){
	//base case 
	if(n == 0){
		return 0; 
	} 
	int cost = INT_MAX; 
	if(dp[n] != -1){
		return dp[n];
	}
	for(int i = 1; i <= k; i++){
		if(n - i >= 0){
			cost = min(cost, frog_jump_dp(n - i) + abs(h[n] - h[n -i]));		
		}	
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
 	cin >> n >> k; 
 	for(int i = 0; i < n; i++){
 		cin >> a[i]; 
 		cin >> b[i]; 
 		cin >> c[i];
 	}
 	cout << frog_jump_dp(n-1) << endl;
  	return 0; 
}