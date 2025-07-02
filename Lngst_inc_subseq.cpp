#include<bits/stdc++.h>
using namespace std;
int longest_inc_subseq(vector<char> &arr,int i,int prev){
    if(i==arr.size())
        return 0;
    int len=longest_inc_subseq(arr,i+1,prev);//not take 
    if(prev==-1||arr[i]>arr[prev]){
        len=max(len,1+longest_inc_subseq(arr,i+1,i));
    }
    return len;
}
int main(){
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<char> arr(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int result = longest_inc_subseq(arr,0, -1);
    cout << "Length of the longest increasing subsequence is: " << result << endl;
    return 0;
}
