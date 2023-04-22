#include <bits/stdc++.h>

using namespace std;

constexpr int mxN = 1e5 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int k;
    cin >> k;
    while (k--) {
        bool dui = false;
        bool cuo = false;
        for (int i = 0; i < n; ++i) {
            int t;
            cin >> t;
            if (t == 0) continue;
            if (t == a[i]) {
                dui = true;
            } else {
                cuo = true;
                // break
                // 考试的时候写了个 break ，结果一直部分对，找了半天。
                // 原来是因为 break 之后还有部分数没输入。
                // 淦
            }
        }
        if (!cuo && dui) {
            cout << "Da Jiang!!!\n";
        } else {
            cout << "Ai Ya\n";
        }
    }

    return 0;
}
