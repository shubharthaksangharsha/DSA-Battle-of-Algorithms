
//Author - Shubharthak Sangharasha
/*
    Description: 
*/


#include<bits/stdc++.h> 
using namespace std; 

int getWoodPiece(int arr[], int N){
	vector<int>prev(N+1, -1), curr(N + 1, -1);
	//base case 
	for(int n = 0; n <= N; n++){
		prev[n] = n * arr[0];
	}
	for(int ind = 1; ind < N; ind++){
		for(int n = 0; n <= N; n++){
			int not_take = prev[n];
			int take = INT_MIN; 
			int rod_length = ind + 1; 
			if(rod_length <= n){
				take = arr[ind] + curr[n - rod_length];
			}
			curr[n] = max(not_take, take);			
		}
		prev = curr;
	}
	return prev[N];
}
int main(){
 	int n, i, a[20], price; 
 	cin >> n; 
 	for(i = 0; i < n; i++){
 		cin >> a[i];
 	}
 	price = getWoodPiece(a, n);
 	cout << "maximum price is " << price << "\n";
 	return 0;
 	
  	return 0; 
}