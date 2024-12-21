#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    int n; cin>>n;
    vector<vector<int>> a(n);
    vector<int> sz(n);
    for(int i = 0; i < n; ++i) cin>>sz[i];

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < sz[i]; ++j){
            int x; cin>>x;
            a[i].push_back(x);
        }
    }

    int ans = 1e9;
    if (n >= 3){
        int s1 = min(sz[0], sz[1]);
        int s2 = min(sz[0], sz[2]);
        int res = 0;
        for(int i = 0; i < s1; ++i){
            res += a[0][i] == a[1][i];
        }
        for(int i = 0; i < s2; ++i){
            res += a[0][i] == a[2][i];
        }
        ans = min(ans, res);

        // cout<<"\t"<<res<<endl;

        res = 0;
        s1 = min(sz[n-1], sz[n-2]);
        s2 = min(sz[n-1], sz[n-3]);
        for(int i = 0; i < s1; ++i){
            res += a[n-1][i] == a[n-2][i];
        }
        for(int i = 0; i< s2; ++i){
            res += a[n-1][i] == a[n-3][i];
        }

        // cout<<"\t"<<res<<endl;

        ans = min(res, ans);
    }else{
        int s = min(sz[0], sz[1]);
        int res = 0;
        for(int i = 0; i < s; ++i){
            res += a[0][i] == a[1][i];
        }
        ans = min(ans, res);
    }

    cout<<ans<<endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; t = 1;
    while (t--){
        solve();
    }

    return 0;
}