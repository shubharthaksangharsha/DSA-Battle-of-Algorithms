//Author - Shubharthak Sangharasha
/*
    Description: 
	You are the owner of a Shipment company. You use conveyor
	belts to ship packages from one port to another. The packages
	must be shipped within 'd’ days.

	The weights of the packages are given in an array ‘weights’.
	The packages are loaded on the conveyor belts every day in
	the same order as they appear in the array. The loaded
	weights must not exceed the maximum weight capacity of the
	ship.

	Find out the least-weight capacity so that you can ship all the
	packages within 'd' days.2023-07-25
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

int get_days(const vector<int>&pf, int const capacity){
	int days = 1, low = 0; high = pf.size() - 1; 
	while (low <= high){
		int mid = low + ( high - low) / 2; 
		if (pf[mid] <= capacity){
			high = mid - 1;
		} else {
			days++;
			low = mid + 1;
		}
	}
	return days; 
}
    // int days = 1, load = 0; 
    // for(int i = 0; i < weights.size(); i++){
    //     if (load + weights[i] > capacity){
    //         days++; load = weights[i];
    //     } else{
    //         load += weights[i];
    //     }
    
    // return days;

}
int leastWeightCapacity(vector<int> &weights, int d)
{
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    cout << low << " " << high << endl;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(get_days(weights, mid) <= d){
            high = mid - 1;
        } else{
            low = mid + 1;
        }
    }
    return low;
}
int main(){
 	int n; cin >> n; 
 	vector<int>arr(n), pf(n); 
 	for(int i = 0; i < arr.size(); i++){
 		cin >> arr[i]; 
 		pf[i] = pf[i - 1] + arr[i]; 
 	}
 	// input(arr); 
 	int d; cin >> d; 
 	// cout << leastWeightCapacity(arr, d);
 	// print(arr);
 	print(pf);
    return 0; 
}