//Author - Shubharthak Sangharasha
/*
    Description: Find the h-index of the given array 
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
    int get_count(vector<int>&c, int mid){
        int count = 0;
        for(int i = 0; i < c.size(); i++ ){
            if(c[i] >= mid){
                count++;
            }
        }
        return count;
    }
public:
    int hIndex(vector<int>& c) {
        sort(c.begin(), c.end());
        int low = 0, high = c.size(); 
        while(low < high){
            int mid = (low + high + 1) / 2;
            if(get_count(c, mid) >= mid){
                low = mid;
            } else{
                high = mid - 1;
            }
        }
        return low; 
    }
};

int main(){
 	int n; cin >> n; 
 	vector<int>arr(n); 
 	input(arr); 
 	// print(arr);
 	Solution sol; 
 	cout << sol.hIndex(arr) << endl;
    return 0; 
}