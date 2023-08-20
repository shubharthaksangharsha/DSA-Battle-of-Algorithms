//Author - Shubharthak Sangharasha
/*
    Description: Find the next permutation of the given array 
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
    void nextPermutation(vector<int>& nums) {
        //Optimal Approach : O(3N), O(1)
        int n = nums.size();
        int index = -1; 
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }
        //Swap the index with max(index+1, n-1)
        if(index == -1) return reverse(nums.begin(), nums.end());
        for(int i = n - 1; i >= index; i--){
            if(nums[i] > nums[index]){
                swap(nums[i], nums[index]);
                break;
            }
        }
        //Step3: Reverse the array to get the sorted order from(index+1, n -1)
        reverse(nums.begin() + (index+1), nums.end());
    }
};
int main(){
 	int n; cin >> n; 
 	vector<int>arr(n); 
 	input(arr); 
 	Solution sol;
 	sol.nextPermutation(arr);
 	print(arr);
    return 0; 
}