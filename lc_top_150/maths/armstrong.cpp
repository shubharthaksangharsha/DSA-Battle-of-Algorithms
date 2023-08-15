
//Author - Shubharthak Sangharasha
/*
    Description: 
*/


#include<bits/stdc++.h> 
using namespace std; 
int const N = 10e6;

bool checkArmstrong(int n){
	int temp = n; 
	int ans = 0;
	int digits = (int)(log10(n) + 1);
	while(temp){
		ans += (int)(pow((temp %10), digits)); 
		temp /= 10;
	}
	return (n == ans);
}



int main(){
 	int n; cin >> n;
	cout << checkArmstrong(n); 	
  	return 0; 
}