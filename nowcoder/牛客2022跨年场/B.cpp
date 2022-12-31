#include <bits/stdc++.h>

using namespace std;
constexpr int mxN = 1e5 + 5;

int n;
int arr[mxN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        m[t]++;
    }
    int one = 0, two = 0, thr = 0;
    for (auto &it : m) {
        if (it.second == 1) {
            one++;
        } else if (it.second == 2) {
            two++;
        } else {
            thr++;
        }
    }

    if (one % 2 == 1 && thr == 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
    return 0;
}
