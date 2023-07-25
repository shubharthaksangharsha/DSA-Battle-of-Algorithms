//Author - Shubharthak Sangharasha
/*
    Description
    You are given 'n'roses and you are also given an array ‘arr’
	where ‘arr[iJ' denotes that the 7”’rose will bloom on the
	‘arr[i]th day.

	You can only pick already bloomed roses that are adjacent to
	make a bouquet. You are also told that you require exactly ‘'k’
	adjacent bloomed roses to make a single bouquet.

	Find the minimum number of days required to make at least
	‘m' bouquets each containing 'k' roses. Return -1if it is not
	possible.
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
bool possible(const vector<int>&arr, int const day, int const k, int const m){
	int counter = 0;
	int answer = 0;
	for(int i = 0; i < arr.size(); i++){
		if(arr[i] <= day){
			counter++;
		} else{
			answer += (counter / k); 
			counter = 0;
		}
	}
	answer += (counter / k); 
	return answer >= m;
}

int roseGarden(vector<int> arr, int k, int m)
{
	int n = arr.size();
	//base case 
	if(n < (k * 1LL* m)){
		return -1;
	}

	//get low and high 
	int mini = INT_MAX, maxi = INT_MIN;
	for(int i = 0; i < arr.size(); i++){
		mini = min(mini, arr[i]);
		maxi = max(maxi, arr[i]);
	}
	int low = mini, high = maxi; 
	while(low <= high){
		int mid = low + (high - low) / 2;
		if(possible(arr, mid, k, m)){
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
 	int k; cin >> k; 
 	int m; cin >> m;
 	cout << roseGarden(arr, k, m);
 	// print(arr);
    return 0; 
}