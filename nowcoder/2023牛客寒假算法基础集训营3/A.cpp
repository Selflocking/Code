#include <bits/stdc++.h>

using namespace std;
constexpr int mxN = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        long long t;
        cin >> t;
        if (t > 0 && t % 2 == 0) {
            while (t % 2 == 0) {
                t /= 2;
            }
        }
        sum += t;
    }
    cout << sum << "\n";
    return 0;
}
