#include <bits/stdc++.h>
using namespace std;

#define run ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define ll long long
#define pb push_back
#define M 1000000007
#define all(x) x.begin(), x.end()
#define loop(i,a,b) for(int i=a; i<b; i++)
#define rloop(i,a,b) for(int i=a; i>=b; i--)

#define sum(x) accumulate((x).begin(), (x).end(), 0LL)
#define maxi(x) *max_element((x).begin(), (x).end())
#define mini(x) *min_element((x).begin(), (x).end())
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a, min(b,c))
#define mem1(a)  memset(a,-1,sizeof(a))
#define mem0(a)  memset(a,0,sizeof(a))
// #define v(a)    vector<a>
// #define map unordered_map
#define pqueue(a) priority_queue<a>
#define p_queue(a)        priority_queue<a, vector<a>, greater<a>>
#define cout(x) cout << x << endl
#define cin(x) cin >> x 
#define print(a) for(auto&x:a) {cout<<x<<" ";} cout<<endl;
#define print2(a) for(auto&x:a){ for(auto&y:x) { cout<<y<<" "; } cout<<endl; }



int main() {
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n; 
    
        vector<pair<long long int , int >> b;
        for(int i = 0; i < n ;i++){
            long long int te;
            cin >> te;
            b.push_back({te,i});
        }

        // sort(a.begin(),a.end());
        sort(b.begin(),b.end());
    

        vector<int> ans(n);
        int j =0 ;
        
        long long int sum1 = 0;
        int rem = 0;
        for(int i = 0 ; i < n ;i++){
            if (j <= i )sum1+= b[i].first;
            while(j <n){
                if (sum1 >= b[j].first){
                    rem+=1;
                    if (j!=i){sum1+= b[j].first;}
                    j++;
                }
                else {
                    break;
                }
            }
            ans[b[i].second]=rem-1;

        } 

        for(auto i : ans)cout << i << " " ;
        cout << endl;
        
    }
    
    return 0 ;
}