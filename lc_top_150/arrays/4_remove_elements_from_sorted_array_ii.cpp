//Author - Shubharthak Sangharasha
/*
    Description: Remove all the duplicates value which occure more than 2 occur in a sorted array
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
int solve(vector<int>&arr){
	int k = 1, last = arr[0]; 
	for(int i = 0; i < arr.size(); i++){
		if (arr[i] > last){
			last = arr[i]; 
			swap(arr[i], arr[k++]);
		}	
	}
	return k;
}
int main(){
 	int n; cin >> n; 
 	vector<int>arr(n); 
 	input(arr); 
 	int k = solve(arr);
 	for(int i = 0; i < k; i++){
 		cout << arr[i] << " ";
 	}
    return 0; 
}