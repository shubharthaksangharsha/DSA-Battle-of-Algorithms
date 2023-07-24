#include<bits/stdc++.h> 
using namespace std; 
int const N = 10e6;

void sayDigit(int n, string arr[]){
	if (n == 0){
		return;
	}
	//processing 
	int digit = n % 10; 
	n = n / 10; 
	
	sayDigit(n, arr); 
	cout << arr[digit] << " ";
}

int main(){
	string arr[10] = {
		"zero", "one", "two", "three",
		"four", "five", "six", 
		"seven", "eight", "nine"}; 
 	int t; 
 	cin >> t; 
 	while(t--){
 		int n; 
 		cin >> n; 
 		sayDigit(n, arr);
 		cout << endl; 

 	}
  	return 0; 
}