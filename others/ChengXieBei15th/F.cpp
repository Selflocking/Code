#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    long long cnt = 1;

    int i = 1;
    int j = 2;
    while (i <= n) {
        while (a[j] >= j - i + 1) {
            cnt++;
            j++;
        }
        cnt += j - i - 1;
        i++;
    }
    cout << cnt << "\n";
}

int main() {

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
