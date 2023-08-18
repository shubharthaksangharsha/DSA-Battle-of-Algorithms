//https://leetcode.com/problems/move-zeroes/description/
//Author - Shubharthak Sangharasha
/*
    Description: Move all the zeros at the right side (inplace)
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
    void moveZeroes(vector<int>& nums) {
        if(nums.size() == 1){
            return;
        }
        int j = -1; 
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                j = i; break;
            }
        }

        for(int i = j+1; i < nums.size(); i++){
            if(nums[i] != 0 && j != -1){
                swap(nums[i], nums[j++]);
            }
        }
    }
};
int main(){
 	int n; cin >> n; 
 	vector<int>arr(n); 
 	input(arr); 
 	Solution sol;
 	sol.moveZeroes(arr);
 	print(arr);
    return 0; 
}