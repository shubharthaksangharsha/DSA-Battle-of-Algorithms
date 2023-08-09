//Author - Shubharthak Sangharasha
/*
    Description: Find no.of triplets can be there such that {arr[i] + arr[j] + arr[k]} = 0
*/

#include<bits/stdc++.h> 
using namespace std; 
int const N = 10e6;

void input(vector<int>&arr){
	for(auto &i: arr){
		cin >> i; 
	}
}

void print(const vector<int>&arr){
	for(auto const i: arr){
		cout << i << " ";
	}
	cout << endl;
}

vector<vector<int>> fourSum(vector<int>& arr, int target) {
        //O(N^3), sc: O(no.of.quadriplets)
        vector<vector<int>>res;
        sort(arr.begin(), arr.end()); 
        for(int i = 0; i < arr.size(); i++){
            if (i > 0 && arr[i] == arr[i - 1]){
                continue;
            }
            for(int j = i + 1; j < arr.size(); j++){
                if(j != (i + 1) && arr[j] == arr[j - 1]){
                    continue;
                }
                int k = j + 1, l = arr.size() - 1; 
                while(k < l){
                    long long sum = arr[i] + arr[j];
                    sum += arr[k];
                    sum += arr[l];
                    if(sum == target){
                        vector<int>temp = {arr[i], arr[j], arr[k], arr[l]};
                        res.push_back(temp);
                        k++; l--; 
                        while(k < l && arr[k] == arr[k-1]){
                            k++;
                        }
                        while(k < l && arr[l] == arr[l + 1]){
                            l--;
                        }
                    } else if(sum < target){
                        k++;
                    } else{
                        l--;
                    }
                }
                
            }
        }
        return res;
}
const vector<vector<int>> solve(vector<int>&arr, int target){
	 return fourSum(arr, target);
        // return f2(arr); //TLE
        // return f(arr);  //TLE
}
int main(){
 	int n; cin >> n; 
 	vector<int>arr(n); 
 	input(arr); 
    int target; cin >> target;
 	vector<vector<int>>res = solve(arr, target);
 	for(auto i: res){
 		for(auto j: i){
 			cout << j << " ";
 		}
 		cout << endl;
 	}
    return 0; 
}