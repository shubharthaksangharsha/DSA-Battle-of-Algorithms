//Author - Shubharthak Sangharasha
/*
    Description: Find minimum in sorted rotated array.
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

int findMin(vector<int>& A)
{
	int ans = INT_MAX; 
	int low = 0, high = A.size() - 1; 
    while(low <= high){

        int mid = low + (high - low) / 2; 
        
        //check for duplicates and trim it 
        if(A[low] == A[mid] && A[mid] == A[high]){
            low++; high--; 
            continue;
        }
        //left sorted 
        if(A[low] <= A[mid]){
            ans = min(ans, A[low]); 
			low = mid + 1;
        } else{
        //right sorted
            ans = min(ans, A[mid]); 
			high = mid - 1; 
        }
    }
    return ans;
}

int main(){
 	int n; cin >> n; 
 	vector<int>arr(n); 
 	input(arr); 
 	cout << findMin(arr) << endl;
    return 0; 
}