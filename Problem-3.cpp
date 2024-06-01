#include<iostream>
using namespace std;

int main(){
    int n,q;
    cin >> n>>q;
    int arr[n];
    int prefix[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    prefix[0]=arr[0];
    for(int i=1;i<n;i++){
        prefix[i] = prefix[i-1]^arr[i];
    }
    while(q--){
        int l,r;
        cin >> l >> r;
        if(l-2==-1){
            cout<<prefix[r-1]<<"\n";
        }
        else{
            int ans = prefix[r-1]^prefix[l-2];
            cout << ans <<"\n";
        }
    }
}
