//Author - Shubharthak Sangharasha
/*
    Description: Check whether the given matrix is valid sudoku or not 
*/

#include<bits/stdc++.h> 
using namespace std; 


void input(vector<vector<char>>&arr){
    for(auto &i: arr){
        for(auto &j : i){
            cin >> j; 
        }
    }
}

void print(const vector<vector<char>>&arr){
    for(auto const i: arr){
        for(auto const j: i){
            cout << j << " ";
        }
        cout << endl;
    }
}

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //row check 
        for(int i = 0; i < 9; i++){
            unordered_set<char>st; 
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.' && st.find(board[i][j]) != st.end()){
                    return false;
                }
                st.insert(board[i][j]);
            }
        }
        //check col
        for(int col = 0; col < 9; col++){
            unordered_set<char>st; 
            for(int row = 0; row < 9; row++){
                if(board[row][col] != '.' && st.find(board[row][col]) != st.end()){
                    return false;
                }
                st.insert(board[row][col]);
            }
        }
        //check sub-boxes 
        vector<unordered_set<char>>check(9); 
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                int loc = (i / 3) * 3 + (j / 3); 
                if(board[i][j] != '.' && check[loc].find(board[i][j]) != check[loc].end()){
                    return false;
                } 
                check[loc].insert(board[i][j]);
            }
        }
        return true;
        
    }
};

int main(){
     int m, n;
     cin >> m >> n; 
     vector<vector<char> >arr(m, vector<char>(n));
     input(arr);
     // print(arr);
     Solution sol;
     cout << sol.isValidSudoku(arr) << endl;
    return 0; 
}