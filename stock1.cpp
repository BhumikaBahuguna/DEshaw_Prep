#include<bits/stdc++.h>
using namespace std;
int maxprofit(vector<int>&prices){
    int mini=prices[0];
    int maxprofit=0;
    int n=prices.size();
    for(int i=1;i<n;i++){
        int cost=prices[i]-mini;
        maxprofit=max(maxprofit,cost);
        mini=min(mini,prices[i]);
    }
    return maxprofit;
}
int main(){
    int n;
    cout << "Enter the number of days: ";
    cin >> n;
    vector<int> prices(n);
    cout << "Enter the stock prices for each day: ";
    for(int i = 0; i < n; i++){
        cin >> prices[i];
    }
    int result = maxprofit(prices);
    cout << "Maximum profit that can be made is: " << result << endl;
    return 0;
}