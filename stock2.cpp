#include<bits/stdc++.h>
using namespace std;
int func(int i, int buy, vector<int>& arr, int n) {
    if(i == n)
        return 0;

    int profit = 0;
    if(buy) {
        profit = max({
            -arr[i] + func(i + 1, 0, arr, n),
            0 + func(i + 1, 1, arr, n)
        });
    } else {
        profit = max({
            arr[i] + func(i + 1, 1, arr, n),
            0 + func(i + 1, 0, arr, n)
        });
    }
    return profit;
}
int main(){
    int n;
    cout << "Enter the number of days: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the stock prices for each day: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int profit = func(0,1,arr,n); // Start with buying
    cout << "Maximum profit that can be made is: " << profit << endl;
    return 0;
}