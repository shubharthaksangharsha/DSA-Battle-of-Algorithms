
//Author - Shubharthak Sangharasha
/*
    Description: Find square root of number in logn TC 
*/


#include<bits/stdc++.h> 
using namespace std; 
int const N = 10e6;

int floorSqrt(int n)
{
    int low = 1; 
    int high = n; 
    while(low <= high){
        long long mid = low + (high - low ) / 2; 
        long long val = (mid * mid);
        if (val <= n){
            low = mid + 1;
        } else{
            high = mid - 1;
        }
    }
    return high;
}


int main(){
 	int n; cin >> n;
	cout << floorSqrt(n) << endl;
  	return 0; 
}