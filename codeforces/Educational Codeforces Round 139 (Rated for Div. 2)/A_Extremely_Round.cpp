#include <algorithm>
#include <bits/stdc++.h>
#include <string>

using namespace std;
constexpr int mxN = 999999;
vector<int> nums;

void solve() {
    int n;
    cin >> n;
    int cnt = 0;
    for (auto &i : nums) {
        if (i > n)
            break;
        cnt++;
    }
    cout << cnt << "\n";
}

void fun() {
    for (int i = 1; i <= mxN; ++i) {
        string s = to_string(i);
        if (s.size() - count(s.begin(), s.end(), '0') <= 1) {
            nums.emplace_back(stoi(s));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    fun();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
