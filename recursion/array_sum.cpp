#include<bits/stdc++.h> 
using namespace std; 
int const N = 10e6;

int sum(int *arr, int size, int &res){
	//base case 
	if(size == 0){
		return res;
	} 
	res += arr[0];
	return sum(arr + 1, --size, res);
}
int main(){
 	int arr[] = {1, 2, 3, 4, 5}; 
 	int size = 5; 
 	int res = 0;
 	cout << sum(arr, size, res) << endl;
  	return 0; 
}