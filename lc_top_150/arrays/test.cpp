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
int solve(vector<int>&arr, int input1, int input2){
	unordered_map<int, bool>mp; 
	for(int i = 0; i < arr.size(); i++){
		mp[arr[i]] = 1; 
	}
	int ans = 0, count = 0;
	for(int i = 1; i <= input1; i++){
		if(!mp[i] && ans + i <= input1){
			ans+= i;
			count++;
		}
	}
	return count;
}
int main(){
 	int input1, input2; cin >> input1 >> input2;

 	vector<int>arr(input2); 
 	input(arr); 
 	cout << solve(arr, input1, input2) << endl;
    return 0; 
}