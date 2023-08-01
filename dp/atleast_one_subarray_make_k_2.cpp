//Author - Shubharthak Sangharasha
/*
    Description: Check wehether if one subarray can make the sum equal to k or not 
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

//using normal recursion 
bool f(int i, int target, const vector<int>&arr){
	//base cases 
	if(target == 0){
		return true;
	}
	if (i == 0){
		return arr[i] == target;
	}
	//not take 
	bool not_take = f(i-1, target, arr); 
	//take 
	bool take = false; 
	if(target >= arr[i]){
		take =  f(i-1, target - arr[i], arr);
	}
	return take or not_take;

}

//using memoization
bool f2(int i, int target, vector<int>&arr, vector<vector<int>>&dp){
	//base case 
	if (target == 0){
		return true; 
	}
	if (i ==  0){
		return arr[i] == target; 
	}
	//memoization 
	if(dp[i][target] != -1){
		return dp[i][target];
	}
	//not take 
	bool not_take = f2(i-1, target, arr, dp); 
	//take 
	bool take = false; 
	if (target >= arr[i]){
		take = f2(i - 1, target - arr[i], arr, dp );
	}
	return dp[i][target] = take or not_take;
}
//dp using tabulation 
bool f3(int i, int target, vector<int>&arr, int n){
	vector<vector<int> >dp(n, vector<bool>(target + 1, 0));
	//base case 
	for(int j = 0; j  < i; j++){
		dp[0][target] = true;
	}

	arr[i][arr[i]] = true; 
	for(int i = 0; i < arr.size(); i++){
		for(int j = 0; j <= target; j++){
			//not take 
			bool not_take = dp[i-1][target];
			//take 
			bool take = false; 
			if (target >= arr[i]){
				take = dp[i - 1][target];
			}
			dp[i][target] = take or not_take;			
		}
	}
	return dp[arr.size() - 1][target];
}

bool solve(vector<int>&arr, int k, int const n){
	// vector<vector<int>>dp(arr.size(), vector<int>(k+1, -1));
	return f3(0, k, arr, arr.size());
	// return f2(arr.size()-1, k, arr, dp);
	// return f(arr.size()-1, k, arr); 
}
int main(){
 	int n; cin >> n; 
 	vector<int>arr(n); 
 	input(arr); 
 	int k; cin >> k;
 	// print(arr);
 	if(solve(arr, k, n)){
 		cout << "True";
 	}else {
 		cout << "False";
 	}
    return 0; 
}