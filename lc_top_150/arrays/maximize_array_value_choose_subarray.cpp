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
class Solution {
private:
    int compute(vector<int>&nums){
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            ans += abs(nums[i] - nums[i+1]);
        }
        return ans;
    }
public:
    // int maxValueAfterReverse(vector<int>& nums) {
    //     //Brute Force
    //     int ans = INT_MIN;
    //     for(int i = 0; i < nums.size(); i++){
    //         pair<int, int>indeces;
    //         int temp = 0;
    //         for(int j =i ; j < nums.size(); j++){
    //             indeces.first = i; 
    //             indeces.second = j; 
    //             reverse(nums.begin() + indeces.first, nums.begin() + indeces.second);
    //             temp+= compute(arr);
    //             ans = max(ans, temp);
    //             reverse(nums.begin() + indeces.first, nums.begin() + indeces.second);
    //         }
    //         ans = max(ans, temp);
    //     }
    //     return ans;
    // }
    int compute_val(vector<int>&nums){
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += abs(nums[i] - nums[i+1]);
        }
        return sum;
    }
};
int main(){
 	int n; cin >> n; 
 	vector<int>arr(n); 
 	input(arr); 
 	Solution sol;
 	cout << sol.compute_val(arr);
    return 0; 
}