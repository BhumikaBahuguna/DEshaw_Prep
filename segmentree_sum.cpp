#include<bits/stdc++.h>
using namespace std;
int getmid(int s,int e){
    return s+(e-s)/2;
}
int getsumutil(int *st,int ss,int se,int qs,int qe,int si){
    if(qs <= ss && qe >= se) {
        return st[si];
    }
    if(se < qs || ss > qe) {
        return 0;
    }
    int mid = getmid(ss, se);
    return getsumutil(st, ss, mid, qs, qe, 2 * si + 1) + getsumutil(st, mid + 1, se, qs, qe, 2 * si + 2);
}
void updateutil(int *st, int ss, int se, int i, int diff, int si) {
    if(i < ss || i > se) {
        return;
    }
    st[si] += diff;
    if(se != ss) {
        int mid = getmid(ss, se);
        updateutil(st, ss, mid, i, diff, 2 * si + 1);
        updateutil(st, mid + 1, se, i, diff, 2 * si + 2);
    }
}
void update(int arr[] ,int *st, int n, int i, int new_val) {
    if(i < 0 || i > n-1) {
        cout << "Index out of bounds" << endl;
        return;
    }
    int diff = new_val - arr[i];
    arr[i] = new_val;
    updateutil(st, 0, n - 1, i, diff, 0);
}
int getsum(int *st, int n, int qs, int qe) {
    if(qs < 0 || qe > n - 1 || qs > qe) {
        cout << "Invalid range" << endl;
        return -1;
    }
    return getsumutil(st, 0, n - 1, qs, qe, 0) ;
}
int constructSTUtil(int arr[], int ss, int se, int *st, int si) {
    if(ss == se) {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getmid(ss, se);
    st[si] = constructSTUtil(arr, ss, mid, st, 2 * si + 1) + constructSTUtil(arr, mid + 1, se, st, 2 * si + 2);
    return st[si];
}
int *constructST(int arr[], int n) {
    int x = (int)(ceil(log2(n)));
    int max_size = 2 * (int)pow(2, x) - 1;
    int *st = new int[max_size];
    constructSTUtil(arr, 0, n - 1, st, 0);
    return st;
}
int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;  
    int *arr=new int[n];
    cout << "Enter the elements: "; 
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int *st = constructST(arr, n);
    cout << "Segment Tree constructed successfully." << endl;
    cout << "sum in range [1, 3]: " << getsum(st, n, 1, 3) << endl;
    update(arr, st, n, 2, 10);
    cout << "After updating index 2 to 10, sum in range [1, 3]: " << getsum(st, n, 1, 3) << endl;
    return 0;
}