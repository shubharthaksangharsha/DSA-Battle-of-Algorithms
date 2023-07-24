#include <iostream>
#include <vector>
using namespace std;

vector<string> solve(string digits, string output, int index, vector<string>& ans, string* mapping) {

}

vector<string> letterCombinations(string digits) {
    string output; 
    string mp[] = {
                "", "", "abc", "def", "ghi", "jkl"; 
    }    
    
}

void print(const vector<string>& arr) {
    for (const string& s : arr) {
        cout << s << " ";
    }
    cout << endl;
}

int main() {
    string s;
    cin >> s;
    vector<string> ans = letterCombinations(s);
    print(ans);

    return 0;
}
