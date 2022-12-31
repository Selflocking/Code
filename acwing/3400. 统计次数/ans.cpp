#include <algorithm>
#include <bits/stdc++.h>
#include <string>

using namespace std;
constexpr int mxN = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        auto it = to_string(i);
        cnt += count(it.begin(), it.end(), '0' + k);
    }
    cout << cnt << "\n";
    return 0;
}
