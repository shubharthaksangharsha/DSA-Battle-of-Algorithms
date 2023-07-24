#include<bits/stdc++.h> 
using namespace std; 
int const N = 10e6;

bool isSorted(int *arr, int size){
	//base case 
	if(size == 0 || size == 1){
		return true;  
	} 
	if (arr[0] > arr[1]){
		return false; 
	} 
	return isSorted(arr + 1, --size);
}
int main(){
 	int arr[] = {1, 2, 3, 4, 5}; 
 	int size = 5; 
 	cout << isSorted(arr, size) << endl;
  	return 0; 
}