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
void solve(vector<int>&arr, int k){
	k = k % arr.size();
	//O(N^2), O(1)
	while(k--){
		int temp = arr[arr.size() - 1]; 
		for(int i = arr.size() - 2; i >= 0; i--){
			arr[i+1] = arr[i];
		}	
		arr[0] = temp;
	}
	//O(N), O(1)
	// reverse(arr.begin(), arr.end());
	// reverse(arr.begin(), arr.begin() + k);
	// reverse(arr.begin() + k, arr.end());
}
int main(){
 	int n; cin >> n; 
 	vector<int>arr(n); 
 	input(arr); 
 	int k; cin >> k; 
 	print(arr);
 	solve(arr, k);
 	print(arr);
    return 0; 
}