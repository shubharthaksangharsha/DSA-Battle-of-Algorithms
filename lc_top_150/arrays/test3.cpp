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

vector<int> getNumPoints(vector<int> layers, vector<int>energy, long k){
	int n = layers.size(); 
	vector<int>ans(n, 0);
	for(int i = 0; i < n; i++){
		int d = k, count = 0; 
		for(int j = i; j < n; j++){
			if(d >= layers[j] && d >= energy[j]){
				count++;
				d = d - layers[j];
			} else{
				break;
			}
		}
		ans[i] = count;
	}
	return ans;
}
int main(){
 	int n; cin >> n; 
 	vector<int>layers(n), energy(n); 
 	input(layers);
 	input(energy);
 	long int k; cin >> k ;
 	vector<int>res = getNumPoints(layers, energy, k);
 	print(res);
    return 0; 
}