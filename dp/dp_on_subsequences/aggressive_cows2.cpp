//Author - Shubharthak Sangharasha
/*
    Description: 
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

bool is_placed(const vector<int>&arr, int const cows, int totaldistance){
	int cow = 1; 
	int value = arr[0]; 
	for(int i = 0; i < arr.size(); i++){
		if(arr[i] - value >= totaldistance){
			cow++;
			value = arr[i];
		}
		if(cow >= cows){
			return true;
		}
	}
	return false;
}
int solve(const vector<int>&arr, const int cows){
	//linear search 
	for(int dist = 1; dist < (arr[arr.size() - 1] - arr[0]); dist++){
		if (is_placed(arr, cows, dist)){
			continue;
		} else{
			return dist - 1;
		}
	}
	 
	return -1;
	//binary search 
	int low = 1, high = arr[arr.size() - 1] - arr[0]; 
	while(low <= high){
		int mid = low + (high - low ) / 2; 
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
 	cout << solve(arr, cows);  
 	// print(arr);
    return 0; 
}