#include <bits/stdc++.h>

using namespace std;

map<int, long long> nums;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; ++i) {
            int t;
            cin >> t;
            nums[t]++;
        }

        if (nums.size() == 1) {
            cout << nums.begin()->second * (nums.begin()->second - 1) << "\n";
        } else {
            cout << 2 * nums.begin()->second * nums.rbegin()->second << "\n";
        }

        nums.clear();
    }
    return 0;
}
