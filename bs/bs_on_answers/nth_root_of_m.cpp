
//Author - Shubharthak Sangharasha
/*
    Description: Find the nth root of m. (for e.g.: n = 3, m = 27, ans = 3(3 * 3 * 3 = 27))
*/


#include<bits/stdc++.h> 
using namespace std; 
int const N = 10e6;

int f(int const mid, int const m, int const n){
    //return 1, if == m
    //return 0, if < m 
    //return 2, if > m
    long long int ans = 1; 
    for(int i = 1; i <= n; i++){
        ans *= mid;
        if (ans > m){
            return 2;
        }
    }
    if (ans == m){
        return 1;
    }
    return 0;
}
int NthRoot(int n, int m) {
    int low = 1; 
    int high = m; 
    while(low <= high){
        int mid = low + (high - low) / 2; 
        if(f(mid, m, n) == 1){
            return mid;
        } else if(f(mid, m, n) == 0){
            low = mid + 1;
        } else{
            high = mid - 1;
        }
    }
    return -1;
}

int main(){
 	int n; cin >> n;
 	int m; cin >> m; 
 	cout << NthRoot(n, m);
 	
  	return 0; 
}