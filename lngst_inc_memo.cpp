#include<bits/stdc++.h>
using namespace std;
int lis(int i ,int prev, vector<int>& arr, vector<vector<int>>& dp) {
    if (i == arr.size())
        return 0;
    if (dp[i][prev + 1] != -1)
        return dp[i][prev + 1]; // Return already computed value
    int len = lis(i + 1, prev, arr, dp); // Not take
    if (prev == -1 || arr[i] > arr[prev]) {
        len = max(len, 1 + lis(i + 1, i, arr, dp)); // Take
    }
    return dp[i][prev + 1] = len; // Store the result in dp array
}
int main(){
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<vector<int>> dp(n, vector<int>(n + 1, -1)); // dp array to store results
    int result = lis(0, -1, arr, dp);
    cout << "Length of the longest increasing subsequence is: " << result << endl;
    return 0;
}