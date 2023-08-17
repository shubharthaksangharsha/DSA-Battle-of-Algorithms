
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

	//Sieve of Esthrasus O(N^2)
	vector<bool>sieve(N, true);
	for(int i = 2; i * i  < N; i++){
		if(sieve[i]){
			int j = 2 * i; 
			while(j < N){
				sieve[j] = false; 
				j += i;
			}
		}
	}
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