//Author - Shubharthak Sangharasha
/*
    Description: Find element index if present in sorted rotated array (contains duplicates).
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

bool f(vector<int>&arr, int const target){
	int low = 0, high = arr.size() - 1; 
	while(low <= high){
		int mid = low + (high - low) / 2; 
		if(arr[mid] == target){
			return true; 
		}
		if (arr[low] == arr[mid] && arr[mid] == arr[high]){
			low++; high--; 
			continue;
		}
		//check left sorted 
		if(arr[low] <= arr[mid]){
			if(arr[low] <= target && target <= arr[mid]){
				high = mid - 1; 
			} else{
				low = mid + 1;
			}
		} else{
			//right sorted
			if(arr[mid] <= target && target <= arr[high]){ 
				low = mid + 1;
			} else{
				high = mid -1;
			}
		} 
	}
	return false; 
}
int main(){
 	int n; cin >> n; 
 	vector<int>arr(n); 
 	input(arr); 
 	int k; cin >> k;
 	cout << f(arr, k) << endl;
    return 0; 
}