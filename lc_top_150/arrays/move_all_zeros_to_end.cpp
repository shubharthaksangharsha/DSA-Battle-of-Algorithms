//Author - Shubharthak Sangharasha
/*
    Description: Move all the zeros at the right side (inplace)
*/

#include<bits/stdc++.h> 
using namespace std; 
int const N = 10e6;

void input(vector<int>&arr){
	for(auto &i: arr){
		cin >> i; 
	}
}

void print(const vector<int>&arr){
	for(auto const i: arr){
		cout << i << " ";
	}
	cout << endl;
}
void solve(vector<int>&arr){

	//Optimzal approach 
	int slow = -1; 
	for(int i = 0; i < arr.size(); i++){
		if(arr[i] == 0){
			slow = i;
			break;
		}
	}
	for(int i = slow + 1; i < arr.size(); i++){
		if(arr[i] != 0){
			swap(arr[i], arr[slow++]);
		}
	}

}
int main(){
 	int n; cin >> n; 
 	vector<int>arr(n); 
 	input(arr); 
 	// print(arr);
 	solve(arr);
 	print(arr);
    return 0; 
}