#include<bits/stdc++.h>
using namespace std;
int eggdrop(int e, int f, vector<vector<int>>& dp) {
    if (f == 0 || f == 1)
        return f;
    if (e == 1)
        return f;
    int mini=INT_MAX;
    if (dp[e][f] != -1)
        return dp[e][f]; // Return already computed value
    for (int k = 1; k <= f; k++) {
        int temp = 1 + max(eggdrop(e - 1, k - 1, dp), eggdrop(e, f - k, dp));
        mini = min(mini, temp);
    }
    return dp[e][f] = mini; // Store the result in dp array
}
int main(){
    int e, f;
    cout << "Enter number of eggs: ";
    cin >> e;
    cout << "Enter number of floors: ";
    cin >> f;
    vector<vector<int>> dp(e + 1, vector<int>(f + 1, -1)); // dp array to store results
    int result = eggdrop(e, f, dp);
    cout << "Minimum number of attempts required to find the critical floor: " << result << endl;
    return 0;
}