//Author - Shubharthak Sangharasha
/*
    Description: Find the union of two arrays
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

const vector<int> solve(vector<int>&arr1, vector<int>&arr2){
	// set<int>st; TC: O(n1logn + n2logn + O(n1 + n2))
	// for(int i = 0; i < arr1.size(); i++){
	// 	st.insert(arr1[i]);
	// }
	// for(int i = 0; i < arr2.size(); i++){
	// 	st.insert(arr2[i]);
	// }
	// return {st.begin(), st.end()};

	//2Pointer approach
	vector<int>res; 
	int i = 0, j = 0; 
	int m = arr1.size(); int n = arr2.size(); 
	while(i < m && j < n){
		if(arr1[i] < arr2[j]){
			if(res.size() == 0 || arr1[i] != arr1[i-1]) {
				res.push_back(arr1[i]);
			}
			i++;
		} else{
			if(res.size() == 0 || arr2[j] != arr2[j-1]) {
				res.push_back(arr2[j]);
			}
			j++;
		}
	}
	while(i < m){
		if(arr1[i] < arr2[j]){
			if(res.size() == 0 || arr1[i] != arr1[i-1]) {
				res.push_back(arr1[i]);
			}
			i++;
		}
	}
	while(j < n){
		if(res.size() == 0 || arr2[j] != arr2[j-1]) {
				res.push_back(arr2[j]);
			}
			j++;	
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