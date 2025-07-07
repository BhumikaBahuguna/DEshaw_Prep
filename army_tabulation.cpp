#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<< "Enter the number of soldiers in the army: ";
    cin>>n;
    vector<int> dp(n+1,INT_MAX);
        dp[1]=0;
    for(int i=2;i<=n;i++){
        dp[i]=1+dp[i-1]; //break one soldier
        if(i%2==0){
            dp[i]=min(dp[i],1+dp[i/2]); //break half the soldiers
        }
        if(i%3==0){
            dp[i]=min(dp[i],1+dp[i/3]); //break one third of the soldiers
        }
    }
    //return dp[n]; //return the minimum breaks required to reduce the army to 1 soldier
    cout << "Minimum number of breaks required to reduce the army to 1 soldier: " << dp[n] << endl;
    return 0;
}