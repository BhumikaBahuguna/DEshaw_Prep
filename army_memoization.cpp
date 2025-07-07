#include<bits/stdc++.h>
using namespace std;
int armyBreak(int n,vector<int>& dp){
    if(dp[n]!=-1) return dp[n]; //if already computed
    if(n==1)
        return 0; //base case
    int mini=1+ armyBreak(n-1,dp); //break one soldier
    if(n%2==0){
        mini=min(mini,1+armyBreak(n/2,dp)); //break half the soldiers
    }
    if(n%3==0){
        mini=min(mini,1+armyBreak(n/3,dp)); //break one third of the soldiers
    }
    return dp[n]=mini; //store the result in dp array
}
int main(){
    int n;
    cout << "Enter the number of soldiers in the army: ";
    cin >> n;
    vector<int> dp(n+1, -1); //dp array to store results
    int result = armyBreak(n, dp);
    cout << "Minimum number of breaks required to reduce the army to 1 soldier: " << result << endl;
    return 0;
}