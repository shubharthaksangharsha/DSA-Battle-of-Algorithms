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
public:
    int jump(vector<int>& nums) {
        if(nums[0] == 0){
            return 0;
        }
        if (nums.size() == 1 and nums[0] != 0){
            return 0;
        }
        int maxReach = nums[0];
        int jumps = 1; 
        int steps = nums[0]; 
        for(int i = 1; i < nums.size(); i++){
            if(i == nums.size() - 1){
                return jumps;
            }
            maxReach = max(maxReach, nums[i] + i); 
            steps--;
            if(steps == 0){
                jumps++;
                if(i >= maxReach){
                    return -1;
                }
                steps = maxReach - i;
            }
        }
        return -1;
    }
};
int main(){
     int n; cin >> n; 
     vector<int>arr(n); 
     input(arr); 
     Solution sol;
     cout << sol.jump(arr) << endl;
     // print(arr);
    return 0; 
}