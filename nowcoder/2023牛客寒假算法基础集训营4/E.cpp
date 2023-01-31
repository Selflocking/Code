#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    long long t;
    long long atk;
    cin >> n >> t >> atk;

    vector<pair<long long, long long>> monster(n);

    for (int i = 0; i < n; ++i) {
        long long a, b;
        cin >> a >> b;
        monster[i] = {a, b};
    }
    long long ans = 0;

    for (int i = 0; i < n; ++i) {
        if (monster[i].first <= atk) {
            ans += t;
            continue;
        }
        if (monster[i].second * t >= atk) {
            cout << -1 << "\n";
            return 0;
        }

        ans += ceil(1.0 * (monster[i].first - atk) /
                    (atk - monster[i].second * t)) *
               t;
        ans += t;
    }

    cout << ans - (t - 1) << "\n";
    return 0;
}
