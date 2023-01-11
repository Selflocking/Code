#include <bits/stdc++.h>

using namespace std;

constexpr int mxN = 1e5 + 5;

void solve() {
    string s;
    cin >> s;
    if (s[0] == s[s.size() - 1]) {
        cout << s[0] << " " << s.substr(1, s.size() - 2) << " "
             << s[s.size() - 1] << "\n";
        return;
    }
    if (s[0] == 'a') {
        int pos = 0;
        for (int i = s.size() - 2; i >= 1; --i) {
            if (s[i] == 'a') {
                pos = i;
                break;
            }
        }
        if (pos == 0) { // a bbbbbbbbbbb b
            cout << "a " << s.substr(1, s.size() - 2) << " b\n";
            return;
        } else { // aaaa a bbbb
            cout << s.substr(0, pos) << " a " << s.substr(pos + 1) << "\n";
            return;
        }
    } else { // b * a
        int pos = 0;
        for (int i = s.size() - 2; i >= 1; --i) {
            if (s[i] == 'a') {
                pos = i;
                break;
            }
        }
        if (pos == 0) { // b bbbbbbbb a
            cout << "b " << s.substr(1, s.size() - 2) << " a\n";
            return;
        } else { // bbbb a bba
            cout << s.substr(0, pos) << " a " << s.substr(pos + 1) << "\n";
            return;
        }
    }

    cout << ":(\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}