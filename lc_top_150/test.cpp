#include<bits/stdc++.h>
using namespace std; 
int countMeetings(vector<int> firstDay, vector<int> lastDay) {
    int ans = 0; 
    vector<pair<int, pair<int, int>>>v; 
    for(int i = 0; i < firstDay.size(); i++){
        v.push_back({lastDay[i] - firstDay[i], {firstDay[i], lastDay[i]}}); 
    }
    sort(v.begin(), v.end());
    set<int>s;
    for(int i = 1; i <= firstDay.size(); i++){
        s.insert(i);
    }
    for(auto i: v){
        int st = i.second.first;
        int ed = i.second.second;
        auto it = s.lower_bound(st);
        if(it  !=  s.end() && *it <= ed){
            ans++;
            s.erase(*it); 
        }
    }
    return ans;

}

int main() {
    int n; cin >> n; 
    vector<int>firstDay(n), lastDay(n);
    for(int i = 0; i < n; i++){
        cin >> firstDay[i];
    }
    for(int i = 0; i < n; i++){
        cin >> lastDay[i];
    }
    
    cout << countMeetings(firstDay, lastDay);
    return 0;
}
