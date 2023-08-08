//Author - Shubharthak Sangharasha
/*
    Description: Find total number of ways to form the target.
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
int f(int i, int target, const vector<int>&arr){
	//base case 
	if(target == 0){
		return 1;
	}
	if (i == 0){
		return target == arr[i];
	}
	//reccurence relation 
	//not take
	int not_take = 0 + f(i - 1, target, arr);
	//take 
	int take = 0;
	if (arr[i] <= target){
		take = f(i - 1, target - arr[i], arr);
	}
	return take + not_take;
}
int f2(int i, int target, const vector<int>&arr, vector<vector<int> >&dp){
	//base case 
	if (target == 0){
		return 1;
	}
	if (i == 0){
		return target == arr[i];
	}
	//memoize 
	if(dp[i][target] != -1){
		return dp[i][target];
	}
	//recurence relation 
	//not take 
	int not_take = f2(i - 1, target, arr, dp);
	//take 
	int take = 0;
	if(arr[i] <= target){
		take = f2(i - 1, target - arr[i], arr, dp);
	}
	return dp[i][target] = not_take + take;
}

int f3(int i, int target, const vector<int>&arr){
	vector<vector<int> >dp(arr.size(), vector<int>(target + 1, -1));
	//base case 
	for(int i = 0; i < arr.size(); i++){
		dp[i][0] = 1;
	}	
	dp[0][arr[0]] = 1;
	for(int i = 1; i < arr.size(); i++){
		for(int t = 0; t <= target; t++){
			//recurence relation 
			//not take 
			int not_take = dp[i - 1][t];
			//take 
			int take = 0;
			if(arr[i] <= t){
				take = dp[i - 1][t - arr[i]];
			}
			dp[i][t] = not_take + take;
		}
	}
	return dp[arr.size() - 1][target];
}
int solve(const vector<int>&arr, int target, const int n){
	vector<vector<int> >dp(n, vector<int>(target+1, -1));
	return f3(n - 1, target, arr);
	return f2(n -1, target, arr, dp);
	return f(n - 1, target, arr);
}
int main(){
	int t; cin >> t; 
	while(t--){
		int n; cin >> n; 
	 	vector<int>arr(n); 
	 	input(arr); 
	 	int target; cin >> target;
	 	cout << solve(arr, target, n);	
	}
 	
    return 0; 
}