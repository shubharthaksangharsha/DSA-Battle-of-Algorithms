
//Author - Shubharthak Sangharasha
/*
    Description: Check whether given integer is pallindrome or not 
*/


#include<bits/stdc++.h> 
using namespace std; 
int const N = 10e6;

int reverse(int n){
	int temp = n; 
	int ans = 0;
	while(temp){
		ans  = (ans * 10) + (temp % 10);  
		temp /= 10; 
	}
	return ans;
}
bool check_pallindrome(int n){
	return (reverse(n) == n); 
}
int main(){
 	int n; cin >> n;
 	if(check_pallindrome(n)){
 		cout << "Yes";
 	} else {
 		cout << "No";
 	}
  	return 0; 
}