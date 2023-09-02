
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
void dfs(int node, vector<int> adj[], int parent, int length, int &count){
	int child_count = 0;
	for(auto adjnode: adj[node]){
		if(adjnode != parent){
			dfs(adjnode, adj, node, 1, count);
			child_count++;
		}
	}
	count += max(0, child_count - 1);
}
int main(){
 	int n; cin >> n;
 	int count = 0;
 	vector<int>adj[n+1];
 	input(adj, n-1);
 	for(int i = 1; i <= n; i++){
 		dfs(i, adj, -1, 0, count);
 	}
 	cout << count << endl;
  	return 0; 
}