//Author - Shubharthak Sangharasha
/*
    Description: Print the maximum no. of stalls you can take having minimum value.
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
bool is_placed(const vector<int>&arr, const int totalcows, int const placed_value){
	int cows = 1; 
	int current = arr[0];
	for(int i = 0; i < arr.size(); i++){
		if(arr[i] - current >= placed_value){
			cows++;
			current = arr[i];
		}
		if(cows >= totalcows){
			return true;
		}
	}
	return false;

}
int solve(const vector<int>&arr, const int cows, const int n){
	//binary search 
	int low = 1, high = (arr[n - 1] - arr[0]);
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
 	// print(arr);
    return 0; 
}