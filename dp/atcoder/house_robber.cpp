//Author - Shubharthak Sangharasha
/*
    Description: 
*/

#include<bits/stdc++.h> 
using namespace std; 
int const N = 10e6;

int maxi_non_adjacent(vector<long long>&arr){
	int n = arr.size(); 
	int prev = arr[0]; 
	int prev2 = 0; 
	for(int i = 1; i < n; i++){
		int take = arr[i]; 
		if(i > 1){
			take += prev2; 
		}
		int not_take = prev; 
		int curi = max(take, not_take); 
		prev2 =	prev; 
		prev = curi; 
	}
	return prev; 
}

long long int houseRobber(vector<int>&house){
	vector<long long>temp1, temp2; 
	int n = house.size(); 
	if(n == 1){
		return house[0];
	}
	for(int i = 0; i < n; i++){
		if(i != 0){
			temp1.push_back(house[i]); 
		} 
		if(i != n - 1){
			temp2.push_back(house[i]);
		}
	}
	return max(maxi_non_adjacent(temp1), maxi_non_adjacent(temp2)); 
}

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
int main(){
 	int n; cin >> n; 
 	vector<int>arr(n); 
 	input(arr); 
 	cout << houseRobber(arr) << endl;
    return 0; 
}