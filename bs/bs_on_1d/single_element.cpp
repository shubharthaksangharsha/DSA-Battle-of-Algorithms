//Author - Shubharthak Sangharasha
/*
    Description: Check for the single element in the sorted array
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
int singleNonDuplicate(vector<int>& arr)
{
	int n = arr.size();
	int low = 1; 
	int high = n - 2; 
	//base cases 
	if (n == 1){
		return arr[0];
	}
	//check first and last index 
	if (arr[0] != arr[1]){
		return arr[0];
	}
	if (arr[n - 1] != arr[n - 2]){
		return arr[n - 1];
	}
	while(low <= high){
		int mid = low + (high - low) / 2; 
		//check for single element 
		if(arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]){
			return arr[mid];
		}
		//check for (even, odd)
		if ((mid % 2 == 1 and arr[mid] == arr[mid - 1]) or (mid % 2 == 0 and arr[mid] == arr[mid+1])){
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	return -1;
}
int main(){
 	int n; cin >> n; 
 	vector<int>arr(n); 
 	input(arr); 
 	// print(arr);
 	cout << singleNonDuplicate(arr);
    return 0; 
}