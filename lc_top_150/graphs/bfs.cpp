//Author - Shubharthak Sangharasha
/*
    Description: BFS Traversal of a graph
*/

#include<bits/stdc++.h> 
using namespace std; 

void input(vector<int>adj[], int edges){
    for(int i = 0; i < edges; i++){
        int u, v; 
        cin >> u >> v; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void display(const vector<int>& arr){
    for(const auto i: arr){
        cout << i << " ";
    }
    cout << endl;
}
void bfs(int src, vector<int>adj[], vector<int>& vis, vector<int>& ans){
    queue<int> q; 
    q.push(src);
    vis[src] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto i: adj[node]){
            if(vis[i] == 0){
                vis[i] = 1; 
                q.push(i);
            }
        }
    }
}
int main(){
    int n, m; 
    cin >> n >> m; 
    vector<int> adj[n+1], vis(n+1, 0), ans;
    input(adj, m);
    //Connected Componenets 
    for(int i = 1; i <= n; i++){
    	if(!vis[i]){
        	bfs(i, adj, vis, ans);
    	}
    }
    display(ans);
    return 0; 
}
