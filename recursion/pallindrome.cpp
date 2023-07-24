
//Author - Shubharthak Sangharasha
/*
    Description: Checking pallindrome using functional recursion 
*/


#include<bits/stdc++.h> 
using namespace std; 
int const N = 10e6;

//checking pallindrome using functional recursion 
bool f(int i, string s){
	//base case
	if(i >= s.size() / 2){
		return true;
	}

	if(s[i] != s[s.size() - 1 - i]){
		return false;
	}
	return f(i+1, s);
}
int main(){
	int t; cin >> t;
	while(t--){
	 	string n; cin >> n;
	 	if(f(0, n)){
	 		cout << "Pallindrome" << endl;;
	 	} else{
	 		cout << "Not Pallindrome" << endl;;
	 	}
	}
  	return 0; 
}