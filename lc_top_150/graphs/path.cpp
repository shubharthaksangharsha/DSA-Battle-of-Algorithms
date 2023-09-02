//Author - Shubharthak Sangharasha
/*
    Description: 
*/

#include<bits/stdc++.h> 
using namespace std; 



void solve(vector<vector<char>>&arr, int const m, int const n){
	//Using BFS 
	vector<vector<int>>vis(m, vector<int>(n, 0));
	queue<pair<string, pair<int, int>>>q;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(arr[i][j] == 'A'){
				q.push({"", {i, j}});
				vis[i][j] = 1;
			}
		}
	}

	while(!q.empty()){
		string path = q.front().first;
		int cr = q.front().second.first;
		int cc = q.front().second.second;
		q.pop();
		if(arr[cr][cc] == 'B'){
			cout << "YES" << endl;
			cout << path.size() << endl;
			cout << path << endl;
			return;
		}
		//Up 
		if(cr >= 1 && cr < m && cc >= 0 && cc < n  && arr[cr-1][cc] != '#' && 
			vis[cr-1][cc] == 0){
				vis[cr-1][cc] = 1;
				q.push({path + "U",{cr - 1, cc}});

		}
		//Left 
		if(cr >= 0 && cr < m && cc >= 1 && cc < n && arr[cr][cc-1] != '#' && 
			vis[cr][cc-1] == 0){
				vis[cr][cc-1] = 1;
				q.push({path + "L",{cr, cc-1}});		
		}

		//Right
		if(cr >= 0 && cr < m && cc >= 0 && cc < n-1 && arr[cr][cc+1] != '#' && 
			vis[cr][cc+1] == 0){
				vis[cr][cc+1] = 1;
				q.push({path + "R",{cr, cc+1}});		
		}

		//Down 
		if(cr >= 0 && cr < m-1 && cc >= 0 && cc < n && arr[cr+1][cc] != '#' && 
			vis[cr+1][cc] == 0){
				vis[cr+1][cc] = 1;
				q.push({path + "D",{cr + 1, cc}});		
		}
	}
	cout << "NO" << endl;
}
int main(){
 	int m, n;
 	cin >> m >> n; 
 	vector<vector<char> >arr(m, vector<char>(n));
 	for(int i = 0; i < m; i++){
 		for(int j = 0; j < n; j++){
 			cin >> arr[i][j];
 		}
 	}

 	solve(arr, m, n);
    return 0;
}