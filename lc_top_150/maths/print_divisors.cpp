
//Author - Shubharthak Sangharasha
/*
    Description: Print all divisors of given number
*/


#include<bits/stdc++.h> 
using namespace std; 
int const N = 10e6;

void print(int n){
	//Brute force 
	// for(int i = 1; i <= n; i++){
	// 	if(n % i == 0){
	// 		cout << i << " ";
	// 	}
	// }

	//sqrt(n) approach :unsorted 
	for(int i = 1; i * i <= n; i++){
		if(n % i == 0){
			cout << i << " ";
			if( (n / i) != i){
				cout << (n / i) << " ";
			}
		}
	}
}
int main(){
 	int n; cin >> n;
 	print(n);
  	return 0; 
}