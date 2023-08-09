//https://leetcode.com/problems/longest-palindromic-substring/
//Author - Shubharthak Sangharasha
/*
    Description: Find longest substring from the given string.
*/


#include<bits/stdc++.h> 
using namespace std; 
int const N = 10e6;

bool check_pallindrome(string &s, int start, int end){
	while(start <= end){
		if(s[start] != s[end]){
			return false;
		}
		start++; end--;
	}
	return true;
}

string solve(string s){
	string ans; 
        if (s.size() == 1){
            ans.push_back(s[0]);
        }
        int maxLength = 0;
        for(int i = 0; i < s.size(); i++){
            for(int j = i; j < s.size(); j++){
                if (check_pallindrome(s, i, j)){
                    int current_length = j - i + 1; 
                    if(current_length > maxLength){
                        maxLength = current_length;
                        ans = s.substr(i, current_length);
                    }
                }
            }
        }
    return ans;
}
int main(){
 	string s; 
 	cin >> s; 
 	cout << solve(s); 
 	
  	return 0; 
}