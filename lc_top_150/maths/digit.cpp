//
//Author - Shubharthak Sangharasha
/*
    Description: Count number of digits in an given integer
*/


#include<bits/stdc++.h> 
using namespace std; 
int const N = 10e6;

int count_digit(int n){
	//TC: O(logbase10(N)),SC: (1)
	//1st method 
	// return ((int)(log10(n) + 1));

	int count = 0;
	while(n > 0){
		n /= 10; count++; 
	}
	return count;
}
int main(){
 	int n; cin >> n;
 	cout << count_digit(n);
  	return 0; 
}