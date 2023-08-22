//Author - Shubharthak Sangharasha
/*
    Description: 
*/

#include<bits/stdc++.h> 
using namespace std; 


void input(vector<vector<int>>&arr){
	for(auto &i: arr){
		for(auto &j : i){
			cin >> j; 
		}
	}
}

void print(const vector<vector<int>>&arr){
	for(auto const i: arr){
		for(auto const j: i){
			cout << j << " ";
		}
		cout << endl;
	}
}

class Solution {
private:
    void transpose(vector<vector<int> >&matrix){
        int n=matrix.size(); 
        // cout <<"Matrix Size:"  << n << " , matrix.size() - 2: " << n - 3 << endl;
        for(int i = 0; i <= n - 2; i++){
            for(int j = i + 1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    void reverse(vector<int>&arr){
        
        int left = 0, right = arr.size() - 1; 
        while(left <= right){
            swap(arr[left++], arr[right--]);
        }
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        //Brute Force: O(n^2) sc: o(n^2) accepted
        // vector<vector<int>>temp(matrix.size(), vector<int>(matrix.size(), 0));
        // for(int i = 0; i < matrix.size(); i++){
        //     for(int j = 0; j < matrix.size(); j++){
        //         temp[j][(matrix.size()-1)-i] = matrix[i][j];
        //     }
        // }
        // //copy the elements back to matrix 
        // for(int i = 0; i < matrix.size(); i++){
        //     for(int j = 0; j < matrix.size(); j++){
        //         matrix[i][j] = temp[i][j];
        //     }
        // }

        //Optimal Approach 
        //2Steps: 
        //Transpose the matrix: Swap the elements other than diagnol
        // i.e: i -> (i + 1 to n - 1) (and first loop will start from i -> 0 to n-2)
        //Reverse the matrix by row: swap the each row with 2 pointer approach 
        // cout << matrix[0].size() << endl;
        transpose(matrix);
        for(int i = 0; i < matrix.size(); i++){
            reverse(matrix[i]);
        }
    }
};

int main(){
 	int m, n;
 	cin >> m >> n; 
 	vector<vector<int> >arr(m, vector<int>(n));
 	input(arr);
 	Solution sol;
 	sol.rotate(arr);
 	print(arr);
    return 0; 
}