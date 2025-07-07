#include <bits/stdc++.h>
using namespace std;
int eggdrop(int e, int f) {
    vector<vector<int>> dp(e + 1, vector<int>(f + 1, 0));
    // Base cases:
    for (int i = 1; i <= e; i++) {
        dp[i][0] = 0; // 0 floors -> 0 attempts
        dp[i][1] = 1; // 1 floor  -> 1 attempt
    }
    for (int j = 1; j <= f; j++) {
        dp[1][j] = j; // 1 egg -> j attempts (worst case linear search)
    }
    // Fill the rest of the table
    for (int i = 2; i <= e; i++) {
        for (int j = 2; j <= f; j++) {
            dp[i][j] = INT_MAX;

            for (int k = 1; k <= j; k++) {
                int temp = 1 + max(dp[i - 1][k - 1], dp[i][j - k]);
                dp[i][j] = min(dp[i][j], temp);
            }
        }
    }
    return dp[e][f];
}
int main() {
    int e, f;
    cout << "Enter number of eggs: ";
    cin >> e;
    cout << "Enter number of floors: ";
    cin >> f;
    int result = eggdrop(e, f);
    cout << "Minimum number of attempts required to find the critical floor: " << result << endl;
    return 0;
}