#include<bits/stdc++.h> 
using namespace std; 
int const N = 10e6;

int fib(int n){
	if (n == 0){
		return 0;
	}
	if (n == 1){
		return 1;
	}
	
	return fib(n -1) + fib(n - 2); 
}

int main(){
 	int t; 
 	cin >> t; 
 	while(t--){
 		int n; 
 		cin >> n; 
 		cout << fib(n) << endl; 
 	}
  	return 0; 
}