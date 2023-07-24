//Author - Shubharthak Sangharasha
/*
    Description: Reverse the array using recursion 
*/
#include<bits/stdc++.h> 
using namespace std; 
int const N = 10e6;

void print(const vector<int>&arr){
	for(auto i: arr){
		cout << i << " ";
	}
	cout << endl;
}

void swap(vector<int>&arr, int l, int r){
	int temp = arr[l];
	arr[l] = arr[r];
	arr[r] = temp;
}


//using single pointer (functional recursion)
void reverse(vector<int>&arr, int i){
	if(i >= arr.size() / 2){
		return;
	}
	swap(arr, i, arr.size() - i - 1); 
	reverse(arr, i+1);
}
//using 2 pointers (parametized recursion)
void reverse(vector<int>&arr, int l, int r){
	if (l > r){
		return;
	}
	swap(arr, l, r); 
	reverse(arr, l+1, r-1);
}
int main(){
 	// int n; cin >> n;
 	vector<int>arr = {1, 2, 3, 4, 5, 6};
 	print(arr);
 	reverse(arr, 0);
 	print(arr);
  	return 0; 
}