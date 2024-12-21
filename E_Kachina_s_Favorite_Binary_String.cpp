#include <bits/stdc++.h>
// #include <chrono>

using namespace std;
using namespace std::chrono;

#define f0r(a, b) for (long long a = 0; a < (b); ++a)
#define f1r(a, b, c) for (long long a = (b); a < (c); ++a)
#define f0rd(a, b) for (long long a = (b); a >= 0; --a)
#define f1rd(a, b, c) for (long long a = (b); a >= (c); --a)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL); cout.tie(NULL);}
#define fix(prec) {cout << setprecision(prec) << fixed;}
#define mp make_pair
#define f first
#define s second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define readgraph(list, edges) for (int i = 0; i < edges; i++) {int a, b; cin >> a >> b; a--; b--; list[a].pb(b); list[b].pb(a);}
#define ai(a, n) for (int ele = 0; ele < n; ele++) cin >> a[ele];
#define ain(a, lb, rb) for (int ele = lb; ele <= rb; ele++) cin >> a[ele];
#define ao(a, n) {for (int ele = 0; ele < (n); ele++) { if (ele) cout << " "; cout << a[ele]; } cout << '\n';}
#define aout(a, lb, rb) {for (int ele = (lb); ele <= (rb); ele++) { if (ele > (lb)) cout << " "; cout << a[ele]; } cout << '\n';}
#define vsz(x) ((long long) x.size())
#define nahi {cout << "NO" << '\n';}
#define haa {cout << "YES" << '\n';}
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
    cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
    cin >> p.first;
    return cin >> p.second;
}
template<typename K, typename V> ostream& operator<<(ostream& cout, const map<K, V>& m) {
    cout << "{";
    for (auto it = m.begin(); it != m.end(); ++it) {
        if (it != m.begin())
            cout << ", ";
        cout << it->first << ": " << it->second;
    }
    cout << "}";
    return cout;
}

const ll mod = 1000000007;
ll n, m, k, p, q, l, r, w, x, y, z , h, d;
string s;
ll ans = 0;

bool two(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

class Solution {
    public:
        void solve(int t) {
            cin >> n;
            // ll cnt  =0;
            s = "";
            ll i = 1;
            while(s.size() < n){
                cout << "? " << i << ' ' << i + 1 << endl;
                // ++cnt;
                cin >> x;
                // if(x != 0 && x != 1){
                //     cout << "! IMPOSSIBLE" << endl;
                    // cout << "! " << s << endl;
                    // cout << "Total calls: " << cnt << endl;
                //     return;
                // }
                if(x == 1){
                    if(s.back() == '#'){
                        // s.back() = '1';
                        cout << "? " << i - 1 << ' ' << i + 1 << endl;
                        cin >> y;
                        // ++cnt;
                        if(y == 1){
                            s.back() = '1';
                        }else if(y == 2){
                            s.back() = '0';
                        }else{
                            cout << "! IMPOSSIBLE" << endl;
                            // cout << "! " << s << endl;
                            // cout << "Total calls: " << cnt << endl;
                            return;
                        }
                        s += "01";
                    }else{
                        s += "01";
                    }
                    i += 2;
                }else if(x == 0){
                    if(!s.empty() && s.back() == '#'){
                        cout << "! IMPOSSIBLE" << endl;
                        // cout << "! " << s << endl;
                        // cout << "Total calls: " << cnt << endl;
                        return;
                    }
                    s.pb('#');
                    ++i;
                }else{
                    cout << "! IMPOSSIBLE" << endl;
                    // cout << "! " << s << endl;
                    // cout << "Total calls: " << cnt << endl;
                    return;
                }

                if(i == n){
                    cout << "! IMPOSSIBLE" << endl;
                    // cout << "! " << s << endl;
                    // cout << "Total calls: " << cnt << endl;
                    return;
                }
            }
            cout << "! " << s << endl;
            // cout << "Total calls: " << cnt << endl;
        }
    private:
};

int main() {
    int tc = 1;
    cin >> tc;
    Solution problem;
    for (int t = 0; t < tc; t++) {
        problem.solve(t);
    }
}