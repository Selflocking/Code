#include <bits/stdc++.h>
#include <math.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string a[2];
    cin >> a[0] >> a[1];
    if (a[0][0] == '0' || a[1][0] == '0') {
        cout << "NO\n";
        return;
    }
    bool t1 = 0;
    bool t2 = 0;
    int cnt = 0;
    if (a[0][0] == '1') {
        t1 = 1;
    }
    if (a[1][0] == '1') {
        t2 = 1;
    }
    if (t1 && t2) {
        cnt++;
    }

    for (int i = 1; i < n; ++i) {
        if (t1 && t2) {
            if (a[0][i] == '1' && a[1][i] == '1') {
                cnt++;
            } else if (a[0][i] == '1' && a[1][i] == '0') {
                if (cnt % 2 == 1) {
                    if (a[1][i - cnt - i] != '1') {
                        cout << "NO\n";
                        return;
                    }
                } else {
                    if (a[0][i - cnt - i] != '1') {
                        cout << "NO\n";
                        return;
                    }
                }
            } else if (a[0][i] == '0' && a[1][i] == '1') {
                if (cnt % 2 == 1) {
                    if (a[0][i - cnt - i] != '1') {
                        cout << "NO\n";
                        return;
                    }
                } else {
                    if (a[1][i - cnt - i] != '1') {
                        cout << "NO\n";
                        return;
                    }
                }
            } else {
                cout << "NO\n";
                return;
            }
        } else if (t1 && !t2) {
            if (a[0][i] != '1') {
                cout << "NO\n";
                return;
            }
        } else if (!t1 && t2) {
            if (a[1][i] != '1') {
                cout << "NO\n";
                return;
            }
        } else {
            cout << "NO\n";
            return;
        }

        if (a[0][i] == '1') {
            t1 = 1;
        }
        if (a[1][i] == '1') {
            t2 = 1;
        }
    }
    cout << "YES\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
