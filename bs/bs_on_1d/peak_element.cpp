//Author - Shubharthak Sangharasha
/*
    Description: Check for the peak element in the array 
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
int findPeakElement(vector<int> &arr) {
    /*
    to find peak element first check the first index and last index 
    then find the between elements and also start with second and second last indexes
    */
    int n = arr.size(); 
    if(n == 1){
        return 0;
    }
    //first and last index 
    if (arr[0] > arr[1]){
        return 0;
    }
    if (arr[n-1] > arr[n-2]){
        return n - 1;
    }
    int low = 1, high = n - 2; 
    while (low <= high){
        int mid = low + (high - low) / 2; 
        //check for peak index 
        if(arr[mid] > arr[mid -1] && arr[mid] > arr[mid + 1]){
            return mid;
        }
        // check for left and right 
        if (arr[mid] > arr[mid - 1]){
            low = mid + 1;
        } else{
            high = mid - 1;
        }
    }
    return -1;
}

int main(){
 	int n; cin >> n; 
 	vector<int>arr(n); 
 	input(arr);
 	cout << findPeakElement(arr);
 	// print(arr);
    return 0; 
}