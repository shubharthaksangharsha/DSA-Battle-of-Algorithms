//Author - Shubharthak Sangharasha
/*
    Description: 
*/

#include<bits/stdc++.h> 
using namespace std; 
int const N = 10e6;


//Recursive Binary Search 

int f2(const vector<int>&arr, int low, int high, int const target){
	//base case 
	if(low > high){
		return -1; 
	}
	int mid = (low + high) / 2; 
	if(arr[mid] == target){
		return mid;
	} else if(target > arr[mid]){
		return f2(arr, mid + 1, high, target); 
	} else{
		return f2(arr, low, mid -1, target);
	}
}
//Iterative Binary Search 
int f(const vector<int>&arr, int const target){
	int low = 0; 
	int high = arr.size() - 1; 
	while(low <= high){
		int mid = (low + high) / 2; 
		if(arr[mid] == target){
			return mid;
		} else if(target > arr[mid]){
			low = mid + 1; 
		} else {
			high = mid - 1; 
		}
	}
	return -1; 
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
 	// cout << f(arr, k);
 	cout << f2(arr, 0, arr.size() -1, k);
    return 0; 
}