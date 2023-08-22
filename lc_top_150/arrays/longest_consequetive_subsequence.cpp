//Author - Shubharthak Sangharasha
/*
    Description: Given array you have to find longest concequetive sequence length.
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
    bool ls(vector<int>&nums, int el){
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == el) return true;
        }
        return false;
    }
public:
    int longestConsecutive(vector<int>& nums) {
        //Brute Force (N^2), O(1) TLE
        //edge case 
        // if(nums.size() == 0) return 0;
        // int ans = 1; 
        // for(int i = 0; i < nums.size(); i++){
        //     int counter = 1; 
        //     int x = nums[i];
        //     while(ls(nums, x+1)){
        //         x++;
        //         counter++;
        //     }
        //     ans = max(ans, counter);
        // }
        // return ans;

        //Better Solution Nlogn, O(1), Accepted
        // if(nums.size() == 0) return 0;
        // sort(nums.begin(), nums.end());
        // int ans = 1; 
        // int last_smaller = INT_MIN; 
        // int counter = 0; 
        // for(int i = 0; i < nums.size(); i++){
        //     if(nums[i] -1 == last_smaller){
        //         last_smaller = nums[i]; 
        //         counter++;
        //     } else if(nums[i] != last_smaller){
        //         last_smaller = nums[i]; 
        //         counter = 1; 
        //     }
        //     ans = max(ans , counter);
        // }
        // return ans;

        //Optimal Solution: O(N), O(N)
        if(nums.size()== 0) return 0;
        unordered_set<int>st; 
        int ans = 1;
        for(int i = 0; i < nums.size(); i++){
            st.insert(nums[i]);
        }
        for(auto i: st){
            if(st.find(i-1) == st.end()){
                int counter = 1; 
                int x = i; 
                while(st.find(x+1) != st.end()){
                    counter++;
                    x++;
                }
                ans = max(counter, ans);
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
 	cout << sol.longestConsecutive(arr);
 	// print(arr);
    return 0; 
}