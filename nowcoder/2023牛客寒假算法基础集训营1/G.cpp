#include <bits/stdc++.h>
#include <cmath>

using namespace std;
constexpr int mxN = 1e5 + 5;

inline int fun(int x) {
    //
    return round(10 * sqrt(x));
}

int n, m;
set<int> locs;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    vector<int> nums(n + 1);
    long long sum = 0;

    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
        sum += nums[i];
        if (fun(nums[i]) != nums[i]) {
            locs.insert(i);
        }
    }

    while (m--) {
        int op;
        cin >> op;
        if (op == 2) {
            cout << sum << "\n";
        } else {
            int l, r, k;
            cin >> l >> r >> k;
            auto it = locs.lower_bound(l);
            auto ed = locs.upper_bound(r);

            while (!locs.empty() && it != ed) {
                sum -= nums[*it];
                bool flag = 0;
                for (int i = 0; i < k; ++i) {
                    int t = fun(nums[*it]);
                    if (nums[*it] == t) {
                        flag = 1;
                        break;
                    } else {
                        nums[*it] = t;
                    }
                }
                sum += nums[*it];
                int t = *it;
                it++;
                if (flag) locs.erase(t);
            }
        }
    }
    return 0;
}
