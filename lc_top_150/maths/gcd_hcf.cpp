
//Author - Shubharthak Sangharasha
/*
    Description: Find GCD/HCF of a 2 numbers.
*/


#include<bits/stdc++.h> 
using namespace std; 
int const N = 10e6;

int gcd_hcf(int a, int b){
	//O(min(n1, n2))
	// int ans = 1;
	// int n = min(n1, n2); 
	// for(int i = 1; i <= n; i++){
	// 	if(n1 % i == 0 && n2 % i == 0){
	// 		ans = i;
	// 	}
	// }
	// return ans;

	//Eucledian Algo : TC: O(log(base i)(min(a, b))), SC: O(1)
	while (a > 0 && b > 0){
		if(a > b){
			a = a % b; 
		} else {
			 b = b % 10;
		}
	}
	return b ? a == 0 : a;
}
int main(){
 	int n1, n2; cin >> n1 >> n2;
 	cout << gcd_hcf(n1, n2);
  	return 0; 
}