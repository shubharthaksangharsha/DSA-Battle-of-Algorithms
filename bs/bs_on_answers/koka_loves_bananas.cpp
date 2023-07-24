//Author - Shubharthak Sangharasha
/*
    Description: Given N piles of bananas determine minimum k integer time it takes for koko to eat all the bananas in given H time.
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

#include<algorithm>
#include<climits>
int maxVal(const vector<int>&v){
    int ans = 0;
    for (int i = 0; i < v.size(); i++) {
      ans = max(ans, v[i]);
    }
    return ans;
}

int calculate_hours(int const k, const vector<int>&v){
    int ans = 0; 
    for(int i = 0; i < v.size(); i++){
    	ans = ans + (ceil((double)(v[i]) / (double)(k)));
    }
    return ans;
}

int minimumRateToEatBananas(vector<int> v, int h) {
    int ans = INT_MAX;
    int low = 1; 
    int high = maxVal(v);
    while(low <= high){
        int mid = low + (high - low) / 2; 
        if (calculate_hours(mid, v) <= h){
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
 	int h; cin >> h;
 	// print(arr);
 	cout << minimumRateToEatBananas(arr, h);
    return 0; 
}