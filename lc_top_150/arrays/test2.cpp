//Author - Shubharthak Sangharasha
/*
    Description: 
*/

#include<bits/stdc++.h> 
using namespace std; 


void input(vector<vector<string>>&arr){
	for(auto &i: arr){
		for(auto &j : i){
			cin >> j; 
		}
	}
}

void print(const vector<vector<string>>&arr){
	for(auto const i: arr){
		for(auto const j: i){
			cout << j << " ";
		}
		cout << endl;
	}
}

bool check_date(string date){
	string year = date.substr(0, 4);
	bool leap=false;
	if(stoi(year) % 4 == 0){
		leap = true;
	}
	string month = date.substr(5, 2);
	if(stoi(month) > 12 || stoi(month) <= 0){
		return false;
	}
	string day = date.substr(8, 2);
	int temp  = stoi(day);
	if(temp > 31 || temp < 1){
		return false;
	}
	if(stoi(month) != 2){
		return true;
	}
	if(leap && temp == 29){
		return true;
	}
	if(temp <= 28 && temp >= 1){
		return true;
	}
	return false;
}
bool check_time(string time){
	if(time == "24:00:00"){
		return true;
	}
	if(stoi(time.substr(0, 2)) < 0 || stoi(time.substr(0, 2)) >= 24){
		return false;
	}
	if(stoi(time.substr(3, 2)) <= 0 && stoi(time.substr(3, 2)) >= 60){
		return false;
	}
	if(stoi(time.substr(6, 2)) <= 0 && stoi(time.substr(6, 2)) >= 60){
		return false;
	}
	return true;
}
vector<vector<string>> countUserLogins(vector<vector<string>>logs){
	sort(logs.begin(), logs.end());
	for(int i = 0; i < logs.size(); i++){
 		for(int j = 0; j < logs[i].size(); j++){
 			cout << logs[i][j] << " ";
 		}
 		cout << endl;
 	}
	cout << "sorted end" << endl;
	int n = logs.size(); 
	vector<vector<string>>ans;
	string user="user9876",date="123456";
	int cnt=0;
	for(auto it:logs){
		if(!check_time(it[1])||!check_date(it[2])){
			continue;
		}
		if(it[0]==user){
			if(date==date) cnt++;
			else{
				if(cnt!=0){
					vector<string>temp = {user, date, to_string(cnt)};
					ans.push_back(temp);
					
				}
				date=it[2];
				cnt = 1;
			}
		}
		else{
			if(cnt!=0){
				vector<string>temp = {user, date, to_string(cnt)};
				ans.push_back(temp);
			}
			user=it[0];
			date=it[2];
			cnt=1;
		}
	}
	if(cnt!=0){
		vector<string>temp = {user, date, to_string(cnt)};
		ans.push_back(temp);
	}
	return ans;
}

int main(){
 	int m, n;
 	cin >> m >> n; 
 	vector<vector<string> >arr ={
 		{"user1", "09:00:00", "2021-01-01"},
 		{"user2", "14:00:00", "2021-01-01"},
 		{"user1", "20:00:00", "2021-01-01"},
 		{"user2", "21:00:00", "2021-01-01"},
 		{"user3", "25:00:00", "2021-01-01"},
 		{"user4", "22:00:00", "2021-02-29"},
 		{"user1", "13:00:00", "2021-01-01"}
 			
 	};
 	vector<vector<string>> ans = countUserLogins(arr);
 	for(int i = 0; i < ans.size(); i++){
 		for(int j = 0; j < ans[i].size(); j++){
 			cout << ans[i][j] << " ";
 		}
 		cout << endl;
 	}
    return 0; 
}