#include<bits/stdc++.h>
#define ll long long
using namespace std;

int mex(vector<int> &arr){
//   sort(arr.begin(), arr.end());
  int N = arr.size();
  int mex = 0;
  for (int idx = 0; idx < N; idx++){
    if (arr[idx] == mex){
      ++mex;
    }
  }
 
  return mex;
}

void solve(){
    int n,k; cin>>n>>k;
    vector<vector<int>> vec(k, vector<int>(3));
    for(int i = 0; i < k; ++i){
        for(int j = 0; j < 3; ++j){
            cin>>vec[i][j];
            vec[i][j]--;
        }
    }

    vector<vector<int>> arr(n);
    for(int i = 0; i < k; ++i){
        for(int j = vec[i][0]; j <= vec[i][1]; ++j){
            arr[j].push_back(vec[i][2]);
        }
    }

    for(int i = 0; i < n; ++i){
        sort(arr[i].begin() , arr[i].end());
    }


    vector<int> res(n);
    for(int i = 0; i < n; ++i){
        int mx = mex(arr[i]);
        mx = min(mx, n-1);
        res[i] = mx;
    }

    for(int i = 0; i < k; ++i){
        int mn = n-1;
        for(int j = vec[i][0]; j <= vec[i][1]; ++j) mn = min(mn, res[j]);
        if (mn == vec[i][2]){
            cout<<"-1"<<endl;
            return;
        }
    }

    // for(int i = 0; i < n; ++i){
    //     if (res[i] >= n){
    //         cout<<-1<<endl;
    //         return;
    //     }
    // }

    for(int i = 0; i < n; ++i) cout<<res[i]+1<<" ";
    cout<<endl;


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t;
    while (t--){
        solve();
    }

    return 0;
}