//Author - Shubharthak Sangharasha
/*
    Description: Implementing lower bound and upper bound 
*/

#include<bits/stdc++.h> 
using namespace std; 
int const N = 10e6;


// Upper bound Iterative way 
int f3(const vector<int>&arr, int const target){
	int low = 0, high = arr.size() - 1; 
	int ans = arr.size(); 
	while(low <= high){
		int mid = low + (high - low) / 2; 
		if(arr[mid] > target){
			ans = mid; 
			high = mid - 1; 
		} else {
			low = mid + 1; 
		}
	}
	return ans; 
}

//Recursive way 
int f2(const vector<int>&arr, int const k, int low, int high, int ans){
	//base case 
	if(low > high){
		return ans;
	}
	int mid = low + (high - low) / 2; 
	if (arr[mid] >= k){
		return f2(arr, k, low, mid -1, mid); 
	} else {
		return f2(arr, k, mid + 1, high, ans);
	}
}
//Iterative way lower bound
int f(const vector<int>&arr, int const target){
	int low = 0, high = arr.size() - 1; 
	int ans = arr.size(); 
	while(low <= high){
		int mid = low + (high - low) / 2; 
		if(arr[mid] >= target){
			ans = mid; 
			high = mid - 1; 
		} else {
			low = mid + 1; 
		}
	}
	return ans; 
}
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
int main(){
 	int n, k; cin >> n; 
 	vector<int>arr(n); 
 	input(arr); 
 	cin >> k;
 	cout << lower_bound(arr.begin(), arr.end(), k) - arr.begin() << endl;    
 	cout << f3(arr, k);
 	return 0; 
}