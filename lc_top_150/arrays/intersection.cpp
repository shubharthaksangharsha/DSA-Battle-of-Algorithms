//Author - Shubharthak Sangharasha
/*
    Description: Find the intersection of two sorted arrays
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
//Incase no duplicates (O(N)), O(N)
const vector<int> remove(vector<int>&arr){
        vector<int>temp;
        if(arr.empty()) return arr; 
        temp.push_back(arr[0]);
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] != arr[i - 1]) temp.push_back(arr[i]);
        }
        return temp;
}
const vector<int>solve(vector<int>&arr1, vector<int>&arr2){
	//Brute force (O(n^2))
	// vector<int>res;
	// vector<int>vis(arr2.size(), 0); 

	// for(int i = 0; i < arr1.size(); i++){
	// 	for(int j = 0; j < arr2.size(); j++){
	// 		if(arr1[i] == arr2[j] && vis[j] != 1){
	// 			res.push_back(arr1[i]);
	// 			vis[j] = 1; 
	// 			break;
	// 		}
	// 	}
	// }
	// return res;

	//O(N) two pointer 
	vector<int>res;
	int i = 0, j = 0; 
	while(i < arr1.size() && j < arr2.size()){
		if(arr1[i] == arr2[j]){
			res.push_back(arr1[i]);
			i++; j++;
		} else if (arr1[i] < arr2[j]){
			i++;
		} else{
			j++;
		}
	}
	return res;
}

int main(){
 	int n, m; cin >> n >> m; 
 	vector<int>arr1(n), arr2(m);
 	input(arr1); input(arr2);
 	vector<int>ans = solve(arr1, arr2);
 	print(ans);
    return 0; 
}