#include <bits/stdc++.h>

using namespace std;

constexpr int mxN = 1e5 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n0, n1, n;
    cin >> n0 >> n1 >> n;
    // 考试的时候我还特判了一下特殊情况，发现并没有用。
    if (n0 == 0) {
        if (n1 % n == 0) {
            cout << 0 << " " << n << "\n";
        } else {
            cout << "No Solution\n";
        }
    }
    if (n1 == 0) {
        if (n0 % n == 0) {
            cout << n << " " << 0 << "\n";
        } else {
            cout << "No Solution\n";
        }
    }

    int res = 0;
    // 考试时随手写了一个 999, 结果总是差一个测试点，de 了半天。
    int bst = 1e9;
    for (int i = 1; i < n; ++i) {
        if (n0 == i) continue;
        if (n0 % i == 0 && n1 % (n - i) == 0) {
            int t = abs(n0 / i - n1 / (n - i));
            if (t < bst) {
                bst = t;
                res = i;
            }
        }
    }
    if (res == 0) {
        cout << "No Solution\n";
    } else {
        cout << res << " " << n - res << "\n";
    }
    return 0;
}
