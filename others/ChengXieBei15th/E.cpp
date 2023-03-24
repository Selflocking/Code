#include <bits/stdc++.h>
#include <math.h>

using namespace std;

// 2 31 1847
void solve() {
    long long n;
    cin >> n;

    bool res = false;

    if (n >= 114514) {
        long long t = 114514;
        if (n % 2 == 0) {
            n /= 2;
            t /= 2;
        }
        if (n % 31 == 0) {
            n /= 31;
            t /= 31;
        }
        if (n % 1847 == 0) {
            n /= 1847;
            t /= 1847;
        }
        for (int i = 0; i < 18; ++i) {
            if (t % n == 0) {
                res = true;
                break;
            } else {
                t = t * 10;
            }
        }
    } else {
        long long t = 114514 % n;
        for (int i = 0; i < 18; ++i) {
            if (t % n == 0) {
                res = true;
                break;
            } else {
                t = t * 10;
            }
        }
    }

    if (res) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
