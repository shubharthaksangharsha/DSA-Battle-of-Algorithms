#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

vector<vector<int>> dp;

int countCoinWays(int n, int x, vector<int>& coins) {
    if (x == 0) {
        return 1; // Base case: Sum is 0, so there is 1 way to make the sum (by not selecting any coin)
    }

    if (n == 0 || x < 0) {
        return 0; // Base case: No coins left or sum becomes negative, so no way to make the sum
    }

    if (dp[n][x] != -1) {
        return dp[n][x]; // If the value2023-07-04 is already computed, return it
    }

    // Exclude the current coin and move to the next coin
    int ways = countCoinWays(n - 1, x, coins) % MOD;

    // Include the current coin and subtract its value from the sum
    ways = (ways + countCoinWays(n, x - coins[n - 1], coins)) % MOD;

    dp[n][x] = ways; // Store the computed value for future use

    return ways;
}

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    dp.resize(n + 1, vector<int>(x + 1, -1)); // Initialize the DP array with -1

    int ways = countCoinWays(n, x, coins);
    cout << ways << endl;

    return 0;
}
