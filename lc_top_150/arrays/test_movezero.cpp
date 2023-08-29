#include<iostream>
#include<vector>


using namespace std;


void swapme(vector<int>&arr, int i, int j){
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}
void input(vector<int>&arr){
  for(auto &i: arr){
    cin >> i;
  }
}
void print(const vector<int>&arr){
  for(const auto i: arr){
    cout << i << " ";
  }
  cout << endl;
}

vector<int> moveZerosToEnd(vector<int>& arr)
{
	int k = 0; 
  while(arr[k] != 0){
    k++;
    break;
  }
  for(int i = k+1; i < arr.size(); i++){
    	if(arr[i] != 0){
        cout << i << " " << k << endl;
        swap(arr[i], arr[k++]);
      }
  }
  return arr;
}

int main() 
{
  int n; cin >> n; 
  vector<int>arr(n);
  input(arr);
  const vector<int>ans = moveZerosToEnd(arr);
  print(ans);
	return 0;
}
