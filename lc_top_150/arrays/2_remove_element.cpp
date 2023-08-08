//Author - Shubharthak Sangharasha
/*
    Description: Remove the given val value from the given array
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
int remove_element(vector<int>&arr, int val){
	int k = 0;
	for(int i = 0; i < arr.size(); i++){
		if(arr[i] != val){
			swap(arr[i], arr[k++]);
		}
	}
	return k;
}
int main(){
 	int n; cin >> n; 
 	vector<int>arr(n); 
 	input(arr); 
 	int val; cin >> val;
 	int k = remove_element(arr, val);
 	for(int i = 0; i < k; i++){
 		cout << arr[i] << " ";
 	}

    return 0; 
}