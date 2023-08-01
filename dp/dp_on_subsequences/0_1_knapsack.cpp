//Author - Shubharthak Sangharasha
/*
    Description: 0/1 Knapsack problem using DP 
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
int f(int ind, int W, vector<int>&weight, vector<int>&value){
	//base case 
	if(ind == 0){
		if (weight[ind] <= W){
			return value[ind];
		} 
		return 0;
	}
	int not_take = 0 + f(ind - 1, W, weight, value); 
	int take = INT_MIN; 
	if (weight[ind] <= W){
		take = value[ind] + f(ind - 1, W - weight[ind], weight, value);
	}
	return max(take, not_take);
}

int f2(int ind, int W, vector<int>&weight, vector<int>&value, vector<vector<int> >&dp){
	//base cases 
	if(ind == 0){
		if (weight[ind] <= W){
			return value[ind];
		}
		return 0;
	}
	//memoization
	if (dp[ind][W] != -1){
		return dp[ind][W]; 
	}

	int not_take = 0 + f2(ind - 1, W, weight, value, dp);
	int take = INT_MIN; 
	if(weight[ind] <= W){
		take = value[ind] + f2(ind - 1, W - weight[ind], weight, value, dp);
	}
	return dp[ind][W] = max(take, not_take);
}

int f3(int ind, int W, vector<int>&weight, vector<int>&value, int n){
	vector<vector<int> >dp(n, vector<int>(W+1, -1));
	
	for(int i = 0; i <= W; i++){
		if (weight[0] <= i){
			dp[0][i] = value[0];
		} else{
			dp[0][i] = 0;
		}
	}

	for(int i = 1; i < n; i++){
		for(int w = 0; w <= W; w++){
			int not_take = 0 + dp[i - 1][w];
			int take = INT_MIN; 
			if(weight[i] <= w){
				take = value[i] + dp[i - 1][w - weight[i]];
			}
			dp[i][w] = max(take, not_take);
		}
	}
	return dp[n -1][W];
}
int f4(int ind, int W, vector<int>&weight, vector<int>&value, int n){
	vector<int>prev(W+1, 0);
	for(int i = 0; i <= W; i++){
		if (weight[0] <= i){
			prev[i] = value[0];
		} else{
			prev[i] = 0;
		}
	}

	for(int i = 1; i < n; i++){
		for(int w = W; w >= 0; w--){
			int not_take = 0 + prev[w];
			int take = INT_MIN; 
			if(weight[i] <= w){
				take = value[i] + prev[w - weight[i]];
			}
			prev[w] = max(take, not_take);
		}
	}
	return prev[W];
}
int knapsack(vector<int>&weight, vector<int>&value, int n, int W){
	vector<vector<int> >dp(n, vector<int>(W + 1, -1));
	return f4(0, W, weight, value, n);
	// return f3(0, W, weight, value, n);
	// return f2(n - 1, W, weight, value, dp);
	// return f(n - 1, W, weight, value);
}
int main(){
 	int n; cin >> n; 
 	int W; cin >> W; 
 	cout << n << " " << W << endl;
 	vector<int>weight(n), value(n);
 	input(weight);
 	input(value);
 	print(weight); 
 	print(value);
 	cout << knapsack(weight, value, n, W);
    return 0; 
}