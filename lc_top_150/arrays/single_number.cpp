//Author - Shubharthak Sangharasha
/*
    Description: Find the unique element in the given duplicates value 
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
    int singleNumber(vector<int>& nums) {
        //Brute force 
        // for(int i = 0; i < nums.size(); i++){
        //     int counter = 0; 
        //     for(int j = 0; j < nums.size(); j++){
        //         if(nums[j] == nums[i]) counter++;
        //     }
        //     if(counter == 1){
        //         return nums[i];
        //     }
        // }
        // return -1;

        //Better solution - frequency array 
        // unordered_map<int, int>freq;
        // for(auto i : nums) freq[i]++;
        // int ans = 0;
        // for(auto i : freq){
        //     if(i.second == 1){
        //         ans =  i.first;
        //         break;
        //     }
        // }
        // return ans;

        //Optimal solution - using xor method 
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) ans ^= nums[i]; 
        return ans; 
    }
};
int main(){
 	int n; cin >> n; 
 	vector<int>arr(n); 
 	input(arr); 
 	Solution sol;
 	cout << sol.singleNumber(arr);
 	// print(arr);
    return 0; 
}