#include<bits/stdc++.h> 
using namespace std; 
int const N = 1e6;
int const M = 1e9 + 7;

int dp[N + 1];
int result(int n){
	if (n == 0){
		return 1; 
	}
	if(dp[n] != -1 ){
		return dp[n];
	}
	int ways = 0;
	for(int i = 1; i <= 6; i++){
		if (n - i >= 0){
			ways = (ways + result(n -i)) % M; 	
		}
	}
	dp[n] = ways; 
	return ways;
}
int main(){
	memset(dp, -1, sizeof(dp));
 	int n; cin >> n; 
 	cout << result(n) << endl; 
  	return 0; 
}