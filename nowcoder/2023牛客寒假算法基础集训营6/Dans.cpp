#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int mxN = 2e5 + 5;

string ss = " udu";

ll dpq[mxN][4] = {1};
ll dph[mxN][4] = {1};
string s;

void work(ll dp[][4]) {
    for (int i = 0; i < s.size(); ++i) {
        dp[i + 1][0] = 1;
        for (int j = 1; j <= 3; ++j) {
            dp[i + 1][j] = dp[i][j];
            if (s[i] == ss[j]) dp[i + 1][j] += dp[i][j - 1];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    work(dpq);
    reverse(s.begin(), s.end());
    work(dph);
    reverse(s.begin(), s.end());

    ll mi = 1e18;
    int ans = 0;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        ll cnt = 0;
        cnt += dpq[i][0] * dph[n - i - 1][3];
        cnt += dpq[i][1] * dph[n - i - 1][2];
        cnt += dpq[i][2] * dph[n - i - 1][1];
        cnt += dpq[i][3] * dph[n - i - 1][0];
        if (mi > cnt) {
            mi = cnt;
            ans = i;
        }
    }
    s[ans] = 'a';
    cout << s << "\n";
    return 0;
}
