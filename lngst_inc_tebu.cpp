#include<bits/stdc++.h>
using namespace std;
int lis(vector<int>& arr) {
    int n=arr.size();
    if(n == 0) return 0; // Handle empty array case
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0)); // dp array to store results
    for(int i=n-1;i>=0;i--){
        for(int prev=i-1;prev>=-1;prev--){
            int len = dp[i+1][prev+1]; // Not take
            if(prev == -1 || arr[i] > arr[prev]) {
                len = max(len, 1 + dp[i+1][i+1]); // Take
            }
            dp[i][prev+1] = len; // Store the result in dp array
        }
    }
    return dp[0][0];
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
    int result = lis(arr);
    cout << "Length of the longest increasing subsequence is: " << result << endl;
    return 0;
}