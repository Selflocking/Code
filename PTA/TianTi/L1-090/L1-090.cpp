#include <bits/stdc++.h>

using namespace std;

constexpr int mxN = 1e5 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;
    int res = a + b;
    cout << res - 16 << "\n";
    cout << res - 3 << "\n";
    cout << res - 1 << "\n";
    cout << res << "\n";

    return 0;
}
