#include<bits/stdc++.h>
using namespace std;
int eggdrop(int e,int f){
    if(f==0||f==1)
        return f;
    if(e==1)
        return f;
    int mini=INT_MAX;
    for(int k=1;k<=f;k++){
        int temp=1+max(eggdrop(e-1,k-1),eggdrop(e,f-k));
        mini=min(mini,temp);
    }
    return mini;
}
int main(){
    int e,f;
    cout << "Enter number of eggs: ";
    cin >> e;
    cout << "Enter number of floors: ";
    cin >> f;
    int result = eggdrop(e, f);
    cout << "Minimum number of attempts required to find the critical floor: " << result << endl;
    return 0;
}