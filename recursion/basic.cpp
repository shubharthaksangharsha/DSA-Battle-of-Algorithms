#include<bits/stdc++.h> 
using namespace std; 
int const N = 10e6;

int fact(int n){
    if (n == 0){
        return 1; 
    }
    return fact(n - 1) * n;
}
int main(){
     int t; 
     cin >> t; 
     while(t--){
        int n; 
        cin >> n; 
        cout << fact(n) << endl;
     }
      return 0; 
}