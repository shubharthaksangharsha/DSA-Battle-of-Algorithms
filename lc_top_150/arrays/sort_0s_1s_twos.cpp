//Author - Shubharthak Sangharasha
/*
    Description: Sort 0s 1s and 2s in given array
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
    void print(const vector<int>nums){
        for(auto i: nums){
            cout << i << " ";
        }
        cout << endl;
    }
public:
    void sortColors(vector<int>& nums) {
        //Brute force o(Nlogn),  o(1)
        // sort(nums.begin(), nums.end());

        //Better solution O(2N), O(1) 
        // int zeros = 0, ones = 0, twos = 0; 
        // for(const int i: nums){
        //     if(i == 0) zeros++;
        //     if(i == 1) ones++;
        //     if(i == 2) twos++;
        // }
        // int i = 0; 
        // while(i < nums.size()){
        //     if(zeros){
        //         nums[i++] = 0; 
        //         zeros--;
        //     } else if(ones){
        //         nums[i++] = 1; 
        //         ones--;
        //     } else if (twos){
        //         nums[i++] = 2;
        //         twos--;
        //     }
        // }

        //Optimal Solution: O(N), O(1) Dutch National Flag Algorithm
        int low = 0, mid = 0, high = nums.size() - 1; 
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low++], nums[mid++]);
            } else if (nums[mid] == 1){
                mid++;
            } else{
                swap(nums[mid], nums[high--]);
            }
        }
        
    }
};
int main(){
 	int n; cin >> n; 
 	vector<int>arr(n); 
 	input(arr); 
 	Solution sol; 
 	sol.sortColors(arr);
 	print(arr);
    return 0; 
}