#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int mxN = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();
    vector<int> cnt(n);

    for (int i = 0; i < n; i++) {
        if (s[i] == 'u') {
            for (int j = i + 1; j < n; ++j) {
                if (s[j] == 'd') {
                    for (int k = j + 1; k < n; ++k) {
                        if (s[k] == 'u') {
                            cnt[j]++;
                            cnt[i]++;
                            cnt[k]++;
                        }
                    }
                }
            }
        }
    }

    int mx = -1;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (cnt[i] > mx) {
            mx = cnt[i];
            ans = i;
        }
    }
    s[ans] = 'a';
    cout << s << "\n";
    return 0;
}
