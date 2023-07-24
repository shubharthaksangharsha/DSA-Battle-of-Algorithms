

//Author - Shubharthak Sangharasha
/*
    Description: Print all the subsequences of the array or string.
*/


#include<bits/stdc++.h> 
using namespace std; 


void display(const vector<int>&res){
	for(auto const i: res){
		cout << i << " ";
	}
	cout << endl;
}
void print(int i, vector<int>&arr, vector<int>&res){	
	//base case 
	if(i >= arr.size()){
		display(res);
		return;
	}
	res.push_back(arr[i]);
	print(i+1, arr, res);
	res.pop_back();
	print(i+1, arr, res);
}
int main(){
 	int n; cin >> n;
 	vector<int>arr(n);
 	vector<int>res;
 	for(int i = 0; i < arr.size(); i++){
		cin >> arr[i];
	}
 	print(0, arr, res);
  	return 0; 
}

