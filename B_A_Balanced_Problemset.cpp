#include <bits/stdc++.h>
#include <chrono>

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
#define mp make_pair
#define f first
#define s second
#define all(v) v.begin(), v.end()
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
    for (auto it = m.begin(); it != m.end(); ++it) {
        if (it != m.begin())
            cout << "\n";
        cout << '"' << it->first << '"' << ": " << '"' << it->second << '"';
    }
    return cout;
}

bool prime(ll n) {
    if (n <= 1) {return false;}
    if (n == 2 || n == 3) {return true;}
    if (n % 2 == 0 || n % 3 == 0) {return false;}
    for (ll i = 5; i * i <= n; i += 6) {
        if ((n % i == 0 || n % (i + 2) == 0)) {return false;}
    }
    return true;
}

void printprimefactors(ll n) {
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            cout << i << ' ';
        }
    }
    for (int i = sqrt(n) + 1; i > 0; --i) {
        if (n % i == 0) {
            cout << n / i << ' ';
        }
    }
}

vector<bool> sieve(ll n) {
    vector<bool> primes(n + 1, true);
    primes[0] = primes[1] = false;
    for (ll index = 2; index * index <= n; ++index) {
        if (primes[index]) {
            for (ll i = index * index; i <= n; i += index) {
                primes[i] = false;
            }
        }
    }
    return primes;
}

// const lld pi = 3.14159265358979323846;
// const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;

ll n, m, k, p, q, l, r, w, x, y, z, h, d;
// const ll template_array_size = 1e6 + 585;
// ll a[template_array_size];
// ll b[template_array_size];
// ll c[template_array_size];
string s;
ll ans = 0;

void solve(int tc = 0){
    // Your solution goes here
    cin >> x >> n;
    if(x%n == 0){
        cout << x/n << '\n';
        return;
    }
    int k = x/n;
    while(k >= 0){
        if((x - k*n) >= 0 && (x - k*n)%k == 0){
            cout << k << '\n';
            return;
        }
        --k;
    }
    cout << 1 << '\n';
}

int main() {
    #ifdef kali㉿Nandeesh
        auto begin = std::chrono::high_resolution_clock::now();
    #endif

    send help

    // Uncomment the next line if you are using USACO
    // usaco("filename");

    int tc = 1;
    cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    #ifdef kali㉿Nandeesh
        auto end = std::chrono::high_resolution_clock::now();
        cout << setprecision(14) << fixed;
        cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
    #endif
}