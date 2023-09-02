//https://leetcode.com/problems/majority-element-ii/description/
//Author - Shubharthak Sangharasha
/*
    Description: Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
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
    vector<int> majorityElement(vector<int>& nums) {
        //Brute Force N^2 O(1) NOT ACCEPTED TLE
        // set<int>ans;
        // for(int i = 0; i < nums.size(); i++){
        //     int counter = 0;
        //     for(int j = 0; j < nums.size(); j++){
        //         if(nums[i] == nums[j]) counter++;
        //     }
        //     if(counter >= (nums.size() / 3) + 1){
        //         ans.insert(nums[i]);
        //     }
        // }
        // return {ans.begin(), ans.end()};

        //Better Solution O(N), O(N) ACCEPTED 
        // unordered_map<int, int>mp;
        // set<int>ans;
        // for(int i = 0; i < nums.size(); i++){
        //     mp[nums[i]]++;
        //     if(mp[nums[i]] >= (nums.size() / 3) + 1) ans.insert(nums[i]);
        // }
        // return {ans.begin(), ans.end()};

        //Optimal Solution 
        int el1 = -1, el2 = -1, c1 = 0, c2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(c1 == 0 && nums[i] != el2){
                c1 = 1;
                el1 = nums[i];
            } else if (c2 == 0 && nums[i] != el1){
                c2 = 1;
                el2 = nums[i];
            }else if(nums[i] == el1){
                c1++;
            } else if (nums[i] == el2){
                c2++;
            } else{
                c1--;
                c2--;
            }
        }
        set<int>ans;
        c1 = 0, c2 = 0;
        int check_ans = (int)(nums.size() / 3) + 1; 
        for(auto i: nums){
            if (i == el1) c1++;
            if (i == el2) c2++;
        }
        if(c1 >= check_ans){
            ans.insert(el1);
        } 
        if(c2 >= check_ans){
            ans.insert(el2);
        }
        return {ans.begin(), ans.end()};
    }
};
int main(){
 	int n; cin >> n; 
 	vector<int>arr(n); 
 	input(arr); 
 	Solution sol;
 	vector<int>res = sol.majorityElement(arr);
 	print(res);
    return 0; 
}