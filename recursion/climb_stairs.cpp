#include<bits/stdc++.h> 
using namespace std; 
int const N = 10e6;
int dp[N];

int count_stairs(int n){
	if (n  < 0){
		return 0;
	}
	if (n == 0){
		return 1;
	}
	if (dp[n] != -1){
		return dp[n];
	}
	dp[n] = count_stairs(n-1) + count_stairs(n - 2);
	return dp[n];
}
=

int main(){
	memset(dp, -1, sizeof(dp));
 	int t; 
 	cin >> t; 
 	while(t--){
 		int n; 
 		cin >> n; 
 		cout << count_stairs(n) << endl;
 	}
  	return 0; 
}