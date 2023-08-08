//Author - Shubharthak Sangharasha
/*
    Description: Calculate the minimum index which has max value to place all the cows
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
bool is_placed(const vector<int>&arr, int totalcows, int place_value){
	int cows = 1, last_stalls = arr[0];
	for(int i = 0; i < arr.size(); i++){
		if(arr[i] - last_stalls >= place_value){
			cows++;
			last_stalls = arr[i];
		}
		if(cows >= totalcows){
			return true;
		}
	}
	return false;
}
int solve(const vector<int>&arr, const int cows, const int n){
	//Binary search 
	int low = 1;
	
	int high = arr[n - 1] - arr[0]; 

	while(low <= high){
		int mid = low + (high - low) / 2; 
		if(is_placed(arr, cows, mid)){
			low = mid + 1;
		} else{
			high = mid - 1;
		}
	}
	return high;
}
int main(){
 	int n; cin >> n; 
 	vector<int>arr(n); 
 	input(arr); 
 	int cows; cin >> cows; 
 	sort(arr.begin(), arr.end());
 	cout << solve(arr, cows, n);
    return 0; 
}