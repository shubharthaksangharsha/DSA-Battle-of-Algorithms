//Author - Shubharthak Sangharasha
/*
    Description: Find missing number in the array
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
    int missingNumber(vector<int>& nums) {
        //Brute force //TC: O(N x N)
        // int N = nums.size(); 
        // int ans = 0;
        // for(int i = 1; i <=N; i++){
        //     int flag = 0; 
        //     for(int j = 0; j < nums.size(); j++){
        //         if(nums[j] == i){
        //             flag = 1; break;
        //         }
        //     }
        //     if(!flag){
        //         ans = i;
        //         break;
        //     }
        // }
        // return ans;

        
        //using hash array 
        // int ans = 0;
        // int N = nums.size() + 1;
        // vector<int>hashh(N, 0); //[0 0 0 0] [1 1 0 1]
        // for(int i = 0; i < nums.size(); i++){
        //     hashh[nums[i]] = 1;
        // }
        // for(int i = 0; i < hashh.size(); i++){
        //     if(hashh[i] == 0){
        //         ans = i;
        //         break;
        //     }
        // }
        // return ans;

        //OPTIMAL SOLUTION - 1
        // int array_sum = accumulate(nums.begin(), nums.end(), 0);
        // int actual_sum = (nums.size() * (nums.size() + 1)) / 2;
        // return actual_sum - array_sum; 

        //OPTIMAL SOLUTION - 2
        int xor1 = 0, xor2 = 0; 
        for(int i = 1; i <= nums.size(); i++){
            xor1 ^= i;
        }
        for(int i = 0; i  < nums.size(); i++){
            xor2 ^= nums[i];
        }
        return xor1 ^ xor2;

    }
};

int main(){
 	int n; cin >> n; 
 	vector<int>arr(n); 
 	input(arr); 
 	// print(arr);
 	Solution sol; 
 	cout << sol.missingNumber(arr);
    return 0; 
}