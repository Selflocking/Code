#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>

using namespace std;

/*
3 4 1 2

3
*/

int main() {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    long long ans = 0;
    for (int i = l2; i <= min(r1, r2); ++i) {
        ans += r1 / i - (l1 - 1) / i;
    }
    cout << ans << "\n";
    return 0;
}