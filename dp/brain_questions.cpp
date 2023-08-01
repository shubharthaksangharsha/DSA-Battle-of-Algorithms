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

//memoization: O(N), SC: O(N) + O(N)
long long int f(int i, vector<vector<int> >&questions, vector<long long>&dp){
        //base case 
        if (i >= questions.size()){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        //not take 
        long long not_take = 0 + f(i + 1, questions, dp); 
        long long take = questions[i][0] + f(i + questions[i][1] + 1, questions, dp);
        return dp[i] = max(take, not_take);
    }

//Tabulation: O(N), SC: O(N)
long long int f2(int i, vector<vector<int> >&questions){
        vector<long long> dp(questions.size() +1, -1); 
        //base case 
        for(int i = questions.size() - 1; i >= 0; i--){
            //not take 
            long long not_take = 0 + dp[i + 1];
            long long take = questions[i][0];
            if (i + questions[i][1] + 1 < questions.size()){
                take += dp[i + questions[i][1] + 1];
            }
            dp[i] = max(take, not_take);
        }
        return dp[0];
}
long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n+1, -1);
        return f2(0, questions);
        return f(0, questions, dp );
}
int main(){
     int m, n;
     cin >> m >> n; 
     vector<vector<int> >arr(m, vector<int>(n));
     input(arr);
     print(arr);
    return 0; 
}