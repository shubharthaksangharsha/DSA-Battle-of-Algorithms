//Author - Shubharthak Sangharasha
/*
    Description: 
*/

#include<bits/stdc++.h> 
using namespace std; 
int const N = 10e6;

void input(vector<string>&arr){
	for(auto &i: arr){
		cin >> i; 
	}
}

void print(const vector<string>&arr){
	for(auto const i: arr){
		cout << i << " ";
	}
	cout << endl;
}
vector<string> preprocessData(vector<string> dates) {
    vector<string> res;

    unordered_map<string, string> monthMap = {
        {"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"},
        {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"},
        {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}
    };

    for(int i = 0; i < dates.size(); i++){
		string year, month, day; 
		string temp = dates[i];
		if(temp.size() % 2 == 0){
			day.push_back('0');
			day.push_back(temp[0]);
			month = monthMap[temp.substr(4, 3)];
			year = temp.substr(8, 4);

		} else{
			day.push_back(temp[0]);
			day.push_back(temp[1]);
			month = monthMap[temp.substr(5, 3)];
			year = temp.substr(9, 4);
		}
		string ans = year + "-" + month	+ "-" + day;
		res.push_back(ans);
    }
    return res;
}
int main(){
 	int n; cin >> n; 
 	std::vector<std::string> inputDates = {
        "6th Jun 1933", "22nd Jan 2013", "7th Apr 1904"
    };
 	// input(arr); 
 	vector<string> ans = preprocessData(inputDates);
 	print(ans);
    return 0; 
}