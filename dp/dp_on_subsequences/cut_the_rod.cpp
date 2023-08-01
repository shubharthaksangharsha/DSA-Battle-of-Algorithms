//Author - Shubharthak Sangharasha
/*
    Description: Return the maximum of price can be achieve by cutting the rod.
*/

#include<bits/stdc++.h> 
using namespace std; 
int const N = 10e6;

void input(vector<int>&arr){
	for(auto &i: arr){
		cin >> i; 
	}
}

void print(const vector<int>&arr){
	for(auto const i: arr){
		cout << i << " ";
	}
	cout << endl;
}
int f(int i, int N, vector<int>&arr){
	//base case 
	if(i == 0){
		return N * arr[0];
	}
	int not_take = 0 + f(i - 1, N, arr); 
	int take = INT_MIN; 
	int rod_length = i + 1; 
	if(rod_length <= N){
		take = arr[i] + f(i, N - rod_length, arr);
	}
	return max(not_take, take);
}
int f2(int i, int N, vector<int>&arr, vector<vector<int> > &dp){
	//base case 
	if(i == 0){
		return N * arr[0];
	}
	//memoize 
	if(dp[i][N] != -1){
		return dp[i][N];
	}
	int not_take = 0 + f2(i - 1, N, arr, dp); 
	int take = INT_MIN; 
	int rod_length = i + 1; 
	if(rod_length <= N){
		take = arr[i] + f2(i, N - rod_length, arr, dp);
	}
	return max(not_take, take);
}
int f3(int i, int N, vector<int>&arr){
	vector<vector<int> > dp(N, vector<int>(N, -1));
	//base case 
	for(int n = 0; n <= N; n++){
		dp[0][n] = n * arr[0];
	}
	for(int ind = 1; ind < N; ind++){
		for(int n = 0; n <= N; n++){
			int not_take = dp[ind - 1][n];
			int take = INT_MIN; 
			int rod_length = ind + 1; 
			if(rod_length <= n){
				take = arr[ind] + dp[ind][n - rod_length];
			}
			dp[ind][n] = max(not_take, take);			
		}
	}
	return dp[N - 1][N];
}
int f4(int i, int N, vector<int>&arr){
	vector<int>prev(N+1, -1), curr(N + 1, -1);
	//base case 
	for(int n = 0; n <= N; n++){
		prev[n] = n * arr[0];
	}
	for(int ind = 1; ind < N; ind++){
		for(int n = 0; n <= N; n++){
			int not_take = prev[n];
			int take = INT_MIN; 
			int rod_length = ind + 1; 
			if(rod_length <= n){
				take = arr[ind] + curr[n - rod_length];
			}
			curr[n] = max(not_take, take);			
		}
		prev = curr;
	}
	return prev[N];
}
int solve(vector<int>&arr, int n){
	vector<vector<int> > dp(n, vector<int>(n + 1, -1));
	return f4(n - 1, n , arr);
	return f3(n - 1, n, arr);
	return f2(n - 1, n, arr, dp);
	return f(n - 1, n, arr);
}
int main(){
 	int n; cin >> n; 
 	vector<int>arr(n); 
 	input(arr); 
 	cout << solve(arr, n);
    return 0; 
}