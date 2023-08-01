//Author - Shubharthak Sangharasha
/*
    Description: 
*/

#include<bits/stdc++.h> 
using namespace std; 
int const N = 10e6;

void input(vector<vector<int> >&points){
	//input
	for(auto &i: points){
		for(auto &j: i){
			cin >> j; 
		}
	} 
}

void print(const vector<vector<int> >&arr){
	//print
  	for(auto const i: arr){
  		for(auto const j: i){
  			cout << j << " ";
  		}
  		cout << endl;
  	}
}
//Recursion
int f1(int day, int last, vector<vector<int> >&points){
	//base case 
	if(day == 0){
		int maxi = 0; 
		for(int task = 0; task < 3; task++){
			if (task != last){
				maxi = max(maxi, points[0][task]);
			}
		}
		return maxi;
	}

	int maxi = 0; 
	for(int task = 0; task < 3; task++){
		if(task != last){
			int point = points[day][task] + f1(day -1, task, points);
			maxi = max(point, maxi);
		}
	}
	return maxi;
}

int f2(int day, int last, vector<vector<int> >&points, vector<vector<int> >&dp){
	//base case 
	if(day == 0){
		int maxi = 0; 
		for(int task = 0; task < 3; task++){
			if (task != last){
				maxi = max(maxi, points[0][task]);
			}
		}
		return maxi;
	}
	if(dp[day][last] != -1){
		return dp[day][last];
	}
	int maxi = 0; 
	for(int task = 0; task < 3; task++){
		if (task != last){
			int point = points[day][task] + f2(day -1, task, points, dp);
			dp[day][last] = maxi = max(maxi, point);
		}
	}
	return dp[day][last] = maxi;
}

//tabulation 
int f3(int day, int last, vector<vector<int> >&points, vector<vector<int> >&dp){

}

int ninja_task(int n, vector<vector<int> >&points){
	vector<vector<int> >dp(n, vector<int>(4, -1));
	return f2(n -1, 3, points, dp);
	return f1(n -1, 3, points);
}
int main(){
	int row; cin >> row;
	vector<vector<int> > points(row, vector<int>(3));
	input(points); 
	cout << ninja_task(row, points);
	// print(points);

	
    return 0; 
}