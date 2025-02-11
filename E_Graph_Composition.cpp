// Author: Nandeesh
// created: 19.01.2025 22:18:11

#include <bits/stdc++.h>
// #include <chrono>

using namespace std;
using namespace std::chrono;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define f0r(a, b) for (long long a = 0; a < (b); ++a)
#define f1r(a, b, c) for (long long a = (b); a < (c); ++a)
#define f0rd(a, b) for (long long a = (b); a >= 0; --a)
#define f1rd(a, b, c) for (long long a = (b); a >= (c); --a)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL); cout.tie(NULL);}
#define fix(prec) {cout << setprecision(prec) << fixed;}
// #define mp make_pair
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

bool prime(long long n) {
    if(n <= 1) {return false;}
    if(n == 2 || n == 3) {return 1;}
    if( n % 2 == 0 || n % 3 == 0) { return false;}
    for(ll i = 5; i*i < n; i += 6) {
        if((n % i == 0 || n % (i+2) == 0)) {return false;}
    }
    return true;
}

void printprimefactors(ll n) {
    for(int i = 1; i*i < n; ++i) {
        if(n % i == 0) {
            cout << i << ' ';
        }
    }
    for(int i = sqrt(n)+1; i > 0; --i) {
        if(n % i == 0) {
            cout << n/i << ' ';
        }
    }
}

vector<int> seive(ll n) {
    vector<int> primes(n + 1, 1);
    for (ll index = 2; index * index <= n; ++index) {
        if (primes[index]) {
            for (ll i = index * index; i <= n; i += index) {
                primes[i] = 0;
            }
        }
    }
    return primes;
}

// mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
// mt19937 rng(61378913);
/* usage - just do rng() */

// void usaco(string filename) {
//   // #pragma message("be careful, freopen may be wrong")
//  \tfreopen((filename + ".txt").c_str(), "r", stdin);
//  \tfreopen((filename + "_out.txt").c_str(), "w", stdout);
// }

// const lld pi = 3.14159265358979323846;
const ll mod = 1000000007;
const int N = 2e5 + 5;
// const ll mod = 998244353;
ll cnt1, cnt2, m1, m2, col[N];
ll n, m, k, p, q, l, r, w, x, y, z , h, d;
// const ll template_array_size = 1e6 + 585;
// ll a[template_array_size];
// ll b[template_array_size];
// ll c[template_array_size];
string s;
ll ans = 0;

bool two(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

map<pair<ll, ll>, ll> mp;
vector<ll> ff[N], gg[N];
bool found1[N], found2[N];

class Solution {
    public:
        void solve(int t) {
            ll n, m1, m2;
            cin >> n >> m1 >> m2;
            cnt1 = 0, cnt2 = 0;
            mp.clear();
            f0r(i, n){
                ff[i].clear();
                gg[i].clear();
                found2[i] = false;
                found1[i] = false;
            }
            f0r(i , m1) {
                ll u, v;
                cin >> u >> v;
                ff[--u].push_back(--v);
                ff[v].push_back(u);
            }
            f0r(i , m2){
                ll u, v;
                cin >> u >> v;
                gg[--u].push_back(--v);
                gg[v].push_back(u);
            }
            f0r(i , n) {
                if (!found1[i]) {
                    cnt1++;
                    dfs(i);
                }
            }
            ans = 0;
            f0r(i , n) {
                for (ll v : ff[i]) {
                    if (col[i] != col[v]) {
                        ans++;
                        mp[{i, v}] = 1;
                    }
                }
            }
            f0r(i , n) {
                if (!found2[i]) {
                    cnt2++;
                    finddd(i);
                }
            }
            cout << ans/2 + (cnt2 - cnt1) << endl;
        }
    private:
        void dfs(int u) {
            col[u] = cnt1;
            found1[u] = true;
            for (int v : gg[u]) {
                if (!found1[v]) {
                    dfs(v);
                }
            }
        }

        void finddd(int u) {
            found2[u] = true;
            for (int v : ff[u]) {
                if (!found2[v] && mp[{u, v}] != 1) {
                    finddd(v);
                }
            }
        }


};

int main() {
    #ifdef kali@Nandeesh
        auto begin = std::chrono::high_resolution_clock::now();
    #endif

    send help

    int tc = 1;
    cin >> tc;
    Solution problem;
    for (int t = 0; t < tc; t++) {
        problem.solve(t);
    }

    #ifdef kali@Nandeesh
        auto end = std::chrono::high_resolution_clock::now();
        cout << setprecision(14) << fixed;
        cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
    #endif
}