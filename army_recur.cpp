#include<bits/stdc++.h>
using namespace std;
int breakArmy(int n){
    if(n==1)
        return 0;
    int mini=1+ breakArmy(n-1);
    if(n%2==0){
        mini=min(mini,1+breakArmy(n/2));
    }
    if(n%3==0){
        mini=min(mini,1+breakArmy(n/3));
    }
    return mini;
}
int main(){
    int n;
    cout << "Enter the number of soldiers in the army: ";
    cin >> n;
    int result = breakArmy(n);
    cout << "Minimum number of breaks required to reduce the army to 1 soldier: " << result << endl;
    return 0;
}