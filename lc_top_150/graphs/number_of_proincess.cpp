
//Author - Shubharthak Sangharasha
/*
    Description: Find number of connected components(proviencess)
*/

#include<bits/stdc++.h> 
using namespace std; 
int const N = 10e6;

void input(vector<vector<int>>&adj, int edges){
    for(int i = 0; i < edges; i++){
        int u, v; 
        cin >> u >> v; 
        adj[u][v] = 1; 
        adj[v][u] = 1; 
    }
}
void print(const vector<vector<int>>&adj){
    for(const auto i: adj){
        for(auto const j: i){
            cout << j << " ";
        } cout << endl;
    }
}
class Solution {
private:
    void dfs(int node, vector<int>adj[], vector<int>&vis){
        vis[node] = 1; 
        for(auto i: adj[node]){
            if(!vis[i]){
                dfs(i, adj, vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0; 
        int m = isConnected.size();
        vector<int>vis(m, 0);
        vector<int>adj[m+1]; 
        for(int i =0; i < m; i++){
            for(int j = 0; j < m; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                    // adj[j].push_back(i);
                }
            }
        }
        for(int i =0; i < m; i++){
            if(!vis[i]){
                dfs(i, adj, vis);
                count++;
            }
        }
        return count;
    }
};
int main(){
     int n, m; 
     cin >> n >> m; 
     vector<vector<int>>adj(n+1, vector<int>(n+1, 0));
     input(adj, m);
     Solution sol;
     cout << sol.findCircleNum(adj);
      return 0; 
}