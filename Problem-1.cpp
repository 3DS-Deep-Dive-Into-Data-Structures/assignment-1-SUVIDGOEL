#include <iostream>
#include <vector>
#include <climits>
#include <set>

using namespace std;

int main(){
    int n,a,b;
    cin >> n >> a >> b;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    long long pr_sum[n];
    pr_sum[0]=arr[0];
    for (int i = 1; i < n; ++i) {
        pr_sum[i]=pr_sum[i-1]+arr[i];
    }
    set<pair<long long, int>> s;
    for (int i = a-1; i < b; ++i) {
        s.insert({pr_sum[i], i});
    }
    long long ans=-1e15;
    for (int i = 0; i+a-1 <= n-1; ++i) {
        ans = max(ans, s.rbegin()->first-((i==0)?0:pr_sum[i-1]));
        s.erase({pr_sum[i+a-1], i+a-1});
        if(i+b<=n-1){
            s.insert({pr_sum[i+b], i+b});
        }
        //cout << ans <<"\n";
    }
    cout << ans;
}
