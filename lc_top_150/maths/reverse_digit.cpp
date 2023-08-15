//https://leetcode.com/problems/reverse-integer/description/
//Author - Shubharthak Sangharasha
/*
    Description: Find the reverse of a number if it execeds int32 then return 0 
*/


#include<bits/stdc++.h> 
using namespace std; 
int const N = 10e6;

class Solution {
public:
    int reverse(int x) {
        int ans = 0; 
        while(x){
            if(ans > INT_MAX / 10 || ans < INT_MIN / 10){
                return 0;
            }
            ans = (ans * 10) + (x % 10); 
            x /= 10; 
        }
        if(ans > INT_MAX || ans < INT_MIN) return 0;
        return int(ans);

    }
};

int main(){
     int n; cin >> n;
     Solution sol; 
     cout << sol.reverse(n);
      return 0; 
}