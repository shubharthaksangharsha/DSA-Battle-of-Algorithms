//Author - Shubharthak Sangharasha
/*
    Description: Find the floor and ceil of the given element in an array
*/

#include<bits/stdc++.h> 
using namespace std; 
int const N = 10e6;

#include<bits/stdc++.h>

//find ceil 
int find_ceil(int arr[], int n, int x){
	int ans = -1;
	int low = 0; 
	int high = n - 1; 
	while(low <= high){
		int mid = low + (high - low) / 2; 
		if(arr[mid] >= x){
			ans = mid; 
			high = mid - 1; 
		} else { 
			low = mid + 1; 
		}
	}
	return ans == -1 ? -1 : arr[ans]; 
}

//find floor
int find_floor(int arr[], int n, int x){
	int ans = -1;
	int low = 0; 
	int high = n - 1; 
	while(low <= high){
		int mid = low + (high - low) / 2; 
		if(arr[mid] <= x){
			ans = mid; 
			low = mid + 1; 
		} else { 
			high = mid - 1;
		}
	}
	return ans == -1 ? -1 : arr[ans]; 
}


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
	sort(arr, arr + n); 
	//ceiling 
	int ceil = find_ceil(arr, n, x); 
	int floor = find_floor(arr, n, x); 
	return make_pair(floor, ceil); 

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
 	int n; cin >> n; 
 	int arr[10000]; 
 	for(int i = 0; i < n; i++){
 		cin >> arr[i]; 
 	}
 	int x; cin >> x; 
 	pair<int, int> result= getFloorAndCeil(arr, n, x); 
 	cout << result.first << " " << result.second; 
    return 0; 
}