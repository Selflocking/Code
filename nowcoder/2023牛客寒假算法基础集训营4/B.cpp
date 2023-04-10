#include <bits/stdc++.h>
#include <cmath>
#include <cstdlib>
#include <sys/types.h>

using namespace std;
constexpr int mxN = 1e5 + 5;

long long a[mxN];
long long b[mxN];
long long c[mxN];
long long n, m;

long long mod(long long a) {
    a %= m;
    if (a < 0) a += m;
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }

    if (n % 2 != 0) {
        a[n / 2 + 1] = c[n / 2 + 1];
        b[n / 2 + 1] = 0;
    }

    for (int i = 1; i <= n / 2; ++i) {
        long long tmp = c[i] + c[n - i + 1];
        if (tmp % 2 == 0)
            a[i] = tmp / 2;
        else if (m % 2 == 1)
            a[i] = (tmp + m) / 2;
        else {
            cout << "No\n";
            return 0;
        }

        a[i] = mod(a[i]);
        b[i] = mod(c[i] - a[i]);
    }

    for (int i = n / 2 + 1; i <= n; ++i) {
        a[i] = a[n - i + 1];
        b[i] = mod(-b[n - i + 1]);
    }

    for (int i = 1; i <= n; ++i) {
        if (mod(a[i] + b[i]) != c[i]) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << " \n"[i == n];
    }
    for (int i = 1; i <= n; ++i) {
        cout << b[i] << " \n"[i == n];
    }
    return 0;
}
