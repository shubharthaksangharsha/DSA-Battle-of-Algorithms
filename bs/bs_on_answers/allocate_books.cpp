//Author - Shubharthak Sangharasha
/*
    Description: 
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
int count_students(const vector<int>&arr, const int pages){
	int student = 1; 
	int val = 0; 
	for(int i = 0; i < arr.size(); i++){
		if(val + arr[i] <= pages){
			val += arr[i];
		} else{
			student++;
			val = arr[i];
		}
	}
	return student;
}
int solve(const vector<int>&arr, int const students, int const n){
	//linear search 
	int low = *max_element(arr.begin(), arr.end());
	int high = accumulate(arr.begin(), arr.end(), 0);
	// for(int pages = low; pages < high; pages++){
	// 	int no_of_students = count_students(arr, pages);
	// 	if(no_of_students == students){
	// 		return pages;
	// 	}
	// }
	//binary search
	while(low <= high){
		int mid = low + (high - low )/ 2; 
		int no_of_students = count_students(arr, mid);
		if(no_of_students > students){
			low = mid + 1;
		} else{
			high = mid - 1;
		}
	}	
	return low;
}
int main(){
 	int n; cin >> n; 
 	vector<int>arr(n); 
 	input(arr); 
 	int students; cin >> students;
 	cout << solve(arr, students, n);
 	// print(arr);
    return 0; 
}