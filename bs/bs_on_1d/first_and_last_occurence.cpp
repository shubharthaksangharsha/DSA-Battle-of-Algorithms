//Author - Shubharthak Sangharasha
/*
    Description: Find first and last index of the given element in the array
*/

#include<bits/stdc++.h> 
using namespace std; 
int const N = 10e6;

int lower_bound(vector<int>&arr, int x){
	int ans = arr.size();
	int low = 0, high = arr.size() - 1; 
	while(low <= high){
		int mid = low + (high - low) / 2; 
		if (arr[mid] >= x){
			ans = mid; 
			high = mid - 1; 
		}	else{
			low = mid + 1; 
		}
	}
	return ans; 
}

int upper_bound(vector<int>&arr, int x){
	int ans = arr.size();
	int low = 0, high = arr.size() - 1; 
	while(low <= high){
		int mid = low + (high - low) / 2; 
		if (arr[mid] > x){
			ans = mid; 
			high = mid - 1; 
		}	else{
			low = mid + 1; 
		}
	}
	return ans; 
}

int firstOccurence(vector<int>&arr, int k){
	int first = -1; 
	int low = 0, high = arr.size() - 1; 
	while(low <= high ){
		int mid = low + (high - low) / 2; 
		if(arr[mid] == k){
			first = mid; 
			high = mid - 1; 
		} else if (arr[mid] < k){
			low = mid + 1; 
		} else { 
			high = mid - 1; 
		}
	}
	return first;
}
int lastOccurence(vector<int>&arr, int k){
	int last = -1; 
	int low = 0, high = arr.size() - 1; 
	while(low <= high ){
		int mid = low + (high - low) / 2; 
		if(arr[mid] == k){
			last = mid; 
			low = mid + 1;  
		} else if (arr[mid] < k){
			low = mid + 1; 
		} else { 
			high = mid - 1; 
		}
	}
	return last;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
	/*lower bound and upper bound concept*/
 	// int lb = lower_bound(arr, k); 
 	// if (lb == arr.size() || arr[lb] != k){
 	// 	return {-1, -1}; 
 	// } 
 	// return {lb, upper_bound(arr, k) - 1}; 

 	//Plain Binary Search for first occurence and last occurence
	int first = firstOccurence(arr, k); 
	if(first == -1 ){
		return {-1, -1};
	} 
	int last = lastOccurence(arr, k); 
	return {first, last};
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
 	vector<int>arr(n); 
 	input(arr); 
 	int k; cin >> k;
 	pair<int, int>res = firstAndLastPosition(arr, arr.size(), k);
 	cout << res.first << " " << res.second << endl;
    return 0; 
}