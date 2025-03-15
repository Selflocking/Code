#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

/*
2
meRDZ
DameDame

em
DameDame
*/

/*
meRDZZ
ZZZZm

*/
int main() {

    int t;
    cin >> t;
    while (t--) {
        string ss;
        cin >> ss;
        const int nn = ss.size();
        string s;
        for (int i = 0; i < nn - 1; ++i) {
            if (ss[i] == 'Z') {
                continue;
            }

            if (ss[i + 1] != 'Z') {
                s += ss[i];
            } else {
                int cnt = 0;
                for (int j = i + 1; j < nn; ++j) {
                    if (ss[j] == 'Z') {
                        cnt++;
                    }
                }
                if (cnt % 2 == 0) {
                    s += ss[i];
                }
                i += cnt;
            }
        }
        if (ss[nn - 1] != 'Z') {
            s += ss[nn - 1];
        }

        string t;

        const int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'R') {
                reverse(t.begin(), t.end());
            } else {
                t += s[i];
            }
        }
        cout << t << "\n";
    }
    return 0;
}