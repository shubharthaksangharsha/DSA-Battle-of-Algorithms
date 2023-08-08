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
int missing_numbers(const vector<int>&arr, int const n, int k){
	// for(int i = 0; i < n; i++){
	// 	if(arr[i] <= k){
	// 		k++;
	// 	} else{
	// 		break;
	// 	}
	// }
	// return k;

	
}
int main(){
 	int n; cin >> n; 
 	vector<int>arr(n); 
 	input(arr); 
 	int k; cin >> k; 
 	cout << missing_numbers(arr, arr.size(), k);
 	// print(arr);
    return 0; 
}