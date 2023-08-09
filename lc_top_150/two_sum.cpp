//https://leetcode.com/problems/two-sum/
//Author - Shubharthak Sangharasha
/*
    Description: Two Sum Problem, Return indeces if (index value1 + index value2) = target. 
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

//brute force, O(N^2), O(1)
const vector<int> f(const vector<int>arr, int target){
        vector<int>res; 
        for(int i = 0; i < arr.size(); i++){
            for(int j = i + 1; j < arr.size(); j++){
                int sum = arr[i] + arr[j]; 
                if(sum == target){
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
        res.push_back(-1);
        res.push_back(-1);
        return res;
}
//Using Unordered Map, O(N), O(N)
const vector<int> f2(vector<int>arr, int const target){
        vector<int>res;
        unordered_map<int, int> mp; 
        for(int i = 0; i < arr.size(); i++){
            int req = target - arr[i];
            if(mp.find(req) != mp.end()){
                return {i, mp[req]};
            }
            mp[arr[i]] = i;
        }
        return {-1, -1};
        
}

vector<int> solve(vector<int>& arr, int target) {
        return f2(arr, target);
}


int main(){
     int n; cin >> n; 
     vector<int>arr(n); 
     input(arr); 
     int target; cin >> target;
     cout << solve(arr, target)[0] << " " << solve(arr, target)[1];
    return 0; 
}
