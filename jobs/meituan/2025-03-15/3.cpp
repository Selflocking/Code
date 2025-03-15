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
    scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
    int ans = 0;
    for (int i = l1; i <= r1; i++) {
        if (i < l2) {
            continue;
        }
        int up = min(i, r2);
        for (int j = l2; j <= up; ++j) {
            ans += (i % j == 0);
        }
    }
    cout << ans << "\n";
    return 0;
}