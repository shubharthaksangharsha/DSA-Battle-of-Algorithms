//Author - Shubharthak Sangharasha
/*
    Description: 
*/

#include<bits/stdc++.h> 
using namespace std; 


void input(vector<vector<int>>&arr){
	for(auto &i: arr){
		for(auto &j : i){
			cin >> j; 
		}
	}
}

void print(const vector<vector<int>>&arr){
	for(auto const i: arr){
		for(auto const j: i){
			cout << j << " ";
		}
		cout << endl;
	}
}

const vector<vector<int>> f(vector<int>&arr){
		//brute force 
		set<vector<int>>st;
		for(int i = 0; i < arr.size(); i++){
			for(int j = i + 1; j < arr.size(); j++){
				for(int k = j + 1; k < arr.size(); k++){
					int sum = arr[i] + arr[j] + arr[k];
					if(sum == 0){
						vector<int>temp = {arr[i], arr[j], arr[k]};
						sort(temp.begin(), temp.end());
						st.insert(temp);
					}
				}
			}
		}
		vector<vector<int>>ans(st.begin(), st.end()); 
		return ans;
}

void solve(vector<int>&arr){

}
int main(){
 	int m, n;
 	cin >> m >> n; 
 	vector<vector<int> >arr(m, vector<int>(n));
 	input(arr);
 	// print(arr);
    return 0; 
}