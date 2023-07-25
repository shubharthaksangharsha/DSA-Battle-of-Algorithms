//Author - Shubharthak Sangharasha
/*
    Description: 
    You are given an array of integers ‘arr'and an integer ‘limit’.

	Your task is to find the smallest positive integer divisor, such
	that upon dividing all the elements of the given array by it, the
	sum of the division's result is less than or equal to the given
	integer's limit.

	Note:

	Each result of the division is rounded to the
	nearest integer greater than or equal to that
	element. For Example, 7/3 = 3.
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

#include<bits/stdc++.h>
int maxVal(const vector<int>&arr){
	int maxi = INT_MIN; 
	for(auto const i: arr){
		maxi = max(maxi, i);
	}
	return maxi;
}
bool find_divisor(const vector<int>&arr, int divisor, int limit){
	int sum = 0; 
	for(int i = 0; i < arr.size(); i++){
		sum += ceil((double)(arr[i]) / (double)(divisor));
	}
	return sum <= limit; 
}
int smallestDivisor(vector<int>& arr, int limit)
{
	int low = 1, high = maxVal(arr); 
	while(low <= high){ 
		int mid = low + (high - low) / 2;
		if (find_divisor(arr, mid, limit)){
			high = mid - 1; 
		} else{
			low = mid + 1;
		}
	}
	return low;
}

int main(){
 	int n; cin >> n; 
 	vector<int>arr(n); 
 	input(arr); 
 	int limit; cin >> limit;
 	// print(arr);
 	cout << smallestDivisor(arr, limit);
    return 0; 
}