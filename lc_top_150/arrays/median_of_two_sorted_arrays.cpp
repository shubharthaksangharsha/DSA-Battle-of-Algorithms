//https://leetcode.com/problems/median-of-two-sorted-arrays/
//Author - Shubharthak Sangharasha
/*
    Description: Find median of given two sorted arrays 
*/

#include<bits/stdc++.h> 
using namespace std; 
int const N = 10e6;

const vector<int> merge(vector<int>arr1, vector<int>arr2){
        vector<int>res;
        int m = arr1.size(), n = arr2.size();
        int i = 0, j = 0, k = 0; 
        while(i < m && j < n){
            if (arr1[i] <= arr2[j]){
                res.push_back(arr1[i++]); 
            } else{
                res.push_back(arr2[j++]);
            }
            k++;
        }
        while(i < m){
            res.push_back(arr1[i++]);
            k++;
        }
        while(j < n){
            res.push_back(arr2[j++]);
            k++;
        }
        return res;
}
const double merge2(const vector<int>&arr1, const vector<int>&arr2){
        int n1 = arr1.size(), n2 = arr2.size(); 
        int i = 0, j = 0; 
        int counter = 0; 
        int prev = -1, current = -1;
        while(i < n1 && j < n2){
            if (counter == (n1 + n2) / 2 + 1){
                if((n1 + n2) % 2 == 0){
                    return (prev + current) / 2.0;
                } else{
                    return current;
                }
            }
            prev = current;             
            if (arr1[i] <= arr2[j]){
                current = arr1[i++];
            } else{
                current = arr2[j++];
            }
            counter++;
        } 
        while (i < n1){
            prev = current; 
            current = arr1[i++]; 
            counter++;
            if (counter == (n1 + n2) / 2 + 1){
                if((n1 + n2) % 2 == 0){
                    return (prev + current) / 2.0;
                } else{
                    return current;
                }
            }
        }
        while (j < n2){
            prev = current; 
            current = arr2[j++]; 
            counter++;
            if (counter == (n1 + n2) / 2 + 1){
                if((n1 + n2) % 2 == 0){
                    return (prev + current) / 2.0;
                } else{
                    return current;
                }
            }
        }
        return 0.0;
}
//Brute Force Solution: O(sizeof(nums1) + sizeof(nums2)), O(sizeof(nums1) + sizeof(nums2))
const double f(vector<int>&nums1, vector<int>&nums2){
        vector<int>ans = merge(nums1, nums2);
        int n = ans.size(); 
        if (n % 2 == 1){
            return ans[n / 2];
        }
        return (ans[n / 2 - 1] + ans[n / 2]) / 2.0;
}
    
//Better solution: O(sizeof(nums1) + sizeof(nums2)), O(1)
const double f2(vector<int>&nums1, vector<int>&nums2){
    return merge2(nums1, nums2);
}
//Optimized Solution: O(log(min(nums1 + nums2))), O(1) using BS
const double f3(vector<int>&nums1, vector<int>&nums2){
     if(nums2.size() < nums1.size()){
        return f3(nums2, nums1);
     }
     int n1 = nums1.size(), n2 = nums2.size();
     int low = 0, high = n1; 
     while(low <= high){
        int cut1 = (low + high) / 2; 
        int cut2 = (n1 + n2 + 1) / 2 - cut1; //works for both odd and even cases 

        int left1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
        int left2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];

        int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
        int right2 =  cut2 == n2 ? INT_MAX : nums2[cut2];

        if(left1 <= right2 && left2 <= right1){
            if((n1  + n2) % 2 == 0){
                return (max(left1, left2) + min(right1, right2)) / 2.0;   
            } else{
                return max(left1, left2);
            }
        } else if (left1 > right2){
            high = cut1 - 1; 
        } else{
            low = cut1 + 1; 
        }
     }
     return 0.0;
}
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return f3(nums1, nums2);
        // return f2(nums1, nums2);   
        // return f(nums1, nums2);
}


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
int main(){
     int m, n; cin >> m >> n; 
     vector<int>arr1(m), arr2(n); 
     input(arr1); input(arr2); 
     cout << findMedianSortedArrays(arr1, arr2);
     return 0; 
}