//Author - Shubharthak Sangharasha
/*
    Description: Two Sum 
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
const vector<int> solve(const vector<int>&arr, int const target){
	// if(arr.size() == 0){
	// 	return ;
	// }
	// if(arr.size() == 1){
	// 	return arr[0] ? target == arr[0] : -1;
	// }
	vector<int>res;
	int low = 0; 
	int high = arr.size() - 1; 
	while(low <= high){
		int sum = arr[low] + arr[high];
		if(sum == target){
			res.push_back(low);
			res.push_back(high);
			return res;
		} else if(sum > target){
			high--;
		} else{
			low++;
		}
	}
	res.push_back(-1);
	res.push_back(-1);
	return res;
}
int main(){
 	int n; cin >> n; 
 	vector<int>arr(n); 
 	input(arr); 
 	int target; cin >> target; 
 	cout << solve(arr, target)[0] <<" " << solve(arr, target)[1];
    return 0; 
}