#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int mxN = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x, y, k, n, t;
    cin >> x >> y >> k >> n >> t;
    ll sum = 0;
    ll bak = n;
    ll v = 0;
    while (n != 0 && sum < t) {
        sum += x * n;
        x += (n + v) / k * y;
        v = (n + v) % k;
        n--;
    }

    if (sum < t)
        cout << -1 << "\n";
    else
        cout << bak - n << "\n";

    return 0;
}
