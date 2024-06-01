#include <bits/stdc++.h>
using namespace std;

int arr[100000];
double min_in[100000][17];
double max_in[100000][17];
double left_max[100000];
double right_max[100000];


double query(int l , int r){
    int len = r-l+1;
    int lg=0;
    while(len!=1){
        lg++;
        len/=2;
    }
    double op1 = (min(min_in[l][lg], min_in[r-(1<<lg)+1][lg]) + max(max_in[l][lg], max_in[r-(1<<lg)+1][lg]))/2;
    double op2 = min(min_in[l][lg], min_in[r-(1<<lg)+1][lg]) + max(left_max[l], right_max[r]);
    //cout << op1 << " "<< op2 << "\n";
    return max(op1, op2);
}

int main() {
    int n;
    cin >> n;
    stack<int> s;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        min_in[i][0] = arr[i];
        max_in[i][0] = arr[i];
    }
    s.push(0);
    left_max[0] = 0;
    for(int i= 1;i<n;i++){
        if(arr[i]<arr[s.top()]){
            left_max[i] = arr[s.top()];
        }
        else{
            left_max[i] = arr[s.top()];
            s.pop();
            s.push(i);
        }
    }
    stack<int> s1;
    s1.push(n-1);
    right_max[n-1] = 0;
    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[s1.top()]){
            right_max[i] = arr[s1.top()];
        }
        else{
            right_max[i] = arr[s1.top()];
            s1.pop();
            s1.push(i);
        }
    }
    for(int j=1;j<=17;j++){
        for(int i=0; i+ (1<<j)-1<=n-1;i++){
            min_in[i][j] = min(min_in[i][j-1], min_in[i+(1<<(j-1))][j-1]);
            max_in[i][j] = max(max_in[i][j-1], max_in[i+(1<<(j-1))][j-1]);
        }
    }

    int q;
    cin >> q;
    while(q--){
        int l,r;
        cin >> l >> r;
        double quer = query(l,r);
        cout << fixed << setprecision(1)<< quer << "\n";
    }
    //cout << INT_MIN;
}
