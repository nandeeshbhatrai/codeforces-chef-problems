#include <vector>
using namespace std;
typedef long long ll;

vector<ll> factors(ll n) {
    vector<ll> f;
    for (ll x = 2; x * x <= n; x++) {
        while (n % x == 0) {
            f.push_back(x);
            n /= x;
        }
    }
    if (n > 1) {
        f.push_back(n);
    }
    return f;
}