//Author - Shubharthak Sangharasha
/*
    Description: Merge 2 given sorted arrays 
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
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //without space 
        for(int i = m; i < m + n; i++){
            nums1[i] = nums2[i - m]; 
        }
        sort(nums1.begin(), nums1.end()); 
        return; 
        //with space 
        vector<int>temp(m + n, 0);
        int i = 0, j = 0, k = 0;
        while(i < m && j < n){
            if (nums1[i] < nums2[j]){
                temp[k++] = nums1[i++];
            } else{
                temp[k++] = nums2[j++];
            }
        }
        while(i < m){
            temp[k++] = nums1[i++];
        }
        while(j < n){
            temp[k++] = nums2[j++];
        }
        while(k--){
            nums1[k] = temp[k];
        }
}
int main(){
 	int m, n; cin >> m >> n; 
 	vector<int>nums1(m + n), nums2(n); 
 	input(nums1);
 	input(nums2);
 	print(nums1);
 	print(nums2);
 	merge(nums1, m, nums2, n);
 	print(nums1);
    return 0; 
}