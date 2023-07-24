#include <iostream>
#include <vector>
using namespace std;

vector<string> solve(string digits, string output, int index, vector<string>& ans, string* mapping) {
    // Base case
    if (index == digits.size()) {
        ans.push_back(output);
        return ans;
    }
    int number = digits[index] - '0';
    string value = mapping[number];
    for (int i = 0; i < value.length(); i++) {
        output.push_back(value[i]);
        solve(digits, output, index + 1, ans, mapping);
        output.pop_back(); // Backtracking
    }
    return ans;
}

vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if (digits.length() == 0) {
        return ans;
    }

    string mapping[10] = {"", "", "abc", "def",
                          "ghi", "jkl", "mno", "pqrs",
                          "tuv", "wxyz"};

    string output;
    int index = 0;

    return solve(digits, output, index, ans, mapping);
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
