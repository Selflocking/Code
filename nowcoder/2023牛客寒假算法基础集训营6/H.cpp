#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int mxN = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int l, r;
    cin >> n;
    cin >> l >> r;
    if (n <= l) {
        cout << 0 << "\n";
    } else if (n > r) {
        cout << 1 << "\n";
    } else {
        int t = n - 1 - l + 1;
        printf("%.9lf", 1.0 * t / (r - l + 1));
    }
    return 0;
}
