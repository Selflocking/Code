#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int mxN = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    ll cnt = 0;
    while (n > 2) {
        n = n / 2 + 1;
        cnt++;
    }
    cout << cnt << "\n";
    return 0;
}
