#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
using ll = unsigned long long;

constexpr long long MOD = 1e9 + 7;

// A55 = 5x4x3x2x1
// C52 = 5x4/2x1
ll CFun(ll all, ll x) {
    ll num = 1;
    for (ll i = 0; i < x; ++i) {
        num *= (all - i);
    }
    for (ll i = 2; i <= x; ++i) {
        num /= i;
    }
    return num % MOD;
}

int main() {
    ll n;
    cin >> n;
    unordered_map<char, ll> hash;
    for (ll i = 0; i < n; ++i) {
        char c;
        cin >> c;
        hash[c]++;
    }
    ll ans = 0;
    for (ll i = 2; i <= n; i += 2) {
        ll a = 0;
        ll x = i / 2;
        for (auto c1 = 'a'; c1 <= 'z'; ++c1) {
            if (hash[c1] < x) continue;
            for (auto c2 = c1 + 1; c2 <= 'z'; ++c2) {
                if (hash[c2] < x) continue;

                a += CFun(hash[c1], x) * CFun(hash[c2], x);
                a = a % MOD;
            }
        }
        ans += a;
        ans = ans % MOD;
    }
    cout << ans << "\n";

    return 0;
}
