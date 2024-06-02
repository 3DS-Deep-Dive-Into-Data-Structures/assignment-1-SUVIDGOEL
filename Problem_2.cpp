#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, sum; cin >> n >> sum;
    pair<int, int> arr[n];
    for (int i = 0; i < n; ++i) {//O(N)
        int a; cin >> a;
        arr[i] = {a, i};
    }
    sort(arr, arr+n); //O(N*LOG(N))

    bool val1=false;
    for (int i = 0; i < n-2; ++i) { //O(N^2)
        int j=i+1,k=n-1;
        bool val=false;
        while(j<k){
            if(arr[j].first+arr[k].first>sum-arr[i].first) k--;
            else if(arr[j].first+arr[k].first<sum-arr[i].first) j++;
            else {
                cout << arr[i].second + 1 << " " << arr[j].second + 1 << " " << arr[k].second + 1;
                val=true;
                break;
            }
        }
        if(val==true) {
            val1= true;
            break;
        }
    }
    if(val1 == false){
        cout << "IMPOSSIBLE";
    }
}
