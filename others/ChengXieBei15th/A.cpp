#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cin >> b[i];
    }
    long long res = 1e18;
    for (int i = 0; i < n; ++i) {
        long long tmp = a[i];
        int j = (i + 1)%n;
        while (j != i) {
            int t = j - 1;
            if (t < 0)
                t = n - 1;
            if (a[j] - b[t] > 0) {
                tmp += a[j] - b[t];
            }
            j = (j + 1) % n;
        }
        if (res > tmp) {
            res = tmp;
        }
    }
    cout << res << '\n';
    return 0;
}
