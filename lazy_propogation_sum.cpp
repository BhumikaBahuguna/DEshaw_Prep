#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int tree[MAX]={0};//to store seg tree
int lazy[MAX]={0};//to store pending updates
void Updaterangeutil(int si,int ss,int se,int us,int ue,int diff){
    if(lazy[si]!=0){
        tree[si] += (se-ss+1) * lazy[si]; //update the node
        if(ss != se){ //not a leaf node
            lazy[2*si+1] += lazy[si]; //mark children as lazy
            lazy[2*si+2] += lazy[si];
        }
        lazy[si] = 0; //clear the lazy value
    }
    if(ss>se ||ss>ue || se<us) return; //out of range
    if(ss>=us && se<=ue){ //current segment is fully in range
        tree[si] += (se-ss+1) * diff; //update the node
        if(ss != se){ //not a leaf node
            lazy[2*si+1] += diff; //mark children as lazy
            lazy[2*si+2] += diff;
        }
        return;
    }
    int mid = (ss + se) / 2; //find mid
    Updaterangeutil(2*si+1, ss, mid, us, ue, diff); //update left child
    Updaterangeutil(2*si+2, mid+1, se, us, ue, diff); //update right child
    tree[si] = tree[2*si+1] + tree[2*si+2]; //update current node
}
void Updaterange(int n, int us, int ue, int diff){
    Updaterangeutil(0, 0, n-1, us, ue, diff);
}
int getsumutil(int ss, int se, int qs, int qe,int si){
    if(lazy[si] != 0){ //check for pending updates
        tree[si] += (se-ss+1) * lazy[si]; //update the node
        if(ss != se){ //not a leaf node
            lazy[2*si+1] += lazy[si]; //mark children as lazy
            lazy[2*si+2] += lazy[si];
        }
        lazy[si] = 0; //clear the lazy value
    }
    if(ss > se || ss > qe || se < qs) return 0; //out of range
    if(ss >= qs && se <= qe) return tree[si]; //current segment is fully in range
    int mid = (ss + se) / 2; //find mid
    return getsumutil( ss, mid, qs, qe,2*si+1) + getsumutil(mid+1, se, qs, qe,2*si+2); //sum of left and right children
}
int getsum(int n, int qs, int qe){
    if(qs<0 || qe>n-1 || qs>qe){
        cout << "Invalid range" << endl;
        return -1; //invalid range
    }
    return getsumutil(0, n-1, qs, qe, 0);
}
void constructSTutil(int arr[],int ss, int se, int si){
    if(ss>se) return; //invalid range
    if(ss == se){ //leaf node
        tree[si] = arr[ss];
        return;
    }
    int mid = (ss + se) / 2; //find mid
    constructSTutil(arr, ss, mid, 2*si+1); //left child
    constructSTutil(arr, mid+1, se, 2*si+2); //right child
    tree[si] = tree[2*si+1] + tree[2*si+2]; //update current node
}
void costructST(int arr[], int n){
    constructSTutil(arr, 0, n-1, 0);
}
int main(){
    int n, q;
    cout << "Enter number of elements in array: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements of array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    costructST(arr, n);
    
    cout<<"sum of range [0, 3]: " << getsum(n, 0, 3) << endl;
    Updaterange(n, 1, 3, 10); //update range [1, 3] by adding 10
    cout<<"sum of range [0, 3] after update: " << getsum(n, 0, 3) << endl;
    return 0;
}