#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
constexpr int mxN = 800 + 5;
int n;
// 640 0000 0000
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    long long sum = 0;
    int mi = 999999999;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int t;
            cin >> t;
            sum += t;
            if ((i + j) % 2 == 1) mi = min(mi, t);
        }
    }
    if (n % 2 == 1) {
        cout << sum << "\n";
    } else {
        cout << sum - mi << "\n";
    }
    return 0;
}
