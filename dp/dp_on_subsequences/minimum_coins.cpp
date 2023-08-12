//Author - Shubharthak Sangharasha
/*
    Description: Find minimum number of coins to make the target
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
//recursive without dp 
int f(int i, int target, vector<int>&arr, int n){
	//base case 
	if (i == 0){
		if(target % arr[i] == 0){
			return target / arr[i];
		}
		return 1e9;
	}
	int not_take = 0 + f(i - 1, target, arr, n); 
	int take = INT_MAX; 
	if(arr[i] <= target){
		take = 1 + f(i, target - arr[i], arr, n);
	}
	return min(take, not_take);
}
int f2(int i, int target, vector<int>&arr, int n, vector<vector<int> >&dp){
	//base case
	if (i == 0){
		if(target % arr[i] == 0){
			return target / arr[i];
		}
		return 1e9;
	}
	//memoize 
	if (dp[i][target] != -1){
		return dp[i][target];
	}
	int not_take = 0  + f2(i - 1, target, arr, n, dp);
	int take  = INT_MAX; 
	if (arr[i] <= target){
		take = 1 + f2(i, target - arr[i], arr, n, dp);
	}
	return dp[i][target] = min(take, not_take);
}
int f3(int i, int target, vector<int>&arr, int n){
	vector<vector<int> >dp(n, vector<int>(target + 1, -1)); 
	//base case 
	for(int t = 0; t <= target; t++){
		if(t % arr[0] == 0){
			dp[0][t] = t / arr[0];
		} else{
			dp[0][t] = 1e9;
		}
	}
	for(int ind = 1; ind < n; ind++){
		for(int t = 0; t <= target; t++){
			int not_take = 0  + dp[ind - 1][t];
			int take  = INT_MAX; 
			if (arr[ind] <= t){
				take = 1 + dp[ind][t - arr[ind]];
			}
			dp[ind][t] = min(take, not_take);			
		}
	}
	int ans =  dp[n - 1][target];
	if (ans >= 1e9){
		return -1;
	}
	return ans;
}
int f4(int i, int target, vector<int>&arr, int n){
	vector<int>prev(target + 1, -1), curr(target + 1, -1);
	for(int t = 0; t <= target; t++){
		if (t % arr[0] == 0){
			prev[t] = t / arr[0];
		} else{
			prev[t] = 1e9;
		}
	}
	for(int ind = 1; ind < n; ind++){
		for(int t = 0; t <= target; t++){
			int not_take = 0  + prev[t];
			int take  = INT_MAX; 
			if (arr[ind] <= t){
				take = 1 + curr[t - arr[ind]];
			}
			curr[t] = min(take, not_take);			
		}
		prev = curr;
	}
	int ans =  prev[target];
	if (ans >= 1e9){
		return -1;
	}
	return ans;
}
int solve(vector<int>&arr, int target, int n){
	vector<vector<int> > dp(n, vector<int>(target + 1, -1));
	return f4(n - 1, target, arr, n);
	return f3(n - 1, target, arr, n);
	return f2(n -1, target, arr, n, dp);
	return f(n- 1,target, arr, n);
}
int main(){
 	int n; cin >> n; 
 	vector<int>arr(n); 
 	input(arr); 
 	int target; cin >> target;
 	cout << solve(arr, target, n);
    return 0; 
}
