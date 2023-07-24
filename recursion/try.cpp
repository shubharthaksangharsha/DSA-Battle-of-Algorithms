#include<bits/stdc++.h> 
using namespace std; 
int const N = 10e6;

void print(int i, int n){
	if (i > n){
		return;
	}
	cout << i << endl;
	print(i+1, n);

}
int main(){
	int n; cin >> n;
 	print(1, n);
  	return 0; 
}