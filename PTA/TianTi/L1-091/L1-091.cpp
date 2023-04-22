#include <bits/stdc++.h>

using namespace std;

constexpr int mxN = 1e5 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    string x;
    cin >> n >> x >> m >> k;
    if (k == n) {
        cout << "mei you mai " << x << " de"
             << "\n";
    } else if (k == m) {
        cout << "kan dao le mai " << x << " de"
             << "\n";
    } else {
        cout << "wang le zhao mai " << x << " de"
             << "\n";
    }
    return 0;
}
