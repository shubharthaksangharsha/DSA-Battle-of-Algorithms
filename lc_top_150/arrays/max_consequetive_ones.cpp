//https://leetcode.com/problems/max-consecutive-ones/
//Author - Shubharthak Sangharasha
/*
    Description: Find the maximum number of ones occurred continously together 
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
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, temp = 0; 
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                temp++;
            } else{
                temp = 0;
            }
            ans = max(ans, temp);
        }
        return ans;
    }
};

int main(){
 	int n; cin >> n; 
 	vector<int>arr(n); 
 	input(arr); 
 	Solution sol;
 	cout << sol.findMaxConsecutiveOnes(arr);
 	// print(arr);
    return 0; 
}