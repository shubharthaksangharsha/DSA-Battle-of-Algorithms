#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3005;

vector<int> adj[MAXN];
int dp_in[MAXN], dp_out[MAXN];

void dfs(int node, int parent) {
    dp_in[node] = dp_out[node] = 0;

    for (int child : adj[node]) {
        if (child != parent) {
            dfs(child, node);
            dp_in[node] = max(dp_in[node], dp_in[child] + 1);
        }
    }

    vector<int> lengths;
    for (int child : adj[node]) {
        if (child != parent) {
            lengths.push_back(dp_in[child] + 1);
        }
    }
    
    sort(lengths.rbegin(), lengths.rend());
    
    if (!lengths.empty()) {
        dp_out[node] = lengths[0];
        for (int i = 1; i < lengths.size(); ++i) {
            dp_out[node] = max(dp_out[node], lengths[i] + i);
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1, 0);
    
    int answer = 0;
    for (int i = 1; i <= n; ++i) {
        answer = max(answer, dp_in[i] + dp_out[i]);
    }
    
    cout << answer - 1<< endl;
    
    return 0;
}
