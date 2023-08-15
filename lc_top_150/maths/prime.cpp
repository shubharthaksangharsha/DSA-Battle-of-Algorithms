
//Author - Shubharthak Sangharasha
/*
    Description: Check whether given number is prime or not 
*/


#include<bits/stdc++.h> 
using namespace std; 
int const N = 10e6;

bool check_prime(int n){
	//Brute force O(n)
	// int count = 0; 
	// for(int i = 1; i <= n; i++){
	// 	if(n % i == 0) count++;
	// }
	// return count == 2;

	//Sqrt(n)
	// int count = 0;
	// for(int i = 1; i * i <= n; i++){
	// 	if(n % i == 0) {
	// 		count++;
	// 		if(n / i != i){
	// 			count++;
	// 		}
	// 	}
	// }
	// return count == 2;

}
int main(){
 	int n; cin >> n;
 	if(check_prime(n)){
 		cout << "Yes";
 	} else{
 		cout << "No";
 	}
  	return 0; 
}