#include <bits/stdc++.h>
#include <math.h>

using namespace std;

void solve() {
    int n;
    long long h;
    cin >> n >> h;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        a[i] = a[i + 1] - a[i];
    }

    long long k = h / n;
    if (h % n != 0) k = k + 1;

    for (int i = 0; i < n - 1; ++i) {
        if (a[i] < k) {
            h -= a[i];
            k = h / (n - i - 1);
            if (h % (n - i - 1) != 0) k++;
        }
    }

    cout << k << "\n";

    // 4 1000
    // 3 25 64 1337
    //  22 39 1273
    // 939
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
