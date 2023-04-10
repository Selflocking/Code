#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
constexpr int mxN = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> s(n);
    fill(s.begin(), s.end(), 0);
    for (int i = 0; i < n; i += 3) {
        if (m > 0) {
            s[i] = 1;
            m--;
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        if (s[i]) continue;
        if (m > 0) {
            s[i] = 1;
            m--;
        } else {
            break;
        }
    }
    int ans = 0;
    for (int i = 0; i < n - 2; ++i) {
        int cnt = 0;
        if (s[i]) cnt++;
        if (s[i + 1]) cnt++;
        if (s[i + 2]) cnt++;
        if (cnt >= 2) ans++;
    }
    cout << ans << "\n";
    return 0;
}
