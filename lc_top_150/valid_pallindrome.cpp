
//Author - Shubharthak Sangharasha
/*
    Description: A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

	Given a string s, return true if it is a palindrome, or false otherwise.
*/


#include<bits/stdc++.h> 
using namespace std; 
int const N = 10e6;

bool checkpallindrome(string &s){
        int start = 0, end = s.size() - 1; 
        while(start <= end){
            if(s[start] != s[end]){
                return false;
            }
            start++; end--;
        }
        return true;
}
char upp_to_low(char c){
	if (c >= 'A' &&  c <= 'Z'){
		return c - 'A' + 'a';
	}
	return c;
}
string convert_all(string s){
        string res;
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= 'A' && s[i] <= 'Z' || s[i] >= '0' && s[i] <= '9' || s[i] >= 'a' && s[i] <= 'z'){
                res.push_back(s[i]);
            }
        }
        for(int i = 0; i < res.size(); i++){
            res[i] = upp_to_low(res[i]);
        }
        return res;
}

bool solve(string s){
	string res = convert_all(s);
	return checkpallindrome(res);
}
int main(){
 	string s; cin >> s; 
 	if(solve(s)) cout << "Yes"; 
 	else cout << "No"; 
  	return 0; 
}