
//Author - Shubharthak Sangharasha
/*
    Description: 
*/

#include<bits/stdc++.h> 
using namespace std; 
int const N = 10e6;

void input(vector<int>adj[], int edges){
	for(int i = 0; i < edges; i++){
		int u, v; 
		cin >> u >> v; 
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}
void print(const vector<int>adj[], int n){
	for(int i = 0; i <= n ; i++){
		cout << i << ": " << "[";
		for(auto j: adj[i]){
			cout << j << ",";
		}
		cout <<"]" <<  endl;
	}
}
int main(){
 	int n, m; 
 	cin >> n >> m; 
 	vector<int>adj[n+1];
 	input(adj, m);
 	print(adj, n);
  	return 0; 
}