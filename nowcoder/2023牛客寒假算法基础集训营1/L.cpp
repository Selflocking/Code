#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    double E = 2 * 0.05 + 3 * 0.1 + 4 * 0.2 + 5 * 0.25 + 6 * 0.2 + 7 * 0.2;

    double mi = 999;
    int ans = 1;
    for (int i = 1; i <= 100; ++i) {
        double t = fabs(3.45 + 0.05 * i - E);
        if (mi > t) {
            mi = t;
            ans = i;
        }
    }

    cout << ans << "\n";
    return 0;
}
