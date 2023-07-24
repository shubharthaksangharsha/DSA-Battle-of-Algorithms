//https://cses.fi/problemset/task/1634/

/*
Bottom Up 

#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1e6;
const int M = 1e9 + 7;

int dp[MAX_N + 1];
int coins[MAX_N];

int result(int n, int k) {
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = INT_MAX;
        for (int j = 0; j < k; j++) {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    return (dp[n] == INT_MAX) ? -1 : dp[n];
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> coins[i];
    }
    cout << result(n, k) << endl;
    return 0;
}
*/
//Top Down
#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1e6;
const int M = 1e9 + 7;

int dp[MAX_N + 1];
int coins[MAX_N];

int result(int n, int k) {
    if (n == 0) {
        return 0;
    }

    if (dp[n] != -1) {
        return dp[n];
    }

    int minCoins = INT_MAX;
    for (int i = 0; i < k; i++) {
        if (n - coins[i] >= 0) {
            int subproblem = result(n - coins[i], k);
            if (subproblem != -1 && subproblem < minCoins) {
                minCoins = subproblem + 1;
            }
        }
    }

    dp[n] = (minCoins == INT_MAX) ? -1 : minCoins;
    return dp[n];
}

int main() {
    int k, n;
    cin >> k >> n;
    for (int i = 0; i < k; i++) {
        cin >> coins[i];
    }

    memset(dp, -1, sizeof(dp)); // Initialize dp array with -1
    cout << result(n, k) << endl;
    return 0;
}
