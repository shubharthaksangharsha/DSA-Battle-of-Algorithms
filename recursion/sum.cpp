#include<bits/stdc++.h> 
using namespace std; 
int const N = 10e6;


//functional recursion 
int f(int n){
	if (n  == 0){
		return 0;
	}
	return n + f(n-1);
}

//parametized recursion 
void f(int i, int sum){
	if (i < 1){
		cout << sum << endl;
		return;
	}
	f(i-1, sum+i);
}
int main(){
 	int n; cin >> n;
 	cout << f(n) << endl;
  	return 0; 
}