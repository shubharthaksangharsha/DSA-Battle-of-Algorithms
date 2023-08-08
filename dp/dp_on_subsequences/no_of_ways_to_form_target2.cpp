//Author - Shubharthak Sangharasha
/*
    Description: 
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
	if (target == 0){
		return 1;
	}
	if (i == 0){
		return target == arr[i];
	}
	//reccurence relation 
	//not take
	int not_take = f(i - 1, target, arr);
	//take 
	int take = 0; 
	if(arr[i] <= target){
		take = f(i - 1, target - arr[i], arr);
	}
	return take + not_take;
}
int f2(int i, int target, const vector<int>&arr, vector<vector<int> >&dp){
	//base cases 
	if(target == 0){
		return 1; 
	}
	if (i == 0){
		return arr[i] == target;
	}
	//reccurence relation 
	//not take 
	int not_take = f2(i - 1, target, arr, dp);
	//take 
	int take = 0;
	if(arr[i] <= target){
		take = f2(i - 1, target - arr[i], arr, dp );
	}
	return take+ not_take;
}
int f3(int target, const vector<int>&arr){
	vector<vector<int> > dp(arr.size(), vector<int>(target + 1, -1));
	//base cases
	for(int t = 0; t <= target; t++){
		dp[0][t] = 1;
	}
	//second base case 
	dp[0][arr[0]] = 1;

	//recursive relation 
	for(int i = 1; i < arr.size(); i++){
		for(int t = 0; t <= target; t++){
				//reccurence relation 
				//not take 
				int not_take = dp[i - 1][t];
				//take 
				int take = 0;
				if(arr[i] <= t){
					take = dp[i - 1][t - arr[i]];
				}
				dp[i][t] =  take + not_take;
		}
	}
	return dp[arr.size() - 1][target];
}
int solve(const vector<int>&arr, int target){
	int n = arr.size();
	vector<vector<int> >dp(n, vector<int>(target + 1, -1));
	return f3(target, arr);
	return f2(n- 1, target, arr, dp);
	return f(n - 1, target, arr);
}
int main(){
 	int n; cin >> n; 
 	vector<int>arr(n); 
 	input(arr); 
 	int target; cin  >> target;
 	cout << solve(arr, target);
    return 0; 
}