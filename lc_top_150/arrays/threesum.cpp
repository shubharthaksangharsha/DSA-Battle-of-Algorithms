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

const vector<vector<int>> f(const vector<int>&arr){
        set<vector<int> >st; 
        for(int i = 0; i < arr.size(); i++){
            for(int j = i + 1; j < arr.size(); j++){
                for(int k = j + 1; k < arr.size(); k++){
                    int sum = arr[i] + arr[j] + arr[k];
                    if( sum == 0){
                        vector<int>temp ={arr[i], arr[j], arr[k]}; 
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
        vector<vector<int> > res(st.begin(), st.end());
        return res;
}
const vector<vector<int>> f2(const vector<int>&arr){
        set<vector<int>>st;  
        for(int i = 0; i < arr.size(); i++){
            set<int>st2;
            for(int j = i + 1; j < arr.size(); j++){
                int req = -(arr[i] + arr[j]);
                if(st2.find(req) != st2.end()){
                    vector<int>temp = {arr[i], arr[j], req};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                st2.insert(arr[j]);
            }
        }
        vector<vector<int> > res(st.begin(), st.end());
        return res;
}
const vector<vector<int>> f3(vector<int>&arr){
        sort(arr.begin(), arr.end());
        set<vector<int>>st;
        for(int i = 0; i < arr.size(); i++){
            if(i > 0 && arr[i] == arr[i - 1]){
                continue;
            }
            int j = i + 1, k = arr.size() - 1; 
            while(j < k){
                int sum = arr[i] + arr[j] + arr[k]; 
                if(sum == 0){
                    vector<int>temp = {arr[i], arr[j], arr[k]};
                    st.insert(temp);
                    j++; k--; 
                    while(j < k && arr[j] == arr[j-1]) {
                        j++;
                    }
                    while(j < k && arr[k] == arr[k+1]){
                        k--;
                    }
                } else if (sum < 0){
                    j++;
                } else{
                    k--; 
                }
            }
        }
        vector<vector<int>>res(st.begin(), st.end());
        return res;
}

const vector<vector<int>> solve(vector<int>&arr){
	 return f3(arr);
        // return f2(arr); //TLE
        // return f(arr);  //TLE
}
int main(){
 	int n; cin >> n; 
 	vector<int>arr(n); 
 	input(arr); 
 	vector<vector<int>>res = solve(arr);
 	for(auto i: res){
 		for(auto j: i){
 			cout << j << " ";
 		}
 		cout << endl;
 	}
    return 0; 
}