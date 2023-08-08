//Author - Shubharthak Sangharasha
/*
    Description: Find the majority element that consists more than n/ 2 times (n = size of the array)
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

int solve(const vector<int>&arr){
	int candidate = 0, counter = 0;
	for(auto i: arr){
		if(counter == 0){
			candidate = i;
		}
		if (i == candidate){
			counter++;
		} else{
			counter--;
		}
	}
	return candidate;
}
int main(){
 	int n; cin >> n; 
 	vector<int>arr(n); 
 	input(arr); 
 	cout << solve(arr); 
    return 0; 
}