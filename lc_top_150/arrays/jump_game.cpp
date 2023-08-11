//Author - Shubharthak Sangharasha
/*
    Description: Find whether it is possible to jump from index 1 to last index or not 
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
    bool canJump(vector<int>& nums) {
        int n = nums.size(); 
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(i > ans){
                return false; 
            }
            ans = max(ans, nums[i] + i); 
        }   
        return true;
    }
};
int main(){
     int n; cin >> n; 
     vector<int>arr(n); 
     input(arr); 
     Solution sol; 
     cout << sol.canJump(arr) << endl;;
     
     // print(arr);
    return 0; 
}