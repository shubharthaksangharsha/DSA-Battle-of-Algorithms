//Author - Shubharthak Sangharasha
/*
    Description: 
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

int count_duplicates(vector<int>arr){
	int n = arr.size(); 
	int count = 0;
	sort(arr.begin(), arr.end());
	for(int i = 0; i < n - 1; i++){
		cout << arr[i] << " ";
		if(arr[i] == arr[i+1]){
			count++;
		}
	}
	return count;
}
int main(){
 	int n; cin >> n; 
 	vector<int>arr(n); 
 	input(arr); 
 	cout << count_duplicates(arr);
    return 0; 
}