#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;
constexpr int mxN = 2e5 + 5;

int parent[mxN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        int t;
        cin >> t;
        parent[i] = t;
    }

    vector<int> depth(n + 1);
    depth[1] = 1;
    for (int i = 2; i <= n; ++i) {
        int cnt = 2;
        while (parent[i] != 1) {
            if (depth[parent[i]] != 0) {
                cnt = depth[parent[i]] + 1;
                break;
            } else {
                cnt++;
                parent[i] = parent[parent[i]];
            }
        }
        depth[i] = cnt;
    }

    vector<int> value(n);

    for (int i = 0; i < n; ++i) {
        cin >> value[i];
    }

    sort(value.begin(), value.end());
    sort(depth.begin(), depth.end());

    long long res = 0;
    for (int i = n - 1; i >= 0; --i) {
        res += 1LL * value[i] * depth[i + 1];
    }
    cout << res << "\n";
    return 0;
}
