
//Author - Shubharthak Sangharasha
/*
    Description: Check the common longest subsequence between the given two strings.
*/


#include<bits/stdc++.h> 
using namespace std; 
int const N = 10e6;

//recursive 
int f(int i1, int i2, string &s1, string &s2){
	//base case 
	if (i1 < 0 || i2 < 0){
		return 0;
	}
	//match
	if (s1[i1] == s2[i2]){
		return 1 + f(i1 - 1, i2 -1, s1, s2);
	}
	//not match 
	return max(f(i1 -1, i2, s1, s2), f(i1, i2 - 1, s1, s2));
}
//dp using memoization 
int f2(int i1, int i2, string &s1, string &s2, vector<vector<int> >&dp){
	//base case 
	if (i1 < 0 || i2 < 0){
		return 0; 
	}
	//memoize 
	if(dp[i1][i2] != -1){
		return dp[i1][i2];
	}
	//match 
	if(s1[i1] == s2[i2]){
		return 1 + f2(i1-1, i2-1, s1, s2, dp);
	}
	//not match 
	return max(f2(i1 -1, i2, s1, s2, dp), f2(i1, i2-1, s1, s2, dp));
}
//dp using tabulation 
int f3(int i1, int i2, string &s1, string &s2){
	vector<vector<int> >dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
	for(int i = 0; i <= s1.size(); i++){
		dp[0][i] = 0;
	}
	for(int i = 0; i <= s2.size(); i++){
		dp[0][i] = 0;
	}
	for(int i = 1; i <= s1.size(); i++){
		for(int j = 1; j <= s2.size(); j++){
			//match 
			if(s1[i] == s2[j]){
				dp[i][j] = 1 + dp[i-1][j-1];
			} else{//not match 
				dp[i][j] =max(dp[i -1][j], dp[i][j - 1]);
			}
		}
	}

	return dp[s1.size()][s2.size()];
}

int f4(int i1, int i2, string &s1, string &s2){
	vector<vector<int> >dp(s1.size() + 1, )
}
int solve(string &s1, string &s2){
	vector<vector<int> >dp(s1.size(), vector<int>(s2.size(), -1));
	return f3(s1.size() - 1, s2.size() - 1, s1, s2);
	return f2(s1.size() -1, s2.size() - 1, s1, s2, dp);
	return f(s1.size() - 1, s2.size() - 1, s1, s2); 
}
int main(){
 	string s1, s2; 
 	cin >> s1 >> s2; 
 	cout <<solve(s1, s2);
 	
  	return 0; 
}