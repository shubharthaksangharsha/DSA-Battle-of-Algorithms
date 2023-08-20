//Author - Shubharthak Sangharasha
/*
    Description: Find maximum subarray with largest sum and return its sum  
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
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0]; 
        int temp = 0;
        for(int i = 0; i < nums.size(); i++){
            temp += nums[i];
            ans = max(ans, temp);
            if(temp < 0){
                temp = 0;
            }
        }
        return ans;
    }
};
int main(){
 	int n; cin >> n; 
 	vector<int>arr(n); 
 	input(arr);
 	Solution sol;
 	cout << sol.maxSubArray(arr); 
 	
    return 0; 
}