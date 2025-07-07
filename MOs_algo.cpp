#include<bits/stdc++.h>
using namespace std;
int block;
struct query{
    int l,r;
};
bool compare(query x, query y){
    if(x.l/block != y.l/block) return x.l/block < y.l/block;
    return x.r < y.r;
}
void queryresults(int a[], int n, query q[], int m) {
    block = (int)sqrt(n);
    sort(q, q + m, compare);
    //vector<int> ans(m);
    int curr_l = 0, curr_r = 0;
    //vector<int> freq(1000001, 0);
    int curr_sum = 0;
    for(int i = 0; i < m; i++) {
        int L=q[i].l;
        int R=q[i].r;
        while(curr_l <L){
            curr_sum -= a[curr_l];
            curr_l++;
        }
        while(curr_l > L) {
            curr_sum += a[curr_l];
            curr_l--;
        }
        while(curr_r <= R) {
            curr_sum += a[curr_r];
            curr_r++;
        }
        while(curr_r > R + 1) {
            curr_sum -= a[curr_r - 1];
            curr_r--;
        }
        cout << "Sum of range [" << L << ", " << R << "] is: " << curr_sum << endl;
    }
}
int main(){
    int n, m;
    cout << "Enter number of elements in array: ";
    cin >> n;
    int a[n];
    cout << "Enter elements of array: ";
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << "Enter number of queries: ";
    cin >> m;
    query q[m];
    cout << "Enter queries (l r):" << endl;
    for(int i = 0; i < m; i++) {
        cin >> q[i].l >> q[i].r;
    }
    queryresults(a, n, q, m);
    return 0;
}