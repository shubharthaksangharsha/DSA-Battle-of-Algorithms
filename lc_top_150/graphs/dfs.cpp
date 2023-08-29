
//Author - Shubharthak Sangharasha
/*
    Description: Print the DFS traversal of graph 
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
void display(const vector<int>&arr){
    for(const auto i: arr){
        cout << i << " ";
    }
    cout << endl;
}
class Solution {
  private:
    void dfs(int node, vector<int>adj[], vector<int>&vis, vector<int>&ans){
        vis[node] = 1; 
        ans.push_back(node);
        for(auto i: adj[node]){
            if(!vis[i]){
                dfs(i, adj, vis, ans);
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans;
        vector<int>vis(V, 0);
        dfs(0, adj, vis, ans);
        // for(int i = 0; i < V; i++){
        //     if(!vis[i]){
        //         dfs(i, adj, vis, ans);
        //     }
        // }
        return ans;
    }
};
int main(){
     int n, m; 
     cin >> n >> m; 
     vector<int>adj[n+1];
     input(adj, m);
     Solution sol;
     vector<int>ans = sol.dfsOfGraph(N, adj);
     display(ans);
     return 0; 
}