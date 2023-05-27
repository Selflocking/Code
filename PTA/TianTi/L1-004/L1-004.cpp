#include <bits/stdc++.h>

using namespace std;

constexpr int mxN = 1e5 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int f;
    cin >> f;
    int ans = 5 * (f - 32) / 9;
    cout << "Celsius = " << ans << "\n";
    return 0;
}
