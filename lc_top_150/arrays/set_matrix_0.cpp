//Author - Shubharthak Sangharasha
/*
    Description: Set all the row and col of the each el to 0 if el == 0
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
    void markCol(int j, vector<vector<int> >&arr){
        for(int i = 0; i < arr.size(); i++){
            if(arr[i][j] != 0) arr[i][j] = -1;
        }
    }
    void markRow(int i, vector<vector<int> >&arr){
        for(int j = 0; j < arr[i].size(); j++){
            if(arr[i][j] != 0) arr[i][j] = -1;
        }
    }
public:
    void setZeroes(vector<vector<int>>& arr) {
        if(arr.size() == 0) return;
        //Brute Force Not Accepted because of range of arr element(INTMIN < el < INT_MAX)
        // for(int i = 0; i < arr.size(); i++){
        //     for(int j = 0; j < arr[i].size(); j++){
        //         if(arr[i][j] == 0){
        //             markRow(i, arr);
        //             markCol(j, arr);
        //         }
        //     }
        // }
        // for(int i = 0; i < arr.size(); i++){
        //     for(int j = 0; j < arr[i].size(); j++){
        //         if(arr[i][j] == -1){
        //             arr[i][j] = 0;
        //         }
        //     }
        // }
        //Better sol: O(MxN), O(M+N) Accepted
        // vector<int>row(arr.size(), 0);
        // vector<int>col(arr[0].size(), 0);
        // for(int i =0; i < arr.size(); i++){
        //     for(int j = 0; j < arr[i].size(); j++){
        //         if(arr[i][j] == 0){
        //             row[i] = 1; 
        //             col[j] = 1; 
        //         }
        //     }
        // }
        // for(int i = 0; i < arr.size(); i++){
        //     for(int j = 0; j < arr[i].size(); j++){
        //         if(row[i] || col[j]){
        //             arr[i][j] = 0;
        //         }
        //     }
        // }
        //optimal approach O(2* n + m), O(1)
        int col0 = 1; 
        for(int i = 0; i < arr.size(); i++){
            for(int j = 0; j < arr[i].size(); j++){
                if(arr[i][j] == 0){
                    arr[i][0] = 0; 
                    if(j != 0){
                        arr[0][j] = 0; 
                    } else{
                        col0 = 0;
                    }
                }
            }
        }
        for(int i = 1; i < arr.size(); i++){
            for(int j = 1; j < arr[i].size(); j++){
                if(arr[i][j] != 0){
                    if(arr[0][j] == 0 || arr[i][0] == 0){
                        arr[i][j] = 0;
                    }
                }
            }
        }
        //first mark the last 
        if(arr[0][0] == 0){
            for(int j = 0; j < arr[0].size(); j++){
                arr[0][j] = 0;
            }
        }
        if(col0 == 0){
            for(int i = 0; i < arr.size(); i++){
                arr[i][0] = 0;
            }
        }
    }
};
int main(){
 	int m, n;
 	cin >> m >> n; 
 	vector<vector<int> >arr(m, vector<int>(n));
 	input(arr);
 	Solution sol; 
 	sol.setZeroes(arr);
 	print(arr);
    return 0; 
}